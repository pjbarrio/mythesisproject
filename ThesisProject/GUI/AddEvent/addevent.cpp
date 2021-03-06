#include "addevent.h"
#include <QFileDialog>
#include <QMessageBox>
#include "iostream.h"

/**
 * This method sets up the GUI of Add Event Dialog window.
 */

AddEvent::AddEvent(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
}

AddEvent::~AddEvent()
{
;
}

/**
 * This method opens a FileDialog event and saves the file
 * selected by the user.
 */

void AddEvent::openExecutableFile(){

	QString filter;

	QStringList files;
	QFileDialog dialog(this, tr("Abrir archivo ejecutable o archivo com�n"));
	dialog.setDirectory("C:/");
	dialog.setFileMode(QFileDialog::ExistingFile);
	dialog.setNameFilter(tr("Archivos ejecutables (*.exe *.com *.bat);;Otros Archivos (*.*)"));

	if (dialog.exec()){
		file = dialog.selectedFiles().first();
		filter = dialog.selectedNameFilter();
	}

	if (QString::compare(filter,QString("Archivos ejecutables (*.exe *.com *.bat)")) == 0){
		setIsExe(true);
		ui.argCheck->setEnabled(true);
	}
	if (QString::compare(filter,QString("Otros Archivos (*.*)")) == 0){
		setIsOther(true);
		ui.argCheck->setEnabled(false);
	}
	ui.appEdit->setText(file);
}

/**
 * This method intercepts the execution event and initializes
 * variables and Widgets.
 */

int AddEvent::exec(){

	initVariables();

	initWidgets();

	return QDialog::exec();
}

/**
 * This method initializes the widgets used to add a new event.
 */

void AddEvent::initWidgets(){
	ui.idEvent->setText("");
	ui.teclaOption->setChecked(false);
	ui.appOption->setChecked(false);
	ui.groupBox_2->setEnabled(false);
	ui.groupBox_3->setEnabled(false);
	ui.appEdit->setText("");
	ui.argCheck->setChecked(false);
	ui.argCheck->setEnabled(false);
	ui.argsEdit->setText("");
}

/**
 * This method initializes the variables which will store
 * the widget values.
 */

void AddEvent::initVariables(){

	setId(&QString(""));
	setIsApp(false);
	setIsKey(false);
	setKey(&QString(""));
	setApp(&QString(""));
	setHasArgs(false);
	setArgs(&QString(""));
	setIsExe(false);
	setIsOther(false);
}

/**
 * This method saves the widget values and returns successfully.
 */

void AddEvent::accept(){

    setId(new QString(ui.idEvent->text()));

    setIsApp(ui.appOption->isChecked());

    setIsKey(ui.teclaOption->isChecked());

    setKey(new QString(ui.comboBox->currentText()));

    setApp(new QString(ui.appEdit->text()));

    setHasArgs(ui.argCheck->isChecked());

    setArgs(new QString(ui.argsEdit->text()));

    if (QString::compare(*getId(),tr(""))==0){
    	QMessageBox::information(this, tr("Faltan setear datos"),
		  tr("No se ha introducido un nombre de evento. "
			 "Para continuar, introduzca un nombre al evento."));
    	return;
    }
    if (!getIsKey() && !getIsApp()){
    	QMessageBox::information(this, tr("Faltan setear datos"),
		  tr("No se ha seleccionado tipo de evento. "
			 "Para continuar, elija un tipo de evento desde las opciones."));
    	return;
    }
    if (getIsApp() && QString::compare(*getApp(),tr(""))==0){
    	QMessageBox::information(this, tr("Faltan setear datos"),
		  tr("No se ha introducido nombre de aplicaci�n. "
			 "Para continuar, introduzca/seleccione la aplicaci�n a ejecutar."));
		return;
    }

    QDialog::accept();
}
