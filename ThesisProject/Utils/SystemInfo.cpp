/*
 * SystemInfo.cpp
 *
 *  Created on: 08-feb-2009
 *      Author: Timpa
 */

#include "SystemInfo.h"
#include <windows.h>
#include <sstream>
#include <fstream>
#include <iomanip>

/*
 * This constructor method initializes the variables used to work
 */

SystemInfo::SystemInfo(int width,int height) {

	workw = width;

	workh = height;

	this->width = GetSystemMetrics(SM_CXSCREEN);

	this->height = GetSystemMetrics(SM_CYSCREEN);

}

SystemInfo::~SystemInfo() {
	;
}

/*
 * This method instantiates the variables passed by parameter
 * with the values which represent the screen resolution.
 */

void SystemInfo::getSystemResolution(int & x, int & y)
{

	 x = width ;

	 y = height ;


}

/*
 * This method instantiates the variables passed by parameter
 * with the values which represent the resolution used to work.
 * by default this is 80 x 60.
 */

void SystemInfo::getSystemWorkResolution(int & ww, int & wh)
{
	ww = workw;

	wh = workh;
}

/*
 * This method return the ratio beetween the screen resolution
 * and work resolution.
 */

void SystemInfo::getSystemRatio(int &x ,int &y )
{

	x = width / workw ;

	y = height / workh ;

}






