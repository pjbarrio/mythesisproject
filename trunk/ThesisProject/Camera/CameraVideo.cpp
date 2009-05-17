/*
 * CameraVideo.cpp
 *
 *  Created on: 08/05/2009
 *      Author: Pablo
 */

#include "CameraVideo.h"

/*
 * This constructor method receive an empty Image List.
 */

CameraVideo::CameraVideo(LogHandler* log,QList<IplImage*>* video):Camera(log) {
	this->video = video;
	this->videoSize = video->size();
}

CameraVideo::~CameraVideo() {
	video = 0;
}

/*
 * This method initiates the current index of the video.
 */

bool CameraVideo::initCamDevice(){
	index = 0;
	logger->addEntry("Camera_Video","created Successfully");
	return true;
}

/*
 * This method returns if exists more pictures to retrieve.
 */

bool CameraVideo::stillTracking(){
	return (index < videoSize);
}

void CameraVideo::stopCamDevice(){
	;
}

/*
 * This method returns the next picture in the video.
 */

IplImage* CameraVideo::retrieveFrame(){

	free = video->at(index);
	clone = cvCreateImage(cvSize(320,240), IPL_DEPTH_8U, 3);
	cvResize(free,clone,1);
//	cvReleaseImage(&free);

	index++;


	return clone;
}
