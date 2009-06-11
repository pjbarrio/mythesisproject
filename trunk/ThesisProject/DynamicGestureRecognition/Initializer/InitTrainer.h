/**
 * InitTrainer.h
 *
 *  Created on: 08/05/2009
 *      \author  Pablo
 *
 * This class is used to work with the Training Method.
 * It interacts with the DTWData objects.
 */

#ifndef INITTRAINER_H_
#define INITTRAINER_H_

#include "../src/DTWData.h"
#include "../../CommonProject/src/CoordsGetter.h"
#include "../../CommonProject/InterfaceWorker/Initializer.h"

class InitTrainer: public Initializer {
public:
	InitTrainer(CoordsGetter*,DTWData*,DTWData*);
	virtual ~InitTrainer();
	void setNewInput(double,double,double);
	void init();
private:
	DTWData* dtwDataTX;
	DTWData* dtwDataTY;
};

#endif /** INITTRAINER_H_ */
