/**
 * CamHandler.cpp
 *
 *  Created on: 04-feb-2009
 *      \author  Timpa
 */

#include "CamHandler.h"
#include "iostream.h"

/**
 * This method initializes the existing variables of the CamHandler object.
 */

CamHandler::CamHandler(LogHandler* logger):Camera(logger) {

	still_tracking = false;


}

/**
 * This method stops the cam device from OpenCV Library.
 */

CamHandler::~CamHandler() {

	stopCamDevice();

}

/**
 * This method initializes the capture from the source camera using
 * OpenCV Library
 */

bool CamHandler::initCamDevice()
{

	componentName = "CamHandler";

	capture = cvCaptureFromCAM( CV_CAP_ANY );



	 if( !capture ) {

		 logger->addEntry(componentName,"There is not any available camera on your system");

		 return false;
	   }


	 //Para que la captura se realice a 320*240, estos valores tiene que definirse asi
	 double w = 288;
	 double h = 352;

     cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH, w);

     cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT, h);


     logger->addEntry(componentName,"Camera started succefully");


	 return true;
}

/**
 * This method returns true if the camera is still
 * tracking or false if it doesn't.
 */

bool CamHandler::stillTracking()
{

	if( (cvWaitKey(10) & 255) == 27 )
		 return false;

	 return true;


}

/**
 * This method release the capture object to stop the
 * capturing process.
 */

void CamHandler::stopCamDevice()
{

	cvReleaseCapture( &capture );

}

/**
 * This method shows the frame in the parameter list on the
 * window which have the "window" name.
 */

void CamHandler::showFrame(std::string window,IplImage *frame)
{

	 cvShowImage( window.c_str(), frame );
}

/**
 * This method returns the last frame captured. It's stored
 * internally.
 */

IplImage *CamHandler::retrieveFrame()
{

	return cvQueryFrame(capture);

}






