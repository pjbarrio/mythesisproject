/*
 * Thread_Worker.cpp
 *
 *  Created on: 29/03/2009
 *      Author: Pablo
 */

#include "Thread_Worker.h"

/*
 * This constructor method saves the reference of the object which represents
 * consumer behaviour
 */

Thread_Worker::Thread_Worker(Initializer* worker):QThread() {
	this->worker = worker;
}

/*
 * This destructor method dereferences the initializer object.
 */

Thread_Worker::~Thread_Worker() {
	this->worker = 0;
}

/*
 * This method invokes the initializer start method.
 */

void Thread_Worker::run()
{
	worker->start();
}


