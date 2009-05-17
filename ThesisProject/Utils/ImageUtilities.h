/*
 * ImageUtilities.h
 *
 *  Created on: 05-feb-2009
 *      Author: Timpa
 *
 * This class draws lines or boxes in the current frame to refer
 * to an existing object.
 */

#ifndef IMAGEUTILITIES_H_
#define IMAGEUTILITIES_H_

#include "cv.h"

class ImageUtilities {
public:
	ImageUtilities();
	virtual ~ImageUtilities();

	IplImage* putMarker(IplImage*,int,int);
	IplImage* drawBox(IplImage*,int,int);

};

#endif /* IMAGEUTILITIES_H_ */
