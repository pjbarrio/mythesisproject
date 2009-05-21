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
#include "../../DynamicGestureRecognition/src/GestureModel.h"
#include "../../DynamicGestureRecognition/src/EventModel.h"

class AddAsociation : public QDialog
{
    Q_OBJECT

public:
    AddAsociation(QWidget *parent = 0);
    ~AddAsociation();

    /*
     * This method returns the associated gestures in order.
     */

    QList<QString*>* getGestures() const {return gestures;}

    /*
     * This method returns the associated events in order.
     */

    QList<QString*>* getEvents() const {return events;}


    int exec(GestureModel*,EventModel*,EventModel*,EventModel*,EventModel*);

private:
    Ui::AddAsociationClass ui;
    QList<QString*>* gestures;
    QList<QString*>* events;
    void setGestures(QList<QString*>* gestures) {this->gestures = gestures;}
    void setEvents(QList<QString*>* events) {this->events = events;}
    void fillGestureList(GestureModel*);
    void fillEventList(EventModel*);
    void initVariables();
    QString* gstring;
    QString* estring;
private slots:
	void saveEventClicked(QListWidgetItem*);
	void saveGestureClicked(QListWidgetItem*);
	void addSelectedItems();
};

#endif // ADDASOCIATION_H
