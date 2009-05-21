
#ifndef QCV_PAINTER_H
#define QCV_PAINTER_H

#include <QPainter>
#include <QPaintDevice>
#include <QRect>
#include <cv.h>

class QCVPainter : public QPainter
{
public:

    QCVPainter();
    explicit QCVPainter(QPaintDevice *);
    ~QCVPainter();

	//

    void drawImage(const QPoint  &p, const IplImage *image);
    void drawImage(const CvPoint &p, const IplImage *image);
    void drawImage(const QRect   &r, const IplImage *image);
    void drawImage(const CvRect  &r, const IplImage *image);
    void drawImage(const QPoint  &p, const IplImage *image, const QRect &sr,
                   Qt::ImageConversionFlags flags = Qt::AutoColor);
    void drawImage(const CvPoint &p, const IplImage *image, const CvRect &sr,
                   Qt::ImageConversionFlags flags = Qt::AutoColor);
    void drawImage(const QRect  &targetRect, const IplImage *image, const QRect  &sourceRect,
                   Qt::ImageConversionFlags flags = Qt::AutoColor);
    void drawImage(const CvRect &targetRect, const IplImage *image, const CvRect &sourceRect,
                   Qt::ImageConversionFlags flags = Qt::AutoColor);
    void drawImage(int x, int y, const IplImage *image,
				   int sx = 0, int sy = 0, int sw = -1, int sh = -1,
				   Qt::ImageConversionFlags flags = Qt::AutoColor);

	//

private:

	// 针对特殊格式进行优化

	void drawImageFast(const IplImage *image);

	QImage qcvQImageFast(const IplImage *image);
};

#endif	// QCV_PAINTER_H

