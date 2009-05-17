/*
 * EuclideanDistance.h
 *
 *  Created on: 05/02/2009
 *      Author: Pablo
 *
 * This class represent a specification of DistanceCalculator.
 * It represent the more common distance calculator, called Euclidean Distance.
 */

#ifndef EUCLIDEANDISTANCE_H_
#define EUCLIDEANDISTANCE_H_

#include "../src/DistanceCalculator.h"

class EuclideanDistance: public DistanceCalculator {
public:
	EuclideanDistance();
	~EuclideanDistance();
	double calculateDistance(double,double,double,double);
};

#endif /* EUCLIDEANDISTANCE_H_ */
