/**
 * CircularBuffer.cpp
 *
 *  Created on: 10/02/2009
 *      \author  Pablo
 */

#include "CircularBuffer.h"

/**
 * This constructor method resizes the vector to the variable
 * capacity passed by parameter and instantiate all internal variables.
 */

CircularBuffer::CircularBuffer(int capacity) {
	cout << "Hello Circular Buffer\n";

	this->values.resize(capacity);
	this->capacity = capacity;
	this->whereToAdd = 0;
	this->hasCompleted = false;
}

/**
 * this method clears the vector which contain the values and dereferences
 * the variables used during its use.
 */

CircularBuffer::~CircularBuffer() {
	cout << "Bye Circular Buffer\n";

	values.clear();
	capacity = 0;
	whereToAdd = 0;
	hasCompleted = false;
}

/**
 * This method adds a new value in the buffer
 */

void CircularBuffer::addValue(double value)
{
	this->values[whereToAdd] = value;

	incCircular(whereToAdd,1);

	if (whereToAdd == 0)
		hasCompleted = true;

}

/**
 * This method returns the number of values in the buffer.
 */

int CircularBuffer::size()
{
	if (hasCompleted)
		return Capacity();

	return whereToAdd;
}

/**
 * This method cleans the buffer
 */
void CircularBuffer::clear()
{
	this->values.clear();
	this->whereToAdd = 0;
	this->hasCompleted = false;
}

/**
 * This method returns the value at "pos" position
 */
double CircularBuffer::at(int pos)
{
	int aux = 0 ;
	if (hasCompleted)
		aux = whereToAdd;
	else
		aux = 0;

	incCircular(aux,pos);
	return this->values[aux];
}

/**
 * This method increase the value of the parameter "value" to represent the next position
 * in the buffer
 */
void CircularBuffer::incCircular(int & value,int inc)
{
	while (inc>capacity)
		inc -=capacity;

	value+=inc;

	if (value>=capacity)

		value=value-capacity;
}








