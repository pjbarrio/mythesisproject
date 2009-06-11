/**
 * DownSamplingFilter.cpp
 *
 *  Created on: 05-feb-2009
 *      \author  Timpa
 */

#include "DownSamplingFilter.h"

DownSamplingFilter::DownSamplingFilter() {
;
}

DownSamplingFilter::~DownSamplingFilter() {
;
}

/**
 * This method applies the Down Sampling filter to the image
 * passed by parameter and return the resulted image.
 */

IplImage *DownSamplingFilter::applyFilter(IplImage* scr)
{

	IplImage* dsImg = cvCreateImage (cvSize (cvRound (scr->width/2),cvRound (scr->height/2)),8, 1);

	cvPyrDown( scr, dsImg,CV_GAUSSIAN_5x5 );

	IplImage* ret = cvCreateImage (cvSize (cvRound (dsImg->width/2),cvRound (dsImg->height/2)),8, 1);

	cvPyrDown( dsImg, ret,CV_GAUSSIAN_5x5 );

	cvReleaseImage( &dsImg );

	return ret;


}


