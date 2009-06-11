/**
 * Thread_Tracker.cpp
 *
 *  Created on: 29/03/2009
 *      \author  Pablo
 */


#include "Thread_Tracker.h"

/**
 * This method saves the initializerCreator object which have the main behavior
 * of this thread.
 */

Thread_Tracker::Thread_Tracker(InitializerCreator *initializerCreator):QThread()
{
	this->initializerCreator = initializerCreator;
}

/**
 * This method dereferences the initializerCreator object.
 */

Thread_Tracker::~Thread_Tracker() {
	this->initializerCreator = 0;
}

/**
 * This method invokes the start method of the initializerCreator instance.
 */

void Thread_Tracker::run()
{

	initializerCreator->start();

}



