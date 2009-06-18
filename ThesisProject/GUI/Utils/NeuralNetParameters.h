/**
 * NeuralNetParameters.h
 *
 *  Created on: 16/06/2009
 *      \author Pablo
 *
 *  This class stores the Neural Network Parameters.
 *  This way, we avoid conflicts beetween fann and MINGW.
 */

#ifndef NEURALNETPARAMETERS_H_
#define NEURALNETPARAMETERS_H_


class NeuralNetParameters {
public:
	static NeuralNetParameters* getInstance();

	int getNetOutput() const {return netOutput;}

	void setNetOutput(int netOutput) {this->netOutput = netOutput;}

	int getStaticGestureOutput() const {return staticGestureOutput;}

	void setStaticGestureOutput(int staticGestureOutput) {this->staticGestureOutput = staticGestureOutput;}

    int getInputSize() const {return inputSize;}

    void setInputSize(int inputSize) {this->inputSize = inputSize;}

private:
	NeuralNetParameters();
	virtual ~NeuralNetParameters();
	static NeuralNetParameters* instance;
	int inputSize;
	int netOutput;
	int staticGestureOutput;
};

#endif /* NEURALNETPARAMETERS_H_ */
