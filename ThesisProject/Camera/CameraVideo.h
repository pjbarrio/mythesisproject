/**
 * CameraVideo.h
 *
 *  Created on: 08/05/2009
 *      \author  Pablo
 *
 * This class represents a video source. It's a list of captured frames.
 */

#ifndef CAMERAVIDEO_H_
#define CAMERAVIDEO_H_

#include "Camera.h"
#include <QList>
#include "cv.h"

class CameraVideo: public Camera {
public:
	CameraVideo(LogHandler*,QList<IplImage*>*);

	virtual ~CameraVideo();

	bool initCamDevice();

	bool stillTracking();

	void stopCamDevice();

	IplImage* retrieveFrame();

private:
	QList<IplImage*>* video;
	int index;
	int videoSize;
	IplImage* clone;
	IplImage* free;
};

#endif /** CAMERAVIDEO_H_ */
