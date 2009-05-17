/*
 * addevent.h
 *
 *  Created on: 05/05/2009
 *      Author: Pablo
 *
 * This GUI class has the responsability of setting
 * the variables to create an event.
 */

#ifndef ADDEVENT_H
#define ADDEVENT_H

#include <QtGui/QDialog>
#include "ui_addevent.h"

class AddEvent : public QDialog
{
    Q_OBJECT

public:
    AddEvent(QWidget *parent = 0);
    ~AddEvent();

    int exec();

    /*
     * This method returns the event's id.
     */

    QString *getId() const {return id;}
    void setId(QString *id){this->id = id;}

    /*
     * This method returns if the event created is an
     * execution application event.
     */

    bool getIsApp() const {return isApp;}
    void setIsApp(bool isApp) {this->isApp = isApp;}

    /*
     * This method returns if the created event is a
     * press key event.
     */

    bool getIsKey() const {return isKey;}
    void setIsKey(bool isKey) {this->isKey = isKey;}

    /*
     * This method returns the key selected.
     */

    QString *getKey() const {return key;}
    void setKey(QString *key) {this->key = key;}

    /*
     * This method returns the filename and the path of the
     * application selected to be executed by the event.
     */

    QString *getApp() const {return app;}
    void setApp(QString *app) {this->app = app;}

    /*
     * This method returns if the application is executed
     * with predetermined args.
     */

    bool getHasArgs() const {return hasArgs;}
    void setHasArgs(bool hasArgs) {this->hasArgs = hasArgs;}

    /*
     * This method returns the args setted by the user.
     */

    QString *getArgs() const {return args;}
    void setArgs(QString *args) {this->args = args;}

    /*
     * This method returns if the application selected is an
     * exe file.
     */

    bool getIsExe() const {return isExe;}
    void setIsExe(bool isExe) {this->isExe = isExe;}

    /*
     * This method returns if the file selected is a common file
     * to be opened by a predetermined application.
     */

    bool getIsOther() const {return isOther;}
    void setIsOther(bool isOther) {this->isOther = isOther;}




private:
    Ui::AddEventClass ui;
    QString file;
    QString *id;
    bool isApp;
    bool isKey;
    QString *key;
    QString *app;
    bool hasArgs;
    QString *args;
    bool isExe;
    bool isOther;
    void initVariables();
    void initWidgets();
private slots:
	void openExecutableFile();
	void accept();
};

#endif // ADDEVENT_H
