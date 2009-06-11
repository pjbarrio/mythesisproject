
using namespace std;
/**
 * DTWDataHandler.h
 *
 *  Created on: 06/02/2009
 *      \author  Pablo
 *
 * This class was created with the purpose of isolate the DTWData from the
 * structure in memory
 *
 */

#ifndef DTWDATAHANDLER_H_
#define DTWDATAHANDLER_H_

#include "DTWData.h"
#include "C:/MinGW/include/c++/3.4.5/bits/stringfwd.h"

class DTWDataHandler {
public:
	DTWDataHandler();
	~DTWDataHandler();
	static DTWData* createDWTDataFromFile(const char*);
	static void DTWDataToDouble(DTWData*,double*&,double*&);

private:
	static void splitString(string,string,string*,string*);
};

#endif /** DTWDATAHANDLER_H_ */
