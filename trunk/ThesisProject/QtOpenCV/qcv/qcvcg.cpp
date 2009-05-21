
#include "qcvcg.h"
#include <assert.h>

// 判断某一与线段共线的点是否在线段上

static
bool iqcvIsOnSegment(const CvPoint& pi, const CvPoint& pj, const CvPoint& pk)
{
	int minx = (pi.x < pj.x)? pi.x: pj.x;
	int maxx = (pi.x > pj.x)? pi.x: pj.x;

	int miny = (pi.y < pj.y)? pi.y: pj.y;
	int maxy = (pi.y > pj.y)? pi.y: pj.y;

	// 点pk已经确定和线段直线共线

	return pk.x >= minx && pk.x <= maxx
		&& pk.y >= miny && pk.y <= maxy;
}

//====================================================================
//====================================================================

// 判断(pi->pj->pk)的方向

int qcvDirection(const CvPoint& pi, const CvPoint& pj, const CvPoint& pk)
{
	int x1 = pk.x - pi.x;
	int y1 = pk.y - pi.y;

	int x2 = pj.x - pi.x;
	int y2 = pj.y - pi.y;

	return x1*y2 - x2*y1;
}

// 判断线段是否相交

bool qcvIsIntersect(const CvPoint& p1, const CvPoint& p2,
					const CvPoint& p3, const CvPoint& p4,
					CvPoint2D32f *px)
{
	// 计算线段的相对位置

	int d1 = qcvDirection(p3, p4, p1);
	int d2 = qcvDirection(p3, p4, p2);
	int d3 = qcvDirection(p1, p2, p3);
	int d4 = qcvDirection(p1, p2, p4);

	// 每个线段都跨越另一个线段的直线

	if(((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0))
		&& ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0)))
	{
		if(px != NULL)
		{
			// 计算交点(没有验证)

			int d  = (p2.y-p1.y)*(p4.x-p3.x)-(p4.y-p3.y)*(p2.x-p1.x);

			int tx = (p2.x-p1.x)*(p4.x-p3.x)*(p3.y-p1.y) +
					 (p2.y-p1.y)*(p4.x-p3.x)*p1.x -
					 (p4.y-p3.y)*(p2.x-p1.x)*p3.x;
			int ty = (p2.y-p1.y)*(p4.y-p3.y)*(p3.x-p1.x) +
					 (p2.x-p1.x)*(p4.y-p3.y)*p1.y -
					 (p4.x-p3.x)*(p2.y-p1.y)*p3.y;

			px->x =  1.f * tx/d;
			px->y = -1.f * ty/d;
		}
		return true;
	}

	// 线段某个端点位于另一个线段上

	if(d1 == 0 && iqcvIsOnSegment(p3, p4, p1))
	{
		if(px != NULL) *px = cvPoint2D32f(p1.x, p1.y);
		return true;
	}
	if(d2 == 0 && iqcvIsOnSegment(p3, p4, p2))
	{
		if(px != NULL) *px = cvPoint2D32f(p2.x, p2.y);
		return true;
	}
	if(d3 == 0 && iqcvIsOnSegment(p1, p2, p3))
	{
		if(px != NULL) *px = cvPoint2D32f(p3.x, p3.y);
		return true;
	}
	if(d4 == 0 && iqcvIsOnSegment(p1, p2, p4))
	{
		if(px != NULL) *px = cvPoint2D32f(p4.x, p4.y);
		return true;
	}

	// 不相交

	return false;
}

//====================================================================
//====================================================================

// 判断多边形是否自交

bool qcvIsSelfIntersect(const CvPoint *pts, int nPoints)
{
	assert(pts != NULL);
	assert(nPoints >= 3);	// 多边形至少3个顶点

	// 每条线段单独判断

	for(int i = 0; i < nPoints; ++i)
	{
		int p1 = (i+0)%nPoints;
		int p2 = (i+1)%nPoints;

		for(int j = 0; j < nPoints; ++j)
		{
			int p3 = (j+0)%nPoints;
			int p4 = (j+1)%nPoints;

			// 两个线段不相邻

			if(p3 == p1 || p3 == p2) continue;
			if(p4 == p1 || p4 == p2) continue;

			// 如果i和j对应的线段相交, 则返回

			if(qcvIsIntersect(pts[p1], pts[p2], pts[p3], pts[p4]))
				return true;
		}
	}

	// 没有自交

	return false;
}

// 判断多边形是否是顺时针方向

bool qcvIsClockwise(const CvPoint *Pts, int nPoints)
{
	assert(Pts != NULL);
	assert(nPoints >= 3);	// 多边形至少3个顶点

	// 多边形不自交

	assert(!qcvIsSelfIntersect(Pts, nPoints));

	// 寻找一条所有顶点都在其一侧的边

	for(int i = 0; i < nPoints; ++i)
	{
		int p1 = i;
		int p2 = (i+1)%nPoints;
		int px = (i+2)%nPoints;

		// 第一个不相邻的点

		int d = qcvDirection(Pts[p1], Pts[p2], Pts[px]);

		// 确定方向

		int flag = (d > 0);

		// 判断剩余的点(除去第一个不相邻的点)

		int j;
		for(j = 0; j < nPoints; ++j)
		{
			int k = (px+j)%nPoints;

			// p1, p2, px点除外

			if(k == p1 || k == p2 || k == px) continue;

			// 判断方向是否一致

			int f = (qcvDirection(Pts[p1], Pts[p2], Pts[k]) > 0);

			// 如果方向不同则终止

			if(flag ^ f) break;
		}

		// 如果判断结束, 则返回结果
		// 如果点始终在左边, 则为逆时针

		if(j >= nPoints) return (!flag);
	}

	// 不可能执行到这里

	assert(false);
	return false;
}

//====================================================================
//====================================================================
