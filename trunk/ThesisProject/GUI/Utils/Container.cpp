/*
 * Container.cpp
 *
 *  Created on: 05/05/2009
 *      Author: Pablo
 */

#include "Container.h"
#include "../../QtOpenCV/qcv/qcvimage.h"

/*
 * This line initializes the Container instance.
 */

Container* Container::instance = 0;


/*
 * This method initializes the model variables.
 */

Container::Container() {
 tp = 0;
 cv = 0;
 isclosed = false;
 ls = 0;
 log = 0;
 fi = 0;
 image = 0;
 filterHandler = 0;
 configHandler = 0;
 rotateX = false;
 rotateY = false;
}

/*
 * This method removes the variables model's values.
 */

Container::~Container() {
	 tp = 0;
	 cv = 0;
	 isclosed = false;
	 ls = 0;
	 log = 0;
	 fi = 0;
	 image = 0;
	 filterHandler = 0;
	 configHandler = 0;
	 rotateX = false;
	 rotateY = false;
}

/*
 * This method creates a new instance of CamViewer associated
 * with the QLabel passed by parameter.
 */

void Container::createCamViewerInstance(QLabel *label)
{
	setCamViewer(new CamViewer(label));

	getCamViewer()->setCapturing(true);

	getCamViewer()->start();
}

/*
 * This method tranforms the filtered image in
 * a PixMap ready to be showed by a label.
 */

void Container::setFilteredImage(IplImage *img)
{
	filteredImageAccess.lock();

	IplImage* clone = cvCreateImage(cvSize(240,180), IPL_DEPTH_8U, 1);
	cvResize(img,clone,1);

	if (fi!=0)
		delete (fi);
	fi = new QPixmap(qcvQPixmap(clone));

	cvReleaseImage(&clone);

	fiset = true;

	filteredImageAccess.unlock();

	fiWaitCondition.wakeAll();
}

/*
 * This method returns the filtered Image
 */
QPixmap* Container::getFilteredImage()
{
	QPixmap* ret;
	filteredImageAccess.lock();

	while (!fiset)
		fiWaitCondition.wait(&filteredImageAccess);

	fiset = false;

	ret = fi;

	filteredImageAccess.unlock();

	return ret;
}

/*
 * This method wakes up the waiting threads to
 * finish the application
 */

void Container::wakeAll(){
	fiWaitCondition.wakeAll();
}

/*
 * This method sets the values: Rotate Horizontally, Rotate Vertically, Suppor Gestures, Support
 * State Visualizator, Cursor support, Open Hand Click activation, Close Hand Click activation.
 */

void Container::setModel(bool rx, bool ry, bool gs, bool ss, bool vp, bool cs, bool cc, bool oc)
{
	rotateX = rx;
	rotateY = ry;
	gestureSupport = gs;
	stateSupport = ss;
	viewPointer = vp;
	clickSupport = cs;
	closeClick = cc;
	openClick = oc;
}

/*
 * This method returns the Container instance.
 */

Container *Container::getInstance()
{
	if (instance == 0){
		instance = new Container();
	}

	return instance;
}

/*
 * This method finishes the current instance of CamViewer.
 */

void Container::finishCamViewer(){

	getCamViewer()->setCapturing(false);

	getCamViewer()->wait();

}

/*
 * This method returns the active LoggerHandler instance.
 */

LogHandler* Container::getLog(){

	logAccess.lock();

	if (log==0){
		log = new LogHandler();
		log->initLogger();
	}

	logAccess.unlock();

	return log;
}

/*
 * This method returns the active ConfigHandler instance.
 */

ConfigHandler* Container::getConfigHandler(){

	configHandlerAccess.lock();

	if (configHandler == 0){
		configHandler = new ConfigHandler(getLog());
		if ( !configHandler->openConfigFile("config.data") ){

			getLog()->closeLogger();

			return 0;

		}
	}

	configHandlerAccess.unlock();

	return configHandler;
}

/*
 * This method returns the LightStabilizer instance.
 */

LightStabilizer* Container::getLightStabilizer(){

	lightStabilizerAccess.lock();

	if (ls==0){
		ls = new LightStabilizer(getLog());
	}

	lightStabilizerAccess.unlock();

	return ls;
}

/*
 * This method returns the FilterHandler instance.
 */

FilterHandler* Container::getFilterHandler(){

	filterHandlerAccess.lock();

	if (filterHandler == 0){
		filterHandler = new FilterHandler(getLog());
		filterHandler->setSkinMaskFile(getConfigHandler()->getSkinMaskFile());
		filterHandler->setSkinDelta(getConfigHandler()->getSkinDelta());
		filterHandler->init();
	}

	filterHandlerAccess.unlock();

	return filterHandler;
}

/*
 * This method creates a new video instance.
 */

void Container::createVideo(){
	video = new QList<IplImage*>();
}

/*
 * This methods append a frame to the active video instance.
 */

void Container::addFrame(IplImage* img){
	video->append(img);
}

/*
 * This method returns the created video.
 */

QList<IplImage*>* Container::getVideo(){
	return video;
}

/*
 * This method deletes the last video instance.
 */

void Container::deleteVideo(){
	delete video;
}

