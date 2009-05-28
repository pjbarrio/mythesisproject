/*
 * DynamicGestureRecognitionAlgorithm.h
 *
 *  Created on: 30/01/2009
 *      Author: Pablo
 *
 *
 * This is the main class of the Gesture Recognition Process.
 * Here you can find the algorithm being used by the system.
 */


#ifndef DYNAMICGESTURERECOGNITIONALGORITHM_H_
#define DYNAMICGESTURERECOGNITIONALGORITHM_H_

#include "ActivationGestureMethod.h"
#include "DTWAlgorithm.h"
#include "GestureEventMapper.h"
#include "GestureRecognizer.h"
#include "DTWData.h"
#include "list.h"
#include "ValuesNormalizator.h"



class DynamicGestureRecognitionAlgorithm {
public:
	DynamicGestureRecognitionAlgorithm(GestureModel*, ActivationGestureMethod*,
			double, DTWAlgorithm*,ValuesNormalizator*);
	virtual ~DynamicGestureRecognitionAlgorithm();
	void addNewInput(double x, double y, double t);


private:
	void DeactivationDetected();
	void NoChangeDetected();
	void ActivationDetected();
	void ErroneusGestureActivation();
	void nothingImportantHappenning();
	void setActualInput(double,double,double);
	void storeInput();
	void cleanBuffers();
	ValuesNormalizator* valuesNormalizator;
	ActivationGestureMethod *agm;
	DTWAlgorithm *dtwalgorithm;
	GestureRecognizer *gr;
	DTWData *tx;
	DTWData *ty;
	GestureEventMapper *gestureEventMapper;
	GestureModel *gestureModel;
	list<double> *lx;
	list<double> *ly;
	list<double> *lt;
	double actualX;
	double actualY;
	double actualT;
	int acdvalue;
	bool inGesture;
	double relaxedRatio;
	double getRelaxedRatio() const {return relaxedRatio;}
	ActivationGestureMethod *getAgm() const {return agm;}
    void setAgm(ActivationGestureMethod *agm) {this->agm = agm;}
    DTWAlgorithm *getDtwalgorithm() const {return dtwalgorithm;}
    GestureRecognizer *getGr() const {return gr;}
    DTWData *getTx() const {return tx;}
    DTWData *getTy() const {return ty;}
    GestureEventMapper *getGestureEventMapper() const {return gestureEventMapper;}
    GestureModel *getGestureModel() const {return gestureModel;}
    void setDtwalgorithm(DTWAlgorithm *dtwalgorithm) {this->dtwalgorithm = dtwalgorithm;}
    bool getInGesture() const {return inGesture;}
    void setInGesture(bool inGesture){this->inGesture = inGesture;}
    double getActualX() const {return actualX;}
    void setActualX(double actualX) {this->actualX = actualX;}
    double getActualY() const {return actualY;}
    void setActualY(double actualY) {this->actualY = actualY;}
    double getActualT() const {return actualT;}
    void setActualT(double actualT) {this->actualT = actualT;}
    void RecognizeMotionDetected();
    void storeDatafromActivationGestureMethod();

};

#endif /* DYNAMICGESTURERECOGNITIONALGORITHM_H_ */
