/*
 * ExecuteApplication.h
 *
 *  Created on: 04/05/2009
 *      Author: Pablo
 *
 * This class implements and Event that trigger an execution of
 * an application.
 */

#ifndef EXECUTEAPPLICATION_H_
#define EXECUTEAPPLICATION_H_

#include "../src/Event.h"
#include "C:/MinGW/include/c++/3.4.5/bits/stringfwd.h"


class ExecuteApplication: public Event {
public:
	ExecuteApplication(const char*,std::string*,std::string*);
	virtual ~ExecuteApplication();
	int execute();
	bool writeXML(QXmlStreamWriter*);
private:
	std::string* appName;
	std::string* args;
};

#endif /* EXECUTEAPPLICATION_H_ */
