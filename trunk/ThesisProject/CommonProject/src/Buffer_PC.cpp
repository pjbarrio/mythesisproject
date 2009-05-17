/*
 * Buffer_PC.cpp
 *
 *  Created on: 30/03/2009
 *      Author: Pablo
 */

#include "Buffer_PC.h"
#include <iostream.h>

/*
 * This method calls the initialize method.
 */

Buffer_PC::Buffer_PC() {

	initialize();
}

/*
 * This method creates the lists which will store
 * the coords obtained by the associated producer.
 */

void Buffer_PC::initialize()
{
	firstCoords = true;
	xValues = new list<double>;
	yValues = new list<double>;
	tValues = new list<double>;
	size = 0;

}

/*
 * This method deletes the lists created to store the
 * coords.
 */

Buffer_PC::~Buffer_PC() {
	firstCoords = false;
	delete (xValues);
	delete (yValues);
	delete (tValues);
}

/*
 * This method saves the coordenates and the time they have arrived
 */

void Buffer_PC::putCoords(double x, double y)
{
	mutex.lock();

	if (firstCoords)
		start();
	end();

	xValues->push_back(x);
	yValues->push_back(y);
	tValues->push_back(secs);

	size++;

	mutex.unlock();

	bufferNotFull.wakeAll();

}

/*
 * This method returns the coordenates and the time they have arrived
 */

void Buffer_PC::getCoords(double & x, double & y, double & t)
{
	mutex.lock();

	while (size == 0)
		bufferNotFull.wait(&mutex);

	x = xValues->front();

	xValues->pop_front();

	y = yValues->front();

	yValues->pop_front();

	t = tValues->front();

	tValues->pop_front();

	size--;

	mutex.unlock();
}

/*
 * This Method initiates the clock
 */

void Buffer_PC::start(){

	t_ini = clock();
	firstCoords = false;

}



/*
 * This method saves on secs the difference beetween this time and the first time saved
 */

void Buffer_PC::end(){


	t_fin = clock();

	secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;

}

