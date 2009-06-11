/**
 * CamViewer.cpp
 *
 *  Created on: 28/04/2009
 *      \author  Pablo
 */

#include "CamViewer.h"
#include <QPixmap>
#include "iostream.h"

#include "windows.h"
#include "Utils/Container.h"

/**
 * This constructor method saves the label where the image
 * will be showed.
 */

CamViewer::CamViewer(QLabel* dst):QThread() {
	this->dst = dst;
	saveVideo = false;
}

/**
 * This method dereferences the destiny label.
 */

CamViewer::~CamViewer() {
	dst = 0;
}

/**
 * This method set the bool variable to save the current frame.
 */

void CamViewer::setSaveFrame(bool s){
	mutex->lock();
	save = s;
	mutex->unlock();
}

/**
 * This method returns the last saved frame. This frame is used
 * to run the hand Diagnostic.
 */

bool CamViewer::getSaveFrame(){
	bool ret;
	mutex->lock();
		ret = save;
	mutex->unlock();
	return ret;
}

/**
 * This method starts the loop which will be capturing and showing
 * images.
 */

void CamViewer::run()
{
	init();

	while (capturing){

		captureFrame();

		dst->setPixmap(QPixmap::fromImage(image->rgbSwapped()));

//		cvReleaseImage(&imgdst);

		cvReleaseImage(&img);

	}

	cvReleaseCapture(&capture);

}

/**
 * This method starts the configuration of the camera.
 */

void CamViewer::init(){

	mutex = new QMutex();

	mutex->lock();

	save = false;

	mutex->unlock();

	height = this->dst->height();

	width = this->dst->width();

	capture = cvCaptureFromCAM(CV_CAP_ANY);

	if(!cvGrabFrame(capture)){              // capture a frame
		printf("Could not grab a frame\n\7");
		exit(0);
	}
}

/**
 * This method retrieves the frame and shows it on the label
 * configured in the constructor. The image is showed using the
 * rotation values used by the user.
 */

void CamViewer::captureFrame()
{

	Container* cont = Container::getInstance();

	imgdst = 0;

	imgdst = cvQueryFrame(capture);           // retrieve the captured frame

	if (cont->getRotateX())
		cvFlip(imgdst,imgdst,1);

	if (cont->getRotateY())
		cvFlip(imgdst,imgdst,-1);

	if (getSaveVideo()){
		cont->addFrame(cvCloneImage(imgdst));
	}

	if (getSaveFrame()){
		  IplImage* clone = cvCreateImage(cvSize(320,240), IPL_DEPTH_8U, 3);
		  cvResize(imgdst,clone,1);
		  cont->setSavedImage(clone);
		  setSaveFrame(false);
	}

	img = cvCreateImage(cvSize(width,height), IPL_DEPTH_8U, 3);

	cvResize(imgdst,img,1);

	image = new QImage((const uchar *)img->imageData,img->width, img->height,img->widthStep, QImage::Format_RGB888);

}

/**
 * This method return the saveVideo value. If the process
 * is saving the video, returns true. If doesn't returns false.
 */

bool CamViewer::getSaveVideo(){
	bool ret;
	saveVideoAccess.lock();
	ret = saveVideo;
	saveVideoAccess.unlock();
	return ret;
}

/**
 * This method sets the capturing value. This value is used to
 * run the loop.
 */

void CamViewer::setCapturing(bool capturing){
	this->capturing = capturing;
}

/**
 * This method sets the saveVideo value. If the saveVideo is setted
 * to true, a new video is created.
 */

void CamViewer::setSaveVideo(bool val){
	saveVideoAccess.lock();
	saveVideo = val;
	if (saveVideo)
		Container::getInstance()->createVideo();
	saveVideoAccess.unlock();
}
