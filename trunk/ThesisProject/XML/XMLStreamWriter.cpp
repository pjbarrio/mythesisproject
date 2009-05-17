/*
 * XMLStreamWriter.cpp
 *
 *  Created on: 10/05/2009
 *      Author: Pablo
 */

#include "XMLStreamWriter.h"
#include <QFile>

/*
 * This Method creates an XMLStreamWriter object
 */

XMLStreamWriter::XMLStreamWriter() {
	;

}

/*
 * This Method deletes the XMLStreamWriter object
 */

XMLStreamWriter::~XMLStreamWriter() {
	;
}

/*
 * This method write the models (Events , Gestures & Associations) in the configuration file.
 */

bool XMLStreamWriter::writeXML(const QString & fileName,GestureModel* gestureModel,
		EventModel* key,EventModel* ckey, EventModel* app, EventModel* fi)
{
	QFile file(fileName);
	if (!file.open(QFile::WriteOnly | QFile::Text)) {
		std::cerr << "Error: Cannot write file "
				  << qPrintable(fileName) << ": "
				  << qPrintable(file.errorString()) << std::endl;
		return false;
	}

	QXmlStreamWriter xmlWriter(&file);
	xmlWriter.setAutoFormatting(true);
	xmlWriter.writeStartDocument();
	xmlWriter.writeStartElement("Configuration");

	writeGestures(gestureModel);
	writeEvents(key,ckey,app,fi);
	writeAssociations();

	xmlWriter.writeEndElement();
	xmlWriter.writeEndDocument();
	file.close();
	if (file.error()) {
		std::cerr << "Error: No se puede escribir en el archivo "
				  << qPrintable(fileName) << ": "
				  << qPrintable(file.errorString()) << std::endl;
		return false;
	}

	return true;

}

/*
 * This method writes the xml Gestures tag.
 */

void XMLStreamWriter::writeGestures(GestureModel* gestureModel){
	xmlWriter.writeStartElement("Gestures");

	gestureModel->begin();
	while (gestureModel->hasNext()){
		Gesture* gesture = gestureModel->getNextGesture();
		writeGesture(gesture);
		gestureModel->next();
	}

	xmlWriter.writeEndElement();
}

/*
 * This method writes a Gesture tag representing the gesture passed by parameter
 */

void XMLStreamWriter::writeGesture(Gesture* gesture){
	xmlWriter.writeStartElement("Gesture");
	xmlWriter.writeAttribute("id",QString(gesture->getId().c_str()));

	DTWData* tx = gesture->getTx();
	DTWData* ty = gesture->getTy();

	tx->begin();
	ty->begin();

	double x;
	double y;
	double t;

	while(tx->hasNext()){
		x = tx->getY();
		y = ty->getY();

		xmlWriter.writeStartElement("Pair");

		xmlWriter.writeTextElement("X",QString::number(x));
		xmlWriter.writeTextElement("Y",QString::number(y));
		xmlWriter.writeTextElement("T",QString::number(t));

		xmlWriter.writeEndElement();

		tx->next();
		ty->next();
	}

	xmlWriter.writeEndElement();
}

/*
 * This method writes the Events tag using every EventModel in the application.
 */

void XMLStreamWriter::writeEvents(EventModel* K,EventModel*C,EventModel*A,EventModel*O){
	xmlWriter.writeStartElement("Events");
	writeKeyEvents(K);
	writeCombinedKeyEvents(C);
	writeApplicationEvents(A);
	writeOpenFileEvents(O);
	xmlWriter.writeEndElement();
}

/*
 * This Method writes the KeyEvents tag using the eventModel passed by parameter.
 */

void XMLStreamWriter::writeKeyEvents(EventModel* eventModel){
	xmlWriter.writeStartElement("KeyEvents");
	eventModel->begin();
	while (eventModel->hasNext()){
		Event* event = eventModel->getNextEvent();
		writeKeyEvent(event);
		eventModel->next();
	}
	xmlWriter.writeEndElement();
}

/*
 * This method invokes the writeXML of the Keyevent passed by parameter
 */

void XMLStreamWriter::writeKeyEvent(Event* event){
	event->writeXML(&xmlWriter);
}

/*
 * This Method writes the CombinedKeyEvents tag using the eventModel passed by parameter.
 */

void XMLStreamWriter::writeCombinedKeyEvents(EventModel* eventModel){
	xmlWriter.writeStartElement("CombinedKeyEvents");
	eventModel->begin();
	while (eventModel->hasNext()){
		Event* event = eventModel->getNextEvent();
		writeCombinedKeyEvent(event);
		eventModel->next();
	}
	xmlWriter.writeEndElement();
}

/*
 * This method invokes the writeXML of the CombinedKeyevent passed by parameter
 */

void XMLStreamWriter::writeCombinedKeyEvent(Event* event){
	event->writeXML(&xmlWriter);
}

/*
 * This Method writes the AppEvents tag using the eventModel passed by parameter.
 */

void XMLStreamWriter::writeApplicationEvents(EventModel* eventModel){
	xmlWriter.writeStartElement("AppEvents");
	eventModel->begin();
	while (eventModel->hasNext()){
		Event* event = eventModel->getNextEvent();
		writeApplicationEvent(event);
		eventModel->next();
	}
	xmlWriter.writeEndElement();
}

/*
 * This method invokes the writeXML of the ApplicationEvent passed by parameter
 */

void XMLStreamWriter::writeApplicationEvent(Event* event){
	event->writeXML(&xmlWriter);
}

/*
 * This Method writes the FileEvents tag using the eventModel passed by parameter.
 */

void XMLStreamWriter::writeOpenFileEvents(EventModel* eventModel){
	xmlWriter.writeStartElement("FileEvents");
	eventModel->begin();
	while (eventModel->hasNext()){
		Event* event = eventModel->getNextEvent();
		writeOpenFileEvent(event);
		eventModel->next();
	}
	xmlWriter.writeEndElement();
}

/*
 * This method invokes the writeXML of the OpenFileEvent passed by parameter
 */

void XMLStreamWriter::writeOpenFileEvent(Event* event){
	event->writeXML(&xmlWriter);
}

/*
 * This Method writes the Associations tag using the GestureEventMapper filled by the application.
 */

void XMLStreamWriter::writeAssociations(){
	xmlWriter.writeStartElement("Associations");
	//TODO falta associations
	xmlWriter.writeEndElement();
}

/*
 * This Method write the association tag generated by the gesture & event
 */

void XMLStreamWriter::writeAssociation(Gesture* gesture, Event* event){
	//TODO Implement method write association
}

