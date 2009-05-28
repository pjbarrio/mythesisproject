/*
 * DynamicGestureRecognitionAlgorithm.cpp
 *
 *  Created on: 30/01/2009
 *      Author: Pablo
 */

#include "DynamicGestureRecognitionAlgorithm.h"
#include "iostream"
#include "../ActivationGestureMethods/AccelerationActivation.h"
#include "../DTWAlgorithms/ItakuraDTWAlgorithm.h"
#include "../DistanceCalculators/EuclideanDistance.h"

/*
 * This method instantiates the variables used to detect gestures and
 * store the variables passed by parameter.
 */

DynamicGestureRecognitionAlgorithm::DynamicGestureRecognitionAlgorithm(GestureModel* gestureModel,
		ActivationGestureMethod* agm, double relaxedRatio,DTWAlgorithm* dtwalgorithm,
		ValuesNormalizator* valuesNormalizator) {
	cout << "Hello Dynamic Gesture Recognition\n";

	this->valuesNormalizator = valuesNormalizator;

	this->agm = agm;

	this->relaxedRatio = relaxedRatio;

	this->dtwalgorithm = dtwalgorithm;

	this ->gestureModel = gestureModel;

	gestureEventMapper = GestureEventMapper::getInstance();

	gr = new GestureRecognizer(getGestureModel());

	tx = new DTWData();

	ty = new DTWData();

	lx = new list<double>;

	ly = new list<double>;

	lt = new list<double>;

	inGesture = false;
}

/*
 * This method deletes the variables creater by the constructor method.
 */

DynamicGestureRecognitionAlgorithm::~DynamicGestureRecognitionAlgorithm() {

	cout << "Bye Dynamic Gesture Recognition\n";

	delete (gr);

	GestureEventMapper::deleteInstance();

	delete (tx);

	delete (ty);

	delete lx;

	delete ly;

	delete lt;

}

/*
 * This is the main method of the recognition process.
 */

void DynamicGestureRecognitionAlgorithm::addNewInput(double x, double y, double t)
{


	double xa,ya,ta;

	lx->push_front(x);

	ly->push_front(y);

	lt->push_front(t);

	while (lx->size() > 0) {



		xa = lx->back();
		lx->pop_back();
		ya = ly->back();
		ly->pop_back();
		ta = lt->back();
		lt->pop_back();



		setActualInput(xa,ya,ta);



		getAgm()->setNewInput(xa,ya,ta);

		if (getAgm()->DetectedGestureActivation() && !getInGesture())
			ActivationDetected();
		else if (getAgm()->DetectedErroneousGestureActivation() && getInGesture())
			ErroneusGestureActivation();
		else if (getAgm()->DetectedGestureDeactivation() && getInGesture())
			DeactivationDetected();
		else
			NoChangeDetected();
		}

}

/*
 * This method is invoked when the AccelerationChangeDetector considers that
 * the gesture has Finished.
 */

void DynamicGestureRecognitionAlgorithm::DeactivationDetected()
{
	cout << "Deactivation        Detected \n ";

	if (getInGesture()){
		setInGesture(false);
	}

	RecognizeMotionDetected();

	cleanBuffers();
}

/*
 * This method call to save the data detected in their respectives buffers.
 */

void DynamicGestureRecognitionAlgorithm::NoChangeDetected()
{
	cout << "NoChDetected \n ";

	storeInput();
}

/*
 * This method Starts when the AccelerationChangeDetector has detected an acceleration
 * in the user movement
 */

void DynamicGestureRecognitionAlgorithm::ActivationDetected()
{
	cout << "Activation Detected \n ";

	cleanBuffers();

	if (!getInGesture()){
		setInGesture(true);
	}

	storeDatafromActivationGestureMethod();
}

/*
 * This method performs the cleanning of the buffers.
 */
void DynamicGestureRecognitionAlgorithm::ErroneusGestureActivation()
{
	cout << "Erroneous        Gesture           Detected \n ";


	double x,y,t;
	getTx()->begin();
	getTy()->begin();
	while (getTx()->hasNext()){

		x = getTx()->getY();
		y = getTy()->getY();
		t = getTx()->getX();
		lx->push_front(x);
		ly->push_front(y);
		lt->push_front(t);
		getTx()->next();
		getTy()->next();

	}

	cleanBuffers();
	setInGesture(false);
}

/*
 * This method reinitialize all the variables used to find a Gesture.
 */

void DynamicGestureRecognitionAlgorithm::nothingImportantHappenning()
{

	setInGesture(false);

	cleanBuffers();

}

/*
 * This method save the values being used by the object in this iteration.
 */

void DynamicGestureRecognitionAlgorithm::setActualInput(double x, double y, double t)
{
	setActualX(x);
	setActualY(y);
	setActualT(t);
}

/*
 * This method clean all buffers used by the class to detect the gesture.
 */
void DynamicGestureRecognitionAlgorithm::cleanBuffers()
{
	getTx()->clean();
	getTy()->clean();
}

/*
 * This method store the X,Y,T values in the buffers.
 */
void DynamicGestureRecognitionAlgorithm::storeInput()
{
	getTx()->addNewXYPair(getActualT(),getActualX());
	getTy()->addNewXYPair(getActualT(),getActualY());
}

/*
 * This method recognize the Gesture that the user has made. If the user movement
 * does not respect any gesture motion, this method does nothing and return.
 */

void DynamicGestureRecognitionAlgorithm::RecognizeMotionDetected()
{
	double remove = getAgm()->GetDataSize() / getRelaxedRatio();

	for (int i=0;i<remove;i++){
		getTx()->removeLastXYPair();
		getTy()->removeLastXYPair();
	}


	Gesture *gesture = getGr()->getRecognizedGesture(valuesNormalizator->normalizeSignal(getTx()),valuesNormalizator->normalizeSignal(getTy()));

	Event *event = getGestureEventMapper()->getEvent(gesture);

	event->execute();
}

/*
 * This method store the Data that has induced to detect the Gesture
 */

void DynamicGestureRecognitionAlgorithm::storeDatafromActivationGestureMethod()
{
	vector<double> x,y,t;
	getAgm()->GetData(x,y,t);
	for (uint i=0;i<x.size();i++){
		getTx()->addNewXYPair(t[i],x[i]);
		getTy()->addNewXYPair(t[i],y[i]);
	}
}












