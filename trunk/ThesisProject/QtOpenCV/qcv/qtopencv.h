
#ifndef QT_OPENCV_H
#define QT_OPENCV_H

#include <cv.h>

#include "qcvtypes.h"
#include "qcvimage.h"
#include "qcvpainter.h"
#include "qcvcg.h"

// �Ƿ���Ҫ�����ڴ�ͳ�ƹ��ܣ�����
// QCVMemWidget

//void      qcvRegisterMetaTypeStreamOperators();
IplImage* qcvGrabWidget(QWidget *widget);


//

#endif	// QT_OPENCV_H

