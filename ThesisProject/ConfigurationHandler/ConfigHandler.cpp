/**
 * ConfigHandler.cpp
 *
 *  Created on: 05-feb-2009
 *      \author  Timpa
 */

#include "ConfigHandler.h"
#include "../GUI/Utils/Container.h"

/**
 * This constructor method stores the LogHandler object to inform the events
 * that will happen inside of this reference.
 */

ConfigHandler::ConfigHandler(LogHandler* logger) {

	this->logger = logger;

	componenetName = "Configurator";

}

/**
 * This method dereferences the logger object.
 */

ConfigHandler::~ConfigHandler() {
	this->logger = 0;
}

/**
 * This method returns the name of the file which has the
 * ANN complex configuration to detect position.
 */

std::string ConfigHandler::getTrackerNetFile()
{

	return Container::getInstance()->getTnf();

	//return "NetDesktopskin_23125.net"; //anda bien!

}

/**
 * This method returns the name of the file which has
 * the ANN configuration to detect hand states (Opened / Closed)
 */

std::string ConfigHandler::getGestureNetFile()
{

	return Container::getInstance()->getGnf();

}

/**
 * This method opens the configuration from the configFile
 * passed by parameter.
 */

bool ConfigHandler::openConfigFile(std::string configFile)
{

	std::string entry = "Config File: " + configFile + " loaded";

	logger->addEntry(componenetName,entry);

	return true;

}

/**
 * This method returns the threshold used to differentiate
 * both hand states (Open/Close).
 */

float ConfigHandler::getGestureThreshold()
{
	return Container::getInstance()->getGestureThreshold();

}

/**
 * This method returns the count of frame which will be
 * retrieved from the camera source.
 */

int ConfigHandler::getMax_frames_to_analize()
{

	return Container::getInstance()->getMaxFramesToAnalize();

}

/**
 * This method return the name of the file which stores
 * the image used to represent the skin Mask.
 */

std::string ConfigHandler::getSkinMaskFile()
{

	return ":/SkinMask/skin.jpg";

}

/**
 * This method returns the threshold used to differentiate
 * the hand state during the diagnostic execution.
 */

float ConfigHandler::getLightStabilizerThresholdDelta()
{
	return Container::getInstance()->getThresholdDelta(); // es un valor para ver cuando paso de un estado de mano abierta a cerrada o viceversa

}

/**
 * This method returns the delta value used to represent
 * skin.
 */

int ConfigHandler::getSkinDelta()
{

	logger->addEntry(componenetName,"El valor delta debe ser mayor a cero. Se uso el valor por defecto--> delta = 42");
	return Container::getInstance()->getSkinDelta();//es el valor del umbral para decidir si es piel o no


}














