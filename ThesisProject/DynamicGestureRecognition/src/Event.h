/*
 * Event.h
 *
 *  Created on: 01/02/2009
 *      Author: Pablo
 *
 *  This Class represent the events which can be executed when the
 *  asociated gesture is detected
 *
 */

#ifndef EVENT_H_
#define EVENT_H_

#include <QXmlStreamWriter>
#include "string.h"

using namespace std;

class Event {
public:
	Event(const char*);
	virtual ~Event();

	/*
	 * This method produces an impact in the GUI application.
	 */

	virtual int execute() = 0;

	/*
	 * This method writes the event in an xml file using the
	 * QXmlStreamWriter object.
	 */

	virtual bool writeXML(QXmlStreamWriter*) = 0;
	string getId(){return id;};
private:
	string id;
};

#endif /* EVENT_H_ */
