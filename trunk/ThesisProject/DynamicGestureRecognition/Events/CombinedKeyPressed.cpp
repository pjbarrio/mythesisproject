/**
 * CombinedKeyPressed.cpp
 *
 *  Created on: 04/05/2009
 *      \author  Pablo
 */

#include "CombinedKeyPressed.h"
#include "iostream.h"

/**
 * This constructor method saves the PressCharEvent object. This object represent the secondKey to be pressed.
 */

CombinedKeyPressed::CombinedKeyPressed(const char* id,BYTE keyPressCode,PressCharEvent* secondPressChar,std::string key):PressCharEvent(id,keyPressCode,key) {

	this->SecondKeyPressed = secondPressChar;

}

/**
 * This method dereferences the second PressCharEvent.
 */

CombinedKeyPressed::~CombinedKeyPressed() {
	this->SecondKeyPressed = 0;
}

/**
 * This method implements the key press event and executes it functionality.
 * It press the first key and the second key (which could be another combination) and release both.
 */

int CombinedKeyPressed::execute(){
	keybd_event(keyPressCode, 0, 0, 0);

	SecondKeyPressed->execute();

	keybd_event(keyPressCode, 0, KEYEVENTF_KEYUP, 0);

	return EXIT_SUCCESS;
}

/**
 * This method writes the Event in a xml file using the tag "Event"
 */

bool CombinedKeyPressed::writeXML(QXmlStreamWriter*  xmlWriter){

	xmlWriter->writeStartElement("Event");

	xmlWriter->writeAttribute("id",QString(this->getId().c_str()));

	this->writeXML(xmlWriter);

	xmlWriter->writeEndElement();

	return true;

}

/**
 * This method writes the key in XML using the xmlWriter passed by
 * parameter.
 */

bool CombinedKeyPressed::writeKeyXML(QXmlStreamWriter* xmlWriter){

	xmlWriter->writeTextElement("Key",QString(this->key.c_str()));

	SecondKeyPressed->writeKeyXML(xmlWriter);

	return true;
}
