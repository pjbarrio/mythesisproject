/*
 * Init.h
 *
 *  Created on: 05/05/2009
 *      Author: Pablo
 *
 * This class is invoked when the application starts.
 * It has the implementation of the "main" method.
 */

#ifndef INIT_H_
#define INIT_H_

#include <QtGui>
#include <QApplication>
#include "../../GUI/newGesture/newgesture.h"
#include "../../GUI/AddGesture/addgesture.h"
#include "../../GUI/AddEvent/addevent.h"
#include "../../GUI/AddAsociation/addasociation.h"
#include "../../GUI/Estado/stateviewer.h"
#include "../../mainwindow.h"
#include "../../GUI/CamViewer.h"
#include "../../GUI/GestureParameters/gestureparameter.h"
class Init {
public:
	Init();
	virtual ~Init();
	int start(int argc, char *argv[]);
};

#endif /* INIT_H_ */
