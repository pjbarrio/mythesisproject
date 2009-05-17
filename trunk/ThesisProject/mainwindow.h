#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "ui_mainwindow.h"
#include "GUI/AddGesture/addgesture.h"
#include "GUI/AddEvent/addevent.h"
#include "GUI/AddAsociation/addasociation.h"
#include "GUI/Estado/stateviewer.h"
#include <windows.h>
#include "DynamicGestureRecognition/src/GestureModel.h"
#include "DynamicGestureRecognition/src/EventModel.h"
#include "DynamicGestureRecognition/Events/PressCharEvent.h"
#include "GUI/HandDiagnostic/handdiagnostic.h"
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>









class ThesisProject : public QMainWindow
{
    Q_OBJECT

public:
    ThesisProject(AddGesture*,AddEvent*,AddAsociation*,StateViewer*,HandDiagnostic*,QWidget *parent = 0);
    ~ThesisProject();
    GestureModel *getGestureModel();

    bool isRotatedX() {return rotatex;};

    bool isRotatedY() {return rotatey;};

    QLabel *getCapturedImage() {return ui.capturedImage;};

    void closeEvent(QCloseEvent *event);

private:

	Ui::ThesisProjectClass ui;

	QSystemTrayIcon* trayIcon;
	QMenu* trayIconMenu;
	QAction* quitAction;
	QAction* StopCapturing;
	QAction* ViewState;
	QAction* Restore;

	AddGesture *addGestureDialog;
    AddEvent *addEventDialog;
    AddAsociation *addAsociationDialog;
    StateViewer *stateViewer;
    HandDiagnostic* handDiagnostic;
    bool rotatex;
    bool rotatey;
    QString UP_STR;
    QString DOWN_STR;
    QString RIGHT_STR;
    QString LEFT_STR;
    QString ESC_STR;
    QString SPACE_STR;
    QString INTRO_STR;
    QString TAB_STR;
    QString F5_STR;
    QString PGUP_STR;
    QString PGDN_STR;
    QString ALT_STR;
    QString ALTTAB_STR;
    static const BYTE UP_BYTE = VK_UP;
    static const BYTE DOWN_BYTE = VK_DOWN;
    static const BYTE RIGHT_BYTE = VK_RIGHT;
    static const BYTE LEFT_BYTE = VK_LEFT;
    static const BYTE ESC_BYTE = VK_ESCAPE;
    static const BYTE SPACE_BYTE = VK_SPACE;
    static const BYTE INTRO_BYTE = VK_RETURN;
    static const BYTE TAB_BYTE = VK_TAB;
    static const BYTE F5_BYTE = VK_F5;
    static const BYTE PGUP_BYTE = VK_PRIOR;
    static const BYTE PGDN_BYTE = VK_NEXT;
    static const BYTE ALT_BYTE = VK_MENU;
    DistanceCalculator *distanceCalculator;
    GestureModel *gestureModel;
    EventModel *keyEventModel;
    EventModel *combinedKeyEventModel;
    EventModel *AppEventModel;
    EventModel *fileEventModel;
    DTWAlgorithm *dtwAlgorithm;
    EventModel *getKeyEventModel();
    EventModel *getCombinedKeyEventModel();
    EventModel *getApplicationEventModel();
    EventModel *getOpenFileEventModel();

    void initVariables();
    PressCharEvent *createPressCharEvent(QString*, QString*);
    void saveConfiguration();
    void createCompleteTrayIcon();
private slots:
	void showNormal();
	void addGesture();
	void addEvent();
	void addAsociation();
	void removeGesture();
	void removeEvent();
	void removeAsociation();
	void rotateX(bool);
	void rotateY(bool);
	void startApplication();
	void runHandDiagnostic();
	void stopCapture();
	void ViewCaptureState();
};

#endif // MAINWINDOW_H