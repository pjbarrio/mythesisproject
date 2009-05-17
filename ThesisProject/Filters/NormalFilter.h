/*
 * NormalFilter.h
 *
 *  Created on: 05-feb-2009
 *      Author: Timpa
 *
 * This class is a kind of filter used to transform the image
 * to an intput for the Artificial Neural Network
 */

#ifndef NORMALFILTER_H_
#define NORMALFILTER_H_


#include "../Fann/include/fann.h"

#include "cv.h"

class NormalFilter {
public:
	NormalFilter();
	virtual ~NormalFilter();

	fann_type* applyFilter(IplImage*);

};

#endif /* NORMALFILTER_H_ */
