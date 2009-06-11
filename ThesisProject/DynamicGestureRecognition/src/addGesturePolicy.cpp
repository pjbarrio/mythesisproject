/**
 * addGesturePolicy.cpp
 *
 *  Created on: 24/01/2009
 *      \author  Pablo

 */

#include "addGesturePolicy.h"

/**
 * This constructor method saves the DTWAlgorithm in an instance
 * variable.
 */

addGesturePolicy::addGesturePolicy(DTWAlgorithm* dtwAlgorithm) {
	cout << "Hello addGesturePolicy\n";
	this->dtwAlgorithm = dtwAlgorithm;
}

/**
 * This method dereferences the variable setted in the constructor.
 */

addGesturePolicy::~addGesturePolicy() {
	cout << "Bye addGesturePolicy\n";

	dtwAlgorithm = 0;
}

/**
 * This method returns true if the new Gesture can be added to the model. Otherwise it returns
 * false.
 */

bool addGesturePolicy::canBeAdded(Gesture *gesture, GestureModel *model)
{
	Gesture *auxGesture;
	bool conflictDetected = false;
	model->begin();
	double auxValueX;
	double auxValueY;

	while (model->hasNext() && !conflictDetected){
		auxGesture = model->getNextGesture();
		auxValueX = model->getDtwAlgorithm()->computeDTWValue(auxGesture->getTx(),gesture->getTx());
		if (model->getDtwAlgorithm()->acceptDTWValue(auxValueX)){
			auxValueY = model->getDtwAlgorithm()->computeDTWValue(auxGesture->getTy(),gesture->getTy());
			if (model->getDtwAlgorithm()->acceptDTWValue(auxValueY))
				conflictDetected = true;
		}
		model->next();
	}
	return !conflictDetected;
}

/**
 * This method return a new instance of addGesturePolicy.
 */

addGesturePolicy *addGesturePolicy::getInstance(DTWAlgorithm *dtwAlgorithm)
{
	return new addGesturePolicy(dtwAlgorithm);
}




