

/**
 * InitTracker.h
 *
 *  Created on: 29/03/2009
 *      \author  Timpa
 *
 *  This class represents the producer thread. I will call the
 *  neuronal network to recognize the hand position.
 */

#ifndef INITTRACKER_H_
#define INITTRACKER_H_

#include "../CommonProject/src/CoordsSaver.h"
#include "../Utils/SystemInfo.h"
#include "../CommonProject/InterfaceWorker/InitializerCreator.h"
#define _WIN32_WINNT 0x0501

#include "..\Camera\CamHandler.h"

#include "..\NeuralNetwork\NeuralNet.h"

#include "..\Filters\FilterHandler.h"

#include "..\Utils\ImageUtilities.h"

#include "..\ConfigurationHandler\ConfigHandler.h"

#include "..\stabilizers\LightStabilizer.h"

#include "..\Logger\LogHandler.h"

#include "iostream.h"

#include "cv.h"

#include <windows.h>

class InitTracker:public InitializerCreator {
public:

	InitTracker(CoordsSaver*,SystemInfo*,Camera*);
	virtual ~InitTracker();
	int start();

private:
	CoordsSaver* coordSaver;
	SystemInfo* sysInfo;
	Camera* cam;
	int ww,wh;
};

#endif /** INITTRACKER_H_ */
