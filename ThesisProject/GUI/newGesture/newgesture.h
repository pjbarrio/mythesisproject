/**
 * newGesture.h
 *
 *  Created on: 05/05/2009
 *      \author  Pablo
 *
 * This class is an specific kind of Windows Dialog.
 * In this window a new gesture can be added.
 */

#ifndef NEWGESTURE_H
#define NEWGESTURE_H

#include <QtGui/QDialog>
#include <QKeyEvent>
#include "ui_newgesture.h"
#include "../../DynamicGestureRecognition/src/DTWData.h"
#include <QList>
#include "cv.h"
#include "../../Camera/CameraVideo.h"
#include "../../DynamicGestureRecognition/CircularBuffer/CircularBuffer.h"


class NewGesture : public QDialog
{
    Q_OBJECT

public:
    NewGesture(QWidget *parent = 0);
    ~NewGesture();

    /**
     * This method returns the <T,X> Component of the saved Gesture.
     */
    DTWData *getTx() const {return tx;}
    void setTx(DTWData *tx) {this->tx = tx;}

    /**
     * This method returns the <T,Y> Component of the saved Gesture.
     */

    DTWData *getTy() const {return ty;}
    void setTy(DTWData *ty) {this->ty = ty;}

    void saveMovement(QList<IplImage*>*);

    int exec();

    void keyPressEvent(QKeyEvent* event);

    void generateCircularBuffer(DTWData*, DTWData*);
private:
	Ui::NewGestureClass ui;
    DTWData* tx;
    DTWData* ty;
    CircularBuffer* cx;
    CircularBuffer* cy;
    void startCapturing();
    void finishCapturing();
    bool hasStarted;
    CameraVideo* cv;
    void initVariables();
    void initWidgets();
    void startCamera();
	void startProgressBar();
	void startCapture();
private slots:
	void accept();
	void viewGesture();
};

#endif // NEWGESTURE_H
