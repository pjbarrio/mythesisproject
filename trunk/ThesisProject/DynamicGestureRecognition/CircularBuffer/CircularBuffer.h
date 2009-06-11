/**
 * CircularBuffer.h
 *
 *  Created on: 10/02/2009
 *      \author  Pablo
 *
 * This class is a circular buffer. The size can be setted in the
 * constructor method.
 */

#ifndef CIRCULARBUFFER_H_
#define CIRCULARBUFFER_H_

#include "vector.h"
using namespace std;

class CircularBuffer {
public:
	CircularBuffer(int);
	virtual ~CircularBuffer();
	void addValue(double);
	int Capacity(){return capacity;};
	int size();
	void clear();
	double at(int);

private:
	void incCircular(int&,int);
	vector<double> values;
	int capacity;
	int whereToAdd;
	bool hasCompleted;
};

#endif /** CIRCULARBUFFER_H_ */
