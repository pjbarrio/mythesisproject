/**
 * XMLParametersWriter.h
 *
 *  Created on: 12/06/2009
 *      Author: Pablo
 */

#ifndef XMLPARAMETERSWRITER_H_
#define XMLPARAMETERSWRITER_H_
#include <QXmlStreamWriter>
/*
 *
 */
class XMLParametersWriter {
public:
	XMLParametersWriter();
	bool writeXML(const QString &);
	virtual ~XMLParametersWriter();
private:
	void writeParametersElement();
	QXmlStreamWriter* xmlWriter;
};

#endif /* XMLPARAMETERSWRITER_H_ */
