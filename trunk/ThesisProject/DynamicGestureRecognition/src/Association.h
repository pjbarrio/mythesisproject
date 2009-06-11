#include "Event.h"
#include "Gesture.h"
/**
 * Association.h
 *
 *  Created on: 21/05/2009
 *      \author  Pablo
 *
 * This class stores an association beetween a Gesture, an Event
 * and their activation bool value.
 */

#ifndef ASSOCIATION_H_
#define ASSOCIATION_H_

class Association {
public:
	Association();
	virtual ~Association();

	/**
	 * This method returns the event Object.
	 */

	Event *getEvent() const {return event;}

	/**
	 * This method set the event Object.
	 */

    void setEvent(Event *event) {this->event = event;}

	/**
	 * This method returns the Gesture Object.
	 */

    Gesture *getGesture() const {return gesture;}

    /**
	 * This method sets the Gesture Object.
	 */

    void setGesture(Gesture *gesture){this->gesture = gesture;}

	/**
	 * This method returns the activated value.
	 */

    bool getActivated() const {return activated;}

    /**
	 * This method sets the activated value.
	 */

    void setActivated(bool activated){this->activated = activated;}

private:
	Event* event;
	Gesture* gesture;
	bool activated;
};

#endif /** ASSOCIATION_H_ */
