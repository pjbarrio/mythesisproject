/**
 * NeuralNetParameters.cpp
 *
 *  Created on: 16/06/2009
 *      \author Pablo
 */

#include "NeuralNetParameters.h"

NeuralNetParameters* NeuralNetParameters::instance = 0;

NeuralNetParameters::NeuralNetParameters() {
	;
}

/**
 * This method creates the Neural Net Parameters instance.
 */

NeuralNetParameters *NeuralNetParameters::getInstance()
{
	if (instance==0){
		instance = new NeuralNetParameters();
	}
	return instance;
}


NeuralNetParameters::~NeuralNetParameters() {
	instance = 0;
}
