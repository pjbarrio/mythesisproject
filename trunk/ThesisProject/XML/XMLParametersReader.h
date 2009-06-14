/**
 * XMLParametersReader.h
 *
 *  Created on: 12/06/2009
 *      \author Pablo
 */

#ifndef XMLPARAMETERSREADER_H_
#define XMLPARAMETERSREADER_H_

#include <QXmlStreamReader>
#include <QString>

class XMLParametersReader {
public:
	XMLParametersReader();
	virtual ~XMLParametersReader();
	bool readFile(const QString &fileName);
private:
	void readParametersElement();
	QXmlStreamReader reader;
};

#endif /* XMLPARAMETERSREADER_H_ */
