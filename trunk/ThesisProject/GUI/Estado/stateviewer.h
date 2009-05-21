/*
 * stateviewer.h
 *
 *  Created on: 05/05/2009
 *      Author: Pablo
 *
 * This GUI Class shows the state of the capturing process.
 * It shows the movement, the filtered image, hand State and
 * velocity and acceleration detected.
 */

#ifndef STATEVIEWER_H
#define STATEVIEWER_H

#include <QtGui/QDialog>
#include "ui_stateviewer.h"
#include "../../DynamicGestureRecognition/CircularBuffer/CircularBuffer.h"
#include <QList>
#include <QLabel>

class StateViewer : public QDialog
{
    Q_OBJECT

public:
    StateViewer(QWidget *parent = 0);
    ~StateViewer();

    /*
     * This method returns the list which represents the velocity graphical
     * equalizator.
     */

    QList<QLabel*>* getVelocityList(){return velocityList;};

    /*
     * This method returns the list which represents the acceleration graphical
     * equalizator.
     */

    QList<QLabel*>* getAccelerationList(){return accelerationList;};
    QLabel* getCoordXLabel(){return ui.XCoord;};
    QLabel* getCoordYLabel(){return ui.YCoord;};
    void setBufferXY(CircularBuffer* cbx,CircularBuffer* cb);
    QLabel* getHandPicture();
    paintMovement* getPaintMovement(){return ui.widget_4;};
    QLabel* getFilteredImage();
private:
	Ui::StateViewerClass ui;
	CircularBuffer* cbx;
	CircularBuffer* cby;
	QList<QLabel*>* velocityList;
	QList<QLabel*>* accelerationList;
	void createArrays();
	void createVelocityArray();
	void createAccelerationArray();
};

#endif // STATEVIEWER_H
