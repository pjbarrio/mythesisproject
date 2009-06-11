/**
 * ImageUtilities.cpp
 *
 *  Created on: 05-feb-2009
 *      \author  Timpa
 */

#include "ImageUtilities.h"

ImageUtilities::ImageUtilities() {

}

ImageUtilities::~ImageUtilities() {

}

/**
 * This method draws a cross indicating the hand position on the
 * frame being processed.
 */

IplImage *ImageUtilities::putMarker(IplImage *scr, int x, int y)
{

	cvLine(scr, cvPoint(x-10,y), cvPoint(x+10,y), cvScalar(0,255,0), 1);
	cvLine(scr, cvPoint(x,y-10), cvPoint(x,y+10), cvScalar(0,255,0), 1);

}

/**
 * This method draws a box starting in x,y and 20*20 size.
 */

IplImage* ImageUtilities::drawBox(IplImage* frame,int x, int y){

		for ( int i = 0 ; i < 21 ; i++)

				cvLine(frame, cvPoint(x,y+i), cvPoint(x+20,y+i), cvScalar(0,255,0), 1);


		return frame;



	}
