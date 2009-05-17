/*
 * GestureModelHandler.h
 *
 *  Created on: 06/02/2009
 *      Author: Pablo
 *
 * This class handle the Gesture Model. It isolate the Model from the Structure used
 * to persist the model.
 */

#ifndef GESTUREMODELHANDLER_H_
#define GESTUREMODELHANDLER_H_

#include "fstream.h"
#include "GestureModel.h"
#include "../Gestures/NoGestureDetected.h"

class GestureModelHandler {
public:
	GestureModelHandler(char*);
	~GestureModelHandler();
	bool fillModel(GestureModel*);
	bool saveModel(GestureModel*,char*);
	/*
	 * This Method returns the NoGestureDetected Instance. This instance is necesary
	 * when the GestureRecognition Process has no detect any gesture.
	 */
	static Gesture* getNoGestureDetectedInstance() {return noGestureDetected;}

private:
	ifstream *gestureFile;
	static NoGestureDetected *noGestureDetected;
};

#endif /* GESTUREMODELHANDLER_H_ */
