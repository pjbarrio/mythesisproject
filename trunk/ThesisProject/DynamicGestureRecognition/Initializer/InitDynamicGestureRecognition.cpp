/*
 * InitDynamicGestureRecognition.cpp
 *
 *  Created on: 29/03/2009
 *      Author: Pablo
 */

#include "InitDynamicGestureRecognition.h"
#include "../../GUI/Utils/Container.h"
#include "../src/ActivationGestureMethod.h"
#include "../ActivationGestureMethods/AccelerationActivation.h"

/*
 * This method saves the SystemInfo object.
 */

InitDynamicGestureRecognition::InitDynamicGestureRecognition(CoordsGetter* coordGetter,SystemInfo* sysInfo):Initializer(coordGetter) {

	this->sysInfo = sysInfo;

}

/*
 * This Method dereferences the sysInfo variable.
 */

InitDynamicGestureRecognition::~InitDynamicGestureRecognition() {
	sysInfo = 0;
}

/*
 * This method initialize the DynamicGestureRecognitionAlgorithm
 * which will detect the gestures made by the user.
 */

void InitDynamicGestureRecognition::init()
{
	Container* cont = Container::getInstance();

	int bufferSize = cont->getBufferSize();//8; //size of the buffer
	int walkedPixels = cont->getWalkedPixels();//100; //number of pixels to detect a trajectory
	double distanceThreshold = cont->getDistanceThreshold();//0.8; //minimun acceptance rate of the walked pixels
	double nonVaryingAccelerationRate = cont->getNonVaryingAccelerationRate();//7000; //acceleration rate allowed
	int minimumPointsCount = cont->getMinimumPointsCount();//15; //to inform that a gesture is valid.
	int relaxedCount = cont->getRelaxedCount();//5; //Values that are relaxed to detect the gesture
	double accelerationThreshold = cont->getAccelerationThreshold();//20300;
	double desaccelerationThreshold = cont->getDesaccelerationThreshold();
	double maxGestureTime = cont->getMaxGestureTime();//2.0;
	DistanceCalculator* distanceCalculatorAGM = cont->getDistanceCalculatorAGM();//new EuclideanDistance();
	ActivationGestureMethod *agm = new AccelerationActivation(bufferSize, walkedPixels, distanceThreshold,
			nonVaryingAccelerationRate, minimumPointsCount, relaxedCount, accelerationThreshold, desaccelerationThreshold,
			maxGestureTime, distanceCalculatorAGM);

	DTWAlgorithm *dTWAlgorithm = cont->getDTWAlgorithm();//new ItakuraDTWAlgorithm(3.0,dcDTW);
	GestureModel *gestureModel = new GestureModel(dTWAlgorithm);
	double relaxedRatio = cont->getRelaxedRatio();//=3.0;
	ValuesNormalizator* valuesNormalizator = cont->getValuesNormalizator();
	dgra = new DynamicGestureRecognitionAlgorithm(gestureModel,agm,relaxedRatio,dTWAlgorithm,valuesNormalizator);

}

/*
 * This method add a new Input in the DynamicGestureRecognitionAlgorithm.
 */

void InitDynamicGestureRecognition::setNewInput(double x, double y, double t)
{
	dgra->addNewInput(x,y,t);
}




