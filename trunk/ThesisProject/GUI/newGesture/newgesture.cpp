#include "newgesture.h"
#include "iostream.h"
#include <QWaitCondition>
#include <windows.h>
#include "../Utils/Container.h"
#include "../../CommonProject/src/CoordsSaver.h"
#include "../../DynamicGestureRecognition/Initializer/InitTrainer.h"
#include "../../Utils/SystemInfo.h"
#include "../../Init/InitTracker.h"
#include "../../CommonProject/Threads/Thread_Tracker.h"
#include <QFileDialog>
#include <QMessageBox>
#include "list.h"
#include "../../DynamicGestureRecognition/src/ValuesNormalizator.h"

/**
 * This method sets the User interface.
 */

NewGesture::NewGesture(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
}

/**
 * This method dereferences the components of the detected
 * gesture.
 */

NewGesture::~NewGesture()
{
	tx = 0;
	ty = 0;
}

/**
 * This is an override method. Is called when the window is
 * opened.
 */

int NewGesture::exec(){

	initVariables();

	initWidgets();

	this->setFocus();

	return QDialog::exec();
}

/**
 * This method inits the variables used while the window
 * is active.
 */

void NewGesture::initVariables(){
	setTx(0);
	setTy(0);
	hasStarted = false;
}

/**
 * This method sets the window's widget to their first
 * state. (The window has been opened for the first time).
 */

void NewGesture::initWidgets(){
	ui.accept->setEnabled(false);
	ui.viewWidget->setVisible(false);
	ui.captureWidget->setVisible(false);
	ui.visualWidget->setVisible(false);
}

/**
 * This method intercepts the KeyEvents and detects if
 * Space bar has been pressed.
 */

void NewGesture::keyPressEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_Space) {
        if (hasStarted)
        	finishCapturing();
        else
        	startCapturing();

    } else {
        QDialog::keyPressEvent(event);
    }
}

/**
 * This method execute the accept event in the
 * QDialog window.
 */

void NewGesture::accept(){
	if (getTx()==0 && getTy()==0){
		QMessageBox::information(this, tr("No se ha cargado un gesto"),
		  tr("Deberá cargar un gesto si quiere finalizar correctamente, la acción se cancelará. "));
		QDialog::reject();
	}
	else
		QDialog::accept();
}

/**
 * This method starts the gesture capturing process.
 * It is called after the first space bar pressed event.
 */

void NewGesture::startCapturing(){
	hasStarted = true;
	ui.captureWidget->setVisible(true);
	ui.visualWidget->setVisible(false);
	ui.viewWidget->setVisible(false);

	startCamera();
	startProgressBar();
	startCapture();
}

/**
 * This method finished the gesture capturing process.
 * It is called after the second space bar pressed event.
 */

void NewGesture::finishCapturing(){



	Container::getInstance()->getCamViewer()->setSaveVideo(false);

	QList<IplImage*>* video = Container::getInstance()->getVideo();

	saveMovement(video);



	hasStarted = false;
	ui.accept->setEnabled(true);
	ui.viewWidget->setVisible(true);
	ui.captureWidget->setVisible(false);
	ui.visualWidget->setVisible(false);

	Container::getInstance()->deleteVideo();

	Container::getInstance()->finishCamViewer();

}

/**
 * This method saves the video and detects the movement of the hand.
 * At the end the gesture is normalized.
 */
void NewGesture::saveMovement(QList<IplImage*>* video){

	Buffer_PC* buf1 = new Buffer_PC();
	CoordsGetter* cg1 = new CoordsGetter(buf1);
	CoordsSaver* cs = new CoordsSaver();
	cs->addNewBuffer(buf1);
	DTWData* dtwTX = new DTWData();
	DTWData* dtwTY = new DTWData();

	InitTrainer* itrainer = new InitTrainer(cg1,dtwTX,dtwTY);
	Thread_Worker* tw = new Thread_Worker(itrainer);
	tw->start();

	SystemInfo* si = new SystemInfo(80,60);
	cv = new CameraVideo(Container::getInstance()->getLog(),video);
	InitTracker* it = new InitTracker(cs,si,cv);
	Thread_Tracker* tt = new Thread_Tracker(it);

	tt->start();
	tt->wait();
	tw->wait();

	ValuesNormalizator* vn = new ValuesNormalizator(si);

	this->setTx(vn->normalizeSignal(dtwTX));
	this->setTy(vn->normalizeSignal(dtwTY));

	cx = new CircularBuffer(dtwTX->getXYPairCount());
	cy = new CircularBuffer(dtwTY->getXYPairCount());

	generateCircularBuffer(dtwTX,dtwTY);

	ui.visualWidget->setData(cx,cy);

}

/**
 * This method generates the CircularBuffers used to draw the movement
 * in the ImageWidget.
 */

void NewGesture::generateCircularBuffer(DTWData* tx, DTWData* ty){
	tx->begin();
	while (tx->hasNext()){
		cx->addValue(tx->getY());
		tx->next();
	}

	ty->begin();
	while (ty->hasNext()){
		cy->addValue(ty->getY());
		ty->next();
	}
}

/**
 * This method draws the gesture detected and show the
 * corresponding widget.
 */

void NewGesture::viewGesture(){
	ui.visualWidget->paintEvent(0);
	ui.visualWidget->setVisible(true);
}

/**
 * This method starts the capture process and show the
 * captured images on the corresponding label.
 */

void NewGesture::startCamera(){
	Container::getInstance()->createCamViewerInstance(ui.imageLabel);
}


/**
 * This method show the progress bar working during 5 seconds.
 */

void NewGesture::startProgressBar(){


	for(int i = 0; i < 100 ; i++){
		ui.progressBar->setValue(i);
		Sleep(50);
	}


}

/**
 * This method informs to the camViewer that the gesture will
 * be saved.
 */

void NewGesture::startCapture(){
	Container::getInstance()->getCamViewer()->setSaveVideo(true);
}
