/*
 * CoordsGetter.cpp
 *
 *  Created on: 14/02/2009
 *      Author: Pablo
 */

#include "CoordsGetter.h"

/*
 * This method saves the buffer associated. This is the
 * buffer used to obtain the coords.
 */

CoordsGetter::CoordsGetter(Buffer_PC* buf) {
	this->buf = buf;
}

/*
 * This method dereferences the buffer.
 */

CoordsGetter::~CoordsGetter() {
	buf = 0;
}

/*
 * This Method recover the x,y,z tuple from the buffer
 */
void CoordsGetter::getNextCoords(double & x, double & y, double & t)
{
	buf->getCoords(x,y,t);
}


