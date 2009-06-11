/**
 * TrainingActivationGestureMethod.h
 *
 *  Created on: 19/04/2009
 *      \author  Pablo
 *
 * This class is used to store gestures during trainig stage.
 */

#ifndef TRAININGACTIVATIONGESTUREMETHOD_H_
#define TRAININGACTIVATIONGESTUREMETHOD_H_

#include "../src/ActivationGestureMethod.h"
#include <vector.h>

class TrainingActivationGestureMethod: public ActivationGestureMethod {
public:

	TrainingActivationGestureMethod();

	virtual ~TrainingActivationGestureMethod();

	void setNewInput(double, double, double);

	bool DetectedGestureActivation();

	bool DetectedGestureDeactivation();

	bool DetectedErroneousGestureActivation();

	void GetData(vector<double>&,vector<double>&,vector<double>&);

	int GetDataSize();

	static const double STARTED_ENTRY = 0.0;

	static const double FINISHED_ENTRY = -1.0;

private:

	vector<double>* xData;
	vector<double>* yData;
	vector<double>* tData;

	bool finished;

	bool started;


};

#endif /** TRAININGACTIVATIONGESTUREMETHOD_H_ */
