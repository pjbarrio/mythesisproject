#include "addgesture.h"
#include "iostream.h"
#include <QMessageBox>
#include "../Utils/Container.h"

/**
 * This method sets up the GUI of the addgesture window
 * and saves the instance of NewGesture pointer.
 */

AddGesture::AddGesture(NewGesture* newGesture, QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);

	this->newGest = newGesture;
	this->tx = 0;
	this->ty = 0;
}

/**
 * This method dereferences the NewGesture's instance.
 */

AddGesture::~AddGesture()
{
	newGest = 0;

}

/**
 * This method show NewGesture window and work with
 * the results unless the user has cancelled the
 * NewGesture's operation.
 */

void AddGesture::newGesture(){

	Container* cont = Container::getInstance();
	cont->finishCamViewer();

	int ret = newGest->exec();

	if (ret==1){
		setTx(newGest->getTx());
		setTy(newGest->getTy());
	}

}

/**
 * This method instercepts the execution event and init variables and
 * widgets.
 */

int AddGesture::exec()
{
	initVariables();
	initWidgets();
	return QDialog::exec();
}

/**
 * This method saves the id written by the user and
 * calls the accept method.
 */

void AddGesture::accept(){
	setId(new QString(ui.idGestureEdit->text()));

	if (getTx()==0 && getTy()==0){
		QMessageBox::information(this, tr("No se ha cargado un gesto"),
		tr("Deberá cargar un gesto para finalizar."));
		return;
	}
	if (QString::compare(*getId(),tr(""))==0){
		QMessageBox::information(this, tr("No se ha identificado el gesto"),
		tr("Deberá introducir un nombre de gesto para continuar."));
		return;
	}

	QDialog::accept();
}

/**
 * This method initializes the Id and coords values.
 */

void AddGesture::initVariables(){
	setId(new QString(""));
	setTx(0);
	setTy(0);
}

/**
 * This method clear the edit text which represent the
 * id value..
 */

void AddGesture::initWidgets(){
	ui.idGestureEdit->setText("");
}
