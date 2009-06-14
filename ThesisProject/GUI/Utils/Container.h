/**
 * Container.h
 *
 *  Created on: 05/05/2009
 *      \author  Pablo
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
    int getDistanceCalculatorAGMIndex() const {return distanceCalculatorAGMIndex;}

    void setDistanceCalculatorAGMIndex(int distanceCalculatorAGMIndex) {this->distanceCalculatorAGMIndex = distanceCalculatorAGMIndex;}

    int getValuesNormalizatorIndex() const {return valuesNormalizatorIndex;}

    void setValuesNormalizatorIndex(int valuesNormalizatorIndex) {this->valuesNormalizatorIndex = valuesNormalizatorIndex;}

    int getDistanceCalculatorDTWIndex() const {return distanceCalculatorDTWIndex;}

    void setDistanceCalculatorDTWIndex(int distanceCalculatorDTWIndex) {this->distanceCalculatorDTWIndex = distanceCalculatorDTWIndex;}

    int getDTWAlgorithmIndex() const {return dTWAlgorithmIndex;}

    void setDTWAlgorithmIndex(int dTWAlgorithmIndex) {this->dTWAlgorithmIndex = dTWAlgorithmIndex;}

    std::string getTnf() const {return tnf;}

    void setTnf(std::string tnf){this->tnf = tnf;}

    std::string getGnf() const {return gnf;}

    void setGnf(std::string gnf) {this->gnf = gnf;}

    double getGestureThreshold() const {return gestureThreshold;}

    void setGestureThreshold(double gestureThreshold){this->gestureThreshold = gestureThreshold;}

    int getMaxFramesToAnalize() const {return maxFramesToAnalize;}

    void setMaxFramesToAnalize(int maxFramesToAnalize) {this->maxFramesToAnalize = maxFramesToAnalize;}

    double getLightStabilizerThresholdDelta() const {return lightStabilizerThresholdDelta;}

    void setLightStabilizerThresholdDelta(double lightStabilizerThresholdDelta) {this->lightStabilizerThresholdDelta = lightStabilizerThresholdDelta;}

    int getSkinDelta() const {return skinDelta;}

    void setSkinDelta(int skinDelta) {this->skinDelta = skinDelta;}

    double getNormalizedTime() const {return normalizedTime;}

    void setNormalizedTime(double normalizedTime) {this->normalizedTime = normalizedTime;}

    double getMaxAcceptedDTWValue() const {return maxAcceptedDTWValue;}

    void setMaxAcceptedDTWValue(double maxAcceptedDTWValue) {this->maxAcceptedDTWValue = maxAcceptedDTWValue;}

    int getXValueDis() const {return xValueDis;}

    void setXValueDis(int xValueDis){this->xValueDis = xValueDis;}

    int getYValueDis() const {return yValueDis;}

    void setYValueDis(int yValueDis) {this->yValueDis = yValueDis;}

    int getSleepValue() const {return sleepValue;}

    void setSleepValue(int sleepValue) {this->sleepValue = sleepValue;}

    int getInputSize() const {return inputSize;}

    void setInputSize(int inputSize) {this->inputSize = inputSize;}

    int getK_Factor() const {return k_factor;}

    void setK_Factor(int k_factor) {this->k_factor = k_factor;}

    int getFrameWindow() const {return frameWindow;}

    void setFrameWindow(int frameWindow) {this->frameWindow = frameWindow;}

    double getDelta() const {return delta;}

    void setDelta(double delta) {this->delta = delta;}

    int getHValue() const {return hValue;}

    void setHValue(int hValue) {this->hValue = hValue;}

    int getSValue() const {return sValue;}

    void setSValue(int sValue) {this->sValue = sValue;}

    double getNoVelocityDetected() const {return noVelocityDetected;}

    void setNoVelocityDetected(double noVelocityDetected) {this->noVelocityDetected = noVelocityDetected;}

    double getNoAccelerationDetected() const {return noAccelerationDetected;}

    void setNoAccelerationDetected(double noAccelerationDetected) {this->noAccelerationDetected = noAccelerationDetected;}

    int getMaxVelocity() const {return maxVelocity;}

    void setMaxVelocity(int maxVelocity) {this->maxVelocity = maxVelocity;}

    int getMaxAcceleration() const {return maxAcceleration;}

    void setMaxAcceleration(int maxAcceleration) {this->maxAcceleration = maxAcceleration;}

    int getDrawSize() const {return drawSize;}

    void setDrawSize(int drawSize) {this->drawSize = drawSize;}

    std::string getLogFile() const {return logFile;}

    void setLogFile(std::string logFile) {this->logFile = logFile;}

    int getNetOutput() const {return netOutput;}

    void setNetOutput(int netOutput) {this->netOutput = netOutput;}

    int getStaticGestureOutput() const {return staticGestureOutput;}

    void setStaticGestureOutput(int staticGestureOutput) {this->staticGestureOutput = staticGestureOutput;}

    double getThresholdDelta() const {return thresholdDelta;}

    void setThresholdDelta(double thresholdDelta) {this->thresholdDelta = thresholdDelta;}

    double getDif() const {return dif;}

    void setDif(double dif) {this->dif = dif;}

    double getFactor() const {return factor;}

    void setFactor(double factor) {this->factor = factor;}

    QString getConfigurationFolder() const {return configurationFolder;}

    void setConfigurationFolder(QString configurationFolder) {this->configurationFolder = configurationFolder;}

    std::string getConfigFile() const {return configFile;}

    void setConfigFile(std::string configFile) {this->configFile = configFile;}

    int getWorkW() const {return workW;}

    void setWorkW(int workW) {this->workW = workW;}

    int getWorkH() const {return workH;}

    void setWorkH(int workH) {this->workH = workH;}

    double getRate() const {return rate;}

    void setRate(double rate) {this->rate = rate;}

    GestureModel *getGestureModel() const {return gestureModel;}

    void setGestureModel(GestureModel *gestureModel) {this->gestureModel = gestureModel;}

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
	GestureModel* gestureModel;
	double relaxedRatio;
	ValuesNormalizator* valuesNormalizator;

	std::string tnf;
	std::string gnf;
	double gestureThreshold;
	int maxFramesToAnalize;
	double lightStabilizerThresholdDelta;
	int skinDelta;
	double normalizedTime;
	double maxAcceptedDTWValue;
	int xValueDis;
	int yValueDis;
	int sleepValue;
	int inputSize;
	int k_factor;
	int frameWindow;
	double delta;
	int hValue;
	int sValue;
	double noVelocityDetected;
	double noAccelerationDetected;
	int maxVelocity;
	int maxAcceleration;
	int drawSize;
	std::string logFile;
	int netOutput;
	int staticGestureOutput;
	double thresholdDelta;
	double dif;
	double factor;
	QString configurationFolder;
	std::string configFile;
	int workW;
	int workH;
	double rate;

	int distanceCalculatorAGMIndex;
	int valuesNormalizatorIndex;
	int distanceCalculatorDTWIndex;
	int dTWAlgorithmIndex;
};

#endif /** CONTAINER_H_ */
