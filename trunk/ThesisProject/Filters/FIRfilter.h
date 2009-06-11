/**
 * FIRfilter.h
 *
 *  Created on: 05-feb-2009
 *      \author  Timpa
 *
 * This class is the last filter used in the hand tracking process.
 * The main responsability of this class is to smooth the movement detected
 * by the ANN.
 */

#ifndef FIRFILTER_H_
#define FIRFILTER_H_



class FIRfilter{
public:
	FIRfilter();
	virtual ~FIRfilter();

	void runLowPassFilter(int Xin,int Yin,int &Xout,int &Yout);

	void runAverageSmoothing(int Xin,int Yin,int &Xout,int &Yout);


private:

	float previous_Xvalues;
	float previous_Yvalues;

	float delta;


	float *previousXValues;
	float *previousYValues;

	int active;

	int k_factor;

	int frameWindow;



};

#endif /** FIRFILTER_H_ */
