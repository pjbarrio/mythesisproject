/*
 * ImageFilter.cpp
 *
 *  Created on: 05-feb-2009
 *      Author: Timpa
 */

#include "ImageFilter.h"

ImageFilter::ImageFilter() {

}

ImageFilter::~ImageFilter() {

}

/*
 * This method returns the image withow affecting it. It is used
 * to generate a Pipe&Filter taking part in different configurations.
 */

IplImage *ImageFilter::applyFilter(IplImage* scr)
{

	return scr;

}


