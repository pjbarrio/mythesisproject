/*
 * CombinedKeyPressed.h
 *
 *  Created on: 04/05/2009
 *      Author: Pablo
 *
 *  This class is an special kind of PressCharEvent. It
 *  represents the combination of keys. One example is Alt+Tab.
 */

#ifndef COMBINEDKEYPRESSED_H_
#define COMBINEDKEYPRESSED_H_

#include "PressCharEvent.h"
#include "windows.h"

class CombinedKeyPressed: public PressCharEvent {
public:
	CombinedKeyPressed(char*,BYTE,PressCharEvent*,std::string);
	virtual ~CombinedKeyPressed();
	int execute();
	bool writeXML(QXmlStreamWriter*);
	bool writeKeyXML(QXmlStreamWriter*);
private:
	PressCharEvent* SecondKeyPressed;
};

#endif /* COMBINEDKEYPRESSED_H_ */
