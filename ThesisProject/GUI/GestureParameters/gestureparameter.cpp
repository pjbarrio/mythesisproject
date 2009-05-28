#include "gestureparameter.h"

GestureParameter::GestureParameter(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
}

GestureParameter::~GestureParameter()
{

}

/*
 * This method updates the maximum number of values to detect
 * a gesture.
 */

void GestureParameter::setDetectedCount(int maxValue){
	ui.relaxedCount->setMaximum(maxValue);
}

/*
 * This method updates the maximum ratio allowed to remove when
 * a gesture es detected.
 */

void GestureParameter::setMaxRelatedRatio(int maxValue){
	ui.relaxedRatio->setMaximum(maxValue);
}
