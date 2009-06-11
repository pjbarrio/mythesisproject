/**
 * FilterHandler.cpp
 *
 *  Created on: 05-feb-2009
 *      \author  Timpa
 */

#include "FilterHandler.h"

#include "ImageFilter.h"


#include <sstream>
#include <fstream>
#include <iomanip>

/**
 * This method saves the LogHandler reference to log every event
 * that occur in this class.
 */

FilterHandler::FilterHandler(LogHandler* logger) {

	 this->logger = logger;

	 componentName = "FilterHandler";

}

/**
 * This method dereferences the logger instance.
 */

FilterHandler::~FilterHandler() {
	this->logger = 0;
}

/**
 * This method initializes the variables and instances used
 * during the pipe&filter process.
 */

void FilterHandler::init(){

		filters_count = 3;

		prefilters = new ImageFilter[filters_count];

		filteredImages = new IplImage[filters_count+1];


		 gf  = new GrayFilter();

		 dsf = new DownSamplingFilter();

		 sf  = new SkinFilter();



		 sf->setSkinMaskFile(SkinMaskFile);

		 sf->setDelta(SkinDelta);


		 if ( !sf->skinValuesGetter() ){

			 logger->addEntry(componentName,"Failed to load Skin Mask. Using Default Values");
			 logger->addEntry(componentName,"Default Values--> Hue:11 -- Sat:106 -- Delta:42");

			 sf->seHValue(11);
			 sf->setSValue(106);
			 sf->setDelta(42);

		 }
		 else
		 {

			 logger->addEntry(componentName,"Skin Mask loaded succesfully");

			 std::string s;
			 std::stringstream out;
			 out << sf->getHValue();
		     s = out.str();

			 logger->addEntry(componentName,"Hue Value "  +s);


			 std::stringstream outt;
			 outt << sf->getSValue();
			 s = outt.str();

			 logger->addEntry(componentName,"Sat Value "  +s);



			 std::stringstream outtt;
			 outtt << sf->getDelta();
			 s = outtt.str();

			 logger->addEntry(componentName,"Hue Value "  +s);

		 }

		 ff = new FIRfilter();



}

/**
 * This method applies the skin filter and the DownSampling filter
 * to the image in the paramter list.
 */

IplImage *FilterHandler::runPreFilters(IplImage *scr)
{

	  first_filter  = sf->applyFilter(scr,skinCount);

	  second_filter = dsf->applyFilter(first_filter);

	  cvReleaseImage(&first_filter);

	return second_filter;



	/**
	filteredImages[0] = *scr;

	for ( int i = 0 ; i < filters_count; i ++){



			IplImage *img    = &filteredImages[i];

			IplImage *imgret = prefilters[i].applyFilter(img);

			filteredImages[i+1] = *imgret;

	}

	return &filteredImages[filters_count+1];*/

}

/**
 * This method applies the low pass filter to the input Xin,Yin and stores
 * their values in Xout,Yout respectivelly.
 */

void FilterHandler::runLowPassFilter(int Xin, int Yin, int &Xout, int &Yout)
{

	ff->runLowPassFilter(Xin,Yin,Xout,Yout);

}

/**
 * This method applies the Average Smoothin filter to the input Xin,Yin and stores
 * their values in Xout,Yout respectivelly.
 */

void FilterHandler::runAverageSmoothing(int Xin, int Yin, int & Xout, int & Yout)
{

	ff->runAverageSmoothing(Xin,Yin,Xout,Yout);

}

/**
 * This method applies the Skin filter to the image passed by parameter.
 */

IplImage *FilterHandler::getSkinImage(IplImage *scr)
{

	return sf->applyFilter(scr,skinCount);
}








