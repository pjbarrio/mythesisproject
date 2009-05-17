/*
 * GrayFilter.cpp
 *
 *  Created on: 05-feb-2009
 *      Author: Timpa
 */

#include "GrayFilter.h"

GrayFilter::GrayFilter() {
;
}

GrayFilter::~GrayFilter() {
;
}

/*
 * This method returns the image passed by parameter modified by
 * a gray scale transformation.
 */

IplImage *GrayFilter::applyFilter(IplImage *scr)
{

	IplImage* gray;

	if ( scr->nChannels == 3){

	  gray = cvCreateImage (cvSize (scr->width, scr->height), 8, 1);

	  cvCvtColor (scr, gray, CV_BGR2GRAY);

	  cvEqualizeHist (gray, gray);

	  return gray;

   }
	else{
		cvEqualizeHist (scr, scr);
		return scr;
	}


}


