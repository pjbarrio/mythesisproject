/**
 * Camera.cpp
 *
 *  Created on: 08/05/2009
 *      \author  Pablo
 */

#include "Camera.h"

/**
 * This constructor method saves the LogHandler object
 */

Camera::Camera(LogHandler* log) {
	this->logger = log;
}

/**
 * This destructor method removes the reference to the logger
 * Object.
 */

Camera::~Camera() {
	logger = 0;
}
