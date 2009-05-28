/*
 * AccelerationActivation.cpp
 *
 *  Created on: 05/02/2009
 *      Author: Pablo
 */

#include "AccelerationActivation.h"
#include "../DistanceCalculators/EuclideanDistance.h"
#include <vector.h>

/*
 * This constructor method initializes all the variables used to detect acceleration
 * in the movement of the hand.
 */

AccelerationActivation::AccelerationActivation(int size,int pixelsToTrajectory,double distanceThreshold,
		double NonVaryingAccelerationRate,int MinNumberOfPoints,int i_threshold,double acc_threshold,double maxTimeGesture,
		DistanceCalculator* distanceCalculator){
	cout << "Hello Acceleration Activation\n";

	this->xValues = new CircularBuffer(size);
	this->yValues = new CircularBuffer(size);
	this->tValues = new CircularBuffer(size);
	this->velocity = new CircularBuffer(size);
	this->acceleration = new CircularBuffer(size);
	this->pixelsToTrajectory = pixelsToTrajectory;
	this->number_of_points = 0;
	this->d_threshold = distanceThreshold; //rate at distance
	this->i_threshold = i_threshold;//how many values use to inform Acceleration
	this->non_varying_acc = NonVaryingAccelerationRate; //value that indicates the range of non varying acceleration
	this->negative_non_varying_acc = (-1)*NonVaryingAccelerationRate; //value that indicates the range of non varying slowdown
	this->min_number_of_points = MinNumberOfPoints;
	this->maxTimeGesture = maxTimeGesture;
	this->distanceCalculator = distanceCalculator;
	this->acc_threshold = acc_threshold; //pixels / sec2 acceleration that have to accept.
}

/*
 * This destructor method deletes the variables and desintantiates the other
 * values setted in the constructor or during the execution.
 */

AccelerationActivation::~AccelerationActivation()
{
	cout << "Bye Acceleration Activation\n";

	delete(xValues);
	delete(yValues);
	delete(tValues);
	delete(velocity);
	delete (acceleration);
	pixelsToTrajectory = 0;
	number_of_points = 0;
	d_threshold = 0;
	i_threshold = 0;
	non_varying_acc = 0;
	negative_non_varying_acc = 0;
	min_number_of_points = 0;
	maxTimeGesture = 0;
	distanceCalculator = 0;
	acc_threshold = 0;

}

/*
 * This method sets a new input value and update all the variables used to detect
 * acceleration.
 */

void AccelerationActivation::setNewInput(double x, double y, double t)
{
	getXValues()->addValue(x);
	getYValues()->addValue(y);
	getTValues()->addValue(t);
	int size = getXValues()->size();
	if (size>1){
		double xant = getXValues()->at(size-2);
		double yant = getYValues()->at(size-2);
		double tant = getTValues()->at(size-2);

		double dist = getDistance(x,y,xant,yant);
		double velocity = dist / (t-tant);
		getVelocity()->addValue(velocity);

		if (size==2)
			getAcceleration()->addValue(0);
		if (size>2){
			double vant = getVelocity()->at(getVelocity()->size() - 2);

			getAcceleration()->addValue((velocity-vant)/(t-tant));


		}
	}
	else if (size==1){
		getVelocity()->addValue(0);
		getAcceleration()->addValue(0);
	}
	setNumber_of_points(getNumber_of_points()+1);
}

/*
 * This method is invoked to detect if an acceleration has been produced
 * by the hand movement.
 */

bool AccelerationActivation::DetectedGestureActivation()
{
	bool td = trajectoryDetected();

	bool ad = AccelerationDetected();

	return (td && ad);
}


/*
 * This method is invoked to detect if the hand has produced a deactivation
 * movement.
 */


bool AccelerationActivation::DetectedGestureDeactivation()
{
	bool sd = SlowDownDetected();

	bool min_p = getNumber_of_points() >= min_number_of_points;

	return  sd && min_p;
}

/*
 * This method detects if the user is following a valid trajectory to provoke a gesture
 */

bool AccelerationActivation::trajectoryDetected()
{
	int i = getXValues()->size() - 1;

	double accumulatedDistance = 0;

	bool possibleTrajectory = false;
	if (i>=0) {
		for (i;i>0 && !possibleTrajectory;i--){
			accumulatedDistance += getDistance(getXValues()->at(i),getYValues()->at(i),getXValues()->at(i-1),getYValues()->at(i-1));
			possibleTrajectory = PossibleTrajectoryDetected(accumulatedDistance,i-1,getXValues()->size()-1);
		}
	}


	return possibleTrajectory;
}

/*
 * This method returns if an erroneous gesture activation has been detected.
 * An erroneous activation may occur if the number of points used is less than minimud setted,
 * or the gesture is longer than max time of a standard gesture.
 */

bool AccelerationActivation::DetectedErroneousGestureActivation()
{
	bool sd = SlowDownDetected();

	bool min_p = getNumber_of_points() < min_number_of_points;

	bool ftexc = (getTValues()->at(getTValues()->size()-1) - firstTime) > maxTimeGesture;

	return ((sd && min_p) || ftexc);
}

/*
 * This method detects the acceleration from the user motion.
 * based on the past movements.
 */
bool AccelerationActivation::AccelerationDetected()
{
	int size = getAcceleration()->size();
	int relaxedPoints = -1;
	double actualAcc = 0;
	if (size > i_threshold+2){
		int infLimit = size-1-i_threshold;
		for (int i=infLimit;i<size;i++){
			actualAcc = getAcceleration()->at(i);
			if (relaxedPoints>0){
				if (actualAcc > negative_non_varying_acc*relaxedPoints && actualAcc < non_varying_acc*relaxedPoints)
					relaxedPoints--;
				else
					return false;
			}
			if (relaxedPoints ==-1 && actualAcc > acc_threshold)
				relaxedPoints = i_threshold;

			if (relaxedPoints==0){
				setNumber_of_points(i_threshold+1);
				firstTime = getTValues()->at(getTValues()->size()-1);
				return true;
			}

		}

	}
	return false;

}

/*
 * This method detects a SlowDown from the user motion. It is based on the past movements
 */
bool AccelerationActivation::SlowDownDetected()
{
	int size = getAcceleration()->size();
		int relaxedPoints = -1;
		double actualAcc = 0;
		if (size > i_threshold+2){
			int infLimit = size-1-i_threshold;
			for (int i=infLimit;i<size;i++){
				actualAcc = getAcceleration()->at(i);


				if (relaxedPoints>0){
					if (actualAcc > negative_non_varying_acc*relaxedPoints && actualAcc < non_varying_acc*relaxedPoints)
						relaxedPoints--;
					else
						return false;
				}

				if (relaxedPoints == -1 && actualAcc < (-1.0)*(acc_threshold))
					relaxedPoints = i_threshold;

				if (relaxedPoints==0){
					return true;
				}
			}

		}
		return false;
}

/*
 * This method returns the values that have induced to the change acceleration detection
 */
void AccelerationActivation::GetData(vector<double>& x,vector<double>& y,vector<double>& t){
	int size = getXValues()->size()-2;
	x.resize(size);
	y.resize(size);
	t.resize(size);
	for(int i = 2;i<getXValues()->size();i++){
			x[i-2]=getXValues()->at(i);
			y[i-2]=getYValues()->at(i);
			t[i-2]=getTValues()->at(i);
		}
}

/*
 * This method returns the distance between two points of the motion
 */
double AccelerationActivation::getDistance(double x1, double y1, double x2, double y2)
{

	return getDistanceCalculator()->calculateDistance(x1,y1,x2,y2);

}

/*
 * This method returns if the motion of the user has done a regular movement.
 */
bool AccelerationActivation::PossibleTrajectoryDetected(double distance, int initPos, int finalPos)
{

	double dis = getDistance(getXValues()->at(initPos),getYValues()->at(initPos),getXValues()->at(finalPos),getYValues()->at(finalPos));
	if (dis>getPixelsToTrajectory())
		return true;

	if (distance*d_threshold < dis && distance > getPixelsToTrajectory())
		return true;

	return false;
}

/*
 * This method returns the count of coords used to recognize an acceleration
 * movement.
 */

int AccelerationActivation::GetDataSize(){
	return i_threshold + 1;
}















