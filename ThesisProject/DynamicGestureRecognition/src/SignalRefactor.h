/**
 * SignalRefactor.h
 *
 *  Created on: 24/01/2009
 *      \author  Pablo
 *
 *  This class has the responsability of refactorize the signal in case it is needed.
 */

#ifndef SIGNALREFACTOR_H_
#define SIGNALREFACTOR_H_

#include "DTWData.h"


class SignalRefactor {
public:
	SignalRefactor();
	virtual ~SignalRefactor();
	DTWData* refactorSignal(DTWData*);
private:


};

#endif /** SIGNALREFACTOR_H_ */
