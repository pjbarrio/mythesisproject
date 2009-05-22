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
	associationTable = new map<Gesture*,vector<Association*>* >();
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
	map<Gesture*,vector<Association*>* >::iterator it = getAssociationTable()->find(gesture);

	if (it == getAssociationTable()->end())
		return 0;

	vector<Association*>* associations = it->second;

	Association* ass = getActiveAssociationFromVector(associations);

	if (ass!=0)
		return ass->getEvent();

	return 0;

}

/*
 * This method returns the association object associated to
 * a gesture.
 */

Association* GestureEventMapper::getAssociation(Gesture* gesture, Event* event){
	map<Gesture*,vector<Association*>*>::iterator it = getAssociationTable()->find(gesture);

	if (it == getAssociationTable()->end())
		return 0;

	vector<Association*>* associations = it->second;

	Association* ass = getAssociationFromVector(event,associations);

	return ass;
}


/*
 * This Method adds a new association with a Gesture and an Event. Returns if
 * the value was added withow activated modifications.
 */

bool GestureEventMapper::addAssociation(Gesture *gesture, Event *event, bool activated)
{
	map<Gesture*,vector<Association*>*>::iterator it = getAssociationTable()->find(gesture);
	vector<Association*>* vec;
	if (it == getAssociationTable()->end())
		vec = new vector<Association*>();
	else
		vec = it->second;

	Association* ass = new Association();
	ass->setGesture(gesture);
	ass->setEvent(event);
	ass->setActivated(activated);

	bool ret = addAssociationToVector(ass,vec);

	(*getAssociationTable())[gesture] = vec;

	return ret;
}

/*
 * This method removes an association given the gesture
 * in it.
 */

void GestureEventMapper::removeAssociation(Gesture* gesture,Event* eve){
	map<Gesture*,vector<Association*>* >::iterator it = getAssociationTable()->find(gesture);

	if (it != getAssociationTable()->end()){
		removeAssociationFromVector(eve,it->second);
		if (it->second->size()==0)
			getAssociationTable()->erase(it);
	}
}

/*
 * This method returns the active association from a vector.
 */

Association* GestureEventMapper::getActiveAssociationFromVector(vector<Association*>* associations){
	vector<Association*>::iterator it = associations->begin();
	Association* aux;
	while (it != associations->end()){
		aux = *it;
		if (aux->getActivated())
			return aux;
		it++;
	}

	return 0;
}

/*
 * This method returns the association which has the Event instance
 * inside of it.
 */

Association* GestureEventMapper::getAssociationFromVector(Event* event,vector<Association*>* associations){
	vector<Association*>::iterator it = associations->begin();
	Association* aux;
	while (it != associations->end()){
		aux = *it;
		if (strcmp(aux->getEvent()->getId(),event->getId()) ==0)
			return aux;
		it++;
	}
	return 0;
}

/*
 * This method adds an association to a vector. In case the association
 * is active and there is an association active inside of the vector, the
 * associaton is stored in inactive form.
 */

bool GestureEventMapper::addAssociationToVector(Association* ass,vector<Association*>* associations){
	bool ret = false;

	if (ass->getActivated()){

		//Verify active association
		Association* activeAssociation = getActiveAssociationFromVector(associations);
		if (activeAssociation!=0){
			ass->setActivated(false);
			ret = true;
		}
	}
	//Verify existent Gesture-Event Association
	Association* EventAssociation = getAssociationFromVector(ass->getEvent(),associations);
	if (EventAssociation==0){
		//Adds the association.
		associations->push_back(ass);
	}
	else{
		if (ass->getActivated()){
			//Activates the existing Gesture-Event Association
			EventAssociation->setActivated(true);
		}
	}

	return ret;

}

/*
 * This method removes the association which have the Event instance
 * inside of it.
 */

void GestureEventMapper::removeAssociationFromVector(Event* event,vector<Association*>* associations){
	Association* ass = getAssociationFromVector(event,associations);
	if (ass==0)
		return;
	vector<Association*>::iterator it = associations->begin();
	Association* aux;
	while (it != associations->end()){
		aux = *it;
		if (aux==ass){
			associations->erase(it);
			return;
		}
		it++;
	}
}

/*
 * This method sets the iterator to its first position
 */

void GestureEventMapper::begin(){
	mapIterator = associationTable->begin();
	if (mapIterator!=getAssociationTable()->end())
		vectorIterator = mapIterator->second->begin();
}

/*
 * This method returns if there are more Associations to look
 * for
 */

bool GestureEventMapper::hasNext(){
	if (vectorIterator != mapIterator->second->end())
		//more in actual gesture.
		return true;
	else {
		if (mapIterator != getAssociationTable()->end())
			return true;
	}
	return false;
}

/*
 * This method advances the iterator inside the map.
 */
void GestureEventMapper::next(){
	//advance in actual vector.
	vectorIterator++;
	if (vectorIterator == mapIterator->second->end()){
		//advance in map iterator.
		mapIterator++;
		//updates vectorIterator.
		if (mapIterator!=getAssociationTable()->end()){
			vectorIterator = mapIterator->second->begin();
			if (vectorIterator == mapIterator->second->end())
				this->next();
		}
	}
}

/*
 * This method returns the selected Association
 */
Association* GestureEventMapper::getActualAssociation(){
	return *vectorIterator;
}
