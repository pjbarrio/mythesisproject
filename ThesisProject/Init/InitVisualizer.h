/*
 * InitVisualizer.h
 *
 *  Created on: 02/05/2009
 *      Author: Pablo
 *
 * This class has the responsability of produces the interaction
 * beetween the tracker and the state visualizator.
 */

#ifndef INITVISUALIZER_H_
#define INITVISUALIZER_H_

#include "../CommonProject/InterfaceWorker/Initializer.h"
#include "../CommonProject/src/CoordsGetter.h"
#include "../Utils/SystemInfo.h"
#include "../mainwindow.h"
#include "../GUI/Estado/stateviewer.h"
#include "../DynamicGestureRecognition/src/DistanceCalculator.h"
#include "../DynamicGestureRecognition/DistanceCalculators/EuclideanDistance.h"
#include <QPixmap>


class InitVisualizer: public Initializer {
public:
	InitVisualizer(CoordsGetter*, SystemInfo*,ThesisProject*, StateViewer*);
	virtual ~InitVisualizer();
	void setNewInput(double,double,double);
	void init();
private:
	CircularBuffer* cb1;
	CircularBuffer* cb2;

	QPixmap* open_Hand;
	QPixmap* close_Hand;
	bool firstXY;
	double lastX;
	double lastY;
	double lastT;
	bool firstVelocity;
	double lastVelocity;
	SystemInfo* systemInfo;
	ThesisProject* tp;
	StateViewer* sv;
	QPixmap* getFilteredImage();
	bool getIsClosed();
	double getVelocity(double,double,double);
	double getAcceleration(double,double);
	void drawPoints(double,double);
	void updateVelocityDrawer(double);
	void updateAccelerationDrawer(double);
	void drawFilteredImage(QPixmap*);
	static const double NO_VELOCITY_DETECTED = -1.0;
	static const double NO_ACCELERATION_DETECTED = -0.1;
	static const double MAX_VELOCITY = 10000.0;
	static const double MAX_ACCELERATION = 10000.0;
	static const int DRAW_SIZE = 15;
	DistanceCalculator* distanceCalculator;
	void writeCoords(double,double);
	void drawHand(bool);
	void drawOpen();
	void drawClosed();
};

#endif /* INITVISUALIZER_H_ */

