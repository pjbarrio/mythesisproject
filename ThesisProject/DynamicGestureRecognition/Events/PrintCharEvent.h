/**
 * PrintCharEvent.h
 *
 *  Created on: 01/02/2009
 *      \author  Pablo
 *
 * This class represent an event that show a message when is executed.
 */

#ifndef PRINTCHAREVENT_H_
#define PRINTCHAREVENT_H_

#include "../src/Event.h"

class PrintCharEvent: public Event {
public:
	PrintCharEvent(const char*,char*);
	virtual ~PrintCharEvent();
	int execute();
	bool writeXML(QXmlStreamWriter*);
private:
	char* message;
	char* getMessage() const {return message;}

};

#endif /** PRINTCHAREVENT_H_ */
