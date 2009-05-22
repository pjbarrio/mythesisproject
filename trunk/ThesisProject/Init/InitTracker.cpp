/*
 * InitTracker.cpp
 *
 *  Created on: 29/03/2009
 *      Author: Pablo
 */

#include "InitTracker.h"
#include "../GUI/Utils/Container.h"

/*
 * This method creates an InitTracker object with the information
 * passed by parameter.
 */


InitTracker::InitTracker(CoordsSaver* coordSaver, SystemInfo* sysInfo, Camera* camera):InitializerCreator() {
	this->coordSaver = coordSaver;
	this->sysInfo = sysInfo;
	this->cam = camera;
}

/*
 * This destructor method dereferences all the objects initialized in the constructor method.
 */

InitTracker::~InitTracker() {
	this->coordSaver = 0;
	this->sysInfo = 0;
	this->cam = 0;
}

/*
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

	ImageUtilities             *util = new ImageUtilities();

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


	cvNamedWindow("Estado actual", CV_WINDOW_AUTOSIZE);
	cvMoveWindow("Estado actual", 100, 100);


	while ( cam->stillTracking() ){

		currentFrame = cam->retrieveFrame();

		filteredImage = filterHandler->runPreFilters(currentFrame);

		Container::getInstance()->setFilteredImage(filteredImage);

		//Hand Tracker

		net->run(filteredImage);

		Xcoord = net->getXcoord();

		Ycoord = net->getYcoord();

		filterHandler->runLowPassFilter(Xcoord,Ycoord,XcoordFIR,YcoordFIR);

		util->putMarker(currentFrame,XcoordFIR*4,YcoordFIR*4);



		cvShowImage("Estado actual", currentFrame );


		coordSaver->saveCoords(XcoordFIR,YcoordFIR);


		//Static Gesture Recognition through skin pixel count

		if ( filterHandler->getSkinCount() > filterHandler->getSkinThreshold()){ // Mano Abierta: mas pixeles blancos

/// EL IF ANTERIOR ES EL DE MANO ABIERTA O CERRADA
///			cam->showFrame(cam->getSecondWindow(),Open);

			Container::getInstance()->setClosed(false);
			//mouse_event(MOUSEEVENTF_LEFTUP, XcoordFIR * x_val, cy - YcoordFIR * y_val, 0, 0);

		}

		else{

			//mouse_event(MOUSEEVENTF_LEFTDOWN, XcoordFIR * x_val, cy - YcoordFIR * y_val, 0, 0);
/// EL ELSE PARA MANO CERRADA
///			cam->showFrame(cam->getSecondWindow(),Close);
			Container::getInstance()->setClosed(true);

		}


		cvReleaseImage( &filteredImage );

	}

	cam->stopCamDevice();

	net->shutDown();

	coordSaver->finishCoordSaver();

	cvDestroyWindow("Estado actual");

	logger->closeLogger();

	return 0;

}


