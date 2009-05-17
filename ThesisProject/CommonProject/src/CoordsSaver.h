/*
 * CoordsSaver.h
 *
 *  Created on: 14/02/2009
 *      Author: Pablo
 *
 *  This class saves the coord in such buffers as getter are actives
 */

#ifndef COORDSSAVER_H_
#define COORDSSAVER_H_

#include "Buffer_PC.h"
#include "vector.h"

class CoordsSaver {
public:
	CoordsSaver();
	virtual ~CoordsSaver();
	void saveCoords(double,double);
	void addNewBuffer(Buffer_PC* );
	void finishCoordSaver();
public:
	vector<Buffer_PC*> *buffers;
};

#endif /* COORDSSAVER_H_ */
