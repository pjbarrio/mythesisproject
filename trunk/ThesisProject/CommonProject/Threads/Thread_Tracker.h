/*
 * Thread_Tracker.h
 *
 *  Created on: 29/03/2009
 *      Author: Pablo
 *
 * This class extends from QThread and stablish the interface
 * which the producers whill extend.
 */

#ifndef THREAD_TRACKER_H_
#define THREAD_TRACKER_H_

#include "../src/CoordsSaver.h"
#include "../../Utils/SystemInfo.h"
#include "../InterfaceWorker/InitializerCreator.h"



class Thread_Tracker: public QThread {
public:
	Thread_Tracker(InitializerCreator*);
	virtual ~Thread_Tracker();
	void run();
private:
	InitializerCreator* initializerCreator;
};


#endif /* THREAD_TRACKER_H_ */
