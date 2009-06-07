/*
 * SakoeChibaDTWAlgorithm.cpp
 *
 *  Created on: 05/02/2009
 *      Author: Pablo
 */

#include "SakoeChibaDTWAlgorithm.h"
#include "math.h"
#include "iostream.h"

/*
 * This method saves the rate value used to detect similar gestures with the SakoeChiba DTW algorithm.
 */

SakoeChibaDTWAlgorithm::SakoeChibaDTWAlgorithm(double rate,DistanceCalculator* distanceCalculator):DTWAlgorithm(distanceCalculator) {
	cout << "Hello SakoeChibaDTWAlgorithm\n";
	this->rate = rate;
}

/*
 * This destructor method desinstantiate the variable rate used by the algorithm to work
 * correctly.
 */

SakoeChibaDTWAlgorithm::~SakoeChibaDTWAlgorithm()
{
	cout << "Bye SakoeChibaDTWAlgorithm\n";
	rate = 0.0;
}

/*
 * This method returns if the algorithm accept the value passed by
 * parameter.
 */

bool SakoeChibaDTWAlgorithm::acceptDTWValue(double dtwvalue)
{
	return (dtwvalue < DTWAlgorithm::maxAcceptedDTWValue);
}

/*
 * This method return the min row of the matrix to explore using
 * rate value, pos, n1 and n2.
 */

int SakoeChibaDTWAlgorithm::getInfValue(int pos, int n1, int n2)
{
	if (getLastpos()==pos){
		return DTWAlgorithm::getInfValue();
	}

	setLastpos(pos);

	double dn2 = (double)n2;
	double dn1 = (double)n1;
	double angle = dn2/dn1;
	double disp = getRate()*dn2;

	double doublepos = (double)pos;
	int l1 = (int)floor(getRate()*dn1);
	int l2 = (int)floor((1.0-getRate())*dn1);

	if (l1 < pos && pos <= l2){
		setInfValue(max(min(n2-2,(int)floor(angle*doublepos - disp)),1));
		setSupValue(min((int)floor(angle*doublepos + disp)+1,n2-2));
		return DTWAlgorithm::getInfValue();
	}
	if (pos <= l1){
		setInfValue(1);
		setSupValue(min((int)floor(angle*pos + disp)+1,n2-2));
		return DTWAlgorithm::getInfValue();
	}
	if (l2 < pos){
		setInfValue(max(min(n2-2,(int)floor(angle*doublepos - disp)),1));
		setSupValue(n2-2);
		return DTWAlgorithm::getInfValue();
	}
	return -1;
}

/*
 * This method return the max row of the matrix to explore using
 * rate value, pos, n1 and n2.
 */

int SakoeChibaDTWAlgorithm::getSupValue(int pos, int n1, int n2)
{
	if (getLastpos()==pos){
		return DTWAlgorithm::getSupValue();
	}
	setInfValue(getInfValue(pos,n1,n2));

	return DTWAlgorithm::getSupValue();
}

