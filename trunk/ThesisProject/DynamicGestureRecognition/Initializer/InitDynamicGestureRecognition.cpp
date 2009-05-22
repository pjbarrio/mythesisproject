/*
 * InitDynamicGestureRecognition.cpp
 *
 *  Created on: 29/03/2009
 *      Author: Pablo
 */

#include "InitDynamicGestureRecognition.h"

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
	//TODO IMPLEMENTAR init gesture
}

/*
 * This method add a new Input in the DynamicGestureRecognitionAlgorithm.
 */

void InitDynamicGestureRecognition::setNewInput(double x, double y, double t)
{
	//dgra->addNewInput(x,y,t);
}




