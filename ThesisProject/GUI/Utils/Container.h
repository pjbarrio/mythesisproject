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
#include "../../DynamicGestureRecognition/src/ValuesNormalizator.h"

class Container {
public:
    CamViewer *getCamViewer() {return cv;};
    void setCamViewer(CamViewer *cam){cv = cam;};
    void setThesisProject(ThesisProject *thesisProject){tp = thesisProject;};
    ThesisProject *getThesisProject() {return tp;};
    void createCamViewerInstance(QLabel*);
    static Container *getInstance();
    QPixmap* getFilteredImage();
    void setFilteredImage(IplImage *filteredImage);
    FilterHandler *getFilterHandler();
    ConfigHandler *getConfigHandler();
    LightStabilizer *getLightStabilizer();
    LogHandler *getLog();
    bool isClosed(){return isclosed;};
    void setClosed(bool value){isclosed = value;};
    void finishCamViewer();
    void setModel(bool, bool, bool, bool, bool, bool, bool, bool);
    void setRotateX(bool val) {rotateX = val;};
    void setRotateY(bool val) {rotateY = val;};
    bool getRotateX() {return rotateX;};
    bool getRotateY() {return rotateY;};
    bool getGestureSupport() {return gestureSupport;};
    bool getStateSupport() {return stateSupport;};
    bool getViewPointer() {return viewPointer;};
    bool getClickSupport(){return clickSupport;};
    bool getCloseClick() {return closeClick;};
    bool getOpenClick() {return openClick;};
    void setSavedImage(IplImage *im){saved = im;};
    IplImage *getSavedImage() {return saved;};
    void setDiagnosticExecuted(bool val) {handDiagnosticExecuted = val;};
    bool getDiagnosticExecuted() {return handDiagnosticExecuted;};
    void createVideo();
    void addFrame(IplImage*);
    QList<IplImage*> *getVideo();
    void deleteVideo();
    void wakeAll();
    ThesisStart *getThesisStart() const{return thesisStart;}
    void setThesisStart(ThesisStart *thesisStart) {this->thesisStart = thesisStart;}



    int getBufferSize() const {return bufferSize;}
    int getWalkedPixels() const {return walkedPixels;}
    double getDistanceThreshold() const {return distanceThreshold;}
    double getNonVaryingAccelerationRate() const {return nonVaryingAccelerationRate;}
    int getMinimumPointsCount() const {return minimumPointsCount;}
    int getRelaxedCount() const {return relaxedCount;}
    double getAccelerationThreshold() const {return accelerationThreshold;}
    double getDesaccelerationThreshold() const {return desaccelerationThreshold;}
    double getMaxGestureTime() const {return maxGestureTime;}
    DistanceCalculator *getDistanceCalculatorAGM() const {return distanceCalculatorAGM;}
    DistanceCalculator *getDistanceCalculatorDTW() const {return distanceCalculatorDTW;}
    DTWAlgorithm *getDTWAlgorithm() const {return dTWAlgorithm;}
    double getRelaxedRatio() const {return relaxedRatio;}
    ValuesNormalizator *getValuesNormalizator() const {return valuesNormalizator;}

    void initGestureParameters();

    void setBufferSize(int bufferSize) {this->bufferSize = bufferSize;}
    void setWalkedPixels(int walkedPixels){this->walkedPixels = walkedPixels;}
    void setDistanceThreshold(double distanceThreshold) {this->distanceThreshold = distanceThreshold;}
    void setNonVaryingAccelerationRate(double nonVaryingAccelerationRate) {this->nonVaryingAccelerationRate = nonVaryingAccelerationRate;}
    void setMinimumPointsCount(int minimumPointsCount) {this->minimumPointsCount = minimumPointsCount;}
    void setRelaxedCount(int relaxedCount){this->relaxedCount = relaxedCount;}
    void setAccelerationThreshold(double accelerationThreshold) {this->accelerationThreshold = accelerationThreshold;}
    void setDesaccelerationThreshold(double desaccelerationThreshold) {this->desaccelerationThreshold = desaccelerationThreshold;}
    void setMaxGestureTime(double maxGestureTime) {this->maxGestureTime = maxGestureTime;}
    void setDistanceCalculatorAGM(DistanceCalculator *distanceCalculatorAGM) {this->distanceCalculatorAGM = distanceCalculatorAGM;}
    void setDistanceCalculatorDTW(DistanceCalculator *distanceCalculatorDTW) {this->distanceCalculatorDTW = distanceCalculatorDTW;}
    void setDTWAlgorithm(DTWAlgorithm *dTWAlgorithm) {this->dTWAlgorithm = dTWAlgorithm;}
    void setRelaxedRatio(double relaxedRatio) {this->relaxedRatio = relaxedRatio;}
    void setValuesNormalizator(ValuesNormalizator *valuesNormalizator) {this->valuesNormalizator = valuesNormalizator;}

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
	int bufferSize;
	int walkedPixels;
	double distanceThreshold;
	double nonVaryingAccelerationRate;
	int minimumPointsCount;
	int relaxedCount;
	double accelerationThreshold;
	double desaccelerationThreshold;
	double maxGestureTime;
	DistanceCalculator* distanceCalculatorAGM;
	DistanceCalculator* distanceCalculatorDTW;
	DTWAlgorithm *dTWAlgorithm;
	double relaxedRatio;
	ValuesNormalizator* valuesNormalizator;
};

#endif /* CONTAINER_H_ */
