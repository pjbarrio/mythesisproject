#include "gestureparameter.h"
#include "../Utils/Container.h"
#include "../../DynamicGestureRecognition/DTWAlgorithms/ItakuraDTWAlgorithm.h"
#include "../../DynamicGestureRecognition/DTWAlgorithms/RawDTWAlgorithm.h"
#include "../../DynamicGestureRecognition/DTWAlgorithms/SakoeChibaDTWAlgorithm.h"

/**
 * This method sets up the gesture Parameter GUI
 */

GestureParameter::GestureParameter(SystemInfo* si, QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	this->si = si;
	initVariables();
}

GestureParameter::~GestureParameter()
{
	this->si = 0;
}

/**
 * This method updates the maximum number of values to detect
 * a gesture.
 */

void GestureParameter::setDetectedCount(int maxValue){
	ui.relaxedCount->setMaximum(maxValue);
}

/**
 * This method updates the maximum ratio allowed to remove when
 * a gesture es detected.
 */

void GestureParameter::setMaxRelatedRatio(int maxValue){
	ui.relaxedRatio->setMaximum(maxValue);
}

/**
 * This method initializes the variables.
 */
void GestureParameter::initVariables(){
	Container* cont = Container::getInstance();

	//TODO todos los setText y esas cosas. Obteniendo del Container.
	bufferSize = cont->getBufferSize();
	ui.bufferSize->setValue(bufferSize);

	relaxedCount = cont->getRelaxedCount();
	ui.relaxedCount->setValue(relaxedCount);

	distanceCalculatorAGM = cont->getDistanceCalculatorAGM();
	distanceCalculatorAGMIndex = cont->getDistanceCalculatorAGMIndex();
	ui.distanceCalculatorAGM->setCurrentIndex(distanceCalculatorAGMIndex);

	nonVaryingAccelerationRate = cont->getNonVaryingAccelerationRate();
	ui.nonVaryingAccelerationRate->setText(QString::number(nonVaryingAccelerationRate));

	accelerationThreshold = cont->getAccelerationThreshold();
	ui.accelerationThreshold->setText(QString::number(accelerationThreshold));

	desaccelerationThreshold = cont->getDesaccelerationThreshold();
	ui.desaccelerationThreshold->setText(QString::number(desaccelerationThreshold));

	walkedPixels = cont->getWalkedPixels();
	ui.walkedPixels->setValue(walkedPixels);

	minimumPointsCount = cont->getMinimumPointsCount();
	ui.minimunPointCount->setValue(minimumPointsCount);

	distanceThreshold = cont->getDistanceThreshold();
	ui.distanceThreshold->setValue(distanceThreshold);

	maxGestureTime = cont->getMaxGestureTime();
	ui.maxGestureTime->setValue(maxGestureTime);

	valuesNormalizatorIndex = cont->getValuesNormalizatorIndex();
	ui.valuesNormalizator->setCurrentIndex(valuesNormalizatorIndex);
	valuesNormalizator = cont->getValuesNormalizator();

	relaxedRatio = cont->getRelaxedRatio();
	ui.relaxedRatio->setValue(relaxedRatio);

	distanceCalculatorDTWIndex = cont->getDistanceCalculatorDTWIndex();
	ui.distanceCalculatorDTW->setCurrentIndex(distanceCalculatorDTWIndex);
	distanceCalculatorDTW = cont->getDistanceCalculatorDTW();

	rate = cont->getRate();
	ui.rate->setValue(rate);

	dTWAlgorithm = cont->getDTWAlgorithm();
	dTWAlgorithmIndex = cont->getDTWAlgorithmIndex();
	ui.dtwAlgorithm->setCurrentIndex(dTWAlgorithmIndex);

}

/**
 * This method intercepts the exec method and initializes the variables
 * which needs some parameters from model.
 */

int GestureParameter::exec(){

	dirtybufferSize = false;
	dirtywalkedPixels = false;
	dirtydistanceThreshold = false;
	dirtynonVaryingAccelerationRate = false;
	dirtyminimumPointsCount = false;
	dirtyrelaxedCount = false;
	dirtyaccelerationThreshold = false;
	dirtydesaccelerationThreshold = false;
	dirtymaxGestureTime = false;
	dirtydistanceCalculatorAGM = false;
	dirtydistanceCalculatorDTW = false;
	dirtyrate = false;
	dirtydTWAlgorithm = false;
	dirtyrelaxedRatio = false;

	return QDialog::exec();
}

/**
 * This method stores the values set by the user in the
 * gesture recognition model's variables
 */

void GestureParameter::accept(){
	Container* cont = Container::getInstance();

	convertStringToRealValues();

	if (dirtybufferSize)
		cont->setBufferSize(bufferSize);
	if (dirtyrelaxedCount)
		cont->setRelaxedCount(relaxedCount);
	if (dirtydistanceCalculatorAGM)
		cont->setDistanceCalculatorAGM(distanceCalculatorAGM);
	if (dirtynonVaryingAccelerationRate)
		cont->setNonVaryingAccelerationRate(nonVaryingAccelerationRate);
	if (dirtyaccelerationThreshold)
		cont->setAccelerationThreshold(accelerationThreshold);
	if (dirtydesaccelerationThreshold)
		cont->setDesaccelerationThreshold(desaccelerationThreshold);
	if (dirtyvaluesNormalizator)
		cont->setValuesNormalizator(valuesNormalizator);

	if (dirtywalkedPixels)
		cont->setWalkedPixels(walkedPixels);
	if (dirtyminimumPointsCount)
		cont->setMinimumPointsCount(minimumPointsCount);
	if (dirtydistanceThreshold)
		cont->setDistanceThreshold(distanceThreshold);
	if (dirtymaxGestureTime)
		cont->setMaxGestureTime(maxGestureTime);

	if (dirtyrelaxedRatio)
		cont->setRelaxedRatio(relaxedRatio);
	if (dirtydistanceCalculatorDTW)
		cont->setDistanceCalculatorDTW(distanceCalculatorDTW);
	if (dirtydTWAlgorithm)
		cont->setDTWAlgorithm(dTWAlgorithm);

	QDialog::accept();
}

/**
 * This method creates the objects represented by the Strings set
 * by the user.
 */
void GestureParameter::convertStringToRealValues(){
	if (dirtydistanceCalculatorAGM){
		if (ui.distanceCalculatorAGM->currentIndex()==0)
			distanceCalculatorAGM = new EuclideanDistance();
		Container::getInstance()->setDistanceCalculatorAGMIndex(ui.distanceCalculatorAGM->currentIndex());
	}
	if (dirtyvaluesNormalizator){
		if (ui.valuesNormalizator->currentIndex()==0)
			valuesNormalizator = new ValuesNormalizator(si);
		Container::getInstance()->setValuesNormalizatorIndex(ui.valuesNormalizator->currentIndex());
	}
	if (dirtydistanceCalculatorDTW){
		if (ui.distanceCalculatorDTW->currentIndex()==0)
			distanceCalculatorDTW = new EuclideanDistance();
		Container::getInstance()->setDistanceCalculatorDTWIndex(ui.distanceCalculatorDTW->currentIndex());
	}
	if (dirtydTWAlgorithm){
		int dtwAlIn = ui.dtwAlgorithm->currentIndex();
		if (dtwAlIn==0)
			dTWAlgorithm = new ItakuraDTWAlgorithm(rate,distanceCalculatorDTW);
		else if (dtwAlIn==1)
			dTWAlgorithm = new RawDTWAlgorithm(distanceCalculatorDTW);
		else if (dtwAlIn==2)
			dTWAlgorithm = new SakoeChibaDTWAlgorithm(rate,distanceCalculatorDTW);
		Container::getInstance()->setDTWAlgorithmIndex(dtwAlIn);
	}
}

/**
 * This method stores the new buffer size value
 */
void GestureParameter::bufferSizeModified(int val){
	dirtybufferSize = true;
	bufferSize = val;
}
/**
 * This method stores the new Relaxed count value
 */
void GestureParameter::relaxedCountModified(int val){
	dirtyrelaxedCount = true;
	relaxedCount = val;
}
/** This method stores the new distance calculator object
 *
 */
void GestureParameter::distanceCalculatorAGMModified(QString val){
	dirtydistanceCalculatorAGM = true;
	distanceCalculatorAGMIndex = ui.distanceCalculatorAGM->currentIndex();
}
/**
 * This method stores the new non varying acceleration rate value
 */
void GestureParameter::nonVaryingAccelerationRateModified(QString val){
	dirtynonVaryingAccelerationRate = true;
	bool fun;
	nonVaryingAccelerationRate = val.toDouble(&fun);
}
/**
 * This method stores the new acceleration threshold value
 */
void GestureParameter::accelerationThresholdModified(QString val){
	dirtyaccelerationThreshold = true;
	bool fun;
	accelerationThreshold = val.toDouble(&fun);
}

/**
 * This method stores the new desacceleration threshold value
 */
void GestureParameter::desaccelerationThresholdModified(QString val){
	dirtydesaccelerationThreshold = true;
	bool fun;
	desaccelerationThreshold = val.toDouble(&fun);
}

/**
 * This method stores the new walked pixels value
 */
void GestureParameter::walkedPixelsModified(int val){
	dirtywalkedPixels = true;
	walkedPixels = val;
}
/**
 * This method stores the new minimum point count value
 */
void GestureParameter::minimumPointCountModified(int val){
	dirtyminimumPointsCount = true;
	minimumPointsCount = val;
}
/**
 * This method stores the new distance threshold value
 */
void GestureParameter::distanceThresholdModified(double val){
	dirtydistanceThreshold = true;
	distanceThreshold = val;
}
/**
 * This method stores the new max gesture time value
 */
void GestureParameter::maxGestureTimeModified(double val){
	dirtymaxGestureTime = true;
	maxGestureTime = val;
}
/**
 * This method stores the new  values normalizator object
 */
void GestureParameter::valuesNormalizatorModified(QString val){
	dirtyvaluesNormalizator = true;
	valuesNormalizatorIndex = ui.valuesNormalizator->currentIndex();
}
/**
 * This method stores the new relaxed ratio value
 */
void GestureParameter::relaxedRatioModified(int val){
	dirtyrelaxedRatio = true;
	relaxedRatio = val;
}
/**
 * This method stores the new distance calculator for DTW Algorithm object
 */
void GestureParameter::distanceCalculatorDTWModified(QString val){
	dirtydistanceCalculatorDTW = true;
	dirtydTWAlgorithm = true;
	distanceCalculatorDTWIndex = ui.distanceCalculatorDTW->currentIndex();
}
/**
 * This method stores the new dtw Algorithm
 */
void GestureParameter::dtwAlgorithmModified(QString val){
	dirtydTWAlgorithm = true;
	dTWAlgorithmIndex = ui.dtwAlgorithm->currentIndex();
}
/**
 * This method stores the new rate value
 */
void GestureParameter::rateModified(double val){
	dirtyrate = true;
	dirtydTWAlgorithm = true;
	rate = val;
}

