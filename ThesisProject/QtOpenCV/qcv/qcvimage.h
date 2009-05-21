
#ifndef QCV_IMAGE_H
#define QCV_IMAGE_H

#include <QtGui>
#include <cv.h>
#include <highgui.h>

//

inline bool qcvIsImage(const IplImage *image){ return CV_IS_IMAGE(image); }

//

IplImage *qcvIplImage(const char *filename, int is_color=CV_LOAD_IMAGE_COLOR);
IplImage *qcvIplImage(const QString &filename, int is_color=CV_LOAD_IMAGE_COLOR);
IplImage *qcvIplImage(const CvSize &size, int depth=IPL_DEPTH_8U, int channels=3);
IplImage *qcvIplImage(const QImage  &image);
IplImage *qcvIplImage(const QPixmap &image);

QImage  qcvQImage (const IplImage *image);
QPixmap qcvQPixmap(const IplImage *image);

bool qcvSaveImage(const char *filename, const IplImage *img);
bool qcvSaveImage(const QString &filename, const IplImage *img);

// ºÍQDataStream¼¯³É

QDataStream& operator>>(QDataStream &in, IplImage *image);
QDataStream& operator<<(QDataStream &out, const IplImage *image);

#endif	// QCV_IMAGE_H
