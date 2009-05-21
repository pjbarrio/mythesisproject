
// 计算几何

#ifndef QCV_CG_H
#define QCV_CG_H

#include <cv.h>

// 判断(pi->pj->pk)的方向
//
// 返回正数: 在pj点左拐
// 返回负数: 在pj点右拐
// 返回零  : 在(pi,pj)直线前进或后退

int  qcvDirection(const CvPoint& pi, const CvPoint& pj, const CvPoint& pk);

// 判断线段是否相交
// 如果相交px可返回交点

bool qcvIsIntersect(const CvPoint& p1, const CvPoint& p2,
					const CvPoint& p3, const CvPoint& p4,
					CvPoint2D32f *px=0);

// 判断多边形是否自交

bool qcvIsSelfIntersect(const CvPoint *pts, int nPoints);

// 判断多边形是否是顺时针方向

bool qcvIsClockwise(const CvPoint *Pts, int nPoints);

//

#endif	// QCV_CG_H

