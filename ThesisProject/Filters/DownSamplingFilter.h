/**
 * DownSamplingFilter.h
 *
 *  Created on: 05-feb-2009
 *      \author  Timpa
 *
 * This class extends from ImageFilter and implements
 * the Down Sampling Filter.
 */

#ifndef DOWNSAMPLINGFILTER_H_
#define DOWNSAMPLINGFILTER_H_

#include "ImageFilter.h"

class DownSamplingFilter: public ImageFilter {
public:
	DownSamplingFilter();
	virtual ~DownSamplingFilter();

	IplImage* applyFilter(IplImage*);
};

#endif /** DOWNSAMPLINGFILTER_H_ */
