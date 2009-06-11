/**
 * GestureNeuralNet.h
 *
 *  Created on: 05-feb-2009
 *      \author  Timpa
 *
 * This class represent the neural network responsible of
 * detect the hand state (open or closed)
 */

#ifndef GESTURENEURALNET_H_
#define GESTURENEURALNET_H_


#include "cv.h"


#include "..\Filters\NormalFilter.h"

#include "../Fann/include/fann.h"

#include "iostream.h"

class GestureNeuralNet {
public:
	GestureNeuralNet();
	virtual ~GestureNeuralNet();

	void run(IplImage*);
	bool startNet();
	void shutDown();

	int getHandGesture();

	/**
	 * This method returns the threshold used to distinguish
	 * beetween open and close hand.
	 */

    float getThreshold() const{return threshold;}

	/**
	 * This method sets the threshold used to distinguish
	 * beetween open and close hand.
	 */

    void setThreshold(float threshold){this->threshold = threshold;}

    /**
     * This method returns the name of the file containing the ANN.
     */

    std::string getnetFile() const{return netFile;}

    /**
     * This method sets the name of the file containing the ANN.
     */

	void setnetFile(std::string NetFile){this->netFile = NetFile;}


private:

	std::string netFile;

	struct fann *network;

	fann_type *output_values;

	fann_type *input_values;

	NormalFilter *normal_filter;

	int handGesture;

	float threshold;

};

#endif /** GESTURENEURALNET_H_ */
