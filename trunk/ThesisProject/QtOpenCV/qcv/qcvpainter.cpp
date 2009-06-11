
#include "qcvpainter.h"
#include "qcvimage.h"
#include "qcvtypes.h"

//

QCVPainter::QCVPainter(){}
QCVPainter::QCVPainter(QPaintDevice *dev):QPainter(dev){}
QCVPainter::~QCVPainter(){}


void QCVPainter::drawImage(const QPoint &p, const IplImage *image)
{
	if(qcvIsImage(image))
	{
		QPainter::drawImage(p, qcvQImage(image));
	}
}
void QCVPainter::drawImage(const CvPoint &p, const IplImage *image)
{
	if(qcvIsImage(image))
	{
		QPainter::drawImage(qcvPoint(p), qcvQImage(image));
	}
}



void QCVPainter::drawImage(const QRect &r, const IplImage *image)
{
	if(qcvIsImage(image))
	{
		QPainter::drawImage(r, qcvQImage(image));
	}
}
void QCVPainter::drawImage(const CvRect &r, const IplImage *image)
{
	if(qcvIsImage(image))
	{
		QPainter::drawImage(qcvRect(r), qcvQImage(image));
	}
}



void QCVPainter::drawImage(const QPoint &p, const IplImage *image, const QRect &sr,
                   Qt::ImageConversionFlags flags /* = Qt::AutoColor */)
{
	if(qcvIsImage(image))
	{
		QPainter::drawImage(p, qcvQImage(image), sr, flags);
	}
}
void QCVPainter::drawImage(const CvPoint &p, const IplImage *image, const CvRect &sr,
                   Qt::ImageConversionFlags flags /* = Qt::AutoColor */)
{
	if(qcvIsImage(image))
	{
		QPainter::drawImage(qcvPoint(p), qcvQImage(image), qcvRect(sr), flags);
	}
}



void QCVPainter::drawImage(const QRect &targetRect, const IplImage *image, const QRect &sourceRect,
                   Qt::ImageConversionFlags flags /* = Qt::AutoColor */)
{
	if(qcvIsImage(image))
	{
		QPainter::drawImage(targetRect, qcvQImage(image), sourceRect, flags);
	}
}
void QCVPainter::drawImage(const CvRect &targetRect, const IplImage *image, const CvRect &sourceRect,
                   Qt::ImageConversionFlags flags /* = Qt::AutoColor */)
{
	if(qcvIsImage(image))
	{
		QPainter::drawImage(qcvRect(targetRect), qcvQImage(image), qcvRect(sourceRect), flags);
	}
}



void QCVPainter::drawImage(int x, int y, const IplImage *image,
			   int sx /* = 0 */, int sy /* = 0 */,
               int sw /* = -1 */, int sh /* = -1 */,
			   Qt::ImageConversionFlags flags /* = Qt::AutoColor */)
{
	if(qcvIsImage(image))
	{
		QPainter::drawImage(x, y, qcvQImage(image), sx, sy, sw, sh, flags);
	}
}



void QCVPainter::drawImageFast(const IplImage *image)
{
	assert(qcvIsImage(image));

//#if (QT_VERSION >= QT_VERSION_CHECK(4, 4, 0))

	int w = image->width;
	int h = image->height;

	int  step = image->widthStep;
	uchar* data = (uchar*)image->imageData;

	// swap RB channel
	// origin IPL_ORIGIN_BL


	cvConvertImage(image, (CvArr*)image, CV_CVTIMG_SWAP_RB);

	QImage img(data, w, h, step, QImage::Format_RGB888);


	cvConvertImage(image, (CvArr*)image, CV_CVTIMG_SWAP_RB);

//#else

//#endif
}



