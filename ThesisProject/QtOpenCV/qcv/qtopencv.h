
#ifndef QT_OPENCV_H
#define QT_OPENCV_H

#include <cv.h>

#include "qcvtypes.h"
#include "qcvimage.h"
#include "qcvpainter.h"
#include "qcvcg.h"

// 是否需要增加内存统计功能？？？
// QCVMemWidget

//void      qcvRegisterMetaTypeStreamOperators();
IplImage* qcvGrabWidget(QWidget *widget);


//

#endif	// QT_OPENCV_H

