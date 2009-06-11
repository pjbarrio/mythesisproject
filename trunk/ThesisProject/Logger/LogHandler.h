/**
 * LogHandler.h
 *
 *  Created on: 05-feb-2009
 *      \author  Timpa
 *
 * This class has the responsabiliy of provide an interface
 * to handle the log file.
 */

#ifndef LOGHANDLER_H_
#define LOGHANDLER_H_



#include "iostream.h"

#include <time.h>

#include <fstream.h>


using namespace std;

class LogHandler {
public:
	LogHandler();
	virtual ~LogHandler();

	void initLogger();

	void addEntry(std::string component, std::string newEntry);

	void closeLogger();

private:

	ofstream log;
	std::string lastComponent;
};

#endif /** LOGHANDLER_H_ */
