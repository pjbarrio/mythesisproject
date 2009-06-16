/**
 * NeuralNet.cpp
 *
 *  Created on: 05-feb-2009
 *      \author  Timpa
 */

#include "NeuralNet.h"

#include <sstream>
#include <fstream>
#include <iomanip>
#include "../GUI/Utils/NeuralNetParameters.h"

/**
 * This method saves the logger instances and initializes the
 * variables used to detect the hand position.
 */

NeuralNet::NeuralNet(LogHandler* logger) {

	this->logger = logger;

	componentName = "NetHandler";

	totalFrames  = 0;

	totalTime = 0;
}

/**
 * This method destroy the neural network created to detect
 * hand position.
 */

NeuralNet::~NeuralNet() {

	fann_destroy(network);//check this!!

}

/**
 * This method processes the image passed by parameter and saves
 * the hand position coords detected by the ANN.
 */

void NeuralNet::run(IplImage *scr)
{

	//Podemos tener varias redes y trabajar de manera conjunta, tipo voting-system

	timeperFrame = clock();

	if ( scr != NULL){

		input_values = normal_filter->applyFilter(scr);//Normalizo la Imagen


		output_values = fann_run(network,input_values);


		xCoord = output_values[0];
		yCoord = output_values[1];

	}

	totalTime = totalTime + ( clock() - timeperFrame);

	totalFrames++;

}

/**
 * This method returns the Y component of the hand coord.
 */

int NeuralNet::getYcoord()
{
	return yCoord;
}

/**
 * This method returns the X component of the hand coord.
 */

int NeuralNet::getXcoord()
{
	return xCoord;
}

/**
 * This method destroy the artificial neural network.
 */

void NeuralNet::shutDown()
{

	std::string s;
	std::stringstream out;
	out << totalTime * 1.0 / totalFrames * 1.0;
	s = out.str();

	logger->addEntry(componentName,"Average time per Frame: " + s);

	fann_destroy(network);

}

/**
 * This method creates the neural network responsible of detect
 * hand position.
 */

bool NeuralNet::startNet()
{


	if ( netFile == "" ){

		logger->addEntry(componentName,"The Network file is not specified in the config file");

		return false;
	}


	network = fann_create_from_file(netFile.c_str());

	if ( network == NULL){

		logger->addEntry(componentName,"The Network file does not exist");
		return false;

	}

	NeuralNetParameters* nnpar = NeuralNetParameters::getInstance();

	normal_filter = new NormalFilter();

	input_values  = new fann_type[nnpar->getInputSize()];

	output_values = new fann_type[nnpar->getNetOutput()];

	xCoord = 0;
	yCoord = 0;

	logger->addEntry(componentName,"The Network was succesfully created from " + netFile);

	return true;
}








