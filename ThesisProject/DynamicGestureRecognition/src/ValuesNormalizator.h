/*
 * ValuesNormalizator.h
 *
 *  Created on: 24/01/2009
 *      Author: Pablo
 *
 *  This class normalize the signal up to known values. In case you have a signal oscilating
 *  beetween -2.1 and 45.0 and you want the signal is in the range of 0.0 and 100.0, you can do it
 *  with this class.
 */

#ifndef VALUESNORMALIZATOR_H_
#define VALUESNORMALIZATOR_H_

#include "DTWData.h"
#include "../../Utils/SystemInfo.h"

class ValuesNormalizator {
public:
	ValuesNormalizator(SystemInfo*);
	virtual ~ValuesNormalizator();
	DTWData* normalizeSignal(DTWData*);
private:
	SystemInfo* sysinfo;
	static const double NORMALIZED_TIME = 2.0;
};

#endif /* VALUESNORMALIZATOR_H_ */
