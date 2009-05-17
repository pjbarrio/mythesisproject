/*
 * NoGestureDetected.cpp
 *
 *  Created on: 01/02/2009
 *      Author: Pablo
 */

#include "NoGestureDetected.h"

/*
 * This method set its id to "NoGestureDetected".
 */

NoGestureDetected::NoGestureDetected():Gesture(0,0,"NoGestureDetected") {
	cout << "Hello No Gesture Detected\n";
}

NoGestureDetected::~NoGestureDetected() {
	cout << "Bye No Gesture Detected\n";
}
