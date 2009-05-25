#ifndef QCV_CG_H
#define QCV_CG_H

#include <cv.h>


int  qcvDirection(const CvPoint& pi, const CvPoint& pj, const CvPoint& pk);



bool qcvIsIntersect(const CvPoint& p1, const CvPoint& p2,
					const CvPoint& p3, const CvPoint& p4,
					CvPoint2D32f *px=0);


bool qcvIsSelfIntersect(const CvPoint *pts, int nPoints);



bool qcvIsClockwise(const CvPoint *Pts, int nPoints);



#endif	// QCV_CG_H

