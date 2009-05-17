/*
 * ExecuteApplication.cpp
 *
 *  Created on: 04/05/2009
 *      Author: Pablo
 */

#include "ExecuteApplication.h"
#include "iostream.h"
#include "windows.h"
#include <tchar.h>

/*
 * This method saves the application file and the arguments written by the user.
 */

ExecuteApplication::ExecuteApplication(char* id,std::string* appName, std::string* appArgs):Event(id) {
	this->appName = appName;

	this->args = appArgs;

}

/*
 * This method dereferences the files used internally.
 */

ExecuteApplication::~ExecuteApplication() {
	appName = 0;
	args = 0;
}

/*
 * This method executes the application using the args. The application is executed in
 * a maximized window.
 */

int ExecuteApplication::execute(){

	ShellExecuteA(NULL, NULL, _T(appName->c_str()), _T(args->c_str()), NULL, SW_MAXIMIZE);

	return EXIT_SUCCESS;
}

/*
 * This method writes the Event in a file using the xmlWriter object using
 * the tag "Event".
 */

bool ExecuteApplication::writeXML(QXmlStreamWriter* xmlWriter){

	xmlWriter->writeStartElement("Event");

	xmlWriter->writeAttribute("id",QString(this->getId()));

	xmlWriter->writeTextElement("App",QString(this->appName->c_str()));

	xmlWriter->writeTextElement("Args",QString(this->args->c_str()));

	xmlWriter->writeEndElement();

	return true;
}
