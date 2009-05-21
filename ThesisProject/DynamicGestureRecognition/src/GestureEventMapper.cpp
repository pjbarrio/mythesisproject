/*
 * GestureEventMapper.cpp
 *
 *  Created on: 01/02/2009
 *      Author: Pablo
 */

#include "GestureEventMapper.h"
#include "Gesture.h"
#include "iostream.h"
#include "Event.h"
#include "../Events/DoNothingEvent.h"
#include "GestureModelHandler.h"

/*
 * This line initializes the instance of the GestureEventMapper class.
 */

GestureEventMapper* GestureEventMapper::instance = 0;

/*
 * This method creates a new map object which will associate Gestures and
 * Events.
 */

GestureEventMapper::GestureEventMapper() {
	cout << "Hello Gesture Event Mapper\n";
	associationTable = new map<Gesture*,Association*>();
}

/*
 * This method deletes the instance and the associationTable created in
 * the constructor method.
 */

GestureEventMapper::~GestureEventMapper() {
	cout << "Bye Gesture Event Mapper\n";

	deleteInstance();
	delete(associationTable);
}

/*
 * This method returns the GestureEventMapper Instance
 */
GestureEventMapper *GestureEventMapper::getInstance()
{
	if (instance==0){
		instance = new GestureEventMapper();
		Event *e = new DoNothingEvent();
		Gesture *g = GestureModelHandler::getNoGestureDetectedInstance();
		instance->addAssociation(g,e,true);
	}
	return instance;
}

/*
 * This method removes the instance. Next time you call getInstance you will get
 * a new instance
 */

void GestureEventMapper::deleteInstance()
{
	delete (instance);
	instance = 0;
}



/*
 * This method returns the Event associated to the gesture given in the parameter
 * list. If it doesn't exists returns 0
 */

Event *GestureEventMapper::getEvent(Gesture *gesture)
{
	map<Gesture*,Association*>::iterator it = getAssociationTable()->find(gesture);

	if (it == getAssociationTable()->end())
		return 0;

	Association* ass = getAssociationTable()->find(gesture)->second;

	if (ass->getActivated())
		return ass->getEvent();

	return 0;

}

/*
 * This method returns the association object associated to
 * a gesture.
 */

Association* GestureEventMapper::getAssociation(Gesture* gesture){
	map<Gesture*,Association*>::iterator it = getAssociationTable()->find(gesture);

	if (it == getAssociationTable()->end())
		return 0;

	Association* ass = getAssociationTable()->find(gesture)->second;

	return ass;
}


/*
 * This Method adds a new association with a Gesture and an Event
 */

void GestureEventMapper::addAssociation(Gesture *gesture, Event *event, bool activated)
{
	Association* ass = new Association();
	ass->setGesture(gesture);
	ass->setEvent(event);
	ass->setActivated(activated);

	(*getAssociationTable())[gesture] = ass;
}
