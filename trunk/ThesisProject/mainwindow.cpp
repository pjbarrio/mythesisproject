#include "mainwindow.h"
#include <stdlib.h>
#include <QString>
#include "Init/InitTracker.h"
#include "Utils/SystemInfo.h"
#include <cv.h>
#include <highgui.h>
#include <tchar.h>
#include <string.h>
#include "DynamicGestureRecognition/Events/PressCharEvent.h"
#include "DynamicGestureRecognition/Events/ExecuteApplication.h"
#include "DynamicGestureRecognition/src/Gesture.h"
#include "DynamicGestureRecognition/Events/CombinedKeyPressed.h"
#include "DynamicGestureRecognition/Events/OpenFileEvent.h"
#include "DynamicGestureRecognition/DistanceCalculators/EuclideanDistance.h"
#include "DynamicGestureRecognition/DTWAlgorithms/ItakuraDTWAlgorithm.h"
#include "DynamicGestureRecognition/src/GestureEventMapper.h"
#include "GUI/Utils/Container.h"
#include <QMessageBox>
#include <QFileDialog>
#include "Init/ThesisStart.h"
#include "XML/XmlStreamReader.h"
#include "XML/XMLStreamWriter.h"


/*
 * This Method initiates the main Application. Receives the Dialog boxes that will appear during the execution.
 */

ThesisProject::ThesisProject(AddGesture* addGesture,AddEvent* addEvent,AddAsociation* addAsociation,StateViewer* stateViewer,HandDiagnostic* handDiagnostic,About* about,QWidget *parent)
    : QMainWindow(parent)
{
	ui.setupUi(this);

	this->addGestureDialog = addGesture;
	this->addEventDialog = addEvent;
	this->addAsociationDialog = addAsociation;
	this->stateViewer = stateViewer;
	this->handDiagnostic = handDiagnostic;
	this->about = about;
	initVariables();

	createCompleteTrayIcon();

	createToolbar();

}

/*
 * This method associates the toolbar actions
 * with their slots.
 */

void ThesisProject::createToolbar(){
	connect(ui.actionSalir,SIGNAL(triggered()),this,SLOT(close()));
	connect(ui.actionAbrir_Configuraci_n,SIGNAL(triggered()),this,SLOT(openConfiguration()));
	connect(ui.actionGestos,SIGNAL(triggered()),this,SLOT(importGestures()));
	connect(ui.actionAbrir_Archivo,SIGNAL(triggered()),this,SLOT(importOpenFileEvents()));
	connect(ui.actionAcerca_de,SIGNAL(triggered()),this,SLOT(openAbout()));
	connect(ui.actionEjecuci_n_Aplicaci_n,SIGNAL(triggered()),this,SLOT(importExecutionApplicationEvents()));
	connect(ui.actionImportar_Todos,SIGNAL(triggered()),this,SLOT(importAllEvents()));
	connect(ui.actionSimulaci_n_Tecla,SIGNAL(triggered()),this,SLOT(importPressKeyEvents()));
	connect(ui.actionCombinaci_n_Teclas,SIGNAL(triggered()),this,SLOT(importCombinedKeyPressEvents()));
	connect(ui.actionSalvar_Configuraci_n,SIGNAL(triggered()),this,SLOT(saveConfigurationinFile()));
	connect(ui.action_Detener_Captura, SIGNAL(triggered()), this, SLOT(stopCapture()));
	ui.menuControl->addAction(ViewState);
	ViewState->setShortcut(QApplication::translate("ThesisProjectClass", "Ctrl+S", 0, QApplication::UnicodeUTF8));
	ui.menuConfiguraci_n->addAction(quitAction);
}

/*
 * This method opens the about window.
 */

void ThesisProject::openAbout(){
	about->exec();
}

/*
 * This methods updates the list views with the models.
 */

void ThesisProject::updateListViews(){
	updateAssociationsView();
	updateGesturesView();
	updateEventsView();
}

/*
 * This method updates the association List View with
 * the gesture Event Mapper instance
 */
void ThesisProject::updateAssociationsView(){
	ui.AsociacionList->clear();

	GestureEventMapper* gem = GestureEventMapper::getInstance();
	gem->begin();
	QString NoDet = QString("NoGestureDetected");
	Association* association;
	QString* ass;
	bool activated;
	while (gem->hasNext()){
		association = gem->getActualAssociation();
		QString gid(association->getGesture()->getId().c_str());
		if (QString::compare(NoDet,gid)!=0)
		{
			QListWidgetItem *qListItem = new QListWidgetItem(ui.AsociacionList);
			QString eid(association->getEvent()->getId().c_str());
			ass = new QString(gid + " <-> " + eid);
			qListItem->setText(*ass);
			activated = association->getActivated();
			if (activated)
				qListItem->setCheckState(Qt::Checked);
			else
				qListItem->setCheckState(Qt::Unchecked);
		}
		gem->next();
	}
}

/*
 * This method updates the Gestures List View with the
 * Gesture Model
 */
void ThesisProject::updateGesturesView(){
	ui.GestosList->clear();

	GestureModel* gm = getGestureModel();
	gm->begin();
	Gesture* g;
	while (gm->hasNext()){
		g = gm->getNextGesture();
		QListWidgetItem *qListItem = new QListWidgetItem(ui.GestosList);
		qListItem->setText(QString(g->getId().c_str()));
		gm->next();
	}
}

/*
 * This method updates the Events Lists View with the
 * Events models.
 */

void ThesisProject::updateEventsView(){
	ui.EventosList->clear();
	updateEventView(getKeyEventModel());
	updateEventView(getCombinedKeyEventModel());
	updateEventView(getApplicationEventModel());
	updateEventView(getOpenFileEventModel());
}

/*
 * This method updates the Event view with the model in the parameter
 * list.
 */

void ThesisProject::updateEventView(EventModel* e){
	e->begin();
	Event* ev;
	while (e->hasNext()){
		ev = e->getNextEvent();
		QListWidgetItem *qListItem = new QListWidgetItem(ui.EventosList);
		qListItem->setText(QString(ev->getId().c_str()));
		e->next();
	}
}

/*
 * This methods opens a configuration from an xml file.
 */

void ThesisProject::openConfiguration(){
	QString* fileName = selectXmlFile();
	if (fileName != 0){
		ConfigurationFileName = fileName;
		fillModels(*fileName,getGestureModel(),getKeyEventModel(),getCombinedKeyEventModel(),
				getApplicationEventModel(),getOpenFileEventModel(),GestureEventMapper::getInstance());
		updateListViews();
	}
}

/*
 * This method returns the selected xml file.
 */

QString* ThesisProject::selectXmlFile(){
	QString* filter = new QString();
	QString fileName = QFileDialog::getOpenFileName(this,
			 "Seleccionar xml de configuración", "Configuration/", tr("Archivos Configuración (*.xml)"),filter);
	if (QString::compare(*filter,tr("Archivos Configuración (*.xml)")) == 0){
		return new QString(fileName);
	}
	return 0;
}

/*
 * This method fills the models with the xml content
 */

void ThesisProject::fillModels(QString fileName,GestureModel* gm, EventModel* k,
		EventModel* ck,EventModel* a,EventModel* o,GestureEventMapper* gem){
	XmlStreamReader* xml = new XmlStreamReader(gm,k,ck,a,o,gem);
	xml->readFile(fileName);
}

/*
 * This method imports all events from an xml file.
 */
void ThesisProject::importAllEvents(){
	QString* fileName = selectXmlFile();
	if (fileName != 0){
		fillModels(*fileName,
				0,getKeyEventModel(),getCombinedKeyEventModel(),
				getApplicationEventModel(),getOpenFileEventModel(),0);
		updateEventsView();
	}
}

/*
 * This method imports OpenFile events from an xml file.
 */

void ThesisProject::importOpenFileEvents(){
	QString* fileName = selectXmlFile();
	if (fileName != 0){
		fillModels(*fileName,
				0,0,0,0,getOpenFileEventModel(),0);
		updateEventView(getOpenFileEventModel());
	}
}

/*
 * This method imports ExecutionApplication events from an xml file.
 */

void ThesisProject::importExecutionApplicationEvents(){
	QString* fileName = selectXmlFile();
	if (fileName != 0){
		fillModels(*fileName,0,0,0,getApplicationEventModel(),0,0);
		updateEventView(getApplicationEventModel());
	}
}

/*
 * This method imports PressKeyEvents events from an xml file.
 */

void ThesisProject::importPressKeyEvents(){
	QString* fileName = selectXmlFile();
	if (fileName != 0){
		fillModels(*fileName,0,getKeyEventModel(),0,0,0,0);
		updateEventView(getKeyEventModel());
	}
}

/*
 * This method imports CombinedKeyPress events from an xml file.
 */

void ThesisProject::importCombinedKeyPressEvents(){
	QString* fileName = selectXmlFile();
	if (fileName != 0){
		fillModels(*fileName,0,0,getCombinedKeyEventModel(),0,0,0);
		updateEventView(getCombinedKeyEventModel());
	}
}

/*
 * This method imports gestures from an xml file.
 */

void ThesisProject::importGestures(){
	QString* fileName = selectXmlFile();
	if (fileName != 0){
		fillModels(*fileName,getGestureModel(),0,0,0,0,0);
		updateGesturesView();
	}
}

/*
 * This method saves the actual configuration in an
 * XML File.
 */

void ThesisProject::saveConfigurationinFile(){
	QString fileName;
	QString Dir;
	QString* filter = new QString();
	if (ConfigurationFileName!=0){
		Dir = *ConfigurationFileName;
	}
	else {
		Dir = "Configuration/";
	}

	fileName = QFileDialog::getSaveFileName(this,"Salvar Configuración actual",Dir,tr("Archivos Configuración (*.xml)"),filter);

	if (QString::compare(*filter,tr("Archivos Configuración (*.xml)")) == 0){
		XMLStreamWriter* xmlwriter = new XMLStreamWriter();
		xmlwriter->writeXML(fileName,getGestureModel(),getKeyEventModel(),
				getCombinedKeyEventModel(),getApplicationEventModel(),getOpenFileEventModel(),
				GestureEventMapper::getInstance());

	}
}

/*
 * This method intercept the close event. The purpose is minimize the application to Systray.
 */

void ThesisProject::closeEvent(QCloseEvent *event)
{
 if (trayIcon->isVisible()) {
	 QMessageBox::information(this, tr("Systray"),
							  tr("El programa seguirá ejecutando en el "
								 "system tray. Para terminar el programa, "
								 "Seleccione <b>Salir</b> en el menú de Contexto "
								 "del system tray."));
	 Container::getInstance()->finishCamViewer();
	 Restore->setEnabled(true);
	 hide();
	 event->ignore();
 }
}

/*
 * This method show the main window in its normal size.
 */

void ThesisProject::showNormal(){
	Container::getInstance()->createCamViewerInstance(ui.capturedImage);
	Restore->setEnabled(false);
	QMainWindow::showNormal();
}

/*
 * This method create the menu that will appear in the system tray.
 */

void ThesisProject::createCompleteTrayIcon(){
	trayIcon = new QSystemTrayIcon(this);
	trayIconMenu = new QMenu(this);

	QIcon icon = QIcon(":/Icon/webcamicon.jpg");
	trayIcon->setIcon(icon);

	trayIcon->setToolTip("Hand Tracker");

	StopCapturing = new QAction(tr("Detener Captura"), this);

	StopCapturing->setIcon(QIcon(QPixmap(":/ToolBar/Stop.jpg")));

	StopCapturing->setShortcut(tr("Ctrl+D"));

	StopCapturing->setEnabled(false);

	trayIconMenu->addAction(StopCapturing);

	connect(StopCapturing, SIGNAL(triggered()), this, SLOT(stopCapture()));

	trayIconMenu->addSeparator();

	ViewState = new QAction(tr("Ver estado"), this);

	ViewState->setEnabled(false);

	ViewState->setIcon(QIcon(QPixmap(":/ToolBar/ViewState.jpg")));

	trayIconMenu->addAction(ViewState);

	connect(ViewState, SIGNAL(triggered()), this, SLOT(ViewCaptureState()));

	showCaptureCross = new QAction(tr("Mostrar Captura"),this);

	showCaptureCross->setEnabled(false);

	showCaptureCross->setCheckable(true);

	trayIconMenu->addAction(showCaptureCross);

	showFiltered = new QAction(tr("Mostrar imagen Filtrada"),this);

	showFiltered->setEnabled(false);

	showFiltered->setCheckable(true);

	trayIconMenu->addAction(showFiltered);

	trayIconMenu->addSeparator();

	Restore = new QAction(tr("Restaurar"), this);

	Restore->setEnabled(false);

	Restore->setIcon(QIcon(QPixmap(":/ToolBar/Restore.png")));

	trayIconMenu->addAction(Restore);

	connect(Restore, SIGNAL(triggered()), this, SLOT(showNormal()));

	trayIconMenu->addSeparator();

	quitAction = new QAction(tr("&Salir"), this);

	quitAction->setShortcut(QApplication::translate("ThesisProjectClass", "Ctrl+Shift+S", 0, QApplication::UnicodeUTF8));

	quitAction->setIcon(QIcon(QPixmap(":/ToolBar/quit.jpg")));

///	connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

	connect(quitAction, SIGNAL(triggered()), this, SLOT(byeApplication()));

	trayIconMenu->addAction(quitAction);

	trayIcon->setContextMenu(trayIconMenu);

	trayIcon->show();
}
/*
 * This method verifies if capturing is running. If so, stops
 * it and then quit the application.
 */

void ThesisProject::byeApplication(){
	if (initiatedCamera){
		stopCapture();
		Container::getInstance()->finishCamViewer();
	}
	qApp->quit();
}
/*
 * This method stops the capture process.
 */

void ThesisProject::stopCapture(){
	finishTrack();
}

/*
 * This method shows the state window.
 */

void ThesisProject::ViewCaptureState(){
	QMetaObject::invokeMethod(stateViewer,"show");
}

/*
 * This method initiates the variables which will be used during the application.
 */

void ThesisProject::initVariables(){
	rotatex = false;
	rotatey = false;
	initiatedCamera = false;
	UP_STR = QString("Up");
	DOWN_STR = QString("Down");
    RIGHT_STR = QString("Right");
    LEFT_STR = QString("Left");
    ESC_STR = QString("Esc");
    SPACE_STR = QString("Space");
    INTRO_STR = QString("Intro");
    TAB_STR = QString("Tab");
    F5_STR = QString("F5");
    PGUP_STR = QString("Pg.Up");
    PGDN_STR = QString("Pg.Dn");
    ALTTAB_STR = QString("Alt+Tab");
    ALT_STR = QString("Alt");

    distanceCalculator = 0;
    dtwAlgorithm = 0;
    gestureModel = 0;

    keyEventModel = 0;
    combinedKeyEventModel = 0;
    AppEventModel = 0;
    fileEventModel = 0;
    sysInfo = 0;
    coordSaver = 0;

    ConfigurationFileName = 0;
}

/*
 * this method removes the variables used during the execution.
 */

ThesisProject::~ThesisProject()
{
	addGestureDialog = 0;
	addEventDialog = 0;
	addAsociationDialog = 0;
	stateViewer = 0;
	handDiagnostic = 0;
}

/*
 * This method shows the AddGesture window and updates the listwidgets showed by the Configuration tab.
 */

void ThesisProject::addGesture()
{

	int ret = addGestureDialog->exec();

	if (ret==1){
		QString* id = addGestureDialog->getId();
		DTWData* tx = addGestureDialog->getTx();
		DTWData* ty = addGestureDialog->getTy();



		std::string* s1 = new std::string(id->toStdString());

		Gesture* g = new Gesture(tx,ty,s1->c_str());

		if (!getGestureModel()->addGesture(g)){
			 QMessageBox::information(this, tr("Hand-Tracking: Nuevo Gesto"),
									  tr("En la base de Gestos ya existe un gesto "
										 "almacenado con las características recientemente "
										 "cargadas. Para evitar funcionamiento incorrecto, el "
										 "gesto introducido no se guardará."));
		}
		else{
			QListWidgetItem *qListItem = new QListWidgetItem(ui.GestosList);
			qListItem->setText(*id);
		}

	}

	Container::getInstance()->createCamViewerInstance(this->getCapturedImage());
}

/*
 * This method shows the AddEvent window and updates the listwidgets showed by the Configuration tab.
 */

void ThesisProject::addEvent()
{
	int ret = addEventDialog->exec();

	if (ret==1){
		QString *id = addEventDialog->getId();

		QListWidgetItem *qListItem = new QListWidgetItem(ui.EventosList);
		qListItem->setText(*id);

		if (addEventDialog->getIsKey()){
			QString* key = addEventDialog->getKey();

			if (QString::compare((*key),ALTTAB_STR) == 0){
				PressCharEvent* pce = new PressCharEvent("CombinedKey",TAB_BYTE,TAB_STR.toStdString());

				char* ident = new char[id->size()];
				strcpy(ident,id->toStdString().c_str());
				CombinedKeyPressed* ckp = new CombinedKeyPressed(ident,ALT_BYTE,pce,ALT_STR.toStdString());

				getCombinedKeyEventModel()->addEvent(ckp);
			}
			else{
				PressCharEvent* pce = createPressCharEvent(id,key);
				if (pce!=0){
					getKeyEventModel()->addEvent(pce);
				}
			}

		}
		else if (addEventDialog->getIsApp()){
			QString* app = addEventDialog->getApp();
			if (addEventDialog->getIsExe()){
				if (addEventDialog->getHasArgs()){
					QString* args = addEventDialog->getArgs();

					std::string* s1 = new std::string(app->toStdString());
					std::string* s2 = new std::string(args->toStdString());

					char* ident = new char[id->size()];
					strcpy(ident,id->toStdString().c_str());

					ExecuteApplication* ea = new ExecuteApplication(ident,s1,s2);

					getApplicationEventModel()->addEvent(ea);

				}
				else {

					char* ident = new char[id->size()];

					strcpy(ident,id->toStdString().c_str());

					std::string* s1 = new std::string(app->toStdString());

					ExecuteApplication* ea = new ExecuteApplication(ident,s1,new std::string(""));

					getApplicationEventModel()->addEvent(ea);
				}

			}
			else if (addEventDialog->getIsOther()){

				char* ident = new char[id->size()];

				strcpy(ident,id->toStdString().c_str());

				std::string* file = new std::string(app->toStdString());

				OpenFileEvent* ofe = new OpenFileEvent(ident,file);

				getOpenFileEventModel()->addEvent(ofe);
			}

		}
	}
}

/*
 * This method creates a PressCharEvent using the values in the parameter list.
 */

PressCharEvent* ThesisProject::createPressCharEvent(QString* id,QString* key){

	char* ident = new char[id->size()];
	strcpy(ident,id->toStdString().c_str());

	if (QString::compare(*key,UP_STR) == 0)
		return new PressCharEvent(ident,UP_BYTE,UP_STR.toStdString());
	if (QString::compare(*key,DOWN_STR) == 0)
		return new PressCharEvent(ident,DOWN_BYTE,DOWN_STR.toStdString());
	if (QString::compare(*key,RIGHT_STR) == 0)
		return new PressCharEvent(ident,RIGHT_BYTE,RIGHT_STR.toStdString());
	if (QString::compare(*key,LEFT_STR) == 0)
		return new PressCharEvent(ident,LEFT_BYTE,LEFT_STR.toStdString());
	if (QString::compare(*key,ESC_STR) == 0)
		return new PressCharEvent(ident,ESC_BYTE,ESC_STR.toStdString());
	if (QString::compare(*key,SPACE_STR) == 0)
		return new PressCharEvent(ident,SPACE_BYTE,SPACE_STR.toStdString());
	if (QString::compare(*key,INTRO_STR) == 0)
		return new PressCharEvent(ident,INTRO_BYTE,INTRO_STR.toStdString());
	if (QString::compare(*key,TAB_STR) == 0)
		return new PressCharEvent(ident,TAB_BYTE,TAB_STR.toStdString());
	if (QString::compare(*key,F5_STR) == 0)
		return new PressCharEvent(ident,F5_BYTE,F5_STR.toStdString());
	if (QString::compare(*key,PGUP_STR) == 0)
		return new PressCharEvent(ident,PGUP_BYTE,PGUP_STR.toStdString());
	if (QString::compare(*key,PGDN_STR) == 0)
		return new PressCharEvent(ident,PGDN_BYTE,PGDN_STR.toStdString());

	return 0;
}

/*
 * This method shows the AddAssociation window and updates the listwidgets showed int the Configuration tab.
 */

void ThesisProject::addAsociation()
{
	int ret = addAsociationDialog->exec(getGestureModel(),getKeyEventModel(),
			getCombinedKeyEventModel(),getApplicationEventModel(),getOpenFileEventModel());

	if (ret==1){
		QList<QString*>* gestures = addAsociationDialog->getGestures();
		QList<QString*>* events = addAsociationDialog->getEvents();

		GestureEventMapper* gestureEventMapper = GestureEventMapper::getInstance();

		QString* gest;
		QString* eve;
		QString* ass;
		Gesture* g;
		Event* e;

		for (int i = 0;i<gestures->size();i++){

			gest = gestures->at(i);
			eve = events->at(i);
			g = getGestureModel()->getGesture(new std::string(gest->toStdString()));
			e = getEventFromModels(eve);

			if (g!=0 && e!=0){
				bool added;
				bool changed = gestureEventMapper->addAssociation(g,e,true,added);
				if (added){
					QListWidgetItem *qListItem = new QListWidgetItem(ui.AsociacionList);

					ass = new QString(*gest + " <-> " + *eve);
					qListItem->setText(*ass);

					if (!changed)
						qListItem->setCheckState(Qt::Checked);
					else
						qListItem->setCheckState(Qt::Unchecked);
				}
				else{
					updateAssociationsView();
				}
			}
		}
	}
}

/*
 * This method returns the Event associated to the id passed by
 * parameter. It looks for the Event in every EventModel.
 */

Event* ThesisProject::getEventFromModels(QString* ev){
	std::string* s = new std::string(ev->toStdString());
	Event* ret = 0;
	ret = getKeyEventModel()->getEvent(s);
	if (ret!=0)
		return ret;
	ret = getApplicationEventModel()->getEvent(s);
	if (ret!=0)
		return ret;
	ret = getOpenFileEventModel()->getEvent(s);
	if (ret!=0)
		return ret;
	ret = getCombinedKeyEventModel()->getEvent(s);
	if (ret!=0)
		return ret;
	return ret;
}

/*
 * This method removes the selected gesture.
 */

void ThesisProject::removeGesture(){
	QList<QListWidgetItem*> q = ui.GestosList->selectedItems();
	if (q.size()==1){
		QString id = q.first()->text();
		getGestureModel()->removeGesture(new std::string(id.toStdString()));
		delete(q.first());
	}

}

/*
 * This method removes the selected Event.
 */

void ThesisProject::removeEvent(){
	QList<QListWidgetItem*> q = ui.EventosList->selectedItems();
	if (q.size()==1){
		QString id = q.first()->text();
		removeEventfromModel(id);
		delete(q.first());
	}
}

/*
 * This method removes the event from the model
 */

void ThesisProject::removeEventfromModel(QString ide){
	Event* e;
	std::string* id = new std::string(ide.toStdString());

	e = getKeyEventModel()->getEvent(id);
	if (e!=0){
		getKeyEventModel()->removeEvent(id);
		return;
	}

	e = getCombinedKeyEventModel()->getEvent(id);
	if (e!=0){
		getCombinedKeyEventModel()->removeEvent(id);
		return;
	}

	e = getApplicationEventModel()->getEvent(id);
	if (e!=0){
		getApplicationEventModel()->removeEvent(id);
		return;
	}

	e = getOpenFileEventModel()->getEvent(id);
	if (e!=0){
		getOpenFileEventModel()->removeEvent(id);
		return;
	}
}

/*
 * This method removes the selected Asociation.
 */

void ThesisProject::removeAsociation(){
	QList<QListWidgetItem*> q = ui.AsociacionList->selectedItems();
	if (q.size()==1){
		QString text = q.first()->text();
		QStringList l = text.split(tr(" <-> "));
		QString gid = l.first();
		QString eid = l.last();
		Gesture* g = getGestureModel()->getGesture(new std::string(gid.toStdString()));
		Event* e = getEventFromModels(&eid);
		GestureEventMapper::getInstance()->removeAssociation(g,e);
		delete(q.first());
	}
}

/*
 * This method set the horizontal rotation of the captured image.
 */

void ThesisProject::rotateX(bool val){
	rotatex = val;
	Container::getInstance()->setRotateX(val);
}

/*
 * This method set the vertical rotation of the captured image.
 */

void ThesisProject::rotateY(bool val){
	rotatey = val;
	Container::getInstance()->setRotateY(val);
}

/*
 * This method starts the hand tracking process using the configuration applied by the user.
 */

void ThesisProject::startApplication(){

	saveConfiguration();

	if (Container::getInstance()->getClickSupport() || Container::getInstance()->getStateSupport()){
		if (!Container::getInstance()->getDiagnosticExecuted()){
			int oknok = QMessageBox::question(this, tr("Hand-Tracking: Falta de Configuración"),
												  tr("No se ha ejecutado el Diagnóstico de estados "
													 "de mano abierta/cerrada. Los resultados obtenidos podrán ser erróneos "
													 "¿Desea continuar?"),QMessageBox::Yes,QMessageBox::No);
			if (oknok==QMessageBox::No)
				return;
		}

	}

	Container::getInstance()->finishCamViewer();

	SystemInfo* si = getSystemInfo();

	CoordsSaver* cs = getCoordSaver();

	CamHandler* ch = new CamHandler(Container::getInstance()->getLog());

	ThesisStart* ts = new ThesisStart(this,this->stateViewer,si,cs);

	Container::getInstance()->setThesisStart(ts);

	this->initTrack(cs,si,ch);

    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(captureNextFrame()));

    timer->start(15);

	ts->start();

}

/*
 * This method saves the configuration provided by the user. It represents the GUI part of the model.
 */

void ThesisProject::saveConfiguration(){

	bool rx  = ui.XRotationBox->isChecked();
	bool ry = ui.YRotationBox->isChecked();
	bool gs = ui.GestureSupport->isChecked();
	bool ss = ui.StateSupport->isChecked();
	bool vp = ui.viewPointer->isChecked();
	bool cs = ui.ClickSupport->isChecked();
	bool oh = ui.OpenHandRadio->isChecked();
	bool ch = ui.CloseHandRadio->isChecked();

	Container::getInstance()->setModel(rx,ry,gs,ss,vp,cs,oh,ch);
}

/*
 * This method executes the diagnostic to determine the hand Open/Close state.
 */

void ThesisProject::runHandDiagnostic(){

	//Finish Thread

	Container* cont = Container::getInstance();

	cont->finishCamViewer();

	//Run hand Diagnostig

	LightStabilizer* lightStabilizer = cont->getLightStabilizer();

	ConfigHandler* config = cont->getConfigHandler();

	lightStabilizer->setThreshold_delta(config->getLightStabilizerThresholdDelta());

	CamHandler* cam = new CamHandler(cont->getLog());

	cam->initCamDevice();

	FilterHandler* filterHandler = cont->getFilterHandler();

	lightStabilizer->runAmbientDiagnostic(cam,filterHandler,handDiagnostic);

	cam->stopCamDevice();

	//Start Thread Again

	cont->createCamViewerInstance(cont->getThesisProject()->getCapturedImage());

}

/*
 * This method returns the GestureModel used by the application.
 */

GestureModel* ThesisProject::getGestureModel()
{
	if (gestureModel == 0){
		distanceCalculator = new EuclideanDistance();
		//TODO VER CUAL ES EL RATE!!
		dtwAlgorithm = new ItakuraDTWAlgorithm(0.3,distanceCalculator);
		gestureModel = new GestureModel(dtwAlgorithm);
	}

	return gestureModel;

}

/*
 * This method returns the Event Model used to store internally the Key Press Events
 */

EventModel* ThesisProject::getKeyEventModel()
{
	if (keyEventModel == 0){
		keyEventModel = new EventModel();
	}
	return keyEventModel;
}

/*
 * This method returns the Event Model used to store internally the Combined Key Events
 */

EventModel* ThesisProject::getCombinedKeyEventModel()
{
	if (combinedKeyEventModel == 0){
		combinedKeyEventModel = new EventModel();
	}
	return combinedKeyEventModel;
}

/*
 * This method returns the Event Model used to store internally the Application Execution Events
 */

EventModel* ThesisProject::getApplicationEventModel()
{
	if (AppEventModel == 0){
		AppEventModel = new EventModel();
	}
	return AppEventModel;
}

/*
 * This method returns the Event Model used to store internally the Open File Events
 */

EventModel* ThesisProject::getOpenFileEventModel()
{
	if (fileEventModel == 0){
		fileEventModel = new EventModel();
	}
	return fileEventModel;
}

/*
 * This method initializes the tracker.
 */

int ThesisProject::initTrack(CoordsSaver* coordSaver, SystemInfo* sysInfo, Camera* camera){

	if (Container::getInstance()->getStateSupport()){

		ViewState->setEnabled(true);

	}

	showCaptureCross->setEnabled(true);

	showCaptureCross->setChecked(true);

	showFiltered->setEnabled(true);

	showFiltered->setChecked(false);

	initiatedCamera = true;

	ui.action_Detener_Captura->setEnabled(true);

	StopCapturing->setEnabled(true);

	ui.startButton->setEnabled(false);

	this->coordSaver = coordSaver;
	this->sysInfo = sysInfo;
	this->cam = camera;

	logger = Container::getInstance()->getLog();

	config = Container::getInstance()->getConfigHandler();

	net = new NeuralNet(logger);

	lightStabilizer = Container::getInstance()->getLightStabilizer();

	filterHandler = Container::getInstance()->getFilterHandler();

	util = new ImageUtilities();

	if ( !cam->initCamDevice() ){

		logger->closeLogger();

		return -1;

	}


	net->setnetFile(config->getTrackerNetFile());

	if ( !net->startNet()){

		logger->closeLogger();

		return -1;

	}

	filterHandler->setSkinThreshold(lightStabilizer->getSkinThreshold());

	captureCrossState = 0; //Created, not showed.

	filteredstate = 0; //Created, not showed.

	return 0;
}

/*
 * This method finishes the tracker.
 */
void ThesisProject::finishTrack(){

	StopCapturing->setEnabled(false);

	ui.action_Detener_Captura->setEnabled(false);

	timer->stop();

	cam->stopCamDevice();

	net->shutDown();

	coordSaver->finishCoordSaver();

	if (captureCrossState == 1 || captureCrossState == 0) //Created & Showed || !Showed.
		cvDestroyWindow("Estado actual");

	if (filteredstate == 1 || filteredstate == 0) //Created & Showed || !Showed.
		cvDestroyWindow("Filtrada");


	logger->closeLogger();

	Container::getInstance()->wakeAll();

	Container::getInstance()->getThesisStart()->wait();

	Container::getInstance()->setThesisStart(0);

	coordSaver = 0;

	Container::getInstance()->createCamViewerInstance(ui.capturedImage);

	ui.startButton->setEnabled(true);

	initiatedCamera = false;

	if (Container::getInstance()->getStateSupport()){
		ViewState->setEnabled(false);
		QMetaObject::invokeMethod(stateViewer,"close");
	}
	showCaptureCross->setChecked(false);
	showCaptureCross->setEnabled(false);
	showFiltered->setChecked(false);
	showFiltered->setEnabled(false);

}

/*
 * The next Slot captures next frame and process it.
 */

void ThesisProject::captureNextFrame(){

	Container* cont = Container::getInstance();

	currentFrame = cam->retrieveFrame();

	if (cont->getRotateX())
		cvFlip(currentFrame,currentFrame,1);

	if (cont->getRotateY())
		cvFlip(currentFrame,currentFrame,-1);

	filteredImage = filterHandler->runPreFilters(currentFrame);

	if (cont->getStateSupport())
		cont->setFilteredImage(filteredImage);

	//Hand Tracker

	net->run(filteredImage);

	Xcoord = net->getXcoord();

	Ycoord = net->getYcoord();

	filterHandler->runLowPassFilter(Xcoord,Ycoord,XcoordFIR,YcoordFIR);

	util->putMarker(currentFrame,XcoordFIR*4,YcoordFIR*4);

	updateShowCapture();

	updateShowFiletered();


	coordSaver->saveCoords(XcoordFIR,YcoordFIR);

	//Static Gesture Recognition through skin pixel count

	if ( filterHandler->getSkinCount() > filterHandler->getSkinThreshold()){ // Mano Abierta: mas pixeles blancos
		cont->setClosed(false);
	}
	else{
		cont->setClosed(true);
	}

	cvReleaseImage( &filteredImage );
}

/*
 * This method shows or not the window which will show
 * the capturedImage with cross.
 */

void ThesisProject::updateShowCapture(){

	if (showCaptureCross->isChecked()){
		if (captureCrossState == 0){ //!Created & !Showed
			cvNamedWindow("Estado actual", CV_WINDOW_AUTOSIZE);
			cvShowImage("Estado actual", currentFrame );
			captureCrossState = 1;
		}
		else if (captureCrossState == 1){ //Created & Showed
			cvShowImage("Estado actual", currentFrame );
		}
	}
	else {
		cvDestroyWindow("Estado actual");
		captureCrossState = 0; //!Created & !Showed
	}

}

/*
 * This method updates the window which will show
 * the filtered image.
 */

void ThesisProject::updateShowFiletered(){

	if (showFiltered->isChecked()){

		if (filteredstate == 0){ //!Created & !Showed
			cvNamedWindow("Filtrada", CV_WINDOW_AUTOSIZE);
			cvShowImage("Filtrada", filteredImage );
			filteredstate = 1;
		}
		else if (filteredstate == 1){ //Created & Showed
			cvShowImage("Filtrada", filteredImage );
		}
	}
	else {
		cvDestroyWindow("Filtrada");
		filteredstate = 0; //!Created & !Showed
	}

}
/*
 * This method returns the systemInfo instance.
 */

SystemInfo* ThesisProject::getSystemInfo(){
	if (sysInfo==0)
		sysInfo = new SystemInfo(80,60);
	return sysInfo;
}

/*
 * This method returns a new coordSaver instance.
 */

CoordsSaver* ThesisProject::getCoordSaver(){
	if (coordSaver==0)
		coordSaver = new CoordsSaver();
	return coordSaver;
}

/*
 * This method analize if the changed item in asociation List
 * is valid or not.
 */

void ThesisProject::analizeChange(QListWidgetItem* item){
	QString text = item->text();
	QStringList l = text.split(tr(" <-> "));
	QString gid = l.first();
	QString eid = l.last();
	Gesture* g = getGestureModel()->getGesture(new std::string(gid.toStdString()));
	Event* eb = getEventFromModels(&eid);

	if (item->checkState() == Qt::Unchecked){
		Association* ass = GestureEventMapper::getInstance()->getAssociation(g,eb);
		ass->setActivated(false);
		return;
	}


	Event* e = GestureEventMapper::getInstance()->getEvent(g);

	if (e==0){
		Association* ass = GestureEventMapper::getInstance()->getAssociation(g,eb);
		ass->setActivated(true);
		return;
	}

	QString ev = QString(e->getId().c_str());
	QString ef = QString("El gesto que se desea activar, ya posee un Evento activo. El evento activo es: ");
	QString ez = ef + ev + QString(". Para continuar, desactive la asociación mencionada.");


	if (QString::compare(eid,ev)!=0){
    	QMessageBox::information(this, tr("Existe evento asociado al gesto"),ez);
    	item->setCheckState(Qt::Unchecked);
    	return;
	}
}
