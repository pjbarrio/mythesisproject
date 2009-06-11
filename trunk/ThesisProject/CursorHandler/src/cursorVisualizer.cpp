/*
 * cursorVisualizer.cpp
 *
 *  Created on: 25/03/2009
 *      Author: Pablo
 */
#include "cursorVisualizer.h"
#include <windows.h>
#include "wtypes.h"
#include "iostream.h"
#include "math.h"

/*
 * This method initializes the variables used to work. These are: resolution,
 * work space and current mouse position.
 */

cursorVisualizer::cursorVisualizer(SystemInfo* sysInfo) {

	this->sysInfo = sysInfo;
	this->sysInfo->getSystemWorkResolution(minhori,minver);
	this->sysInfo->getSystemResolution(horizontal,vertical);
	POINT p;
	GetCursorPos(&p);
	lastx = p.x;
	lasty = p.y;
	clickperformed = false;
}

/*
 * This method desinstantiate all the variables used during
 * running time.
 */

cursorVisualizer::~cursorVisualizer() {
	minhori = 0;
	minver = 0;
	horizontal = 0;
	vertical = 0;
	lastx = 0;
	lasty = 0;
}

/*
 * This Method shows the cursor pointer on the screen.
 */

void cursorVisualizer::setCursorPos(int x, int y)
{
	valx = adapt(x,minhori,horizontal);
	valy = adapt(y,minver,vertical);

	drawSequence(lastx,lasty,valx,valy);

	lastx = valx;
	lasty = valy;
}

/*
 * This method performs a left button click on the last pos registered by
 * the tracker
 */

void cursorVisualizer::click(){
	if (!clickperformed){
		mouse_event(MOUSEEVENTF_LEFTDOWN, lastx, lasty, 0, 0);
		clickperformed = true;
	}
}

/*
 * This method releases de click on the last pos registered by the tracker.
 */

void cursorVisualizer::releaseClick(){
	if (clickperformed){
		mouse_event(MOUSEEVENTF_LEFTUP, lastx, lasty, 0, 0);
		clickperformed = false;
	}
}

/*
 * This method adapt the point toward the screen
 */

int cursorVisualizer::adapt(int pos, int max,int fact)
{
	double norm = (double)pos / (double)max;

	double val = norm * (double)fact;

	int ret = (int)val;

	return ret;

}

/*
 * This method simulates the movement of the mouse pointer
 * through the segment determined by (ix1,iy1) and (ix2,iy2).
 */

void cursorVisualizer::drawSequence(int ix1,int iy1,int ix2,int iy2){
	x1 = ix1;
	x2 = ix2;
	y1 = iy1;
	y2 = iy2;


	if (x1<x2){
		if (y1 < y2){
			pend = ( y2 - y1 ) / ( x2 - x1 );
			desp = y1 - pend * x1;
			while (y1 < y2){
				x1++;
				y1 = pend * x1 + desp;
				Sleep(1);
				SetCursorPos(x1,y1);
			}
		}
		else if (y2 < y1){
			pend = ( y2 - y1 ) / ( x2 - x1 );
			desp = y1 - pend * x1;
			while (y2 < y1){
				x1++;
				y1 = pend * x1 + desp;
				Sleep(1);
				SetCursorPos(x1,y1);
			}
		}
		else{
			while (x1 < x2){
				x1++;
				Sleep(1);
				SetCursorPos(x1,y1);
			}
		}
	}
	else if (x2 < x1){
		if (y1 < y2){
			pend = ( y2 - y1 ) / ( x2 - x1 );
			desp = y1 - pend * x1;
			while (y1 < y2){
				x1--;
				y1 = pend * x1 + desp;
				Sleep(1);
				SetCursorPos(x1,y1);
			}
		}
		else if (y2 < y1){
			pend = ( y2 - y1 ) / ( x2 - x1 );
			desp = y1 - pend * x1;
			while (y2 < y1){
				x1--;
				y1 = pend * x1 + desp;
				Sleep(1);
				SetCursorPos(x1,y1);
			}
		}
		else{
			while (x2 < x1){
				x1--;
				Sleep(1);
				SetCursorPos(x1,y1);
			}
		}
	}
	else if (x1==x2){
		if (y1 < y2){
			while (y1 <= y2){
				y1++;
				Sleep(1);
				SetCursorPos(x1,y1);
			}
		}
		else if (y2 < y1){
			while (y2 < y1){
				y1--;
				Sleep(1);
				SetCursorPos(x1,y1);
			}
		}
		else{
			Sleep(1);
			SetCursorPos(x2,y2);
		}
	}

}
