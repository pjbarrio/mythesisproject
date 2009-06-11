/**
 * FilterHandler.h
 *
 *  Created on: 05-feb-2009
 *      \author  Timpa
 *
 * This class has the responsability of managing the pipe&filter
 * process during the application execution.
 */

#ifndef FILTERHANDLER_H_
#define FILTERHANDLER_H_

#include "cv.h"

#include "ImageFilter.h"

#include "GrayFilter.h"
#include "DownSamplingFilter.h"
#include "SkinFilter.h"
#include "FIRfilter.h"

#include "..\Logger\LogHandler.h"

class FilterHandler {
public:
	FilterHandler(LogHandler*);
	virtual ~FilterHandler();

	IplImage* runPreFilters(IplImage*);

	int getSkinCount(){return skinCount;};

	void runLowPassFilter(int Xin,int Yin,int &Xout,int &Yout);

	void runAverageSmoothing (int Xin,int Yin,int &Xout,int &Yout);

	double getSkinThreshold() const {return skinThreshold;}

    void setSkinThreshold(double skinThreshold){this->skinThreshold = skinThreshold;}

    IplImage* getSkinImage(IplImage*);

    void setSkinMaskFile(std::string SkinMaskFile){this->SkinMaskFile = SkinMaskFile;};

    void init();
    int getSkinDelta() const{return SkinDelta;}

    void setSkinDelta(int SkinDelta){this->SkinDelta = SkinDelta;}

private:

	ImageFilter *prefilters;

	IplImage* filteredImages;

	int filters_count;

	GrayFilter *gf;
	DownSamplingFilter *dsf;
	SkinFilter *sf;
	FIRfilter *ff;

	IplImage* first_filter;
	IplImage* second_filter;
	IplImage* third_filter;

	int skinCount;

	double skinThreshold;

	LogHandler* logger;

	std::string SkinMaskFile;

	int SkinDelta;

	std::string componentName;


};

#endif /** FILTERHANDLER_H_ */
