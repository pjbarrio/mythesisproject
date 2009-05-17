/*
 * OpenFileEvent.cpp
 *
 *  Created on: 04/05/2009
 *      Author: Pablo
 */

#include "OpenFileEvent.h"
#include "iostream.h"
#include "windows.h"
#include <tchar.h>

/*
 * This method saves the name of the file which will be opened later.
 */

OpenFileEvent::OpenFileEvent(char* id,std::string* file):Event(id) {
	this->file = file;
}

/*
 * This method dereferences the file variable.
 */

OpenFileEvent::~OpenFileEvent() {
	this->file = 0;
}

/*
 * This method open the file with its predetermined program setted by the
 * Operative System.
 */

int OpenFileEvent::execute(){
	ShellExecuteA(NULL, _T("open"), _T(file->c_str()), NULL, NULL, SW_MAXIMIZE);
	return EXIT_SUCCESS;
}

/*
 * This method writes the OpenFile Event using the xmlWriter in a
 * XML file using the tag "Event".
 */

bool OpenFileEvent::writeXML(QXmlStreamWriter* xmlWriter){
	xmlWriter->writeStartElement("Event");

	xmlWriter->writeAttribute("id",QString(this->getId()));

	xmlWriter->writeTextElement("File",QString(this->file->c_str()));

	xmlWriter->writeEndElement();

	return true;
}
