/**
 * addGesturePolicy.h
 *
 *  Created on: 24/01/2009
 *      \author  Pablo
 *
 *  This Class has the responsability of analyze if a new gesture can be saved. It depends on
 *  the policy you use.
 *
 */



#ifndef ADDGESTUREPOLICY_H_
#define ADDGESTUREPOLICY_H_

#include "GestureModel.h"
#include "DTWAlgorithm.h"
#include "Gesture.h"


class addGesturePolicy {
public:
	addGesturePolicy(DTWAlgorithm*);
	virtual ~addGesturePolicy();
	bool canBeAdded(Gesture*,GestureModel*);
	static addGesturePolicy *getInstance(DTWAlgorithm*);


private:
	DTWAlgorithm *dtwAlgorithm;
	DTWAlgorithm *getDtwAlgorithm() const {return dtwAlgorithm;}
};

#endif /** ADDGESTUREPOLICY_H_ */
