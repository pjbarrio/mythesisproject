/*
 * Container.h
 *
 *  Created on: 05/05/2009
 *      Author: Pablo
 *
 * This class represent the model application camera model.
 * Every variable that could change the image interpretation
 * could be found here. It is designed in a singleton pattern
 *
 */

#ifndef CONTAINER_H_
#define CONTAINER_H_

#include "../CamViewer.h"
#include "../../mainwindow.h"
#include <QLabel>
#include <QMutex>
#include <QPixmap>
#include <QList>
#include "cv.h"
#include "../../Filters/FilterHandler.h"
#include "../../ConfigurationHandler/ConfigHandler.h"
#include "../../stabilizers/LightStabilizer.h"
#include "../../Logger/LogHandler.h"
#include "../../CommonProject/InterfaceWorker/Initializer.h"
#include "../../CommonProject/Threads/Thread_Worker.h"
#include "../../Init/ThesisStart.h"

class Container {
public:
    CamViewer *getCamViewer()
    {
        return cv;
    }

    ;
    void setCamViewer(CamViewer *cam)
    {
        cv = cam;
    }

    ;
    void setThesisProject(ThesisProject *thesisProject)
    {
        tp = thesisProject;
    }

    ;
    ThesisProject *getThesisProject()
    {
        return tp;
    }

    ;
    void createCamViewerInstance(QLabel*);
    static Container *getInstance();
    QPixmap* getFilteredImage();
    void setFilteredImage(IplImage *filteredImage);
    FilterHandler *getFilterHandler();
    ConfigHandler *getConfigHandler();
    LightStabilizer *getLightStabilizer();
    LogHandler *getLog();
    bool isClosed()
    {
        return isclosed;
    }

    ;
    void setClosed(bool value)
    {
        isclosed = value;
    }

    ;
    void finishCamViewer();
    void setModel(bool, bool, bool, bool, bool, bool, bool, bool);
    void setRotateX(bool val)
    {
        rotateX = val;
    }

    ;
    void setRotateY(bool val)
    {
        rotateY = val;
    }

    ;
    bool getRotateX()
    {
        return rotateX;
    }

    ;
    bool getRotateY()
    {
        return rotateY;
    }

    ;
    bool getGestureSupport()
    {
        return gestureSupport;
    }

    ;
    bool getStateSupport()
    {
        return stateSupport;
    }

    ;
    bool getViewPointer()
    {
        return viewPointer;
    }

    ;
    bool getClickSupport()
    {
        return clickSupport;
    }

    ;
    bool getCloseClick()
    {
        return closeClick;
    }

    ;
    bool getOpenClick()
    {
        return openClick;
    }

    ;
    void setSavedImage(IplImage *im)
    {
        saved = im;
    }

    ;
    IplImage *getSavedImage()
    {
        return saved;
    }

    ;
    void setDiagnosticExecuted(bool val)
    {
        handDiagnosticExecuted = val;
    }

    ;
    bool getDiagnosticExecuted()
    {
        return handDiagnosticExecuted;
    }

    ;
    void createVideo();
    void addFrame(IplImage*);
    QList<IplImage*> *getVideo();
    void deleteVideo();

    void wakeAll();

    ThesisStart *getThesisStart() const {return thesisStart;}

    void setThesisStart(ThesisStart *thesisStart){this->thesisStart = thesisStart;}

private:
	QList<IplImage*>* video;
	QList<Initializer*>* initializerList;
	QList<Thread_Worker*>* threadworkerList;
	QMutex filteredImageAccess;
	QWaitCondition fiWaitCondition;
	bool fiset;
	QMutex logAccess;
	QMutex configHandlerAccess;
	QMutex lightStabilizerAccess;
	QMutex filterHandlerAccess;
	IplImage* saved;
	bool rotateX;
	bool rotateY;
	bool gestureSupport;
	bool stateSupport;
	bool viewPointer;
	bool clickSupport;
	bool closeClick;
	bool openClick;
	bool handDiagnosticExecuted;
	FilterHandler* filterHandler;
	ConfigHandler* configHandler;
	LightStabilizer *ls;
	LogHandler* log;
	Container();
	virtual ~Container();
	static Container* instance;
	CamViewer* cv;
	ThesisProject* tp;
	QPixmap* fi;
	QImage* image;
	bool isclosed;
	ThesisStart* thesisStart;
};

#endif /* CONTAINER_H_ */
