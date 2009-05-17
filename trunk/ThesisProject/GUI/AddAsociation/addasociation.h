/*
 * addasociation.h
 *
 *  Created on: 05/05/2009
 *      Author: Pablo
 *
 * This class offer the user the behaviour to add
 * new <Gesture,Event> mapping.
 */

#ifndef ADDASOCIATION_H
#define ADDASOCIATION_H

#include <QtGui/QDialog>
#include "ui_addasociation.h"

class AddAsociation : public QDialog
{
    Q_OBJECT

public:
    AddAsociation(QWidget *parent = 0);
    ~AddAsociation();

    /*
     * This method returns the associated gestures in order.
     */

    QList<QString*> getGestures() const {return gestures;}
    void setGestures(QList<QString*> gestures) {this->gestures = gestures;}

    /*
     * This method returns the associated events in order.
     */

    QList<QString*> getEvents() const {return events;}
    void setEvents(QList<QString*> events) {this->events = events;}

private:
    Ui::AddAsociationClass ui;
    QList<QString*> gestures;
    QList<QString*> events;
};

#endif // ADDASOCIATION_H
