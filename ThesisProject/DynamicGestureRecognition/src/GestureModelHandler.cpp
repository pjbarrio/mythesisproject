/**
 * GestureModelHandler.cpp
 *
 *  Created on: 06/02/2009
 *      \author  Pablo
 */

#include "GestureModelHandler.h"
#include "DTWDataHandler.h"
#include "../Gestures/NoGestureDetected.h"
#include "string.h"

using namespace std;

/**
 * This line creates a NoGestureDetected instance.
 */

NoGestureDetected* GestureModelHandler::noGestureDetected = new NoGestureDetected();

/**
 * This method creates an ifstream to read the GestureModel from the
 * file passed by parameter
 */

GestureModelHandler::GestureModelHandler(char *fileName)
{
	cout << "Hello Gesture Model Handler\n";
	gestureFile = new ifstream();
	gestureFile->open(fileName);
}

/**
 * This method deletes the ifstream object.
 */

GestureModelHandler::~GestureModelHandler()
{
	cout << "Bye Gesture Model Handler\n";

	delete (gestureFile);
}

/**
 * This method fills the model from the file in the constructor method
 */

bool GestureModelHandler::fillModel(GestureModel *gestureModel)
{


	DTWData *txSerie;
	DTWData *tySerie;

	string id;
	string txName;
	string tyName;

	if (gestureFile->good()){

		*gestureFile >> id;
		*gestureFile >> txName;
		*gestureFile >> tyName;


		while (!gestureFile->eof()){

			txSerie = DTWDataHandler::createDWTDataFromFile(txName.c_str());
			tySerie = DTWDataHandler::createDWTDataFromFile(tyName.c_str());

			gestureModel->addGesture(new Gesture(txSerie,tySerie,id.c_str()));

			*gestureFile >> id;
			*gestureFile >> txName;
			*gestureFile >> tyName;

		}
	}
	else{
		cout << "Cannot open File! \n";
		return false;
	}

	gestureFile->close();
	return true;
}

/**
 * This Method save the model in the parameter list on the File "fileName"
 */

bool GestureModelHandler::saveModel(GestureModel *gestureModel, char *fileName)
{
	//TODO saveModel in file
	return 0;
}






