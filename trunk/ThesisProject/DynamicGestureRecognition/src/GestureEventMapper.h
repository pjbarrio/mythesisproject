
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
#include "vector.h"
class GestureEventMapper {

public:
	bool addAssociation(Gesture*,Event*,bool,bool&);
	void removeAssociation(Gesture*,Event*);
	Event* getEvent(Gesture *);
	Association* getAssociation(Gesture*,Event*);
	static GestureEventMapper *getInstance();
	static void deleteInstance();
	void begin();
	bool hasNext();
	void next();
	Association* getActualAssociation();
private:
	map<Gesture*,vector<Association*>* >::iterator mapIterator;
	vector<Association*>::iterator vectorIterator;
	static GestureEventMapper *instance;
	map<Gesture*,vector<Association*>* > *associationTable;
    map<Gesture*,vector<Association*>* > *getAssociationTable() const {return associationTable;}
    GestureEventMapper();
    ~GestureEventMapper();
    Association* getActiveAssociationFromVector(vector<Association*>*);
    Association* getAssociationFromVector(Event*,vector<Association*>*);
    bool addAssociationToVector(Association*,vector<Association*>*,bool&);
    void removeAssociationFromVector(Event*,vector<Association*>*);
};

#endif /* GESTUREEVENTMAPPER_H_ */
