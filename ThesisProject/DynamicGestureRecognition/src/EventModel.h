
/**
 * EventModel.h
 *
 *  Created on: 03/05/2009
 *      \author  Pablo
 *
 * This class is used to store the Events that the application will
 * use during the execution time.
 */

#ifndef EVENTMODEL_H_
#define EVENTMODEL_H_

#include "vector.h"
#include "Event.h"
#include "../Events/DoNothingEvent.h"

class EventModel {
public:
	EventModel();
	virtual ~EventModel();
	Event* getNextEvent();
	int getEventModelSize();
	void begin();
	bool hasNext();
	void next();
	bool addEvent(Event*);
	void removeEvent(std::string*);
	Event* getEvent(std::string*);

private:
	vector<Event*> *events;
	vector<Event*>::iterator eventsIterator;
	vector<Event*>::iterator getEventsIterator() const {return eventsIterator;}
	vector<Event*> *getEvents() const {return events;}
	void setEventsIterator(vector<Event*>::iterator eventsIterator){
		this->eventsIterator = eventsIterator;}
	DoNothingEvent *doNothingEventInstance;
};

#endif /** EVENTMODEL_H_ */
