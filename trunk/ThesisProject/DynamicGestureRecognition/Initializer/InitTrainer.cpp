/**
 * InitTrainer.cpp
 *
 *  Created on: 08/05/2009
 *      \author  Pablo
 */

#include "InitTrainer.h"

/**
 * This method saves the DTWData objects passed by parameter. They will store
 * the coords.
 */

InitTrainer::InitTrainer(CoordsGetter* cg, DTWData* tx, DTWData* ty):Initializer(cg) {
	this->dtwDataTX = tx;
	this->dtwDataTY = ty;
}

/**
 * This method dereferences the dtwData objects.
 */

InitTrainer::~InitTrainer() {
	this->dtwDataTX = 0;
	this->dtwDataTY = 0;
}

/**
 * This method adds coords to the DTWData objects.
 */

void InitTrainer::setNewInput(double x, double y, double t){
	dtwDataTX->addNewXYPair(t,x);
	dtwDataTY->addNewXYPair(t,y);
}

/**
 * This method do nothing, because the variables used
 * are instantiated in the constructor method.
 */

void InitTrainer::init(){
	;
}
