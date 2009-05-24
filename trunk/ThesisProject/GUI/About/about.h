/*
 * About.h
 *
 *  Created on: 23/05/2009
 *      Author: Pablo
 *
 * This GUI class shows the info about the
 * project owners.
 */

#ifndef ABOUT_H
#define ABOUT_H

#include <QtGui/QDialog>
#include "ui_about.h"

class About : public QDialog
{
    Q_OBJECT

public:
    About(QWidget *parent = 0);
    ~About();
 private:
    Ui::AboutClass ui;
};

#endif // ABOUT_H
