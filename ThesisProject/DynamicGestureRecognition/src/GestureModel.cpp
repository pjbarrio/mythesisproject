/*
 * GestureModel.cpp
 *
 *  Created on: 24/01/2009
 *      Author: Pablo
 */

#include "GestureModel.h"
#include "addGesturePolicy.h"
#include "string.h"

/*
 * This method creates a new vector which will store the Gestures.
 * Besides, it store the DTWAlgorithm object.
 */

GestureModel::GestureModel(DTWAlgorithm *dtwAlgorithm) {
	cout << "Hello Gesture Model\n";
	gestures = new vector<Gesture*>();
	noGestureDetectedInstance = 0;
	this->dtwAlgorithm = dtwAlgorithm;
}

/*
 * This method deletes the vector used internally and dereferences the
 * DTWAlgorithm object.
 */

GestureModel::~GestureModel() {
	cout << "Bye Gesture Model\n";

	delete (gestures);
	dtwAlgorithm = 0;
}




/*
 * This method returns how many series it has got.
 */

int GestureModel::getGestureModelSize()
{
	return getGestures()->size();
}

/*
 * This method returns the Gesture in the actual position
 */

Gesture *GestureModel::getNextGesture()
{
	return *getGesturesIterator();
}

/*
 * This Method initializes the iterator
 */

void GestureModel::begin()
{
	gesturesIterator = getGestures()->begin();
}

/*
 * This Method notifies if it exists elements in the iterator.
 */

bool GestureModel::hasNext()
{
	return (getGesturesIterator() != getGestures()->end());
}

/*
 * This Method advance in the iterator to the next element.
 */

void GestureModel::next()
{
	gesturesIterator++;
}


/*
 * This method adds a Gesture in the model if it can be put in
 */
bool GestureModel::addGesture(Gesture *gesture)
{
	addGesturePolicy *agp = addGesturePolicy::getInstance(this->getDtwAlgorithm());

	if (agp->canBeAdded(gesture,this)){
		getGestures()->push_back(gesture);
	}
	return false;
}

/*
 * This method returns the Gesture corresponding to the id in the parameter
 * list.
 */

Gesture* GestureModel::getGesture(std::string* id){
	this->begin();
	Gesture* ret;
	const char* strid = id->c_str();
	const char* ch;

	while (this->hasNext()){
		ret = this->getNextGesture();
		ch = ret->getId().c_str();
		if (strcmp(strid,ch) == 0)
			return ret;
		this->next();
	}
	return 0;
}

/*
 * this method removes the gesture from the model.
 */

void GestureModel::removeGesture(std::string *id)
{
	Gesture* g = this->getGesture(id);
	if (g!=0)
		getGestures()->erase(getGesturesIterator());
}




















