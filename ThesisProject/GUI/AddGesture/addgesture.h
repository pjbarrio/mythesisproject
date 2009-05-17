/*
 * addgesture.h
 *
 *  Created on: 05/05/2009
 *      Author: Pablo
 *
 * This GUI class is used to set new gestures.
 * This window offers an edit label where the user can
 * write the gesture's id.
 */

#ifndef ADDGESTURE_H
#define ADDGESTURE_H

#include <QtGui/QDialog>
#include "ui_addgesture.h"
#include "../../DynamicGestureRecognition/src/DTWData.h"
#include "../newGesture/newgesture.h"

class AddGesture : public QDialog
{
    Q_OBJECT

public:
    AddGesture(NewGesture*, QWidget *parent = 0);
    ~AddGesture();

    /*
     * This method returns the gesture id setted by the user.
     */

    QString *getId() const {return id;}
    void setId(QString *id) {this->id = id;}

    /*
     * This method returns the <T,X> component gesture.
     */

    DTWData *getTx() const {return tx;}
    void setTx(DTWData *tx) {this->tx = tx;}

    /*
     * This method returns the <T,Y> component gesture.
     */

    DTWData *getTy() const {return ty;}
    void setTy(DTWData *ty) {this->ty = ty;}

    int exec();

private:

	Ui::AddGestureClass ui;
    QString *id;
    DTWData *tx;
    DTWData *ty;
    void initVariables();
    void initWidgets();
    NewGesture* newGest;

private slots:
	void newGesture();
	void accept();
};

#endif // ADDGESTURE_H
