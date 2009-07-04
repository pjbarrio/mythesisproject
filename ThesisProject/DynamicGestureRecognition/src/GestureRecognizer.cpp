/**
 * GestureRecognizer.cpp
 *
 *  Created on: 01/02/2009
 *      \author  Pablo
 */

#include "GestureRecognizer.h"
#include "GestureModelHandler.h"

/**
 * This constructor method saves the gestureModel passed by parameter.
 */

GestureRecognizer::GestureRecognizer(GestureModel* gestureModel) {
	cout << "Hello Gesture Recongnizer\n";
	this->dtwAlgorithm = gestureModel->getDtwAlgorithm();
	this->gestureModel = gestureModel;

}

/**
 * This destructor method dereferences the variables used internally.
 */

GestureRecognizer::~GestureRecognizer() {
	cout << "Bye Gesture Recongnizer\n";

	dtwAlgorithm = 0;
	gestureModel = 0;
}

/**
 * This method return the most similar Gesture if it is as similar as we want or returns
 * a NonGestureDetected if no gesture in the gesture Model match whit it.
 */

Gesture *GestureRecognizer::getRecognizedGesture(DTWData *txData, DTWData *tyData)
{
	//TODO Here we could apply a LowerBound Algorithm

	Gesture *rt = 0;
	bool found = false;
	getGestureModel()->begin();
	double txdtw;
	double tydtw;

	while(getGestureModel()->hasNext() && !found){

		Gesture *auxGesture = getGestureModel()->getNextGesture();

		DTWData* auxTx = auxGesture->getTx();

		txdtw = getDtwAlgorithm()->computeDTWValue(auxTx,txData);

		cout << "\nComparación <T , X> " << txdtw << "\n";

		if (getDtwAlgorithm()->acceptDTWValue(txdtw)){

			DTWData* auxTy = auxGesture->getTy();

			tydtw = getDtwAlgorithm()->computeDTWValue(auxTy,tyData);

			cout << "\nComparación <T , Y> " << tydtw << "\n";

			if (getDtwAlgorithm()->acceptDTWValue(tydtw)){

				found = true;

				rt = auxGesture;
			}
		}

		getGestureModel()->next();
	}

	if (rt==0)
		rt = GestureModelHandler::getNoGestureDetectedInstance();

	return rt;



}


