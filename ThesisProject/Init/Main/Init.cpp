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
#include "../../XML/XMLParametersWriter.h"
#include "../../XML/XMLParametersReader.h"



Init::Init() {
}

Init::~Init() {

}

/**
 * This method is invoked when the application starts. It will
 * create the different windows and will show the main window.
 */

int Init::start(int argc, char *argv[]){

	loadParameters();

	QApplication a(argc, argv);

	if (!QSystemTrayIcon::isSystemTrayAvailable()) {
			 QMessageBox::critical(0, QObject::tr("Systray"),
								   QObject::tr("No es posible detectar Systray "
											   "en este sistema."));
			 return 1;
	}

	QApplication::setQuitOnLastWindowClosed(false);

	SystemInfo* si = new SystemInfo(80,60);

	NewGesture* newGesture = new NewGesture(si);

	AddGesture* addGesture = new AddGesture(newGesture,0);

	AddEvent* addEvent = new AddEvent();

	AddAsociation* addAsociation = new AddAsociation();

	StateViewer* stateViewer = new StateViewer();

	HandDiagnostic* handDiagnostic = new HandDiagnostic();

	About* about = new About();

	GestureParameter* gp = new GestureParameter(si);

	ThesisProject w(addGesture,addEvent,addAsociation,stateViewer,handDiagnostic,about,gp,si, 0);

	Container::getInstance()->createCamViewerInstance(w.getCapturedImage());

	Container::getInstance()->setThesisProject(&w);

	w.show();

	int ret = a.exec();

	Container::getInstance()->finishCamViewer();

	saveParameters();

	return ret;
}

/*
 * This method load the application Parameters
 */

void Init::loadParameters(){
	XMLParametersReader* xmlReader = new XMLParametersReader();
	xmlReader->readFile("Configuration/Parameters.xml");
}

/*
 * This method saves the application Parameters
 */

void Init::saveParameters(){
	XMLParametersWriter* xmlWriter = new XMLParametersWriter();
	xmlWriter->writeXML("Configuration/Parameters.xml");
}
