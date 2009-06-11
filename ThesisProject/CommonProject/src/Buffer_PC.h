/**
 * Buffer_PC.h
 *
 *  Created on: 30/03/2009
 *      \author  Pablo
 *
 * This class represents the buffer that is used to
 * synchronize the producer object and the consumer one.
 */

#ifndef BUFFER_PC_H_
#define BUFFER_PC_H_


#include <time.h>
#include <list.h>
#include "qmutex.h"
#include "qwaitcondition.h"
#include "qthread.h"




class Buffer_PC {
public:
	Buffer_PC();
	virtual ~Buffer_PC();
	void putCoords(double, double);
	void getCoords(double&, double&, double&);
	void initialize();
	void start();
	void end();
private:
	bool firstCoords;
	clock_t t_ini;
	clock_t t_fin;
	double secs;
	QMutex mutex;
	QWaitCondition bufferNotFull;
	list<double> *xValues;
	list<double> *yValues;
	list<double> *tValues;
	int size;
};

#endif /** BUFFER_PC_H_ */
