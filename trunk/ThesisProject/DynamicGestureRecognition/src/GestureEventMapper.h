
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


#include "Gesture.h"
#include "map.h"
#include "Association.h"

class GestureEventMapper {

public:
	void addAssociation(Gesture*,Event*,bool);
	Event* getEvent(Gesture *);
	Association* getAssociation(Gesture*);
	static GestureEventMapper *getInstance();
	static void deleteInstance();
private:
	static GestureEventMapper *instance;
	map<Gesture*,Association*> *associationTable;
    map<Gesture*,Association*> *getAssociationTable() const {return associationTable;}
    GestureEventMapper();
    ~GestureEventMapper();
};

#endif /* GESTUREEVENTMAPPER_H_ */
