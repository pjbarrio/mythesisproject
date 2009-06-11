/**
 * Gesture.cpp
 *
 *  Created on: 01/02/2009
 *      \author  Pablo
 *
 */

#include "Gesture.h"

/**
 * This method stores the variables passed by parameter. This
 * variables represent the gesture.
 */

Gesture::Gesture(DTWData *tx, DTWData *ty, const char *id)
{
	cout << "Hello Gesture\n";
	this->tx = tx;
	this->ty = ty;
	this->id = id;
}

/**
 * This method dereferences the variables instantiated in the constructor
 * method and clear the id string object.
 */

Gesture::~Gesture() {
	cout << "Bye Gesture\n";

	tx = 0;
	ty = 0;
	id.clear();
}


