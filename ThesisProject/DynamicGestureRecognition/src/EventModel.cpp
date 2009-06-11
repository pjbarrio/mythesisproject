/**
 * EventModel.cpp
 *
 *  Created on: 03/05/2009
 *      \author  Pablo
 */

#include "EventModel.h"
#include "string.h"



/**
 * This method creates a vector which will store the event objects.
 */

EventModel::EventModel() {
	cout << "Hello Event Model\n";
	events = new vector<Event*>();
	doNothingEventInstance = 0;
}

/**
 * This method deletes the vector created in the constructor method.
 */

EventModel::~EventModel() {
	cout << "Bye Event Model\n";
	delete (events);
	doNothingEventInstance = 0;
}

/**
 * This method returns how many events it has got.
 */

int EventModel::getEventModelSize()
{
	return getEvents()->size();
}

/**
 * This method returns the Event in the actual position
 */

Event *EventModel::getNextEvent()
{
	return *getEventsIterator();
}

/**
 * This Method initializes the iterator
 */

void EventModel::begin()
{
	eventsIterator = getEvents()->begin();
}

/**
 * This Method notifies if it exists elements in the iterator.
 */

bool EventModel::hasNext()
{
	return (getEventsIterator() != getEvents()->end());
}

/**
 * This Method advance in the iterator to the next element.
 */

void EventModel::next()
{
	eventsIterator++;
}


/**
 * This method adds an Event in the model if it can be put in
 */
bool EventModel::addEvent(Event *event)
{

	getEvents()->push_back(event);
	return true;
}

/**
 * This method returns the Event corresponding to the id in the parameter
 * list.
 */

Event* EventModel::getEvent(std::string* id){
	this->begin();
	Event* ret;
	const char* strid = id->c_str();
	while (this->hasNext()){
		ret = this->getNextEvent();
		if (strcmp(strid,ret->getId().c_str()) == 0)
			return ret;
		this->next();
	}
	return 0;
}

/**
 * This method removes the Event from the model.
 */

void EventModel::removeEvent(std::string *id)
{
	Event* e = this->getEvent(id);
	if (e!=0)
		getEvents()->erase(getEventsIterator());
}
