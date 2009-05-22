/*
 * PressCharEvent.cpp
 *
 *  Created on: 04/05/2009
 *      Author: Pablo
 */

#include "PressCharEvent.h"
#include "iostream.h"

/*
 * This method saves the keyCode and the string asociated to this keyCode.
 */

PressCharEvent::PressCharEvent(const char* id,BYTE keyPressCode,std::string key):Event(id) {
	this->keyPressCode = keyPressCode;
	this->key = key;
}

/*
 * This method dereferences the keyCode used and its string representation.
 */

PressCharEvent::~PressCharEvent() {
	keyPressCode = 0;
	key.clear();
}

/*
 * This method simulates the keyboard event.
 */

int PressCharEvent::execute()
{
	keybd_event(keyPressCode, 0, 0, 0);

	::Sleep(100);

	// Release Key

	keybd_event(keyPressCode, 0, KEYEVENTF_KEYUP, 0);

	return EXIT_SUCCESS;
}

/*
 * This method writes the Event using an "Event" tag using the xmlWriter
 * passed by parameter.
 */

bool PressCharEvent::writeXML(QXmlStreamWriter* xmlWriter){
	xmlWriter->writeStartElement("Event");

	xmlWriter->writeAttribute("id",QString(this->getId().c_str()));

	this->writeKeyXML(xmlWriter);

	xmlWriter->writeEndElement();

	return true;
}

/*
 * This method writes the key in the xml File associated to
 * xmlWriter using the tag "Key".
 */

bool PressCharEvent::writeKeyXML(QXmlStreamWriter* xmlWriter){

	xmlWriter->writeTextElement("Key",QString(this->key.c_str()));

	return true;
}
