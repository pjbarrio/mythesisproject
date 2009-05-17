
/*
 * Initializer.h
 *
 *  Created on: 29/03/2009
 *      Author: Pablo
 *
 * This abstract class provides the interface to work with
 * coords consumers.
 */

#ifndef INITIALIZER_H_
#define INITIALIZER_H_

#include "../src/CoordsGetter.h"

class Initializer {
public:
	Initializer(CoordsGetter*);
	virtual ~Initializer();
	void start();

	/*
	 * This virtual method sets the input coords to the consumer
	 * which will use them
	 */

	virtual void setNewInput(double,double,double) = 0;

	/*
	 * This virtual method initializes the consumer object. Is called when
	 * start() is invoked.
	 */

	virtual void init() = 0;

	/*
	 * This method set the running value. true means that the application
	 * is generating source information. False means that the tracker has finished.
	 */

	void setRunning(bool val){running = val;};

	/*
	 * This method returns the running value.
	 */

	bool isRunning(){return running;};
protected:
	CoordsGetter* coordGetter;
	bool running;

};

#endif /* INITIALIZER_H_ */
