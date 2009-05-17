/*
 * ItakuraDTWAlgorithm.h
 *
 *  Created on: 05/02/2009
 *      Author: Pablo
 *
 *  This Class provides the implementation for the Itakura Parallelogram in the
 *  DTW algorithm. It performs the main algoritm in O(n) time.
 */

#ifndef ITAKURADTWALGORITHM_H_
#define ITAKURADTWALGORITHM_H_

#include "../src/DTWAlgorithm.h"


class ItakuraDTWAlgorithm: public DTWAlgorithm {
public:
	ItakuraDTWAlgorithm(double,DistanceCalculator*);
	~ItakuraDTWAlgorithm();
	bool acceptDTWValue(double);
private:
	double rate;
	double getRate(){return rate;};

protected:

	double **calculateMatrix(DTWData*,DTWData*);

	int getInfValue(int,int,int);

	int getSupValue(int,int,int);
};

#endif /* ITAKURADTWALGORITHM_H_ */
