/*
 * InitCursor.cpp
 *
 *  Created on: 29/03/2009
 *      Author: Pablo
 */

#include "InitCursor.h"
#include "iostream.h"
#include "math.h"

/*
 * This method set the position of the mouse.
 */

InitCursor::InitCursor(CoordsGetter* coordGetter,SystemInfo* sysInfo):Initializer(coordGetter) {

	this->sysInfo = sysInfo;

	lastx = 0;
	lasty = 0;
}

/*
 * This method initializes the variables used to simulate the movent of the mouse
 */

InitCursor::~InitCursor() {
	this->sysInfo = 0;
}

/*
 * This method creates a cursorVisualizer object with the systemInfo object
 * passed by parameter in the constructor method.
 */

void InitCursor::init()
{
	cv = new cursorVisualizer(sysInfo);
}

/*
 * this method detects if the input is valid and call the
 * cursorVisualizator object to draw the mouse pointer position.
 */

void InitCursor::setNewInput(double x, double y, double t)
{

	if (abs(x-lastx)<=2 && abs(y-lasty)<=2){
		x = lastx;
		y = lasty;
	}
	cv->setCursorPos((int)x,(int)y);

	lastx = x;
	lasty = y;
}

