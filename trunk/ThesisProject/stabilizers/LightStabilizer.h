/**
 * LightStabilizer.h
 *
 * Created on: 07-feb-2009
 *      \author  Timpa
 *
 * This class has the responsability of differentiate Hand's states
 * using skin pixel count.
 */

#ifndef LIGHTSTABILIZER_H_
#define LIGHTSTABILIZER_H_

#include "cv.h"
#include "highgui.h"

#include "..\Filters\filterHandler.h"

#include "..\Camera\CamHandler.h"

#include "..\Logger\LogHandler.h"
#include "../GUI/HandDiagnostic/handdiagnostic.h"


class LightStabilizer {
public:
	LightStabilizer(LogHandler*);
	virtual ~LightStabilizer();

	void runAmbientDiagnostic(CamHandler*,FilterHandler*,HandDiagnostic*);

    int getMax_frames_to_analize() const{return max_frames_to_analize;}

    void setMax_frames_to_analize(int max_frames_to_analize){this->max_frames_to_analize = max_frames_to_analize;}

    double getAverageSkinPixels() const{return averageSkinPixels;}

    double getSkinThreshold();

    float getThreshold_delta() const{return threshold_delta;}

    void setThreshold_delta(float threshold_delta){this->threshold_delta = threshold_delta;}

private:

	int max_frames_to_analize;

	double averageSkinPixels;

	double skinThreshold;

	float threshold_delta;

	std::string componentName;

	LogHandler* logger;
};

#endif /** LIGHTSTABILIZER_H_ */
