/**
 * AddGestureToModelAlgorithm.h
 *
 *  Created on: 13/06/2009
 *     \author Pablo
 */

#ifndef ADDGESTURETOMODELALGORITHM_H_
#define ADDGESTURETOMODELALGORITHM_H_



#include "../src/DistanceCalculator.h"
#include "../src/DTWData.h"
#include "../src/DTWAlgorithm.h"

class AddGestureToModelAlgorithm: public DTWAlgorithm {
public:
	AddGestureToModelAlgorithm(DistanceCalculator*);
	virtual ~AddGestureToModelAlgorithm();
	double computeDTWValue(DTWData*,DTWData*);
	bool acceptDTWValue(double);
protected:
	int getInfValue(int a,int b,int c) {return 0;};

	int getSupValue(int a,int b,int c) {return 0;};

};

#endif /* ADDGESTURETOMODELALGORITHM_H_ */
