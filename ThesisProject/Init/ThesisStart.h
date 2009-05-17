/*
 * ThesisStart.h
 *
 *  Created on: 02/05/2009
 *      Author: Pablo
 *
 * This threaded class creates the tracker and the consumers
 * configured by the user.
 */

#ifndef THESISSTART_H_
#define THESISSTART_H_

#include <QThread>
#include "../mainwindow.h"
#include "../GUI/Estado/stateviewer.h"

#include "../Utils/SystemInfo.h"
#include "../CommonProject/src/CoordsSaver.h"
#include "../CommonProject/src/Buffer_PC.h"
#include "../CommonProject/src/CoordsGetter.h"
#include "../CursorHandler/src/Initializer/InitCursor.h"
#include "../CommonProject/Threads/Thread_Worker.h"
#include "../DynamicGestureRecognition/Initializer/InitDynamicGestureRecognition.h"
#include "InitVisualizer.h"
#include "InitTracker.h"
#include "../CommonProject/Threads/Thread_Tracker.h"

class ThesisStart: public QThread {
public:
	ThesisStart(ThesisProject*, StateViewer*);
	virtual ~ThesisStart();
	void run();
private:
	ThesisProject* tp;
	StateViewer* sv;
};

#endif /* THESISSTART_H_ */
