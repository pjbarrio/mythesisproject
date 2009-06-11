/**
 * Initializer.cpp
 *
 *  Created on: 29/03/2009
 *      \author  Pablo
 */

#include "Initializer.h"

/**
 * This method saves the coordGetter which will be used to
 * retrieve the coords obtained by the tracker.
 */

Initializer::Initializer(CoordsGetter* coordGetter) {
	this->coordGetter = coordGetter;
	running = true;
}

/**
 * This destructor method dereferences the CoordGetter instance.
 */

Initializer::~Initializer() {
	this->coordGetter = 0;
}

/**
 * This method calls init() method and start the loop until
 * running is set to false.
 */

void Initializer::start()
{
	init();
	double x,y,t;
	while (isRunning()){
		coordGetter->getNextCoords(x,y,t);
		if (x==-1 && y==-1)
			setRunning(false);
		else
			setNewInput(x,y,t);
	}

}

