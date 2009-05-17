/*
 * DoNothingEvent.cpp
 *
 *  Created on: 01/02/2009
 *      Author: Pablo
 */

#include "DoNothingEvent.h"
#include "cstdlib"
#include "iostream.h"

DoNothingEvent::DoNothingEvent():Event("DoNothingEvent") {

	cout << "Hello Do Nothing Event\n";
}

DoNothingEvent::~DoNothingEvent() {
	cout << "Bye Do Nothing Event\n";

}

/*
 * this method does nothing. We need this.
 */

int DoNothingEvent::execute()
{
	return EXIT_SUCCESS;
}

/*
 * this method does nothing. We need this.
 */

bool DoNothingEvent::writeXML(QXmlStreamWriter*){
	return true;
}

