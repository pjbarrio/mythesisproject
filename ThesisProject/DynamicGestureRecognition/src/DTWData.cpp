/*
 * DWTData.cpp
 *
 *  Created on: 24/01/2009
 *      Author: Pablo
 */

#include "DTWData.h"
#include "iostream"

/*
 * This method creates two vectors which will be used to represent
 * the group of pairs internally.
 */

DTWData::DTWData() {
	cout << "Hello DTWData\n";
	xvalues = new list<double>();
	yvalues = new list<double>();
}

/*
 * This method deletes the vectors instances created in the constructor
 * method.
 */

DTWData::~DTWData() {
	cout << "Bye DTWData\n";

	delete(xvalues);
	delete(yvalues);
}

/*
 * This method insert a new <x,y> pair in the serie.
 */

void DTWData::addNewXYPair(double x, double y)
{
	getXvalues()->push_back(x);
	getYvalues()->push_back(y);
}


/*
 * This method returns the size of the serie
 */

int DTWData::getXYPairCount()
{
	return getXvalues()->size();
}

/*
 * This method returns the X Value from the actual position in the serie
 */

double DTWData::getX()
{
	return *getXIterator();
}

/*
 * This method set the vectors's iterator to the beginning to start
 * the iterating process.
 */

void DTWData::begin()
{
	xIterator = getXvalues()->begin();
	yIterator = getYvalues()->begin();
}

/*
 * This method returns true if it exists a value in the actual X and Y variables
 */

bool DTWData::hasNext()
{
	return (getXIterator() != getXvalues()->end());
}

/*
 * This method advance in the iterators x and y
 */
void DTWData::next()
{
	xIterator++;
	yIterator++;
}

/*
 * This method returns the Y Value from the actual position in the serie
 */

double DTWData::getY()
{
	return *getYIterator();
}

/*
 * This method removes the last added pair from the vectors
 */
void DTWData::removeLastXYPair()
{
	getXvalues()->pop_back();
	getYvalues()->pop_back();
}

/*
 * This method cleans the arrays containing data.
 */

void DTWData::clean()
{
	getXvalues()->clear();
	getYvalues()->clear();
}























