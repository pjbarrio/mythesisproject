/**
 * Init.cpp
 *
 *  Created on: 05/05/2009
 *      \author  Pablo
 */

#include "Init.h"
#include "../../GUI/Utils/Container.h"
#include "../../GUI/HandDiagnostic/handdiagnostic.h"
#include "../../GUI/CamViewer.h"



Init::Init() {
}

Init::~Init() {

}

/**
 * This method is invoked when the application starts. It will
 * create the different windows and will show the main window.
 */

int Init::start(int argc, char *argv[]){

	QApplication a(argc, argv);

	if (!QSystemTrayIcon::isSystemTrayAvailable()) {
			 QMessageBox::critical(0, QObject::tr("Systray"),
								   QObject::tr("No es posible detectar Systray "
											   "en este sistema."));
			 return 1;
	}

	QApplication::setQuitOnLastWindowClosed(false);

	NewGesture* newGesture = new NewGesture();

	AddGesture* addGesture = new AddGesture(newGesture,0);

	AddEvent* addEvent = new AddEvent();

	AddAsociation* addAsociation = new AddAsociation();

	StateViewer* stateViewer = new StateViewer();

	HandDiagnostic* handDiagnostic = new HandDiagnostic();

	About* about = new About();

	SystemInfo* si = new SystemInfo(80,60);

	GestureParameter* gp = new GestureParameter(si);

	ThesisProject w(addGesture,addEvent,addAsociation,stateViewer,handDiagnostic,about,gp,si, 0);

	Container::getInstance()->createCamViewerInstance(w.getCapturedImage());

	Container::getInstance()->setThesisProject(&w);

	w.show();

	int ret = a.exec();

	Container::getInstance()->finishCamViewer();

	return ret;
}
