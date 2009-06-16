/**
 * AddGestureToModelAlgorithm.cpp
 *
 *  Created on: 13/06/2009
 *      \author Pablo
 */

#include "AddGestureToModelAlgorithm.h"
#include "iostream.h"

AddGestureToModelAlgorithm::AddGestureToModelAlgorithm(DistanceCalculator*d):DTWAlgorithm(d) {
	cout << "Hello AddGestureToModelAlgorithm\n";
}

AddGestureToModelAlgorithm::~AddGestureToModelAlgorithm() {
	cout << "Bye AddGestureToModelAlgorithm\n";
}

/**
 * This method returns a escape value.
 */

double AddGestureToModelAlgorithm::computeDTWValue(DTWData *dtw1, DTWData *dtw2)
{
	return 0.0;
}

/**
 * This method returns true. We need this
 */

bool AddGestureToModelAlgorithm::acceptDTWValue(double value)
{
	return true;
}




