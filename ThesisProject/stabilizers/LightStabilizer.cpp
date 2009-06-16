/**
 * LightStabilizer.cpp
 *
 *  Created on: 07-feb-2009
 *      \author  Timpa
 */

#include "LightStabilizer.h"

#include <sstream>
#include <fstream>
#include <iomanip>
#include "../GUI/Utils/Container.h"

/**
 * This method saves the LogHandler reference and initialize the
 * variables used to run the hand diagnostic.
 */

LightStabilizer::LightStabilizer(LogHandler* logger) {

	this->logger = logger;

	componentName = "Light Stabilizer";

	threshold_delta = Container::getInstance()->getThresholdDelta();
}

/**
 * This method dereferences de Log Handler object.
 */

LightStabilizer::~LightStabilizer() {

	this->logger = 0;

	threshold_delta = 0;
}

/**
 * This method capture a serie of frames and obtain the similar skin pixel count.
 */

void LightStabilizer::runAmbientDiagnostic(CamHandler *cam,FilterHandler*filterHandler,HandDiagnostic* handDiagnostic)
{

	Container::getInstance()->createCamViewerInstance(handDiagnostic->getCaptureLabel());
	/*
	 * Capturamos una serie de frames y sacamos datos como la cantidad de pixeles
	 * similares al color de la piel y demas
	 */

	int ret = handDiagnostic->exec();

	if (ret == 0){

		Container::getInstance()->setDiagnosticExecuted(false);

		Container::getInstance()->finishCamViewer();

		return;
	}

	Container::getInstance()->setDiagnosticExecuted(true);

	//Primera parte...

	averageSkinPixels = 0;

	double skinHandOpen = handDiagnostic->getFrameOpenCount();

	double skinHandClose = handDiagnostic->getFrameClosedCount();

	Container::getInstance()->finishCamViewer();

	//Cálculo

	float dif = skinHandOpen * 1.0 / skinHandClose * 1.0;

	if ( dif < Container::getInstance()->getDif() ){

		logger->addEntry(componentName,"Hand Analisis failed. Using proportional values");

		skinHandOpen = (skinHandOpen < skinHandClose )? skinHandClose : skinHandClose;

		skinHandClose = (double)skinHandOpen * Container::getInstance()->getFactor();

	}

	skinThreshold = ((skinHandOpen - skinHandClose)*threshold_delta) + skinHandClose -averageSkinPixels;


	std::string s;
	std::stringstream out;
	out << skinHandOpen;
	s = out.str();

	logger->addEntry(componentName,"Skin pixels in Open Hand: " + s);


	std::stringstream outt;
	outt << skinHandClose;
	s = outt.str();

	logger->addEntry(componentName,"Skin pixels in Close Hand: " + s);


	std::stringstream outtt;
	outtt << threshold_delta;
	s = outtt.str();

	logger->addEntry(componentName,"Threshold Delta " + s);


	std::stringstream outttt;
	outttt << skinThreshold;
	s = outttt.str();

	logger->addEntry(componentName,"Threshold " + s);



}

/**
 * This method returns the skinThreshold value calculated in the
 * hand Diagnostic method.
 */

double LightStabilizer::getSkinThreshold()
{

	return skinThreshold;

}




