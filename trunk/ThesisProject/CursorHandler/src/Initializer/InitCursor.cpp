/**
 * InitCursor.cpp
 *
 *  Created on: 29/03/2009
 *      \author  Pablo
 */

#include "InitCursor.h"
#include "iostream.h"
#include "math.h"
#include "../../../GUI/Utils/Container.h"

/**
 * This method set the position of the mouse.
 */

InitCursor::InitCursor(CoordsGetter* coordGetter,SystemInfo* sysInfo,bool click, bool closeclick, bool openclick):Initializer(coordGetter) {

	this->sysInfo = sysInfo;

	lastx = 0;
	lasty = 0;
	this->click = click;
	this->closeclick = click;
	this->openclick = openclick;
}

/**
 * This method initializes the variables used to simulate the movent of the mouse
 */

InitCursor::~InitCursor() {
	this->sysInfo = 0;
}

/**
 * This method creates a cursorVisualizer object with the systemInfo object
 * passed by parameter in the constructor method.
 */

void InitCursor::init()
{
	cv = new cursorVisualizer(sysInfo);

}

/**
 * this method detects if the input is valid and call the
 * cursorVisualizator object to draw the mouse pointer position.
 */

void InitCursor::setNewInput(double x, double y, double t)
{
	bool close = Container::getInstance()->isClosed();
	double first = x-lastx;
	if (first<0)
		first*=(-1);
	double second = y-lasty;
	if (second<0)
		second*=(-1);

	if (first<=3 && second<=3){
		x = lastx;
		y = lasty;
	}
	else{
		if (!click)
			cv->setCursorPos((int)x,(int)y,false);
		else if (click){
			if (close && closeclick){
				cv->setCursorPos((int)x,(int)y,true);
			} else if (!close && openclick){
				cv->setCursorPos((int)x,(int)y,true);
			} else {
				cv->setCursorPos((int)x,(int)y,false);
			}
		}
	}
	lastx = x;
	lasty = y;
}

