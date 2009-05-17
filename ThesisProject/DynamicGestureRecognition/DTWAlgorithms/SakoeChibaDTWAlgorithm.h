/*
 * SakoeChibaDTWAlgorithm.h
 *
 *  Created on: 05/02/2009
 *      Author: Pablo
 *
 *  This Class provides the implementation for the Sakoe-Chiba band in the
 *  DTW algorithm. It performs the main algoritm in O(n) time.
 */

#ifndef SAKOECHIBADTWALGORITHM_H_
#define SAKOECHIBADTWALGORITHM_H_

#include "../src/DTWAlgorithm.h"

class SakoeChibaDTWAlgorithm: public DTWAlgorithm {
public:
	SakoeChibaDTWAlgorithm(double, DistanceCalculator*);
	~SakoeChibaDTWAlgorithm();
	bool acceptDTWValue(double);


private:
	double rate;

	double getRate(){return rate;}



protected:

	int getInfValue(int,int,int);

	int getSupValue(int,int,int);
};

#endif /* SAKOECHIBADTWALGORITHM_H_ */
