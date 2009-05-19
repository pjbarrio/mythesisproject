/*
 * InitVisualizer.cpp
 *
 *  Created on: 02/05/2009
 *      Author: Pablo
 */

#include "InitVisualizer.h"
#include "string.h"
#include <iostream>
#include <sstream>
#include "../GUI/Utils/Container.h"

/*
 * This method sets the values used by the state
 * visualizator.
 */

InitVisualizer::InitVisualizer(CoordsGetter* cg, SystemInfo* si,ThesisProject* tp, StateViewer* sv):Initializer(cg) {
	systemInfo = si;
	this->tp = tp;
	this->sv = sv;
	firstXY = true;
	firstVelocity = true;
}

/*
 * This method dereferences the variables set in the constructor method.
 */

InitVisualizer::~InitVisualizer() {
	systemInfo = 0;
	this->tp = 0;
	this->sv = 0;
	firstXY = false;
	firstVelocity = false;
}

/*
 * This method initializes the variables used to draw the
 * tracking state.
 */

void InitVisualizer::init()
{
	distanceCalculator = new EuclideanDistance();
	open_Hand = new QPixmap("hand_open.jpg");
	close_Hand = new QPixmap("hand_close.jpg");
	cb1 = new CircularBuffer(DRAW_SIZE);
	cb2 = new CircularBuffer(DRAW_SIZE);
	sv->setBufferXY(cb1,cb2);
}

/*
 * This method updates the widgets state to show the movement of the
 * user's hand.
 */

void InitVisualizer::setNewInput(double x, double y, double t)
{
//	QPixmap* image = getFilteredImage();

//	bool closed = getIsClosed();

//	double velocity = getVelocity(x,y,t);

//	double acc = getAcceleration(velocity,t);

//	updateVelocityDrawer(velocity);

//	updateAccelerationDrawer(acc);

//	drawPoints(x,y);

	writeCoords(x,y);

//	drawHand(closed);

//	drawFilteredImage(image);

	lastX = x;
	lastY = y;
	lastT = t;
//	lastVelocity = velocity;

}

/*
 * This method paints the filtered image on the window
 */
void InitVisualizer::drawFilteredImage(QPixmap* image){
	sv->setFilteredImage(image);
}

/*
 * This method returns the filtered image saved by the tracking process.
 */

QPixmap* InitVisualizer::getFilteredImage(){
	return Container::getInstance()->getFilteredImage();
}

/*
 * This method returns if the hand is closed.
 */

bool InitVisualizer::getIsClosed(){
	return Container::getInstance()->isClosed();
}

/*
 * This method returns the velocity detected knowing the last values
 * and the new ones in the parameter list.
 */

double InitVisualizer::getVelocity(double x,double y,double t){
	double vel;
	if (!firstXY){
		vel = distanceCalculator->calculateDistance(x,y,lastX,lastY);
		vel /= (t-lastT);
	} else {
		vel = NO_VELOCITY_DETECTED;
		firstXY = false;
	}
	return vel;
}

/*
 * This method returns the acceleration detected knowing the last values
 * and the new ones in the parameter list.
 */

double InitVisualizer::getAcceleration(double velocity,double t){
	double acc;
	if (!firstVelocity){
		acc = (velocity-lastVelocity)/(t-lastT);
	}else{
		if (velocity==NO_VELOCITY_DETECTED){
			acc = NO_ACCELERATION_DETECTED;
		}
		else {
			acc = NO_ACCELERATION_DETECTED;
			firstVelocity = false;
		}
	}

	return acc;
}

/*
 * This method add the new <X,Y> to the movement graph.
 */

void InitVisualizer::drawPoints(double x,double y){
	cb1->addValue(x);
	cb2->addValue(y);
	sv->getPaintMovement()->paintEvent(0);
}

/*
 * This method updates the velocity equalizer widget.
 */

void InitVisualizer::updateVelocityDrawer(double velocity){
	if (velocity != NO_VELOCITY_DETECTED){
		double limite = (velocity * 18.0) / MAX_VELOCITY;
		int i = 0;
		for (i = 0; i < 18 && i < limite;i++){
			sv->getVelocityList()->at(i)->setEnabled(true);
		}
		for (; i < 18 ; i++){
			sv->getVelocityList()->at(i)->setEnabled(false);
		}
	}

}

/*
 * This method updates the acceleration equalizer widget.
 */

void InitVisualizer::updateAccelerationDrawer(double acceleration){
	if (acceleration != NO_ACCELERATION_DETECTED){
		double limite = (acceleration * 18.0) / MAX_ACCELERATION;
		int i = 0;
		for (i = 0; i < 18 && i < limite;i++){
			sv->getAccelerationList()->at(i)->setEnabled(true);
		}
		for (; i < 18 ; i++){
			sv->getAccelerationList()->at(i)->setEnabled(false);
		}
	}
}

/*
 * This method show the coords detected.
 */

void InitVisualizer::writeCoords(double x,double y){

	std::string sx;

	// convert double x to string sx

	 {std::ostringstream ss;
		ss << x;
		sx = ss.str();}


	std::string sy;

	// convert double y to string sy

	{ std::ostringstream ss;
		ss << y;
		sy = ss.str();
	}


	sv->getCoordXLabel()->setText(QString(sx.c_str()));

	sv->getCoordYLabel()->setText(QString(sy.c_str()));
}

/*
 * This method verify if the hand is closed or opened and
 * show the right picture (open or close hand).
 */

void InitVisualizer::drawHand(bool closed){
	if (closed)
		drawClosed();
	else
		drawOpen();
}

/*
 * This method shows a picture corresponding to an open hand.
 */

void InitVisualizer::drawOpen(){
	sv->setHandPicture(open_Hand);
}

/*
 * This method shows a picture corresponding to a closed hand.
 */

void InitVisualizer::drawClosed(){
	sv->setHandPicture(close_Hand);
}
