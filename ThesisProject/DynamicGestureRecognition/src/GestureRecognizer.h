
/*
 * GestureRecognizer.h
 *
 *  Created on: 01/02/2009
 *      Author: Pablo
 *
 *	This Class is the responsible of return the Gesture Detected.
 */

#ifndef GESTURERECOGNIZER_H_
#define GESTURERECOGNIZER_H_

#include "DTWData.h"
#include "Gesture.h"
#include "DTWAlgorithm.h"
#include "GestureModel.h"

class GestureRecognizer {
public:
	GestureRecognizer(GestureModel*);
	virtual ~GestureRecognizer();
	Gesture *getRecognizedGesture(DTWData*,DTWData*);


private:
	DTWAlgorithm *dtwAlgorithm;
	GestureModel *gestureModel;
	DTWAlgorithm *getDtwAlgorithm() const {return dtwAlgorithm;}
	GestureModel *getGestureModel() const {return gestureModel;}

};

#endif /* GESTURERECOGNIZER_H_ */
