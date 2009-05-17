/*
 * DTWData.h
 *
 *  Created on: 24/01/2009
 *      Author: Pablo
 *
 *  This class is a set of pairs <x,y> which will be used to represent one serie.
 */


#ifndef DTWDATA_H_
#define DTWDATA_H_

#include "list.h"

class DTWData {


public:
	DTWData();
	virtual ~DTWData();
	void addNewXYPair(double x,double y);
	void removeLastXYPair();
	int getXYPairCount();
	void begin();
	bool hasNext();
	void next();
	double getX();
	double getY();
	void clean();


private:
	list<double> *xvalues;
	list<double> *yvalues;
	list<double> *getXvalues() const {return xvalues;}
	list<double> *getYvalues() const {return yvalues;}
	list<double>::iterator xIterator;
	list<double>::iterator yIterator;
	list<double>::iterator getXIterator() const {return xIterator;}
	list<double>::iterator getYIterator() const {return yIterator;}
};

#endif /* DTWDATA_H_ */
