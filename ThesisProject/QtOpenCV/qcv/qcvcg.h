
// ���㼸��

#ifndef QCV_CG_H
#define QCV_CG_H

#include <cv.h>

// �ж�(pi->pj->pk)�ķ���
//
// ��������: ��pj�����
// ���ظ���: ��pj���ҹ�
// ������  : ��(pi,pj)ֱ��ǰ�������

int  qcvDirection(const CvPoint& pi, const CvPoint& pj, const CvPoint& pk);

// �ж��߶��Ƿ��ཻ
// ����ཻpx�ɷ��ؽ���

bool qcvIsIntersect(const CvPoint& p1, const CvPoint& p2,
					const CvPoint& p3, const CvPoint& p4,
					CvPoint2D32f *px=0);

// �ж϶�����Ƿ��Խ�

bool qcvIsSelfIntersect(const CvPoint *pts, int nPoints);

// �ж϶�����Ƿ���˳ʱ�뷽��

bool qcvIsClockwise(const CvPoint *Pts, int nPoints);

//

#endif	// QCV_CG_H

