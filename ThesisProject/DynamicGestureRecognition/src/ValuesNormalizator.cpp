/*
 * ValuesNormalizator.cpp
 *
 *  Created on: 24/01/2009
 *      Author: Pablo
 */

#include "ValuesNormalizator.h"

/*
 * This method saves the SystemInfo object.
 */

ValuesNormalizator::ValuesNormalizator(SystemInfo* sysinfo) {
	cout << "Hello Values Normalizator\n";
	this->sysinfo = sysinfo;
}

/*
 * This method dereferences the SystemInfo object.
 */

ValuesNormalizator::~ValuesNormalizator() {
	cout << "Bye Values Normalizator\n";
	sysinfo = 0;
}

/*
 * This method normalize the "serie" up to a range of "range". i.e: if the range is 60.0, the
 * difference beetween the minimun value and the maximun value will be exactly 60.0.
 * if the "centerToZero" Parameter is set, the median value of the signal will be the 0.0 now.
 */

DTWData *ValuesNormalizator::normalizeSignal(DTWData *signal)
{
	double maxTime = 0;

	DTWData* ret = new DTWData();

	double maxx = -1;

	double minx = 999999;

	double avg = 0,sum = 0;

	signal->begin();

	while (signal->hasNext()){

		double coord = signal->getY();

		if (coord>maxx)
			maxx = coord;
		if (coord<minx)
			minx = coord;

		sum+=coord;

		maxTime = signal->getX();

		signal->next();
	}

	avg = sum / (double)signal->getXYPairCount();

	double valToSave;

	signal->begin();

	double firstTime = signal->getX();

	double minTime = signal->getX();

	double difTime = maxTime-minTime;

	while (signal->hasNext()){

		double coord = signal->getY();

		double lastTime = ((signal->getX() - firstTime)/difTime)*NORMALIZED_TIME;

		valToSave = coord - avg;

		ret->addNewXYPair(lastTime,valToSave);

		signal->next();
	}

	return ret;
}


