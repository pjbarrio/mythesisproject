/**
 * NeuralNet.h
 *
 *  Created on: 05-feb-2009
 *      \author  Timpa
 *
 * This class represents the ANN which will detect the hand
 * position in a picture.
 */

#ifndef NEURALNET_H_
#define NEURALNET_H_

#include "cv.h"


#include "..\Filters\NormalFilter.h"

#include "..\Logger\LogHandler.h"

#include "../Fann/include/fann.h"

#include "iostream.h"

#include "time.h"

class NeuralNet {
public:
	NeuralNet(LogHandler*);
	virtual ~NeuralNet();

	void run(IplImage*);
	int getXcoord();
	int getYcoord();
	bool startNet();
	void shutDown();

	/**
	 * This method returns the net file name.
	 */

    std::string getnetFile() const{return netFile;}

    /**
     * This method saves the net file name.
     */

    void setnetFile(std::string NetFile){this->netFile = NetFile;}

private:

	std::string netFile;

	struct fann *network;

	fann_type *output_values;

	fann_type *input_values;

	NormalFilter *normal_filter;

	int xCoord;

	int yCoord;

	LogHandler* logger;

	std::string componentName;

	int totalTime;

	clock_t timeperFrame;

	int totalFrames;

};

#endif /** NEURALNET_H_ */
