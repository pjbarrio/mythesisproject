/**
 * EuclideanDistance.cpp
 *
 *  Created on: 05/02/2009
 *      \author  Pablo
 */

#include "EuclideanDistance.h"
#include "math.h"
#include "iostream.h"

EuclideanDistance::EuclideanDistance()
{
	cout << "Hello Euclidean Distance\n";
}

EuclideanDistance::~EuclideanDistance()
{
	cout << "Bye Euclidean Distance\n";

}

/**
 * This method returns the calculated Euclidean distances beetween the points
 * (x1,y1) and (x2,y2)
 */

double EuclideanDistance::calculateDistance(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x2-x1,2.0) + pow(y2-y1,2.0));
}


