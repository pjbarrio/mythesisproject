/**
 * NoGestureDetected.h
 *
 *  Created on: 01/02/2009
 *      \author  Pablo
 *
 * This class is used when no Gesture has been recognized. Is associated with
 * doNothingEvent to ensure completeness.
 */

#ifndef NOGESTUREDETECTED_H_
#define NOGESTUREDETECTED_H_

#include "../src/Gesture.h"
#include "C:/MinGW/include/c++/3.4.5/bits/stringfwd.h"
using namespace std;

class NoGestureDetected: public Gesture {
public:
	NoGestureDetected();
	virtual ~NoGestureDetected();

};

#endif /** NOGESTUREDETECTED_H_ */
