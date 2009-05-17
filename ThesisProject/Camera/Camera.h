
/*
 * Camera.h
 *
 *  Created on: 08/05/2009
 *      Author: Pablo
 *
 * This class represent the video source. There are many specialization of this class.
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include "../Logger/LogHandler.h"
#include "cv.h"

class Camera {
public:
	Camera(LogHandler*);

	virtual ~Camera();

/*
 * This method initializes the camDevice
 */

	virtual	bool initCamDevice() = 0;

/*
 * This method returns if there is more images to capture
 */

	virtual bool stillTracking() = 0;

/*
 * This method stops the camDevice removing the reference to every object
 * existing in this Camera object.
 */

	virtual void stopCamDevice() = 0;

/*
 * This method returns the next Frame existing in the source code.
 */

	virtual IplImage* retrieveFrame() = 0;

protected:

	LogHandler* logger;
};

#endif /* CAMERA_H_ */
