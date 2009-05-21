
#include "qcvtypes.h"

//

struct static_qcvtypes_h
{
	static_qcvtypes_h()
	{
		qRegisterMetaTypeStreamOperators<CvPoint>("CvPoint");
		qRegisterMetaTypeStreamOperators<CvPoint2D32f>("CvPoint2D32f");
		qRegisterMetaTypeStreamOperators<CvPoint2D64f>("CvPoint2D64f");
		qRegisterMetaTypeStreamOperators<CvPoint3D32f>("CvPoint3D32f");
		qRegisterMetaTypeStreamOperators<CvPoint3D64f>("CvPoint3D64f");
		
		qRegisterMetaTypeStreamOperators<CvSize>("CvSize");
		qRegisterMetaTypeStreamOperators<CvSize2D32f>("CvSize2D32f");
		
		qRegisterMetaTypeStreamOperators<CvRect>("CvRect");
		
		qRegisterMetaTypeStreamOperators<CvScalar>("CvScalar");
	}
};

static static_qcvtypes_h staticInit;

//
