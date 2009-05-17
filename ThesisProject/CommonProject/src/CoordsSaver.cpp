/*
 * CoordsSaver.cpp
 *
 *  Created on: 14/02/2009
 *      Author: Pablo
 */

#include "CoordsSaver.h"

/*
 * This method creates an empty list which will store the buffers
 * where the producer will write the coords detected.
 */

CoordsSaver::CoordsSaver() {
	buffers = new vector<Buffer_PC*>;
}

/*
 * This method deletes the buffer list.
 */

CoordsSaver::~CoordsSaver() {
	delete(buffers);
}

/*
 * This methods save the coords in every buffer it has.
 */

void CoordsSaver::saveCoords(double x, double y)
{
	vector<Buffer_PC*>::iterator it = buffers->begin();

	Buffer_PC* auxBuffer;

	while (it != buffers->end()){

		auxBuffer = *it;

		auxBuffer->putCoords(x,y);

		it++;
	}


}

/*
 * This Method adds a new buffer to the buffer's array.
 */

void CoordsSaver::addNewBuffer(Buffer_PC *buffer)
{
	buffers->push_back(buffer);
}

/*
 * This Method informs that capturing has finished
 */

void CoordsSaver::finishCoordSaver(){
	saveCoords(-1,-1);
}
