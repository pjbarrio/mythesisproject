/*
 * TrainingActivationGestureMethod.cpp
 *
 *  Created on: 19/04/2009
 *      Author: Pablo
 */

#include "TrainingActivationGestureMethod.h"

/*
 * this method creates the vectors used to store different coords.
 */

TrainingActivationGestureMethod::TrainingActivationGestureMethod() {

	xData = new vector<double>;
	yData = new vector<double>;
	tData = new vector<double>;

	finished = false;

	started = false;
}

/*
 * This method clear the vectores which are containing coords.
 */

TrainingActivationGestureMethod::~TrainingActivationGestureMethod() {
	xData->clear();
	yData->clear();
	tData->clear();
}

/*
 * This method stores the coords in their respectives vectors.
 */

void TrainingActivationGestureMethod::setNewInput(double x, double y, double t)
{
	if (t == TrainingActivationGestureMethod::STARTED_ENTRY){
		started = true;
		finished = false;
		xData->clear();
		yData->clear();
		tData->clear();
	}

	if (t != TrainingActivationGestureMethod::FINISHED_ENTRY){
		started = false;
		finished = false;
		xData->push_back(x);
		yData->push_back(y);
		tData->push_back(t);
	}
	else{
		finished = true;
		started = false;
	}



}

/*
 * This method returns if the storing process has been initiated.
 */

bool TrainingActivationGestureMethod::DetectedGestureActivation()
{
	return started;
}

/*
 * This method returns if the storing process has finished.
 */

bool TrainingActivationGestureMethod::DetectedGestureDeactivation()
{
	return finished;
}

/*
 * This method always returns false, because this class is used to store
 * coords and times.
 */

bool TrainingActivationGestureMethod::DetectedErroneousGestureActivation()
{
	return false;
}

/*
 * This method fill the variables passed by parameter with the content of the vectors used
 * to store coords internally.
 */

void TrainingActivationGestureMethod::GetData(vector<double>& x,vector<double>& y,vector<double>& t)
{
	int size = xData->size();

	x.resize(size);
	y.resize(size);
	t.resize(size);

	for(int i = 0;i<size;i++){
		x[i]=xData->at(i);
		y[i]=yData->at(i);
		t[i]=tData->at(i);
	}

}

int TrainingActivationGestureMethod::GetDataSize()
{
	return 0;
}










