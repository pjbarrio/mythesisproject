#include "mainwindow.h"
#include <stdlib.h>
#include <QString>
#include "Init/InitTracker.h"
#include "Utils/SystemInfo.h"
#include <cv.h>
#include <highgui.h>
#include "Init/ThesisStart.h"
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

/*
 * This Method initiates the main Application. Receives the Dialog boxes that will appear during the execution.
 */

ThesisProject::ThesisProject(AddGesture* addGesture,AddEvent* addEvent,AddAsociation* addAsociation,StateViewer* stateViewer,HandDiagnostic* handDiagnostic,QWidget *parent)
    : QMainWindow(parent)
{
	ui.setupUi(this);

	this->addGestureDialog = addGesture;
	this->addEventDialog = addEvent;
	this->addAsociationDialog = addAsociation;
	this->stateViewer = stateViewer;
	this->handDiagnostic = handDiagnostic;
	initVariables();

	createCompleteTrayIcon();


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

	StopCapturing->setEnabled(false);

	trayIconMenu->addAction(StopCapturing);

	connect(StopCapturing, SIGNAL(triggered()), this, SLOT(stopCapture()));

	ViewState = new QAction(tr("Ver estado"), this);

	ViewState->setEnabled(false);

	trayIconMenu->addAction(ViewState);

	connect(ViewState, SIGNAL(triggered()), this, SLOT(ViewCaptureState()));

	trayIconMenu->addSeparator();

	Restore = new QAction(tr("Restaurar"), this);

	Restore->setEnabled(false);

	trayIconMenu->addAction(Restore);

	connect(Restore, SIGNAL(triggered()), this, SLOT(showNormal()));

	trayIconMenu->addSeparator();

	quitAction = new QAction(tr("&Quit"), this);

	connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));


	trayIconMenu->addAction(quitAction);


	trayIcon->setContextMenu(trayIconMenu);

	trayIcon->show();
}

/*
 * This method stops the capture process.
 */

void ThesisProject::stopCapture(){
	//TODO Stop Capture.
}

/*
 * This method shows the state window.
 */

void ThesisProject::ViewCaptureState(){
	//TODO View State tenog que hacer el show del stateviewer
}

/*
 * This method initiates the variables which will be used during the application.
 */

void ThesisProject::initVariables(){
	rotatex = false;
	rotatey = false;

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

		QListWidgetItem *qListItem = new QListWidgetItem(ui.GestosList);
		qListItem->setText(*id);
///		qListItem->setCheckState(Qt::Unchecked);

		std::string* s1 = new std::string(id->toStdString());

		Gesture* g = new Gesture(tx,ty,s1->c_str());

		if (!getGestureModel()->addGesture(g)){
			//TODO Informar que no se pudo cargar
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
///		qListItem->setCheckState(Qt::Unchecked);

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
					getCombinedKeyEventModel()->addEvent(pce);
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
	int ret = addAsociationDialog->exec();

	if (ret==1){
		QList<QString*> gestures = addAsociationDialog->getGestures();
		QList<QString*> events = addAsociationDialog->getEvents();

		GestureEventMapper* gestureEventMapper = GestureEventMapper::getInstance();


		for (int i = 0;i<gestures.size();i++){
			QListWidgetItem *qListItem = new QListWidgetItem(ui.AsociacionList);
			QString q(*gestures.at(i) + " - " + *events.at(i));
			qListItem->setText(q);
			qListItem->setCheckState(Qt::Checked);



			//TODO HAY QUE HACERLO CHE!!!!
		}


	}
}

/*
 * This method removes the selected gesture.
 */

void ThesisProject::removeGesture(){
	QList<QListWidgetItem*> q = ui.GestosList->selectedItems();
	if (q.size()==1){
		delete(q.first());
	}

}

/*
 * This method removes the selected Event.
 */

void ThesisProject::removeEvent(){
	QList<QListWidgetItem*> q = ui.EventosList->selectedItems();
	if (q.size()==1){
		delete(q.first());
	}
}

/*
 * This method removes the selected Asociation.
 */

void ThesisProject::removeAsociation(){
	QList<QListWidgetItem*> q = ui.AsociacionList->selectedItems();
	if (q.size()==1){
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

	Container::getInstance()->finishCamViewer();

	ThesisStart* ts = new ThesisStart(this,this->stateViewer);

	ts->start();

	ts->wait();

	Container::getInstance()->createCamViewerInstance(ui.capturedImage);
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
		dtwAlgorithm = new ItakuraDTWAlgorithm(3,distanceCalculator);
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
