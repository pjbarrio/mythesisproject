/**
 * ThesisStart.cpp
 *
 *  Created on: 02/05/2009
 *      \author  Pablo
 */

#include "ThesisStart.h"
#include "../GUI/Utils/Container.h"
#include <QMessageBox>

/**
 * This method saves the references to Main Window and
 * State Visualizer.
 */

ThesisStart::ThesisStart(ThesisProject* tp, StateViewer* sv,SystemInfo*si,CoordsSaver*cs):QThread() {
	this->tp = tp;
	this->sv = sv;
	this->cs = cs;
	this->si = si;
}

/**
 * This method dereferences the variables saved in the
 * constructor method.
 */

ThesisStart::~ThesisStart() {
	this->tp = 0;
	this->sv = 0;
}

/**
 * This method executes the tracker and all the consumer process
 * selected by the user.
 */

void ThesisStart::run() {

	Thread_Worker* tw1;

	Thread_Worker* tw2;

	Thread_Worker* tw3;

	Container* cont = Container::getInstance();

	bool showCursor = cont->getViewPointer();

	bool gesture = cont->getGestureSupport();

	bool state = cont->getStateSupport();

	//Cursor
	if (showCursor){

		Buffer_PC* buf1 = new Buffer_PC();

		cs->addNewBuffer(buf1);

		CoordsGetter* cg1 = new CoordsGetter(buf1);

		bool click = cont->getClickSupport();

		bool closeclick = cont->getCloseClick();

		bool openclick = cont->getOpenClick();

		InitCursor* ic = new InitCursor(cg1,si,click,closeclick,openclick);

		tw1 = new Thread_Worker(ic);

		tw1->start();

 	}
	//DynamicGestureRecognition
	if (gesture){

		Buffer_PC* buf2 = new Buffer_PC();

		cs->addNewBuffer(buf2);

		CoordsGetter* cg2 = new CoordsGetter(buf2);

		InitDynamicGestureRecognition* idgr = new InitDynamicGestureRecognition(cg2,si);

		tw2 = new Thread_Worker(idgr);

		tw2->start();

	}
	//Visualizator
	if (state){

		Buffer_PC* buf3 = new Buffer_PC();

		cs->addNewBuffer(buf3);

		CoordsGetter* cg3 = new CoordsGetter(buf3);

		InitVisualizer* iv = new InitVisualizer(cg3,si,tp,sv);

		tw3 = new Thread_Worker(iv);

		tw3->start();

	}
	//Tracker



/**	InitTracker* it = new InitTracker(cs,si,ch);

	Thread_Tracker* tt = new Thread_Tracker(it);

	tt->start();

	tt->wait();*/

	if (showCursor)
		tw1->wait();

	if (gesture)
		tw2->wait();

	if (state)
		tw3->wait();


}
