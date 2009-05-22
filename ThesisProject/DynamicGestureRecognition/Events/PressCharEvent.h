/*
 * PressCharEvent.h
 *
 *  Created on: 04/05/2009
 *      Author: Pablo
 *
 * This class is used to emulate that a Key has been pressed.
 */

#ifndef PRESSCHAREVENT_H_
#define PRESSCHAREVENT_H_

#include "windows.h"
#include "../src/Event.h"

class PressCharEvent: public Event {
public:
	PressCharEvent(const char*,BYTE,std::string);
	virtual ~PressCharEvent();
	int execute();
	bool writeXML(QXmlStreamWriter*);
	bool writeKeyXML(QXmlStreamWriter*);
protected:
	BYTE keyPressCode;
	std::string key;
};

#endif /* PRESSCHAREVENT_H_ */
