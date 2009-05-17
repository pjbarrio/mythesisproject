/*
 * GestureNeuralNet.cpp
 *
 *  Created on: 05-feb-2009
 *      Author: Timpa
 */

#include "GestureNeuralNet.h"

GestureNeuralNet::GestureNeuralNet() {
	;
}

/*
 * This method destroy the neural network created.
 */

GestureNeuralNet::~GestureNeuralNet() {

	fann_destroy(network);

}

/*
 * This method process the image passed by parameter and
 * obtain the hand state.
 */

void GestureNeuralNet::run(IplImage *scr)
{

	//Podemos tener varias redes y trabajar de manera conjunta, tipo voting-system

	if ( scr != NULL){

		input_values = normal_filter->applyFilter(scr);//Normalizo la Imagen


		output_values = fann_run(network,input_values);


		float res = output_values[0];

		if ( res > threshold)
			handGesture = 1;
		else
			handGesture = 0;


	}

}


/*
 * This method destroy the neural network created.
 */

void GestureNeuralNet::shutDown()
{
	//grabamos en el log el tiempo promedio de proceso, y demas

	fann_destroy(network);

}

/*
 * This method creates the neural network from file and initializes
 * the variables used by the process.
 */

bool GestureNeuralNet::startNet()
{
	//si no podemos grabamos en el log

	if ( netFile == "" )//log
		return false;

	network = fann_create_from_file(netFile.c_str());

	normal_filter = new NormalFilter();

	input_values  = new fann_type[4800];

	output_values = new fann_type[1];

	return true;
}

/*
 * This method returns the hand state detected by the ANN.
 */

int GestureNeuralNet::getHandGesture()
{
	return handGesture;

}




