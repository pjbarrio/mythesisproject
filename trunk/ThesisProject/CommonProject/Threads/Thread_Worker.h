/*
 * Thread_Worker.h
 *
 *  Created on: 29/03/2009
 *      Author: Pablo
 *
 * This class extends from QThread and represents the interfae which
 * Consumers will implement.
 */

#ifndef THREAD_WORKER_H_
#define THREAD_WORKER_H_

#include "../InterfaceWorker/Initializer.h"

class Thread_Worker: public QThread {
public:
	Thread_Worker(Initializer*);
	virtual ~Thread_Worker();
	void run();
private:
	Initializer* worker;
};

#endif /* THREAD_WORKER_H_ */
