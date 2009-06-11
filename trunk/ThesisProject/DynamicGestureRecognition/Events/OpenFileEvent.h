/**
 * OpenFileEvent.h
 *
 *  Created on: 04/05/2009
 *      \author  Pablo
 *
 * This class implements the event which will open a file with its
 * predetermined by the operative System.
 */

#ifndef OPENFILEEVENT_H_
#define OPENFILEEVENT_H_

#include "../src/Event.h"
#include "C:/MinGW/include/c++/3.4.5/bits/stringfwd.h"


class OpenFileEvent: public Event {
public:
	OpenFileEvent(const char*,std::string*);
	virtual ~OpenFileEvent();
	int execute();
	bool writeXML(QXmlStreamWriter*);
private:
	std::string* file;
};

#endif /** OPENFILEEVENT_H_ */
