/**
 * paintmovement.h
 *
 *  Created on: 05/05/2009
 *      \author  Pablo
 *
 * This Widget class is used to draw the hand movement
 * captured by the tracker.
 */


#ifndef PAINTMOVEMENT_H
#define PAINTMOVEMENT_H

#include <QtGui/QWidget>
#include <QPaintEvent>
#include "ui_paintmovement.h"
#include "../../DynamicGestureRecognition/CircularBuffer/CircularBuffer.h"
#include "../../Utils/SystemInfo.h"

class paintMovement : public QWidget
{
    Q_OBJECT

public:
    paintMovement(QWidget *parent = 0);
    ~paintMovement();
    void paintEvent(QPaintEvent *event);
    void setData(CircularBuffer*,CircularBuffer*);
    void setSystemInfo(SystemInfo* si){systemInfo = si;systemInfo->getSystemWorkResolution(ancho,alto);};

private:
    Ui::paintMovementClass ui;
    CircularBuffer* xvalues;
    CircularBuffer* yvalues;
    SystemInfo* systemInfo;
    int alpha;
    QColor* q1;
    QPen* p1;
    int circsize;
    int index;
    int w;
    int h;
    int inc;
    int ancho;
    int alto;
    int adapt(int,int);
};

#endif // PAINTMOVEMENT_H
