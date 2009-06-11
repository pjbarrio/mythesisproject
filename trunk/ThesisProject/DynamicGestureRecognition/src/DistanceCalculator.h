/**
 * DistanceCalculator.h
 *
 *  Created on: 05/02/2009
 *      \author  Pablo
 *  This class is the responsible of calculate de Distance between points of the
 *  time series.
 */

#ifndef DISTANCECALCULATOR_H_
#define DISTANCECALCULATOR_H_

class DistanceCalculator {
public:
	DistanceCalculator();
	virtual ~DistanceCalculator();
	/**
	 * This method returns the corresponding value to the difference between points
	 * (x1,y1) and (x2,y2)
	 */
	virtual double calculateDistance(double,double,double,double) = 0;
};

#endif /** DISTANCECALCULATOR_H_ */
