/**
 * GrayFilter.h
 *
 *  Created on: 05-feb-2009
 *      \author  Timpa
 *
 * This class is a specific kind of Image Filter. It will transform the image
 * to gray scale.
 */

#ifndef GRAYFILTER_H_
#define GRAYFILTER_H_

#include "ImageFilter.h"

class GrayFilter: public ImageFilter {
public:
	GrayFilter();
	virtual ~GrayFilter();

	IplImage* applyFilter(IplImage*);

};

#endif /** GRAYFILTER_H_ */
