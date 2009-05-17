/*
 * AccelerationActivation.h
 *
 *  Created on: 05/02/2009
 *      Author: Pablo
 *
 * This class detects a gesture when it realizes that the motion
 * has increase the velocity
 */

#ifndef ACCELERATIONACTIVATION_H_
#define ACCELERATIONACTIVATION_H_

#include "../src/ActivationGestureMethod.h"
#include "../CircularBuffer/CircularBuffer.h"
#include <vector.h>
#include "../src/DistanceCalculator.h"

class AccelerationActivation: public ActivationGestureMethod {
public:
	AccelerationActivation(int,int,double,double,int,int,double,double,DistanceCalculator*);
	~AccelerationActivation();
	void setNewInput(double, double, double);
	bool DetectedGestureActivation();
	bool DetectedGestureDeactivation();
	bool DetectedErroneousGestureActivation();
	void GetData(vector<double>&,vector<double>&,vector<double>&);
	int GetDataSize();
private:
	bool trajectoryDetected();
	bool AccelerationDetected();
	bool SlowDownDetected();
	double getDistance(double,double,double,double);
	bool PossibleTrajectoryDetected(double,int,int);
	int number_of_points;
	int pixelsToTrajectory;
	double acc_threshold;
	double firstTime;
	double maxTimeGesture;
    CircularBuffer *getXValues() const {return xValues;}
    CircularBuffer *getYValues() const {return yValues;}
    CircularBuffer *getTValues() const {return tValues;}
    CircularBuffer *getVelocity() const {return velocity;}
    CircularBuffer *getAcceleration() const{return acceleration;}
	int getPixelsToTrajectory()const {return pixelsToTrajectory;}
	int getNumber_of_points() const {return number_of_points;}
	void setNumber_of_points(int number_of_points) {this->number_of_points = number_of_points;}

    CircularBuffer *xValues;
	CircularBuffer *yValues;
	CircularBuffer *tValues;
	CircularBuffer *velocity;
	CircularBuffer *acceleration;

	DistanceCalculator *getDistanceCalculator() const {return distanceCalculator;}

	//Configuration variables.

	double d_threshold; //distance Threshold
	int i_threshold;//how many values use to inform Acceleration
	double non_varying_acc; //value that indicates the range of non varying acceleration
	double negative_non_varying_acc; //value that indicates the range of non varying slowdown
	int min_number_of_points;

	//distanceCalculator

	DistanceCalculator *distanceCalculator;
};

#endif /* ACCELERATIONACTIVATION_H_ */
