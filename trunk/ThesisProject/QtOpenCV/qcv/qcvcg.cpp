
#include "qcvcg.h"
#include <assert.h>

// �ж�ĳһ���߶ι��ߵĵ��Ƿ����߶���

static
bool iqcvIsOnSegment(const CvPoint& pi, const CvPoint& pj, const CvPoint& pk)
{
	int minx = (pi.x < pj.x)? pi.x: pj.x;
	int maxx = (pi.x > pj.x)? pi.x: pj.x;

	int miny = (pi.y < pj.y)? pi.y: pj.y;
	int maxy = (pi.y > pj.y)? pi.y: pj.y;

	// ��pk�Ѿ�ȷ�����߶�ֱ�߹���

	return pk.x >= minx && pk.x <= maxx
		&& pk.y >= miny && pk.y <= maxy;
}

//====================================================================
//====================================================================

// �ж�(pi->pj->pk)�ķ���

int qcvDirection(const CvPoint& pi, const CvPoint& pj, const CvPoint& pk)
{
	int x1 = pk.x - pi.x;
	int y1 = pk.y - pi.y;

	int x2 = pj.x - pi.x;
	int y2 = pj.y - pi.y;

	return x1*y2 - x2*y1;
}

// �ж��߶��Ƿ��ཻ

bool qcvIsIntersect(const CvPoint& p1, const CvPoint& p2,
					const CvPoint& p3, const CvPoint& p4,
					CvPoint2D32f *px)
{
	// �����߶ε����λ��

	int d1 = qcvDirection(p3, p4, p1);
	int d2 = qcvDirection(p3, p4, p2);
	int d3 = qcvDirection(p1, p2, p3);
	int d4 = qcvDirection(p1, p2, p4);

	// ÿ���߶ζ���Խ��һ���߶ε�ֱ��

	if(((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0))
		&& ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0)))
	{
		if(px != NULL)
		{
			// ���㽻��(û����֤)

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

	// �߶�ĳ���˵�λ����һ���߶���

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

	// ���ཻ

	return false;
}

//====================================================================
//====================================================================

// �ж϶�����Ƿ��Խ�

bool qcvIsSelfIntersect(const CvPoint *pts, int nPoints)
{
	assert(pts != NULL);
	assert(nPoints >= 3);	// ���������3������

	// ÿ���߶ε����ж�

	for(int i = 0; i < nPoints; ++i)
	{
		int p1 = (i+0)%nPoints;
		int p2 = (i+1)%nPoints;

		for(int j = 0; j < nPoints; ++j)
		{
			int p3 = (j+0)%nPoints;
			int p4 = (j+1)%nPoints;

			// �����߶β�����

			if(p3 == p1 || p3 == p2) continue;
			if(p4 == p1 || p4 == p2) continue;

			// ���i��j��Ӧ���߶��ཻ, �򷵻�

			if(qcvIsIntersect(pts[p1], pts[p2], pts[p3], pts[p4]))
				return true;
		}
	}

	// û���Խ�

	return false;
}

// �ж϶�����Ƿ���˳ʱ�뷽��

bool qcvIsClockwise(const CvPoint *Pts, int nPoints)
{
	assert(Pts != NULL);
	assert(nPoints >= 3);	// ���������3������

	// ����β��Խ�

	assert(!qcvIsSelfIntersect(Pts, nPoints));

	// Ѱ��һ�����ж��㶼����һ��ı�

	for(int i = 0; i < nPoints; ++i)
	{
		int p1 = i;
		int p2 = (i+1)%nPoints;
		int px = (i+2)%nPoints;

		// ��һ�������ڵĵ�

		int d = qcvDirection(Pts[p1], Pts[p2], Pts[px]);

		// ȷ������

		int flag = (d > 0);

		// �ж�ʣ��ĵ�(��ȥ��һ�������ڵĵ�)

		int j;
		for(j = 0; j < nPoints; ++j)
		{
			int k = (px+j)%nPoints;

			// p1, p2, px�����

			if(k == p1 || k == p2 || k == px) continue;

			// �жϷ����Ƿ�һ��

			int f = (qcvDirection(Pts[p1], Pts[p2], Pts[k]) > 0);

			// �������ͬ����ֹ

			if(flag ^ f) break;
		}

		// ����жϽ���, �򷵻ؽ��
		// �����ʼ�������, ��Ϊ��ʱ��

		if(j >= nPoints) return (!flag);
	}

	// ������ִ�е�����

	assert(false);
	return false;
}

//====================================================================
//====================================================================
