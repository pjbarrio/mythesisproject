
/**
 * InitCursor.h
 *
 *  Created on: 29/03/2009
 *      \author  Pablo
 *
 * This class is used to simulate the movement
 * of the mouse with the coords provided by the
 * hand tracker.
 */

#ifndef INITCURSOR_H_
#define INITCURSOR_H_

#include "../cursorVisualizer.h"
#include "../../../CommonProject/InterfaceWorker/Initializer.h"
#include "../../../CommonProject/src/CoordsGetter.h"
#include "../../../Utils/SystemInfo.h"

class InitCursor:public Initializer{
public:
	InitCursor(CoordsGetter*,SystemInfo*,bool, bool, bool);
	virtual ~InitCursor();
	void setNewInput(double,double,double);
	void init();
private:
	SystemInfo* sysInfo;
	cursorVisualizer *cv;
	int lasty;
	int lastx;
	bool click;
	bool closeclick;
	bool openclick;
};

#endif /** INITCURSOR_H_ */
