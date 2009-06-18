/**
 * XMLParametersWriter.cpp
 *
 *  Created on: 12/06/2009
 *      Author: Pablo
 */

#include "XMLParametersWriter.h"
#include "../GUI/Utils/Container.h"
#include <QFile>
#include "../GUI/Utils/NeuralNetParameters.h"

XMLParametersWriter::XMLParametersWriter() {

}

XMLParametersWriter::~XMLParametersWriter() {
}

/**
 * This method starts the XML File
 */

bool XMLParametersWriter::writeXML(const QString & fileName)
{
	QFile file(fileName);
	if (!file.open(QFile::WriteOnly | QFile::Text)) {
		std::cerr << "Error: Cannot write file "
				  << qPrintable(fileName) << ": "
				  << qPrintable(file.errorString()) << std::endl;
		return false;
	}

	xmlWriter = new QXmlStreamWriter(&file);
	xmlWriter->setAutoFormatting(true);
	xmlWriter->writeStartDocument();
	xmlWriter->writeStartElement("Parameters");

	writeParametersElement();

	xmlWriter->writeEndElement();
	xmlWriter->writeEndDocument();
	file.close();
	if (file.error()) {
		std::cerr << "Error: No se puede escribir en el archivo "
				  << qPrintable(fileName) << ": "
				  << qPrintable(file.errorString()) << std::endl;
		return false;
	}

	return true;

}


/**
 * This method saves the Parameter Element
 */

void XMLParametersWriter::writeParametersElement()
{
	Container* cont = Container::getInstance();
	NeuralNetParameters* nnpar = NeuralNetParameters::getInstance();

	std::string tnf = cont->getTnf();

	xmlWriter->writeTextElement("TrackerNetFile",QString(tnf.c_str()));

	//"NetDesktopSkin.net"

	std::string gnf = cont->getGnf();

	xmlWriter->writeTextElement("GestureNetFile",QString(gnf.c_str()));
	//"Net_Desktop_skin_Gesture_2096.net"

	double gestureThreshold = cont->getGestureThreshold();
	xmlWriter->writeTextElement("GestureThreshold",QString::number(gestureThreshold));

	//50.0

	int maxFramesToAnalize = cont->getMaxFramesToAnalize();
	xmlWriter->writeTextElement("MaxFramesToAnalize",QString::number(maxFramesToAnalize));

	//20

	double lightStabilizerThresholdDelta = cont->getLightStabilizerThresholdDelta();
	xmlWriter->writeTextElement("LightStabilizerThresholdDelta",QString::number(lightStabilizerThresholdDelta));

	//0.20

	int skinDelta = cont->getSkinDelta();
	xmlWriter->writeTextElement("SkinDelta",QString::number(skinDelta));

	//42

	double normalizedTime = cont->getNormalizedTime();
	xmlWriter->writeTextElement("NormalizedTime",QString::number(normalizedTime));

	// 2.0;

	double maxAcceptedDTWValue = cont->getMaxAcceptedDTWValue();
	xmlWriter->writeTextElement("MaxAcceptedDTWValue",QString::number(maxAcceptedDTWValue));

	// 500.0;

	int xValueDis = cont->getXValueDis();
	xmlWriter->writeTextElement("XValueDisernible",QString::number(xValueDis));

	//-1

	int yValueDis = cont->getYValueDis();
	xmlWriter->writeTextElement("YValueDisernible",QString::number(yValueDis));

	//-1

	int sleepValue = cont->getSleepValue();
	xmlWriter->writeTextElement("SleepValue",QString::number(sleepValue));

	//1

	int inputSize = nnpar->getInputSize();
	xmlWriter->writeTextElement("InputSize",QString::number(inputSize));

	// 4800

	int k_factor = cont->getK_Factor();
	xmlWriter->writeTextElement("K_FACTOR",QString::number(k_factor));

	// 1

	int frameWindow = cont->getFrameWindow();
	xmlWriter->writeTextElement("FrameWindow",QString::number(frameWindow));

	// 5

	double delta = cont->getDelta();
	xmlWriter->writeTextElement("Delta",QString::number(delta));

	// 0.20


	int hValue = cont->getHValue();
	xmlWriter->writeTextElement("HValue",QString::number(hValue));

	//11

	int sValue = cont->getSValue();
	xmlWriter->writeTextElement("SValue",QString::number(sValue));


	//106

	double noVelocityDetected = cont->getNoVelocityDetected();
	xmlWriter->writeTextElement("NoVelocityDetected",QString::number(noVelocityDetected));

	//-1.0

	double noAccelerationDetected = cont->getNoAccelerationDetected();
	xmlWriter->writeTextElement("NoAccelerationDetected",QString::number(noAccelerationDetected));

	//-0.1

	int maxVelocity = cont->getMaxVelocity();
	xmlWriter->writeTextElement("MaxVelocity",QString::number(maxVelocity));

	//110

	int maxAcceleration = cont->getMaxAcceleration();
	xmlWriter->writeTextElement("MaxAcceleration",QString::number(maxAcceleration));

	//3400

	int drawSize = cont->getDrawSize();
	xmlWriter->writeTextElement("DrawSize",QString::number(drawSize));

	//30

	std::string logFile = cont->getLogFile();
	xmlWriter->writeTextElement("LogFile",QString(logFile.c_str()));

	//"log.txt"

	int netOutput = nnpar->getNetOutput();
	xmlWriter->writeTextElement("NetOutPut",QString::number(netOutput));

	//2

	int staticGestureOutput = nnpar->getStaticGestureOutput();
	xmlWriter->writeTextElement("StaticGestureOutput",QString::number(staticGestureOutput));

	//1

	double thresholdDelta = cont->getThresholdDelta();
	xmlWriter->writeTextElement("ThresholdDelta",QString::number(thresholdDelta));

	//0.2

	double dif = cont->getDif();
	xmlWriter->writeTextElement("Dif",QString::number(dif));

	//1.01

	double factor = cont->getFactor();
	xmlWriter->writeTextElement("Factor",QString::number(factor));

	//0.75

	QString configurationFolder = cont->getConfigurationFolder();
	xmlWriter->writeTextElement("ConfigurationFolder",configurationFolder);

	//"Configuration/"

	std::string configFile = cont->getConfigFile();
	xmlWriter->writeTextElement("ConfigFile",QString(configFile.c_str()));

	//"config.data"

	int workW = cont->getWorkW();
	xmlWriter->writeTextElement("WorkW",QString::number(workW));

	//80

	int workH = cont->getWorkH();
	xmlWriter->writeTextElement("WorkH",QString::number(workH));

	//60

	int bufferSize = cont->getBufferSize();
	xmlWriter->writeTextElement("BufferSize",QString::number(bufferSize));

	//6

	int relaxedCount = cont->getRelaxedCount();
	xmlWriter->writeTextElement("RelaxedCount",QString::number(relaxedCount));

	//3

	int distanceCalculatorAGMIndex = cont->getDistanceCalculatorAGMIndex();
	xmlWriter->writeTextElement("DistanceCalculatorAGMIndex",QString::number(distanceCalculatorAGMIndex));
	//0

	double nonVaryingAccelerationRate = cont->getNonVaryingAccelerationRate();
	xmlWriter->writeTextElement("NonVaryingAccelerationRate",QString::number(nonVaryingAccelerationRate));

	//450.0

	double accelerationThreshold = cont->getAccelerationThreshold();
	xmlWriter->writeTextElement("AccelerationThreshold",QString::number(accelerationThreshold));

	//600.0

	double desaccelerationThreshold = cont->getDesaccelerationThreshold();
	xmlWriter->writeTextElement("DesaccelerationThreshold",QString::number(desaccelerationThreshold));

	//400.0

	int walkedPixels = cont->getWalkedPixels();
	xmlWriter->writeTextElement("WalkedPixel",QString::number(walkedPixels));

	//30

	int minimumPointsCount = cont->getMinimumPointsCount();
	xmlWriter->writeTextElement("MinimumPointsCount",QString::number(minimumPointsCount));

	//6

	double distanceThreshold = cont->getDistanceThreshold();
	xmlWriter->writeTextElement("DistanceThreshold",QString::number(distanceThreshold));

	//0.75

	double maxGestureTime = cont->getMaxGestureTime();
	xmlWriter->writeTextElement("MaxGestureTime",QString::number(maxGestureTime));

	//2.0

	int valuesNormalizatorIndex = cont->getValuesNormalizatorIndex();
	xmlWriter->writeTextElement("ValuesNormalizatorIndex",QString::number(valuesNormalizatorIndex));

	//"0"

	double relaxedRatio = cont->getRelaxedRatio();
	xmlWriter->writeTextElement("RelaxedRatio",QString::number(relaxedRatio));

	//2.0

	int distanceCalculatorDTWIndex = cont->getDistanceCalculatorDTWIndex();
	xmlWriter->writeTextElement("DistanceCalculatorDTWIndex",QString::number(distanceCalculatorDTWIndex));
	//0

	double rate = cont->getRate();
	xmlWriter->writeTextElement("Rate",QString::number(rate));

	//0.3

	int dTWAlgorithmIndex = cont->getDTWAlgorithmIndex();
	xmlWriter->writeTextElement("DTWAlgorithmIndex",QString::number(dTWAlgorithmIndex));
	//0

	int frequency = cont->getFrequency();
	xmlWriter->writeTextElement("Frequency",QString::number(frequency));
}


