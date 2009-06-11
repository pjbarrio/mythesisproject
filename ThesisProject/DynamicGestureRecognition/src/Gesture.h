
/**
 * Gesture.h
 *
 *  Created on: 01/02/2009
 *      \author  Pablo
 *
 *  This Class represent one Gesture in the Gesture Model
 */

#ifndef GESTURE_H_
#define GESTURE_H_

#include "DTWData.h"
#include "C:/MinGW/include/c++/3.4.5/bits/stringfwd.h"

using namespace std;

class Gesture {
public:
	Gesture(DTWData*, DTWData*, const char*);
	virtual ~Gesture();
    /**
     * This method returns the <T,X> component of the gesture
     */

	DTWData *getTx() const {return tx;}

	/**
	 * This method returns the <T,Y> component of the gesture
	 */

	DTWData *getTy() const {return ty;}

	/**
	 * This method returns the Gesture's id.
	 */

    string getId() const {return id;}

private:
	DTWData *tx;
	DTWData *ty;
	string id;
};

#endif /** GESTURE_H_ */
