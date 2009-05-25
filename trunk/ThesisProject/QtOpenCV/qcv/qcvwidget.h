
#ifndef QCV_WIDGET_H
#define QCV_WIDGET_H

#include <QWidget>
#include <cv.h>

class QCVWidget : public QWidget
{
	Q_OBJECT

public:

	QCVWidget(QWidget *parent=0);

public slots:

	void showImage(const IplImage *img);


protected:

	void paintEvent(QPaintEvent *event);

private:

	IplImage*	m_image;
};

#endif	// QCV_WIDGET_H

