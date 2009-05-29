/*
 * gestureparameter.h
 *
 *  Created on: 25/05/2009
 *      Author: Pablo
 *
 * This GUI class provides the interface to set the Gesture
 * Recognition Parameters.
 */

#ifndef GESTUREPARAMETER_H
#define GESTUREPARAMETER_H

#include <QtGui/QDialog>
#include "ui_gestureparameter.h"
#include "../../Utils/SystemInfo.h"
#include "../../DynamicGestureRecognition/src/DistanceCalculator.h"
#include "../../DynamicGestureRecognition/src/DTWAlgorithm.h"
#include "../../DynamicGestureRecognition/src/ValuesNormalizator.h"

class GestureParameter : public QDialog
{
    Q_OBJECT

public:
    GestureParameter(QWidget *parent = 0);
    ~GestureParameter();
    int exec(SystemInfo*);
private:
    Ui::GestureParameterClass ui;
    SystemInfo* si;
    void initVariables();
    int bufferSize;
	int walkedPixels;
	double distanceThreshold;
	double nonVaryingAccelerationRate;
	int minimumPointsCount;
	int relaxedCount;
	double accelerationThreshold;
	double maxGestureTime;
	DistanceCalculator* distanceCalculatorAGM;
	DistanceCalculator* distanceCalculatorDTW;
	double rate;
	DTWAlgorithm *dTWAlgorithm;
	double relaxedRatio;
	ValuesNormalizator* valuesNormalizator;
	bool dirtybufferSize;
	bool dirtywalkedPixels;
	bool dirtydistanceThreshold;
	bool dirtynonVaryingAccelerationRate;
	bool dirtyminimumPointsCount;
	bool dirtyrelaxedCount;
	bool dirtyaccelerationThreshold;
	bool dirtymaxGestureTime;
	bool dirtydistanceCalculatorAGM;
	bool dirtydistanceCalculatorDTW;
	bool dirtyrate;
	bool dirtydTWAlgorithm;
	bool dirtyrelaxedRatio;
	bool dirtyvaluesNormalizator;
	QString distanceCalculatorAGMString;
	QString valuesNormalizatorString;
	QString distanceCalculatorDTWString;
	QString dTWAlgorithmString;
	void convertStringToRealValues();
private slots:
	void setDetectedCount(int);
	void setMaxRelatedRatio(int);
	void accept();
	void bufferSizeModified(int);
	void relaxedCountModified(int);
	void distanceCalculatorAGMModified(QString);
	void nonVaryingAccelerationRateModified(QString);
	void accelerationThresholdModified(QString);
	void walkedPixelsModified(int);
	void minimumPointCountModified(int);
	void distanceThresholdModified(double);
	void maxGestureTimeModified(double);
	void valuesNormalizatorModified(QString);
	void relaxedRatioModified(int);
	void distanceCalculatorDTWModified(QString);
	void dtwAlgorithmModified(QString);
	void rateModified(double);

};

#endif // GESTUREPARAMETER_H
