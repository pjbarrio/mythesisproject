
/*
 * GestureEventMapper.h
 *
 *  Created on: 01/02/2009
 *      Author: Pablo
 *
 *  This class maps one Gesture with an Event. This way we can make a gesture and an Event
 *  will be trigered.
 */
#ifndef GESTUREEVENTMAPPER_H_
#define GESTUREEVENTMAPPER_H_

#include "Event.h"
#include "Gesture.h"
#include "map.h"

class GestureEventMapper {

public:
	void addAssociation(Gesture*,Event*);
	Event *getEvent(Gesture *);
	static GestureEventMapper *getInstance();
	static void deleteInstance();
private:
	static GestureEventMapper *instance;
	map<Gesture*,Event*> *associationTable;
    map<Gesture*,Event*> *getAssociationTable() const {return associationTable;}
    GestureEventMapper();
    ~GestureEventMapper();
};

#endif /* GESTUREEVENTMAPPER_H_ */
