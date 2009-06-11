/**
 * InitializerCreator.h
 *
 *  Created on: 31/03/2009
 *      \author  Pablo
 *
 * This interface class is used to initialize the producer objects.
 * The main producer class is InitTracker
 */

#ifndef INITIALIZERCREATOR_H_
#define INITIALIZERCREATOR_H_

class InitializerCreator {
public:
	InitializerCreator();
	virtual ~InitializerCreator();

	/**
	 * This method is invoked by the current thread to start the capturing
	 * process.
	 */

	virtual int start() = 0;
};

#endif /** INITIALIZERCREATOR_H_ */
