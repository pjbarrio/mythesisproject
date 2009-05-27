/*
 * XmlStreamReader.cpp
 *
 *  Created on: 10/05/2009
 *      Author: Pablo
 */

#include "XmlStreamReader.h"
#include <QFile>
#include "string.h"
#include "../DynamicGestureRecognition/Events/OpenFileEvent.h"
#include "../DynamicGestureRecognition/Events/ExecuteApplication.h"
#include "../DynamicGestureRecognition/src/GestureEventMapper.h"

/*
 * This method creates the XmlStreamReader object and fill the models passed by parameter. Besides, initializes the variables
 * which represent the keys used by Press Key Events.
 */

XmlStreamReader::XmlStreamReader(GestureModel* gm, EventModel* k, EventModel* ck,
		EventModel* a, EventModel* f, GestureEventMapper* gem) {
	gestureModel = gm;
	keyEventModel = k;
	combinedKeyEventModel = ck;
	appEventModel = a;
	fileEventModel = f;
	this->gem = gem;
	UP_STR = QString("Up");
	DOWN_STR = QString("Down");
	RIGHT_STR = QString("Right");
	LEFT_STR = QString("Left");
	ESC_STR = QString("Esc");
	SPACE_STR = QString("Space");
	INTRO_STR = QString("Intro");
	TAB_STR = QString("Tab");
	F5_STR = QString("F5");
	PGUP_STR = QString("Pg.Up");
	PGDN_STR = QString("Pg.Dn");
	ALTTAB_STR = QString("Alt+Tab");
	ALT_STR = QString("Alt");
}

/*
 * This method represent the destructor of the XmlStreamReader object.
 */

XmlStreamReader::~XmlStreamReader() {
	gestureModel = 0;
	keyEventModel = 0;
	combinedKeyEventModel = 0;
	appEventModel = 0;
	fileEventModel = 0;
	gem = 0;
}

/*
 * This method read the file passed by parameter.
 */

bool XmlStreamReader::readFile(const QString & fileName)
{
	QFile file(fileName);
	if (!file.open(QFile::ReadOnly | QFile::Text)) {
		std::cerr << "Error: No es posible abrir " << qPrintable(fileName)
				  << ": " << qPrintable(file.errorString())
				  << std::endl;
		return false;
	}
	reader.setDevice(&file);

    reader.readNext();
    while (!reader.atEnd()) {
        if (reader.isStartElement()) {
            if (reader.name() == "Configuration") {
                readConfigurationElement();
            } else {
                reader.raiseError(QObject::tr("Este archivo no contiene Configuración"));
            }
        } else {
            reader.readNext();
        }
    }

    file.close();
	if (reader.hasError()) {
		std::cerr << "Error: Se ha fallado al parsear el archivo "
				  << qPrintable(fileName) << ": "
				  << qPrintable(reader.errorString()) << std::endl;
		return false;
	} else if (file.error() != QFile::NoError) {
		std::cerr << "Error: No se puede leer el archivo " << qPrintable(fileName)
				  << ": " << qPrintable(file.errorString())
				  << std::endl;
		return false;
	}

	return true;

}

/*
 * This method reads the configuration element.
 */

void XmlStreamReader::readConfigurationElement(){
	reader.readNext();
	while (!reader.atEnd()) {
		if (reader.isEndElement()) {
			reader.readNext();
			break;
		}

		if (reader.isStartElement()) {
			if (reader.name() == "Gestures") {
				readGesturesElement();
			} else if (reader.name() == "Events"){
				readEventsElement();
			}else if (reader.name() == "Associations"){
				readAssociationsElement();
			}
		} else {
			reader.readNext();
		}
	}

}

/*
 * This method reads the gestures element.
 */

void XmlStreamReader::readGesturesElement(){
	reader.readNext();
	while (!reader.atEnd()) {
		if (reader.isEndElement()) {
			reader.readNext();
			break;
		}
		if (reader.isStartElement()) {
			if (reader.name() == "Gesture") {
				QString idGesture = reader.attributes().value("id").toString();
				readGestureElement(idGesture);
			}
		} else {
			reader.readNext();
		}
	}

}

/*
 * This method reads the gesture element from the configuration file and store it in the gesture Model
 */

void XmlStreamReader::readGestureElement(QString idGesture){
	reader.readNext();
	DTWData* dtwTX = new DTWData();
	DTWData* dtwTY = new DTWData();
	while (!reader.atEnd()) {
		if (reader.isEndElement()) {
			reader.readNext();
			break;
		}

		if (reader.isStartElement()) {
			if (reader.name() == "Pair") {
				readPairElement(dtwTX,dtwTY);
			}
		} else {
			reader.readNext();
		}
	}
	Gesture* gest = new Gesture(dtwTX,dtwTY,idGesture.toStdString().c_str());
	if (gestureModel!=0)
		gestureModel->addGesture(gest);
}

/*
 * This method reads the next x,y,t tupla and stores it in the DTWData's passed by parameter.
 */

void XmlStreamReader::readPairElement(DTWData* tx, DTWData* ty){
	reader.readNext();
	QString xString;
	QString yString;
	QString tString;
	double x;
	double y;
	double t;
	while (!reader.atEnd()) {
		if (reader.isEndElement()) {
			reader.readNext();
			char* finalPtr;
			x = strtod(xString.toStdString().c_str(),&finalPtr);
			y = strtod(yString.toStdString().c_str(),&finalPtr);
			t = strtod(tString.toStdString().c_str(),&finalPtr);
			tx->addNewXYPair(t,x);
			ty->addNewXYPair(t,y);
			break;
		}

		if (reader.isStartElement()) {
			if (reader.name() == "X") {
				xString = reader.readElementText();
				if (reader.isEndElement())
					reader.readNext(); //Skip </X>
			}
			if (reader.name() == "Y") {
				yString = reader.readElementText();
				if (reader.isEndElement())
					reader.readNext(); //Skip </Y>
			}
			if (reader.name() == "T") {
				tString = reader.readElementText();
				if (reader.isEndElement())
					reader.readNext(); //Skip </T>
			}
		} else {
			reader.readNext();
		}
	}
}

/*
 * This method reads the events element from the configuration file and store it in the corresponding event Model
 */

void XmlStreamReader::readEventsElement(){
	reader.readNext();
	while (!reader.atEnd()) {
		if (reader.isEndElement()) {
			reader.readNext();
			break;
		}

		if (reader.isStartElement()) {
			if (reader.name() == "KeyEvents") {
				readKeyEventsElements();
			} else if (reader.name() == "CombinedKeyEvents") {
				readCombinedKeyEventsElements();
			} else if (reader.name() == "AppEvents") {
				readApplicationEventsElements();
			} else if (reader.name() == "FileEvents") {
				readFileEventsElements();
			}
		}else {
			reader.readNext();
		}
	}
}


/*
 * This method reads the events element from the configuration
 * file and store it in the keyPress event Model
 */


void XmlStreamReader::readKeyEventsElements(){
	reader.readNext();
	while (!reader.atEnd()) {
		if (reader.isEndElement()) {
			reader.readNext();
			break;
		}

		if (reader.isStartElement()) {
			if (reader.name() == "Event") {
				QString idEvent = reader.attributes().value("id").toString();
				readKeyEventElement(idEvent);
			}
		} else {
			reader.readNext();
		}
	}
}

/*
 * This method reads the event element from the configuration file and
 * store it in the Key event Model using the idEvent passed by parameter.
 */

void XmlStreamReader::readKeyEventElement(QString idEvent){
	reader.readNext();
	while (!reader.atEnd()) {
		if (reader.isEndElement()) {
			reader.readNext();
			break;
		}

		if (reader.isStartElement()) {
			if (reader.name() == "Key") {
				QString key = reader.readElementText();
				BYTE ky = getKeyCode(key);
				char* ident = new char[idEvent.size()];
				strcpy(ident,idEvent.toStdString().c_str());
				PressCharEvent* pc = new PressCharEvent(ident,ky,key.toStdString());
				if (keyEventModel!=0)
					keyEventModel->addEvent(pc);
				if (reader.isEndElement())
					reader.readNext(); //Skip </Key>
			}
		} else {
			reader.readNext();
		}
	}
}

/*
 * This methods returns the key Code corresponding to the key passed by parameter.
 */

BYTE XmlStreamReader::getKeyCode(QString key){
	if (QString::compare(key,UP_STR) == 0)
		return VK_UP;
	if (QString::compare(key,DOWN_STR) == 0)
		return VK_DOWN;
	if (QString::compare(key,RIGHT_STR) == 0)
		return VK_RIGHT;
	if (QString::compare(key,LEFT_STR) == 0)
		return VK_LEFT;
	if (QString::compare(key,ESC_STR) == 0)
		return VK_ESCAPE;
	if (QString::compare(key,SPACE_STR) == 0)
		return VK_SPACE;
	if (QString::compare(key,INTRO_STR) == 0)
		return VK_RETURN;
	if (QString::compare(key,TAB_STR) == 0)
		return VK_TAB;
	if (QString::compare(key,F5_STR) == 0)
		return VK_F5;
	if (QString::compare(key,PGUP_STR) == 0)
		return VK_PRIOR;
	if (QString::compare(key,PGDN_STR) == 0)
		return VK_NEXT;
	if (QString::compare(key,ALT_STR) == 0)
		return VK_MENU;
	return 0;
}

/*
 * This method reads the events element from the configuration
 * file and store it in the Combined Key Press event Model
 */

void XmlStreamReader::readCombinedKeyEventsElements(){
	reader.readNext();
	while (!reader.atEnd()) {
		if (reader.isEndElement()) {
			reader.readNext();
			break;
		}

		if (reader.isStartElement()) {
			if (reader.name() == "Event") {
				QString idEvent = reader.attributes().value("id").toString();
				readCombinedKeyEventElement(idEvent);
			}
		} else {
			reader.readNext();
		}
	}
}

/*
 * This method reads the event element from the configuration file and
 * store it in the Combined Key event Model using the idEvent passed by parameter.
 */

void XmlStreamReader::readCombinedKeyEventElement(QString idEvent){
	reader.readNext();
	QList<QString> keyList;
	while (!reader.atEnd()) {
		if (reader.isEndElement()) {
			reader.readNext();
			CombinedKeyPressed* ck = createCombinedKeyPressed(idEvent,keyList);
			if (combinedKeyEventModel!=0)
				combinedKeyEventModel->addEvent(ck);
			break;
		}

		if (reader.isStartElement()) {
			if (reader.name() == "Key") {
				QString key = reader.readElementText();
				keyList.append(key);
				if (reader.isEndElement()){
					reader.readNext(); //Skip </Key>
				}
			}
		} else {
			reader.readNext();
		}
	}
}

/*
 * This methods creates an instance of CombinedKeyPressed Event using the idEvent as its id attribute
 * and keyList as its key combination.
 */

CombinedKeyPressed* XmlStreamReader::createCombinedKeyPressed(QString idEvent,QList<QString> keyList){
	QString ak = keyList.at(keyList.size()-1);
	char* ident = new char[idEvent.size()];
	strcpy(ident,idEvent.toStdString().c_str());
	PressCharEvent* ake = new PressCharEvent(ident,getKeyCode(ak),ak.toStdString());
	CombinedKeyPressed* ke;
	for(int i = keyList.size()-2 ; i >= 0 ; i--){
		ak = keyList.at(i);
		ke = new CombinedKeyPressed(ident,getKeyCode(ak),ake,ak.toStdString());
		ake = ke;
	}
	return ke;
}

/*
 * This method reads the events element from the configuration
 * file and store it in the Application Execution event Model
 */

void XmlStreamReader::readApplicationEventsElements(){
	reader.readNext();
	while (!reader.atEnd()) {
		if (reader.isEndElement()) {
			reader.readNext();
			break;
		}

		if (reader.isStartElement()) {
			if (reader.name() == "Event") {
				QString idEvent = reader.attributes().value("id").toString();
				readApplicationEventElement(idEvent);
			}
		} else {
			reader.readNext();
		}
	}
}

/*
 * This method reads the event element from the configuration file and
 * store it in the Application Execution event Model using the idEvent
 * passed by parameter.
 */

void XmlStreamReader::readApplicationEventElement(QString idEvent){
	reader.readNext();
	QString fileName;
	QString args;
	while (!reader.atEnd()) {
		if (reader.isEndElement()) {
			reader.readNext();
			std::string* app = new std::string(fileName.toStdString());
			std::string* arg = new std::string(args.toStdString());
			char* ident = new char[idEvent.size()];
			strcpy(ident,idEvent.toStdString().c_str());
			ExecuteApplication* ea = new ExecuteApplication(ident,app,arg);
			if (appEventModel!=0)
				appEventModel->addEvent(ea);
			break;
		}

		if (reader.isStartElement()) {
			if (reader.name() == "App") {
				fileName = reader.readElementText();
				if (reader.isEndElement())
					reader.readNext(); //Skip </App>
			}
			if (reader.name() == "Args"){
				args = reader.readElementText();
				if (reader.isEndElement())
					reader.readNext(); //Skip </Args>
			}
		} else {
			reader.readNext();
		}
	}
}

/*
 * This method reads the events element from the configuration
 * file and store it in the Open File event Model
 */

void XmlStreamReader::readFileEventsElements(){
	reader.readNext();
	while (!reader.atEnd()) {
		if (reader.isEndElement()) {
			reader.readNext();
			break;
		}

		if (reader.isStartElement()) {
			if (reader.name() == "Event") {
				QString idEvent = reader.attributes().value("id").toString();
				readFileEventElement(idEvent);
			}
		} else {
			reader.readNext();
		}
	}
}

/*
 * This method reads the event element from the configuration file and
 * store it in the Open File event Model using the idEvent
 * passed by parameter.
 */

void XmlStreamReader::readFileEventElement(QString idEvent){
	reader.readNext();
	QString fileName;
	while (!reader.atEnd()) {
		if (reader.isEndElement()) {
			reader.readNext();
			std::string* file = new std::string(fileName.toStdString());
			char* ident = new char[idEvent.size()];
			strcpy(ident,idEvent.toStdString().c_str());
			OpenFileEvent* ofe = new OpenFileEvent(ident,file);
			if (fileEventModel!=0)
				fileEventModel->addEvent(ofe);
			break;
		}

		if (reader.isStartElement()) {
			if (reader.name() == "File") {
				fileName = reader.readElementText();
				reader.readNext(); //skip </File>
			}
		} else {
			reader.readNext();
		}
	}
}

/*
 * This method reads the Assiciations element and stores them in the GestureEventMapper instance.
 */

void XmlStreamReader::readAssociationsElement(){
	reader.readNext();
	while (!reader.atEnd()) {
		if (reader.isEndElement()) {
			reader.readNext();
			break;
		}

		if (reader.isStartElement()) {
			if (reader.name() == "Association") {
				QString isActive = reader.attributes().value("active").toString();
				readAssociationElement(isActive);
			}
		} else {
			reader.readNext();
		}
	}
}

/*
 * this method stores in the GestureEventMapper the asociation among
 * the Gesture read and the event read.
 */

void XmlStreamReader::readAssociationElement(QString isActive){
	QString idGest;
	QString idEvent;
	reader.readNext();
	while (!reader.atEnd()) {
		if (reader.isEndElement()) {
			reader.readNext();
			break;
		}

		if (reader.isStartElement()) {
			if (reader.name() == "Gesture") {
				idGest = reader.readElementText();
				reader.readNext();
			} else if (reader.name() == "Event") {
				idEvent = reader.readElementText();
				reader.readNext();
				createAssociation(idGest,idEvent,isActive);
			}
		} else {
			reader.readNext();
		}
	}
}


/*
 * This method adds the association to the GestureEventMapper instance.
 */
void XmlStreamReader::createAssociation(QString idGest, QString idEvent, QString isActive){
	if (QString::compare(idEvent,QString("DoNothingEvent")) == 0)
		return;

	Event* e = getEventFromModels(idEvent);
	std::string* id = new std::string(idGest.toStdString());
	if (gestureModel==0)
		return;
	Gesture* g = gestureModel->getGesture(id);
	bool active = false;
	bool added;
	if (QString::compare(isActive,QString("true")) == 0)
		active = true;

	if (gem!=0);
		gem->addAssociation(g,e,active,added);
}

/*
 * This method returns the Event instance associated with the string in
 * the parameter list.
 */

Event* XmlStreamReader::getEventFromModels(QString ide){
	std::string* id = new std::string(ide.toStdString());
	Event* e;
	if (keyEventModel != 0){
		e = keyEventModel->getEvent(id);
		if (e!=0)
			return e;
	}
	if (combinedKeyEventModel!=0){
		e = combinedKeyEventModel->getEvent(id);
		if (e!=0)
			return e;
	}
	if (appEventModel!=0){
		e = appEventModel->getEvent(id);
		if (e!=0)
			return e;
	}
	if (fileEventModel!=0){
		e = fileEventModel->getEvent(id);
		if (e!=0)
			return e;
	}
	return 0;
}
