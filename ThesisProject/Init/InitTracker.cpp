/**
 * InitTracker.cpp
 *
 *  Created on: 29/03/2009
 *      \author  Pablo
 */

#include "InitTracker.h"
#include "../GUI/Utils/Container.h"

/**
 * This method creates an InitTracker object with the information
 * passed by parameter.
 */


InitTracker::InitTracker(CoordsSaver* coordSaver, SystemInfo* sysInfo, Camera* camera):InitializerCreator() {
	this->coordSaver = coordSaver;
	this->sysInfo = sysInfo;
	this->sysInfo->getSystemWorkResolution(ww,wh);
	this->cam = camera;
}

/**
 * This destructor method dereferences all the objects initialized in the constructor method.
 */

InitTracker::~InitTracker() {
	this->coordSaver = 0;
	this->sysInfo = 0;
	this->cam = 0;
}

/**
 * This method start a loop which will be looping until the camera device
 * stops retrieving frames. This method obtain the real captured frame and
 * apply the filters it need to get into the ANN.
 * After this, the coords provided by the network are stored for the consumers
 * activity.
 */

int InitTracker::start()
{
	LogHandler               *logger = Container::getInstance()->getLog();

	ConfigHandler            *config = Container::getInstance()->getConfigHandler();

	NeuralNet                   *net = new NeuralNet(logger);

	LightStabilizer *lightStabilizer = Container::getInstance()->getLightStabilizer();

	FilterHandler     *filterHandler = Container::getInstance()->getFilterHandler();

//	ImageUtilities             *util = new ImageUtilities();

	if ( !cam->initCamDevice() ){

		logger->closeLogger();

		return -1;

	}


	net->setnetFile(config->getTrackerNetFile());

	if ( !net->startNet()){

		logger->closeLogger();

		return -1;

	}
	filterHandler->setSkinThreshold(lightStabilizer->getSkinThreshold());

	int Xcoord,Ycoord,XcoordFIR,YcoordFIR;

	IplImage* currentFrame;

	IplImage* filteredImage;

	bool rotx = Container::getInstance()->getRotateX();

	bool roty = Container::getInstance()->getRotateY();

	while ( cam->stillTracking() ){

		currentFrame = cam->retrieveFrame();

		filteredImage = filterHandler->runPreFilters(currentFrame);

		//Hand Tracker

		net->run(filteredImage);

		Xcoord = net->getXcoord();

		Ycoord = net->getYcoord();

		if (rotx)
			Xcoord = ww - Xcoord;
		if (roty)
			Ycoord = wh - Ycoord;


		filterHandler->runLowPassFilter(Xcoord,Ycoord,XcoordFIR,YcoordFIR);

		coordSaver->saveCoords(XcoordFIR,YcoordFIR);

		cvReleaseImage( &filteredImage );

	}

	cam->stopCamDevice();

	net->shutDown();

	coordSaver->finishCoordSaver();

	logger->closeLogger();

	return 0;

}


