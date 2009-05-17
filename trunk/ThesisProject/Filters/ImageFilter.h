/*
 * ImageFilter.h
 *
 *  Created on: 05-feb-2009
 *      Author: Timpa
 *
 * This asbtract class is used to provide a unified interface
 * for the existing filters in the application.
 */

#ifndef IMAGEFILTER_H_
#define IMAGEFILTER_H_

#include "cv.h"
#include "highgui.h"

class ImageFilter {
public:
	ImageFilter();
	virtual ~ImageFilter();

	IplImage* applyFilter(IplImage*);
};

#endif /* IMAGEFILTER_H_ */
