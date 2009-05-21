
#include "qcvwidget.h"
#include "qcvpainter.h"

//

QCVWidget::QCVWidget(QWidget *parent): QWidget(parent)
{
	m_image = NULL;
}

void QCVWidget::showImage(const IplImage *img)
{
	m_image = (IplImage*)img;
	update();
}
void QCVWidget::paintEvent(QPaintEvent *event)
{
	QCVPainter painter(this);
	painter.drawImage(rect(), m_image);
}
// QMovie
// Q_D
