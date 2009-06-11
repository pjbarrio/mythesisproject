/**
 * DTWDataHandler.cpp
 *
 *  Created on: 06/02/2009
 *      \author  Pablo
 */

#include "DTWDataHandler.h"
#include "string"
#include "stdlib.h"
#include "fstream.h"
#include "iostream"

using namespace std;

DTWDataHandler::~DTWDataHandler()
{
	cout << "Hello DTWDataHandler\n";
}

DTWDataHandler::DTWDataHandler()
{
	cout << "Bye DTWDataHandler\n";
}

/**
 * This Method Creates a DTWData structure from file in the parameter list
 * "fileName"
 */


DTWData *DTWDataHandler::createDWTDataFromFile(const char* fileName)
{
	DTWData *ret = 0;

	ifstream in;

	in.open(fileName);

	string s1,s2;

	double d1,d2;

	if (in.good()){

		string auxString;

		ret = new DTWData();

		in >> auxString;

		while (!in.eof()){

			splitString(auxString,",",&s1,&s2);

			d1 = strtod(s1.c_str(),0);

			d2 = strtod(s2.c_str(),0);

			ret->addNewXYPair(d1,d2);

			in >> auxString;

		}

	}

	else
		cout << "File " << fileName << " couldn't be opened! \n";

	in.close();

	return ret;
}

/**
 * This method returns the data of the dtwData in two double[] structures
 */

void DTWDataHandler::DTWDataToDouble(DTWData *dtwData, double *&xdata,double *&ydata)
{
	xdata = new double[dtwData->getXYPairCount()];
	ydata = new double[dtwData->getXYPairCount()];

	dtwData->begin();

	int i = 0;

	while (dtwData->hasNext()){
		xdata[i] = dtwData->getX();
		ydata[i] = dtwData->getY();

		dtwData->next();

		i++;
	}

}

/**
 * This Method splits a string in 2 and returns these.
 */

void DTWDataHandler::splitString(string str, string seperater, string *first, string *second)
{
	int i = str.find(seperater);

	*first = str.substr(0,i);

	*second = str.substr(i+1,str.size());

}



