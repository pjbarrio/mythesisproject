/**
 * DTWAlgorithm.h
 *
 *  Created on: 24/01/2009
 *      \author  Pablo
 *
 *  This class is the main class of the model. It defines the DTWAlgorithm to be used in
 *  gesture recognition
 */

#ifndef DTWALGORITHM_H_
#define DTWALGORITHM_H_

#include "DTWData.h"
#include "DistanceCalculator.h"
#include "vector.h"

class DTWAlgorithm {
public:
	DTWAlgorithm(DistanceCalculator*);
	virtual ~DTWAlgorithm();

	double computeDTWValue(DTWData*,DTWData*);

	/**
	 * This method decides if the value in the parameter list is an acceptance value
	 * under the necesary conditions
	*/

	virtual bool acceptDTWValue(double) = 0;


protected:

	static const double maxAcceptedDTWValue = 7000.0;

	void calculateMatrix(DTWData*,DTWData*,vector<vector<double> > &);

	/**
	 * This virtual method decides the minimun posible value for j when the
	 * algorithm is iterating by the "pos" position.
	 */

	virtual int getInfValue(int,int,int) = 0;

	/**
	 * This virtual method decides the minimun posible value for j when the
	 * algorithm is iterating by the "pos" position.
	 */

	virtual int getSupValue(int,int,int) = 0;

	double calculateDistance(double,double,double,double);

	DistanceCalculator *getDistanceCalculator() const {return distanceCalculator;}

	void setInfValue(int infValue){this->infValue = infValue;}

	void setSupValue(int supValue){this->supValue = supValue;}

	int getInfValue(){return infValue;}

	int getSupValue(){return supValue;}

	int getLastpos() const {return lastpos;}

	void setLastpos(int lastpos) {this->lastpos = lastpos;}
private:

	DistanceCalculator *distanceCalculator;

	int infValue;

	int supValue;

	int lastpos;
};

#endif /** DTWALGORITHM_H_ */
