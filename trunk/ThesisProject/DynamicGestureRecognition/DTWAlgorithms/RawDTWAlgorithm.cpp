/**
 * RawDTWAlgorithm.cpp
 *
 *  Created on: 05/02/2009
 *      \author  Pablo
 */

#include "RawDTWAlgorithm.h"

RawDTWAlgorithm::RawDTWAlgorithm(DistanceCalculator *distanceCalculator):DTWAlgorithm(distanceCalculator)
{
	cout << " Hello RawDTWAlgorithm\n";
}
RawDTWAlgorithm::~RawDTWAlgorithm()
{
	cout << " Bye RawDTWAlgorithm\n";
}

/**
 * This method returns if the algorithm accept the value
 * passed by parameter.
 */

bool RawDTWAlgorithm::acceptDTWValue(double dtwvalue)
{
	return (dtwvalue < DTWAlgorithm::maxAcceptedDTWValue);
}

/**
 * This method returns the min row used to execute the algorithm.
 * In this case is 1.
 */

int RawDTWAlgorithm::getInfValue(int pos, int n1, int n2)
{
	return 1;
}


/**
 * This method return the max row of the matrix to explore.
 * In this case, last row is n2-1.
 */


int RawDTWAlgorithm::getSupValue(int pos, int n1, int n2)
{
	return n2-2;
}









