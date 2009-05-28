/*
 * gestureparameter.h
 *
 *  Created on: 25/05/2009
 *      Author: Pablo
 *
 * This GUI class provides the interface to set the Gesture
 * Recognition Parameters.
 */

#ifndef GESTUREPARAMETER_H
#define GESTUREPARAMETER_H

#include <QtGui/QDialog>
#include "ui_gestureparameter.h"

class GestureParameter : public QDialog
{
    Q_OBJECT

public:
    GestureParameter(QWidget *parent = 0);
    ~GestureParameter();

private:
    Ui::GestureParameterClass ui;

private slots:
	void setDetectedCount(int);
	void setMaxRelatedRatio(int);
};

#endif // GESTUREPARAMETER_H
