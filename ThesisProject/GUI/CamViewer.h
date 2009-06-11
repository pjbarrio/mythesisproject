/**
 * CamViewer.h
 *
 *  Created on: 28/04/2009
 *      \author  Pablo
 * This class has the responsability of integrating GUI
 * with OpenCV. This class will show the captured images on
 * labels used in the Dialog Windows.
 */

#ifndef CAMVIEWER_H_
#define CAMVIEWER_H_
#include <QThread>
#include <QLabel>
#include <QMainWindow>
#include <QImage>
#include <cv.h>
#include <highgui.h>
#include <QMutex>
#include "../mainwindow.h"
#include <QList>







class CamViewer : public QThread {
public:
	CamViewer(QLabel*);
	virtual ~CamViewer();
	void run();
	void captureFrame();
	void setCapturing(bool);
	void setSaveFrame(bool);
	bool getSaveFrame();
	void init();
	void setSaveVideo(bool);
private:
	bool getSaveVideo();
	QMutex* mutex;
	QMutex saveVideoAccess;
	QMutex* capturingMutex;
	QLabel* dst;
	CvCapture* capture;
	IplImage* img;
	IplImage* imgdst;
	QImage* image;
	bool capturing;
	bool save;
	int width;
	int height;
	bool saveVideo;
};

#endif /** CAMVIEWER_H_ */
