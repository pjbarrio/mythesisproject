/**
 * Event.cpp
 *
 *  Created on: 01/02/2009
 *      \author  Pablo
 */

#include "Event.h"
#include "iostream.h"

/**
 * This method stores the id of the event passed by parameter.
 */

Event::Event(const char* id) {
	cout << "Hello Event\n";
	this->id = id;
}

/**
 * This method dereferences the id variable.
 */

Event::~Event() {
	cout << "Bye Event\n";
	id.clear();
}
