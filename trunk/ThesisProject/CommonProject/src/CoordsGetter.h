
/**
 * CoordsGetter.h
 *
 *  Created on: 14/02/2009
 *      \author  Pablo
 *
 *  This class recovers the coords from the Shared Buffer
 */

#ifndef COORDSGETTER_H_
#define COORDSGETTER_H_
#include "Buffer_PC.h"

class CoordsGetter {
public:
	CoordsGetter(Buffer_PC*);
	virtual ~CoordsGetter();
	void getNextCoords(double&,double&,double&);
private:
	Buffer_PC* buf;
};

#endif /** COORDSGETTER_H_ */
