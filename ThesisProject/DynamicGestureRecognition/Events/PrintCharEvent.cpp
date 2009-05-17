/*
 * PrintCharEvent.cpp
 *
 *  Created on: 01/02/2009
 *      Author: Pablo
 */

#include "PrintCharEvent.h"
#include "iostream.h"

/*
 * This metod saves the message passed by parameter.
 */

PrintCharEvent::PrintCharEvent(char* id,char* s):Event(id) {
	cout << "Hello Print Char Event\n";
	this->message = s;
}

/*
 * This method dereferences the message variable.
 */

PrintCharEvent::~PrintCharEvent() {
	cout << "Bye Print Char Event\n";

	message = 0;
}

/*
 * This method writes the message in the standard out and return EXIT_SUCCESS.
 */

int PrintCharEvent::execute()
{
	cout << getMessage() << "\n";
	return EXIT_SUCCESS;
}

/*
 * This method does nothing. We need this.
 */

bool PrintCharEvent::writeXML(QXmlStreamWriter*){
	return true;
}


