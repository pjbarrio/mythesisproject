/**
 * NormalFilter.cpp
 *
 *  Created on: 05-feb-2009
 *      \author  Timpa
 */

#include "NormalFilter.h"

NormalFilter::NormalFilter() {
;
}

NormalFilter::~NormalFilter() {
;
}

/**
 * This method tranforms the image passed by parameter in an
 * input for the ANN.
 */

fann_type* NormalFilter::applyFilter(IplImage *scr)
{


	int height = scr->height;
	int width  = scr->width;
    int step   = scr->widthStep;

    int i,j;

    uchar* data = (uchar *)scr ->imageData;

    fann_type input[4800];

	for (i= 0; i < height ; i++)
	   for (j= 0; j < width ; j++ )
		   input[i*width+j] = data[i*step+j]/255;



	return input;


}


