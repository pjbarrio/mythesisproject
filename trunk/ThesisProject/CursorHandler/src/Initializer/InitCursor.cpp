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
	this->closeclick = closeclick;
	this->openclick = openclick;
	clickperformed = false;
	errorX = Container::getInstance()->getErrorX();
	errorY = Container::getInstance()->getErrorY();
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

void InitCursor::setNewInput(double xdob, double ydob, double t)
{
	int x = (int)xdob;
	int y = (int)ydob;
	bool close = Container::getInstance()->isClosed();

	double first = x-lastx;
	if (first<0)
		first*=(-1);
	double second = y-lasty;
	if (second<0)
		second*=(-1);

	if (first<=errorX && second<=errorY){
		x = lastx;
		y = lasty;
	}

	if (!click){
		if (x!=lastx || y!=lasty)
			cv->setCursorPos((int)x,(int)y,false);
	}
	else if (click){
		if (x==lastx && y==lasty){
			//same positions, verify change state.
			if (close && closeclick || !close && openclick){
				if (!clickperformed){
					cv->setCursorPos((int)x,(int)y,true);
					clickperformed = true;
				}
			}else {
				if (clickperformed){
					cv->setCursorPos((int)x,(int)y,false);
					clickperformed = false;
				}
			}
		} else {
			//different possition, make all the arrangements.
			if (close && closeclick || !close && openclick){
				cv->setCursorPos((int)x,(int)y,true);
				clickperformed = true;
			} else{
				cv->setCursorPos((int)x,(int)y,false);
				clickperformed = false;
			}
		}
	}

	lastx = x;
	lasty = y;
}

