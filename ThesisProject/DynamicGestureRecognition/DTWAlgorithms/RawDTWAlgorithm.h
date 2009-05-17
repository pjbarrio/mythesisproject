/*
 * RawDTWAlgorithm.h
 *
 *  Created on: 05/02/2009
 *      Author: Pablo
 *
 *  This Class Implements the basic implementation of DTW. It doesn't provide
 *  a perform. The main algorithm is O(n2).
 */

#ifndef RAWDTWALGORITHM_H_
#define RAWDTWALGORITHM_H_


#include "../src/DTWAlgorithm.h"

class RawDTWAlgorithm: public DTWAlgorithm {
public:
	RawDTWAlgorithm(DistanceCalculator*);
	~RawDTWAlgorithm();
	bool acceptDTWValue(double);

protected:

	double **calculateMatrix(DTWData*,DTWData*);

	int getInfValue(int,int,int);

	int getSupValue(int,int,int);
};

#endif /* RAWDTWALGORITHM_H_ */
