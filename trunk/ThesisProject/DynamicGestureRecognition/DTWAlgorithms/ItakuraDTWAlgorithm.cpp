/**
 * IrakuraDTWAlgorithm.cpp
 *
 *  Created on: 05/02/2009
 *      \author  Pablo
 */

#include "ItakuraDTWAlgorithm.h"
#include "math.h"

/**
 * This constructor method saves the rate value used to create
 * the structure which will be used to run the algorithm.
 */

ItakuraDTWAlgorithm::ItakuraDTWAlgorithm(double rate, DistanceCalculator* distanceCalculator):DTWAlgorithm(distanceCalculator) {
	cout << "Hello ItakuraDTWAlgorithm\n";
	this->rate = rate;
}

/**
 * this method desinstantiate the rate value used during the execution of
 * the algorithm.
 */

ItakuraDTWAlgorithm::~ItakuraDTWAlgorithm()
{
	cout << " Bye ItakuraDTWAlgorithm\n";

	rate = 0.0;
}

/**
 * This method returns if the value passed by parameter is accepted by the
 * algorithm.
 */

bool ItakuraDTWAlgorithm::acceptDTWValue(double dtwvalue)
{
	return (dtwvalue < DTWAlgorithm::maxAcceptedDTWValue);
}

/**
 * This method return the min row of the matrix to explore using
 * rate value, pos, n1 and n2.
 */

int ItakuraDTWAlgorithm::getInfValue(int pos, int n1, int n2)
{
	if (getLastpos()==pos){
		return DTWAlgorithm::getInfValue();
	}

	setLastpos(pos);

	double doublepos = (double)pos;
	double dn2 = (double)n2;
	double dn1 = (double)n1;
	int l1 = (int)floor(dn1*(1.0-getRate())/(2.0-getRate()));
	int l2 = (int)floor(dn1/(2.0-getRate()));

	if (pos <= l1){
			setInfValue(max(min(n2-2,(int)floor(((1.0-getRate())*dn2/dn1)*doublepos)),1));
			setSupValue(min((int)floor((dn2/((1.0-getRate())*dn1)*doublepos))+1,n2-2));
			return DTWAlgorithm::getInfValue();
		}
	if (l1 < pos && pos <= l2){
		setInfValue(max(min(n2-2,(int)floor(((1.0-getRate())*dn2/dn1)*doublepos)),1));
		setSupValue(min((int)floor(((1.0-getRate())*dn2/dn1)*doublepos + getRate()*dn2)+1,n2-2));
		return DTWAlgorithm::getInfValue();
	}
	if (l2 < pos){
		setInfValue(max(min(n2-2,(int)floor((dn2/((1.0-getRate())*dn1))*doublepos - (getRate()*dn2/(1.0-getRate())))),1));
		setSupValue(min((int)floor(((1.0-getRate())*dn2/dn1)*doublepos + getRate()*dn2)+1,n2-2));
		return DTWAlgorithm::getInfValue();
	}

	return -1;
}

/**
 * This method return the max row of the matrix to explore using
 * rate value, pos, n1 and n2.
 */

int ItakuraDTWAlgorithm::getSupValue(int pos,int n1,int n2)
{
	if (getLastpos()==pos){
		return DTWAlgorithm::getSupValue();
	}

	setInfValue(getInfValue(pos,n1,n2));

	return DTWAlgorithm::getSupValue();
}
