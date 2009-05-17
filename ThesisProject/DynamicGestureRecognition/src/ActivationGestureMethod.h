/*
 * ActivationGestureMethod.h
 *
 *  Created on: 24/01/2009
 *      Author: Pablo
 *
 *      This class detects if the pointer has made a faster movement. It maybe a Gesture.
 */

#ifndef ACTIVATIONGESTUREMETHOD_H_
#define ACTIVATIONGESTUREMETHOD_H_

#include <vector.h>

class ActivationGestureMethod {
public:
	ActivationGestureMethod();

	virtual ~ActivationGestureMethod();

	/*
	 * This method save the new input on a buffer. This buffer is used to calculate the acceleration
	 * Change.
	 *
	 */

	virtual void setNewInput(double, double, double) = 0;

	/*
	 * This Method returns true if the method has detected an activation signal
	 * under the algorithm defined circumstances
	 */
	virtual bool DetectedGestureActivation() = 0;

	/*
	 * This Method returns true if the gesture active has finished
	 */


	virtual bool DetectedGestureDeactivation() = 0;

	/*
	 * This method informs that Erroneous Gesture Activation has been Detected
	 */
	virtual bool DetectedErroneousGestureActivation() = 0;

	/*
	 * This method returns the values that induces a Gesture Detected
	 */

	virtual void GetData(vector<double>&,vector<double>&,vector<double>&) = 0;

	/*
	 * This method returns the number of data used to detect the Activation or Deactivation.
	 */

	virtual int GetDataSize() = 0;
};

#endif /* ACCELERATIONCHANGEDETECTOR_H_ */
