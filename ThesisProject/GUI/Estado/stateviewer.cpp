#include "stateviewer.h"

/*
 * This method sets up the GUI of tracking state
 * visualization and creates the internal equalizer
 * representation.
 */

StateViewer::StateViewer(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	createArrays();

}

/*
 * This method set the Circular buffers (coords X,Y) used to draw
 * hand movement
 */

void StateViewer::setBufferXY(CircularBuffer* cbx,CircularBuffer* cby){
	this->cbx = cbx;
	this->cby = cby;
	ui.widget_4->setData(this->cbx,this->cby);
}

/*
 * This method deletes the internal equalizer lists.
 */

StateViewer::~StateViewer()
{
	delete(velocityList);
	delete(accelerationList);
}

/*
 * This method creates the Acceleration and Velocity
 * equalizers arrays.
 */

void StateViewer::createArrays(){
	createVelocityArray();
	createAccelerationArray();
}

/*
 * This method creates the velocity Equalizer
 * internal representation.
 */

void StateViewer::createVelocityArray(){
	velocityList = new QList<QLabel*>();
	velocityList->append(ui.vgreendark3);
	velocityList->append(ui.vgreendark2);
	velocityList->append(ui.vgreendark1);
	velocityList->append(ui.vgreen3);
	velocityList->append(ui.vgreen2);
	velocityList->append(ui.vgreen1);
	velocityList->append(ui.vyellowlight3);
	velocityList->append(ui.vyellowlight2);
	velocityList->append(ui.vyellowlight1);
	velocityList->append(ui.vyellow3);
	velocityList->append(ui.vyellow2);
	velocityList->append(ui.vyellow1);
	velocityList->append(ui.vorange3);
	velocityList->append(ui.vorange2);
	velocityList->append(ui.vorange1);
	velocityList->append(ui.vred3);
	velocityList->append(ui.vred2);
	velocityList->append(ui.vred1);
}

/*
 * This method returns the Hand State pixmap.
 */

QLabel* StateViewer::getHandPicture()
{
	return ui.handState;
}

/*
 * This method sets the label which will
 * show the filtered Image
 */

QLabel* StateViewer::getFilteredImage(){
	return ui.processedImage;
}
/*
 * This method creates the acceleration Equalizer
 * internal representation.
 */

void StateViewer::createAccelerationArray(){
	accelerationList = new QList<QLabel*>();
	accelerationList->append(ui.agreendark3);
	accelerationList->append(ui.agreendark2);
	accelerationList->append(ui.agreendark1);
	accelerationList->append(ui.agreen3);
	accelerationList->append(ui.agreen2);
	accelerationList->append(ui.agreen1);
	accelerationList->append(ui.ayellowlight3);
	accelerationList->append(ui.ayellowlight2);
	accelerationList->append(ui.ayellowlight1);
	accelerationList->append(ui.ayellow3);
	accelerationList->append(ui.ayellow2);
	accelerationList->append(ui.ayellow1);
	accelerationList->append(ui.aorange3);
	accelerationList->append(ui.aorange2);
	accelerationList->append(ui.aorange1);
	accelerationList->append(ui.ared3);
	accelerationList->append(ui.ared2);
	accelerationList->append(ui.ared1);
}
