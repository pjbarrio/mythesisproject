/*
 * DoNothingEvent.h
 *
 *  Created on: 01/02/2009
 *      Author: Pablo
 *
 *  This Event is triggered when no matching gesture has been detected
 */

#ifndef DONOTHINGEVENT_H_
#define DONOTHINGEVENT_H_

#include "../src/Event.h"

class DoNothingEvent: public Event {
public:
	DoNothingEvent();
	virtual ~DoNothingEvent();
	int execute();
	bool writeXML(QXmlStreamWriter*);
};

#endif /* DONOTHINGEVENT_H_ */
