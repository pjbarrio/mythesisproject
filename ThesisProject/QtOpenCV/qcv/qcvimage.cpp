
#include "qcvimage.h"

//====================================================================
//====================================================================

static IplImage* cvxCopyQImage(const QImage &qImage, IplImage **pIplImage=0);
static QImage&   cvxCopyIplImage(const IplImage *pIplImage, QImage &qImage);

//====================================================================
//====================================================================

IplImage *qcvIplImage(const char *filename, int iscolor)
{
	return cvLoadImage(filename, iscolor);
}
IplImage *qcvIplImage(const QString &filename, int is_color)
{
	return cvLoadImage(filename.toAscii().constData(), is_color);
}
IplImage *qcvIplImage(const CvSize &size, int depth, int channels)
{
	return cvCreateImage(size, depth, channels);
}
IplImage *qcvIplImage(const QImage  &image)
{
	return cvxCopyQImage(image);
}
IplImage *qcvIplImage(const QPixmap &image)
{
	return qcvIplImage(image.toImage());
}

//

QImage qcvQImage (const IplImage *image)
{
	QImage qImage;
	cvxCopyIplImage(image, qImage);
	return qImage;
}
QPixmap qcvQPixmap(const IplImage *image)
{
	return QPixmap::fromImage(qcvQImage(image));
}

//

bool qcvSaveImage(const char *filename, const IplImage *img)
{
	return cvSaveImage(filename, img);
}
bool qcvSaveImage(const QString &filename, const IplImage *img)
{
	return cvSaveImage(filename.toAscii().constData(), img);
}

// 和QDataStream集成

QDataStream& operator>>(QDataStream &in, IplImage *image)
{
	assert(false);

	IplImage head[1];
	in.readRawData((char*)head, sizeof(head));

	if(image->imageSize == head->imageSize)
	{
		// 图像内存大小一致
	
		char *data = image->imageData;
		in.readRawData(data, image->imageSize);
		memcpy(image, head, sizeof(head));
		image->imageData = data;
	}
	else
	{
		// 分配内存
	}

	// cvReleaseImage 是否能正确释放 ???

	return in;
}
QDataStream& operator<<(QDataStream &out, const IplImage *image)
{
	assert(false);
	return out;
}

//====================================================================
//====================================================================

static IplImage *cvxCopyQImage(const QImage &qImage, IplImage **ppIplImage)
{
	if(qImage.isNull()) return NULL;

	// 图像大小
	
	int w = qImage.width();
	int h = qImage.height();

	// 创建IplImage

	IplImage *pIplImage = (!ppIplImage || !CV_IS_IMAGE(*ppIplImage))?
		cvCreateImage(cvSize(w,h), IPL_DEPTH_8U, 3): (*ppIplImage);
	if(!CV_IS_IMAGE(pIplImage)) return NULL;

	// 调整大小

	if(pIplImage->width != w || pIplImage->height != h)
	{
		// 需要修改pIplImage指针

		cvReleaseImage(&pIplImage);
		pIplImage = cvCreateImage(cvSize(w,h), IPL_DEPTH_8U, 3);

		if(!CV_IS_IMAGE(pIplImage)) 
		{
			if(!ppIplImage) (*ppIplImage) = pIplImage;
			return NULL;
		}
	}

	// 设置左上角起点

	pIplImage->origin = IPL_ORIGIN_TL;

	// 复制像素
	
	int x, y;
	for(x = 0; x < pIplImage->width; ++x)
	{
		for(y = 0; y < pIplImage->height; ++y)
		{
			QRgb rgb = qImage.pixel(x, y);

			// 灰度/彩色

			if(pIplImage->nChannels == 1)
			{
				cvSet2D(pIplImage, y, x, CV_RGB(qGray(rgb), 0, 0));
			}
			else
			{
				cvSet2D(pIplImage, y, x, CV_RGB(qRed(rgb), qGreen(rgb), qBlue(rgb)));
			}
		}
	}

	// 更新(*ppIplImage)

	if(!ppIplImage) (*ppIplImage) = NULL;
	return pIplImage;
}

static QImage& cvxCopyIplImage(const IplImage *pIplImage, QImage &qImage)
{
	if(!CV_IS_IMAGE(pIplImage)) return qImage;

	// 图像大小

	int w = pIplImage->width;
	int h = pIplImage->height;

	// 调整qImage的大小

	if(qImage.width() != w || qImage.height() != h)
	{
		qImage = QImage(w, h, QImage::Format_RGB32);
	}

	// 复制像素
	
	int x, y;
	for(x = 0; x < pIplImage->width; ++x)
	{
		for(y = 0; y < pIplImage->height; ++y)
		{
			CvScalar color = cvGet2D(pIplImage, y, x);

			// 灰度/彩色

			if(pIplImage->nChannels == 1)
			{
				int v = color.val[0];
				
				qImage.setPixel(x, y, qRgb(v,v,v));
			}
			else
			{
				int r = color.val[2];
				int g = color.val[1];
				int b = color.val[0];
				
				qImage.setPixel(x, y, qRgb(r,g,b));
			}
		}
	}

	// 上下翻转

	if(pIplImage->origin != IPL_ORIGIN_TL)
	{
		qImage = qImage.mirrored(false, true);
	}

	return qImage;
}

//
