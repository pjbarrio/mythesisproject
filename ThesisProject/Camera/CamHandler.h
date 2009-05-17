/*
 * CamHandler.h
 *
 *  Created on: 04-feb-2009
 *      Author: Timpa
 *
 *  This class is the interface provided by the application to
 *  work with a webcam standard, isolating the application from
 *  technical specifications.
 */

#ifndef CAMHANDLER_H_
#define CAMHANDLER_H_

#include "cv.h"
#include "highgui.h"

#include "stdio.h"
#include "iostream.h"

#include "..\Logger\LogHandler.h"
#include "Camera.h"

class CamHandler : public Camera{
public:
	CamHandler(LogHandler*);
	virtual ~CamHandler();

	bool initCamDevice();

	bool stillTracking();

	void stopCamDevice();

	void showFrame(std::string,IplImage*);

	IplImage* retrieveFrame();

    std::string getThirdWindow() const{return thirdWindow;}

    void setThirdWindow(std::string thirdWindow){this->thirdWindow = thirdWindow;}

    std::string getFirstWindow() const{return firstWindow;}

    void setFirstWindow(std::string firstWindow){this->firstWindow = firstWindow;}

    std::string getSecondWindow() const{return secondWindow;}

    void setSecondWindow(std::string secondWindow){this->secondWindow = secondWindow;}

    CvCapture* getCam(){return capture;};

private:

	IplImage* resizedImage;

	IplImage* img;

	CvCapture* capture;

	bool still_tracking;

	std::string firstWindow;

	std::string secondWindow;

	std::string thirdWindow;

	std::string componentName;


};

#endif /* CAMHANDLER_H_ */
