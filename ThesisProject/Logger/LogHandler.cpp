/**
 * LogHandler.cpp
 *
 *  Created on: 05-feb-2009
 *      \author  Timpa
 */

#include "LogHandler.h"

LogHandler::LogHandler() {

	;

}

LogHandler::~LogHandler() {
	;
}

/**
 * This method initializes the log file.
 */

void LogHandler::initLogger()
{

	log.open("log.txt",ios::out);

	char dateStr [9];
    char timeStr [9];
	_strdate( dateStr);
	_strtime( timeStr );

	log << "log created on " << dateStr << " "<< timeStr << "\n" << "\n";

}

/**
 * This method adds an entry to the log file. The entry has the following format:
 * "COMPONENT"
 * "Component's message"
 */

void LogHandler::addEntry(std::string component, std::string newEntry)
{

	log << "\n";

	if ( component != lastComponent ){

		lastComponent = component;
		log << "\n" << "--- " << component << " ---" << "\n";
	}

	log << "- " << newEntry;

	log << "\n";
}

/**
 * This method closes the file and writes it on hardDisk.
 */

void LogHandler::closeLogger()
{

	char dateStr [9];
    char timeStr [9];
	_strdate( dateStr);
	_strtime( timeStr );

	log << "\n"<<"log close on " << dateStr << " "<< timeStr;

	log.close();

}


