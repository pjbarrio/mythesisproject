/*
 * GestureModel.h
 *
 *  Created on: 24/01/2009
 *      Author: Pablo
 *
 *  This class is a set of Gestures. In this case the model contains gestures, this is a GestureModel.
 */



#ifndef GESTUREMODEL_H_
#define GESTUREMODEL_H_


#include "Gesture.h"
#include "vector.h"
#include "../Gestures/NoGestureDetected.h"
#include "DTWAlgorithm.h"





class GestureModel {
public:
	GestureModel(DTWAlgorithm*);
	virtual ~GestureModel();
	Gesture* getNextGesture();
	int getGestureModelSize();
	void begin();
	bool hasNext();
	void next();
	bool addGesture(Gesture*);

	/*
	 * This method returns the dtwAlgorithm instance used to determine
	 * if a Gesture is valid to be added.
	 */

	DTWAlgorithm *getDtwAlgorithm() const {return dtwAlgorithm;}
	Gesture* getGesture(std::string*);

private:
	DTWAlgorithm *dtwAlgorithm;
	vector<Gesture*> *gestures;
	vector<Gesture*>::iterator gesturesIterator;
	vector<Gesture*>::iterator getGesturesIterator() const {return gesturesIterator;}
	vector<Gesture*> *getGestures() const {return gestures;}
	void setGesturesIterator(vector<Gesture*>::iterator gesturesIterator){
		this->gesturesIterator = gesturesIterator;}
	NoGestureDetected *noGestureDetectedInstance;
};

#endif /* GESTUREMODEL_H_ */
