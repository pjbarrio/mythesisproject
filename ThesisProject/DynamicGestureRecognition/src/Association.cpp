/*
 * Association.cpp
 *
 *  Created on: 21/05/2009
 *      Author: Pablo
 */

#include "Association.h"

/*
 * This method initializes the instance objects.
 */

Association::Association() {
	gesture = 0;
	event = 0;
	activated = false;

}

/*
 * this method dereferences the instance objects
 */

Association::~Association() {
	gesture = 0;
	event = 0;
	activated = false;
}
