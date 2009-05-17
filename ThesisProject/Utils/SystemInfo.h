/*
 * SystemInfo.h
 *
 *  Created on: 08-feb-2009
 *      Author: Timpa
 *
 * This class provide the information about the resolution that
 * the process uses to work and the Screen Resolution configured
 * by the user.
 */

#ifndef SYSTEMINFO_H_
#define SYSTEMINFO_H_



class SystemInfo {
public:

	SystemInfo(int,int);

	virtual ~SystemInfo();

	void getSystemResolution(int&,int&);

	void getSystemWorkResolution(int&,int&);

	void getSystemRatio(int&,int&);

private:

	int width, height, workw, workh;
};


#endif /* SYSTEMINFO_H_ */
