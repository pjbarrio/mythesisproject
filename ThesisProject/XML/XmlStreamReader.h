/*
 * XmlStreamReader.h
 *
 *  Created on: 10/05/2009
 *      Author: Pablo
 *
 * This class read the configuration file and fill the models provided in the constructor.
 */

#ifndef XMLSTREAMREADER_H_
#define XMLSTREAMREADER_H_

#include <QString>
#include "../DynamicGestureRecognition/src/GestureModel.h"
#include "../DynamicGestureRecognition/src/EventModel.h"
#include <QXmlStreamReader>
#include "windows.h"
#include "../DynamicGestureRecognition/Events/CombinedKeyPressed.h"

class XmlStreamReader {
public:
	XmlStreamReader(GestureModel* , EventModel* , EventModel* ,
			EventModel* , EventModel* );
	virtual ~XmlStreamReader();
	bool readFile(const QString &fileName);

private:

	void readConfigurationElement();
	void readGesturesElement();
	void readGestureElement(QString);
	void readPairElement(DTWData*, DTWData*);
	BYTE getKeyCode(QString);
	void readEventsElement();
	void readKeyEventsElements();
	void readKeyEventElement(QString);
	void readCombinedKeyEventsElements();
	void readCombinedKeyEventElement(QString);
	CombinedKeyPressed* createCombinedKeyPressed(QString,QList<QString>);
	void readApplicationEventsElements();
	void readApplicationEventElement(QString);
	void readFileEventsElements();
	void readFileEventElement(QString);
	void readAssociationsElement();
	void readAssociationElement(QString);

	QXmlStreamReader reader;

	GestureModel* gestureModel;
	EventModel* keyEventModel;
	EventModel* combinedKeyEventModel;
	EventModel* appEventModel;
	EventModel* fileEventModel;

    QString UP_STR;
    QString DOWN_STR;
    QString RIGHT_STR;
    QString LEFT_STR;
    QString ESC_STR;
    QString SPACE_STR;
    QString INTRO_STR;
    QString TAB_STR;
    QString F5_STR;
    QString PGUP_STR;
    QString PGDN_STR;
    QString ALT_STR;
    QString ALTTAB_STR;
};

#endif /* XMLSTREAMREADER_H_ */
