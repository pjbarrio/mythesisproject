



/**
 * cursorVisualizer.h
 *
 *  Created on: 25/03/2009
 *      \author  Pablo
 *
 *  This Class Shows the mouse Cursor on the screen
 */

#ifndef CURSORVISUALIZER_H_
#define CURSORVISUALIZER_H_

#include "../../Utils/SystemInfo.h"

class cursorVisualizer {
public:
	cursorVisualizer(SystemInfo*);
	virtual ~cursorVisualizer();
	void setCursorPos(int,int,bool);
	void click();
	void releaseClick();

private:
	int horizontal,vertical;
	int minhori,minver;
	SystemInfo* sysInfo;
	int lastx;
	int lasty;
	int valx;
	int valy;
	int incx;
	int incy;
	int adapt(int,int,int);
	void drawSequence(int,int,int,int,bool);
	double pend;
	double desp;
	double x1,x2,y1,y2;
	bool clickperformed;
	int sleep;
};

#endif /** CURSORVISUALIZER_H_ */
