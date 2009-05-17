#include "addgesture.h"
#include "iostream.h"
#include "../Utils/Container.h"

/*
 * This method sets up the GUI of the addgesture window
 * and saves the instance of NewGesture pointer.
 */

AddGesture::AddGesture(NewGesture* newGesture, QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);

	this->newGest = newGesture;
}

/*
 * This method dereferences the NewGesture's instance.
 */

AddGesture::~AddGesture()
{
	newGest = 0;
}

/*
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

/*
 * This method instercepts the execution event and init variables and
 * widgets.
 */

int AddGesture::exec()
{
	initVariables();
	initWidgets();
	return QDialog::exec();
}

/*
 * This method saves the id written by the user and
 * calls the accept method.
 */

void AddGesture::accept(){
	setId(new QString(ui.idGestureEdit->text()));
	QDialog::accept();
}

/*
 * This method initializes the Id and coords values.
 */

void AddGesture::initVariables(){
	setId(new QString(""));
	setTx(0);
	setTy(0);
}

/*
 * This method clear the edit text which represent the
 * id value..
 */

void AddGesture::initWidgets(){
	ui.idGestureEdit->setText("");
}
