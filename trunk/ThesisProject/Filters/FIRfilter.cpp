/**
 * FIRfilter.cpp
 *
 *  Created on: 05-feb-2009
 *      \author  Timpa
 */

#include "FIRfilter.h"
#include "../GUI/Utils/Container.h"

/**
 * This method initializes the useful variables to achieve
 * the smoothing effect in the movement detected.
 */

FIRfilter::FIRfilter() {

	previous_Xvalues = 0;
	previous_Yvalues = 0;

	active =0;


	k_factor = Container::getInstance()->getK_Factor();//OJO: tiene que ser menor o igual a frameWindow

	frameWindow = Container::getInstance()->getFrameWindow(); // ventana de analisis


	previousXValues = new float[frameWindow];
	previousYValues = new float[frameWindow];

	delta = Container::getInstance()->getDelta();



}

FIRfilter::~FIRfilter() {
;
}

/**
 * This method executes the low pass filter with the Xin and Yin values
 * passed by parameter.
 */

void FIRfilter::runLowPassFilter(int Xin, int Yin, int & Xout, int & Yout)

{

	/*
	 * tags: Low-pass filter, wikipedia
	 *
	 */

	Xout =  previous_Xvalues + delta * (Xin - previous_Xvalues );
	Yout =  previous_Yvalues + delta * (Yin - previous_Yvalues );


	previous_Xvalues = Xout;
	previous_Yvalues = Yout;




}

/**
 * This method shifts the values in the values list.
 */

void shiftValues(float *values,int frameWindow){

	for ( int i = 0; i < frameWindow -1 ; i++)
		values[i] = values[i+1];

}

/**
 * This method executes the average smoothing algorithm using the variables
 * passed by parameter (Xin & Yin).
 */

void FIRfilter::runAverageSmoothing(int Xin, int Yin, int & Xout, int & Yout)
{


	/*
	 * tags: Exponential smoothing, wikipedia
	 *
	 */

	if ( active >= frameWindow){

	Xout = previousXValues[frameWindow-1] + ( (Xin -previousXValues[frameWindow-1 - k_factor])/ k_factor) ;
	Yout = previousYValues[frameWindow-1] + ( (Yin -previousYValues[frameWindow-1 - k_factor])/ k_factor) ;

    shiftValues(previousXValues,frameWindow);
    shiftValues(previousYValues,frameWindow);

    previousXValues[frameWindow-1] = Xout;
    previousYValues[frameWindow-1] = Yout;


	}
	else{

		previousXValues[active] = Xin;
		previousYValues[active] = Yin;

		active++;


	}



}







