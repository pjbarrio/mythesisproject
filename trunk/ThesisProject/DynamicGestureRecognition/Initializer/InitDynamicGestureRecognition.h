/*
 * InitDynamicGestureRecognition.h
 *
 *  Created on: 29/03/2009
 *      Author: Pablo
 *
 * This class implements Initializer and manipulates the
 * DynamicGestureRecognitionAlgorithm used to detect gestures
 * during the execution time.
 */

#ifndef INITDYNAMICGESTURERECOGNITION_H_
#define INITDYNAMICGESTURERECOGNITION_H_

#include "../../CommonProject/InterfaceWorker/Initializer.h"
#include "../../CommonProject/src/CoordsGetter.h"
#include "../../Utils/SystemInfo.h"
#include "../src/DynamicGestureRecognitionAlgorithm.h"

class InitDynamicGestureRecognition: public Initializer{
public:
	InitDynamicGestureRecognition(CoordsGetter*,SystemInfo*);
	virtual ~InitDynamicGestureRecognition();
	void setNewInput(double,double,double);
	void init();
private:
	SystemInfo* sysInfo;
	DynamicGestureRecognitionAlgorithm *dgra;

};

#endif /* INITDYNAMICGESTURERECOGNITION_H_ */
