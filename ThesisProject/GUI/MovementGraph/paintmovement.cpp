#include "paintmovement.h"
#include <QPainter>
#include "iostream.h"

/*
 * This method sets the User interface objects
 * and creates the pen used to draw the movement.
 */

paintMovement::paintMovement(QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
	q1 = new QColor("#000000");
	p1 = new QPen(*q1, 12, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
	this->xvalues = 0;
	this->yvalues = 0;
}

/*
 * This method deletes the variables used to draw the gesture.
 */

paintMovement::~paintMovement()
{
	delete (q1);
	delete (p1);
}

/*
 * This method is invoked when the window need to be repainted.
 */

void paintMovement::paintEvent(QPaintEvent *event)
{
	if (xvalues == 0 || yvalues == 0)
		return;

	circsize = xvalues->size();
	if (circsize == 0)
		return;

    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);

    //DrawRect

    painter.setPen(QPen(Qt::black, 5, Qt::SolidLine, Qt::RoundCap));

    painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));

    painter.drawRect(0,0,width(),height());

    painter.setRenderHint(QPainter::Antialiasing, true);

    //Init Alpha

    alpha = 10;

    //Calc inc

    inc = 245 / circsize;

    //Draw Points

    index = 0;

    w = width();

    h = height();

    while (index < circsize){

    	q1->setAlpha(alpha);

    	p1->setColor(*q1);

    	painter.setPen(*p1);

    	painter.drawPoint(adapt(xvalues->at(index),w),adapt(yvalues->at(index),h));

    	alpha += inc;

    	index++;

    }
}

/*
 * This method set the Circular Buffers to draw the gesture movement.
 * The first parameter represent the xCoord, while the second represent the
 * yCoord.
 */

void paintMovement::setData(CircularBuffer* xs,CircularBuffer* ys){
	xvalues = xs;
	yvalues = ys;
}

/*
 * This method readapt the pixel position to the
 * Widget size.
 */

int paintMovement::adapt(int val,int max){
	return (val*max)/80;
}
