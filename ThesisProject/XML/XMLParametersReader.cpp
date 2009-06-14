/**
 * XMLParametersReader.cpp
 *
 *  Created on: 12/06/2009
 *      Author: Pablo
 */

#include "XMLParametersReader.h"
#include <QString>
#include <QFile>
#include "string.h"
#include "../GUI/Utils/Container.h"
#include "../DynamicGestureRecognition/src/DTWAlgorithm.h"
#include "../DynamicGestureRecognition/DTWAlgorithms/ItakuraDTWAlgorithm.h"
#include "../DynamicGestureRecognition/DTWAlgorithms/RawDTWAlgorithm.h"
#include "../DynamicGestureRecognition/DTWAlgorithms/SakoeChibaDTWAlgorithm.h"
#include "../DynamicGestureRecognition/src/GestureModel.h"
#include "../DynamicGestureRecognition/DistanceCalculators/EuclideanDistance.h"
#include "../DynamicGestureRecognition/src/ValuesNormalizator.h"

XMLParametersReader::XMLParametersReader() {
;
}

XMLParametersReader::~XMLParametersReader() {
;
}

/**
 * This method reads the parameter file.
 */

bool XMLParametersReader::readFile(const QString & fileName){
	QFile file(fileName);
	if (!file.open(QFile::ReadOnly | QFile::Text)) {
		std::cerr << "Error: No es posible abrir " << qPrintable(fileName)
				  << ": " << qPrintable(file.errorString())
				  << std::endl;
		return false;
	}
	reader.setDevice(&file);

	reader.readNext();
	while (!reader.atEnd()) {
		if (reader.isStartElement()) {
			if (reader.name() == "Parameters") {
				readParametersElement();
			} else {
				reader.raiseError(QObject::tr("Este archivo no contiene Parámetros"));
			}
		} else {
			reader.readNext();
		}
	}

	file.close();
	if (reader.hasError()) {
		std::cerr << "Error: Se ha fallado al parsear el archivo "
				  << qPrintable(fileName) << ": "
				  << qPrintable(reader.errorString()) << std::endl;
		return false;
	} else if (file.error() != QFile::NoError) {
		std::cerr << "Error: No se puede leer el archivo " << qPrintable(fileName)
				  << ": " << qPrintable(file.errorString())
				  << std::endl;
		return false;
	}

	return true;
}

/**
 * This method reads the parameter element.
 */

void XMLParametersReader::readParametersElement(){
	Container* cont = Container::getInstance();
	reader.readNext();
	reader.readNext();

	QString TrackerNetFile = reader.readElementText();
	reader.readNext();
	reader.readNext();
	std::string tnf = TrackerNetFile.toStdString();
	cont->setTnf(tnf);

	//"NetDesktopSkin.net"

	QString GestureNetFile = reader.readElementText();
	reader.readNext();
	reader.readNext();
	std::string gnf = GestureNetFile.toStdString();
	cont->setGnf(gnf);

	//"Net_Desktop_skin_Gesture_2096.net"

	QString GestureThreshold = reader.readElementText();
	reader.readNext();
	reader.readNext();
	double gestureThreshold = GestureThreshold.toDouble();
	cont->setGestureThreshold(gestureThreshold);

	//50.0

	QString MaxFramesToAnalize = reader.readElementText();
	reader.readNext();
	reader.readNext();
	int maxFramesToAnalize = MaxFramesToAnalize.toInt();
	cont->setMaxFramesToAnalize(maxFramesToAnalize);

	//20

	QString LightStabilizerThresholdDelta = reader.readElementText();
	reader.readNext();
	reader.readNext();
	double lightStabilizerThresholdDelta = LightStabilizerThresholdDelta.toDouble();
	cont->setLightStabilizerThresholdDelta(lightStabilizerThresholdDelta);

	//0.20

	QString SkinDelta = reader.readElementText();
	reader.readNext();
	reader.readNext();
	int skinDelta = SkinDelta.toInt();
	cont->setSkinDelta(skinDelta);

	//42

	QString NormalizedTime = reader.readElementText();
	reader.readNext();
	reader.readNext();
	double normalizedTime = NormalizedTime.toDouble();
	cont->setNormalizedTime(normalizedTime);

	// 2.0;

	QString MaxAcceptedDTWValue = reader.readElementText();
	reader.readNext();
	reader.readNext();
	double maxAcceptedDTWValue = MaxAcceptedDTWValue.toDouble();
	cont->setMaxAcceptedDTWValue(maxAcceptedDTWValue);

	// 500.0;

	QString XValueDis = reader.readElementText();
	reader.readNext();
	reader.readNext();
	int xValueDis = XValueDis.toInt();
	cont->setXValueDis(xValueDis);

	//-1

	QString YValueDis = reader.readElementText();
	reader.readNext();
	reader.readNext();
	int yValueDis = YValueDis.toInt();
	cont->setYValueDis(yValueDis);

	//-1

	QString SleepValue = reader.readElementText();
	reader.readNext();
	reader.readNext();
	int sleepValue = SleepValue.toInt();
	cont->setSleepValue(sleepValue);

	//1

	QString InputSize = reader.readElementText();
	reader.readNext();
	reader.readNext();
	int inputSize = InputSize.toInt();
	cont->setInputSize(inputSize);

	// 4800

	QString K_factor = reader.readElementText();
	reader.readNext();
	reader.readNext();
	int k_factor = K_factor.toInt();
	cont->setK_Factor(k_factor);

	// 1

	QString FrameWindow = reader.readElementText();
	reader.readNext();
	reader.readNext();
	int frameWindow = FrameWindow.toInt();
	cont->setFrameWindow(frameWindow);

	// 5

	QString Delta = reader.readElementText();
	reader.readNext();
	reader.readNext();
	double delta = Delta.toDouble();
	cont->setDelta(delta);

	// 0.20


	QString HValue = reader.readElementText();
	reader.readNext();
	reader.readNext();
	int hValue = HValue.toInt();
	cont->setHValue(hValue);

	//11

	QString SValue = reader.readElementText();
	reader.readNext();
	reader.readNext();
	int sValue = SValue.toInt();
	cont->setSValue(sValue);

	//106

	QString NoVelocityDetected = reader.readElementText();
	reader.readNext();
	reader.readNext();
	double noVelocityDetected = NoVelocityDetected.toDouble();
	cont->setNoVelocityDetected(noVelocityDetected);

	//-1.0

	QString NoAccelerationDetected = reader.readElementText();
	reader.readNext();
	reader.readNext();
	double noAccelerationDetected = NoAccelerationDetected.toDouble();
	cont->setNoAccelerationDetected(noAccelerationDetected);

	//-0.1

	QString MaxVelocity = reader.readElementText();
	reader.readNext();
	reader.readNext();
	int maxVelocity = MaxVelocity.toInt();
	cont->setMaxVelocity(maxVelocity);

	//110

	QString MaxAcceleration = reader.readElementText();
	reader.readNext();
	reader.readNext();
	int maxAcceleration = MaxAcceleration.toInt();
	cont->setMaxAcceleration(maxAcceleration);

	//3400

	QString DrawSize = reader.readElementText();
	reader.readNext();
	reader.readNext();
	int drawSize = DrawSize.toInt();
	cont->setDrawSize(drawSize);

	//30

	QString LogFile = reader.readElementText();
	reader.readNext();
	reader.readNext();
	std::string logFile = LogFile.toStdString();
	cont->setLogFile(logFile);

	//"log.txt"

	QString NetOutput = reader.readElementText();
	reader.readNext();
	reader.readNext();
	int netOutput = NetOutput.toInt();
	cont->setNetOutput(netOutput);

	//2

	QString StaticGestureOutput = reader.readElementText();
	reader.readNext();
	reader.readNext();
	int staticGestureOutput = StaticGestureOutput.toInt();
	cont->setStaticGestureOutput(staticGestureOutput);

	//1

	QString ThresholdDelta = reader.readElementText();
	reader.readNext();
	reader.readNext();
	double thresholdDelta = ThresholdDelta.toDouble();
	cont->setThresholdDelta(thresholdDelta);

	//0.2

	QString Dif = reader.readElementText();
	reader.readNext();
	reader.readNext();
	double dif = Dif.toDouble();
	cont->setDif(dif);

	//1.01

	QString Factor = reader.readElementText();
	reader.readNext();
	reader.readNext();
	double factor = Factor.toDouble();
	cont->setFactor(factor);

	//0.75

	QString configurationFolder = reader.readElementText();
	reader.readNext();
	reader.readNext();
	cont->setConfigurationFolder(configurationFolder);

	//"Configuration/"

	QString ConfigFile = reader.readElementText();
	reader.readNext();
	reader.readNext();
	std::string configFile = ConfigFile.toStdString();
	cont->setConfigFile(configFile);

	//"config.data"

	QString WorkW = reader.readElementText();
	reader.readNext();
	reader.readNext();
	int workW = WorkW.toInt();
	cont->setWorkW(workW);

	//80

	QString WorkH = reader.readElementText();
	reader.readNext();
	reader.readNext();
	int workH = WorkH.toInt();
	cont->setWorkH(workH);

	//60

	QString BufferSize = reader.readElementText();
	reader.readNext();
	reader.readNext();
	int bufferSize = BufferSize.toInt();
	cont->setBufferSize(bufferSize);

	//6

	QString RelaxedCount = reader.readElementText();
	reader.readNext();
	reader.readNext();
	int relaxedCount = RelaxedCount.toInt();
	cont->setRelaxedCount(relaxedCount);

	//3

	QString distanceCalculatorAGMString = reader.readElementText();
	reader.readNext();
	reader.readNext();
	if (distanceCalculatorAGMString.toInt()==0){
		DistanceCalculator* distanceCalculatorAGM = new EuclideanDistance();
		cont->setDistanceCalculatorAGM(distanceCalculatorAGM);
		cont->setDistanceCalculatorAGMIndex(distanceCalculatorAGMString.toInt());
	}
	//"Distancia Euclídea"

	QString NonVaryingAccelerationRate = reader.readElementText();
	reader.readNext();
	reader.readNext();
	double nonVaryingAccelerationRate = NonVaryingAccelerationRate.toDouble();
	cont->setNonVaryingAccelerationRate(nonVaryingAccelerationRate);

	//450.0

	QString AccelerationThreshold = reader.readElementText();
	reader.readNext();
	reader.readNext();
	double accelerationThreshold = AccelerationThreshold.toDouble();
	cont->setAccelerationThreshold(accelerationThreshold);

	//600.0

	QString DesaccelerationThreshold = reader.readElementText();
	reader.readNext();
	reader.readNext();
	double desaccelerationThreshold = DesaccelerationThreshold.toDouble();
	cont->setDesaccelerationThreshold(desaccelerationThreshold);

	//400.0

	QString WalkedPixels = reader.readElementText();
	reader.readNext();
	reader.readNext();
	int walkedPixels = WalkedPixels.toInt();
	cont->setWalkedPixels(walkedPixels);

	//30

	QString MinimumPointsCount = reader.readElementText();
	reader.readNext();
	reader.readNext();
	int minimumPointsCount = MinimumPointsCount.toInt();
	cont->setMinimumPointsCount(minimumPointsCount);

	//6

	QString DistanceThreshold = reader.readElementText();
	reader.readNext();
	reader.readNext();
	double distanceThreshold = DistanceThreshold.toDouble();
	cont->setDistanceThreshold(distanceThreshold);

	//0.75

	QString MaxGestureTime = reader.readElementText();
	reader.readNext();
	reader.readNext();
	double maxGestureTime = MaxGestureTime.toDouble();
	cont->setMaxGestureTime(maxGestureTime);

	//2.0

	QString valuesNormalizatorString = reader.readElementText();
	cont->setValuesNormalizatorIndex(valuesNormalizatorString.toInt());
	reader.readNext();
	reader.readNext();
	if (valuesNormalizatorString.toInt()== 0){ //"Normalizador Simple"
		SystemInfo* si = new SystemInfo(workW,workH);
		ValuesNormalizator* valuesNormalizator = new ValuesNormalizator(si);
		cont->setValuesNormalizator(valuesNormalizator);
	}


	QString RelaxedRatio = reader.readElementText();
	reader.readNext();
	reader.readNext();
	double relaxedRatio = RelaxedRatio.toDouble();
	cont->setRelaxedRatio(relaxedRatio);

	//2.0

	QString distanceCalculatorDTWString = reader.readElementText();
	cont->setDistanceCalculatorDTWIndex(distanceCalculatorDTWString.toInt());
	reader.readNext();
	reader.readNext();
	DistanceCalculator* distanceCalculatorDTW;
	if (distanceCalculatorDTWString.toInt() == 0){
		distanceCalculatorDTW = new EuclideanDistance();
		cont->setDistanceCalculatorDTW(distanceCalculatorDTW);

	}
	//Distancia Euclídea

	QString Rate = reader.readElementText();
	reader.readNext();
	reader.readNext();
	double rate = Rate.toDouble();
	cont->setRate(rate);

	//0.3

	QString dTWAlgorithmString = reader.readElementText();
	int dtwAlgorithmIndexVal = dTWAlgorithmString.toInt();
	cont->setDTWAlgorithmIndex(dtwAlgorithmIndexVal);
	DTWAlgorithm* dTWAlgorithm;
	if (dtwAlgorithmIndexVal==0)
		dTWAlgorithm = new ItakuraDTWAlgorithm(rate,distanceCalculatorDTW);
	else if (dtwAlgorithmIndexVal==1)
		dTWAlgorithm = new RawDTWAlgorithm(distanceCalculatorDTW);
	else if (dtwAlgorithmIndexVal==2)
		dTWAlgorithm = new SakoeChibaDTWAlgorithm(rate,distanceCalculatorDTW);
	cont->setDTWAlgorithm(dTWAlgorithm);

	//Paralelogramo de Itakura

	GestureModel* gestureModel = new GestureModel(dTWAlgorithm);
	cont->setGestureModel(gestureModel);

	reader.readNext();
}
