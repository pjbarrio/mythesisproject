#include "handdiagnostic.h"
#include "../Utils/Container.h"
#include "cv.h"

/**
 * This method sets up the Hand Diagnostic GUI.
 */

HandDiagnostic::HandDiagnostic(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
}

HandDiagnostic::~HandDiagnostic()
{
;
}

/**
 * This method executes the diferents steps of the
 * hand state configuration.
 */

void HandDiagnostic::proceder(){
	if (paso == 0){
		//Mano abierta;

		Container::getInstance()->getCamViewer()->setSaveFrame(true);

		while(Container::getInstance()->getCamViewer()->getSaveFrame());

		IplImage* image = Container::getInstance()->getSavedImage();

		Container::getInstance()->getFilterHandler()->getSkinImage(image);

		countOpen = Container::getInstance()->getFilterHandler()->getSkinCount();

		ui.but->setText(QString("Cargar Mano Cerrada"));

		ui.handState->setPixmap(QPixmap(":/HandState/hand_close.jpg"));

	}
	if (paso == 1){
		//Mano cerrada;

		Container::getInstance()->getCamViewer()->setSaveFrame(true);

		while(Container::getInstance()->getCamViewer()->getSaveFrame());

		IplImage* image = Container::getInstance()->getSavedImage();

		Container::getInstance()->getFilterHandler()->getSkinImage(image);

		countClose = Container::getInstance()->getFilterHandler()->getSkinCount();

		ui.but->setText(QString("Finalizar"));
	}
	if (paso == 2){

		QDialog::accept();

	}
	paso++;
}

/**
 * This method intercepts the activation of the window
 * and initializes the variables and widgets.
 */

int HandDiagnostic::exec(){

	paso = 0;

	ui.but->setText(QString("Cargar Mano abierta"));

	ui.handState->setPixmap(QPixmap(":/HandState/hand_open.jpg"));

	return QDialog::exec();
}
