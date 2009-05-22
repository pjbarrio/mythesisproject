/*
 * XMLStreamWriter.h
 *
 *  Created on: 10/05/2009
 *      Author: Pablo
 *
 * This class is used to write the xml configuration file.
 */

#ifndef XMLSTREAMWRITER_H_
#define XMLSTREAMWRITER_H_
#include "../DynamicGestureRecognition/src/Gesture.h"
#include "../DynamicGestureRecognition/src/Event.h"
#include "../DynamicGestureRecognition/src/GestureModel.h"
#include "../DynamicGestureRecognition/src/EventModel.h"
#include <QString>
#include <QXmlStreamWriter>
#include "../DynamicGestureRecognition/src/GestureEventMapper.h"

class XMLStreamWriter {
public:
	XMLStreamWriter();
	virtual ~XMLStreamWriter();
	bool writeXML(const QString &fileName,GestureModel*,
			EventModel*,EventModel*, EventModel*, EventModel*, GestureEventMapper*);
private:
	void writeGestures(GestureModel*);
	void writeGesture(Gesture*);
	void writeEvents(EventModel*,EventModel*,EventModel*,EventModel*);
	void writeKeyEvents(EventModel* eventModel);
	void writeKeyEvent(Event*);
	void writeCombinedKeyEvents(EventModel* eventModel);
	void writeCombinedKeyEvent(Event*);
	void writeApplicationEvents(EventModel* eventModel);
	void writeApplicationEvent(Event*);
	void writeOpenFileEvents(EventModel* eventModel);
	void writeOpenFileEvent(Event*);
	void writeAssociations(GestureEventMapper*);
	void writeAssociation(Gesture*,Event*,bool);
	QXmlStreamWriter* xmlWriter;
};

#endif /* XMLSTREAMWRITER_H_ */
