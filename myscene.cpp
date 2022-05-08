#include "myscene.h"

MyScene::MyScene(fractal_base *&fractal, QObject *parent)
	: QGraphicsScene(parent), fractal(fractal)
{}

MyScene::~MyScene()
{

}

void MyScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	previousPoint = event->scenePos();
}
#include <ctime>
#include <iostream>
void MyScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	if (!fractal)
		return;
	fractal->dif_coord(previousPoint.x() - event->scenePos().x()
					   , previousPoint.y() - event->scenePos().y());
	QImage img(width(), height(), QImage::Format_RGB32);
	img.fill(fractal->iter_color(0));
	QPainter painter(&img);
	painter.translate(event->scenePos().x() - previousPoint.x(),
					  event->scenePos().y() - previousPoint.y());
	render(&painter);
	int start = clock();
	fractal->draw_fractal(&img);
	cout << clock() - start << endl;
	addPixmap(QPixmap::fromImage(img));
	previousPoint = event->scenePos();
}

void MyScene::wheelEvent(QGraphicsSceneWheelEvent *event)
{
	if (!fractal)
		return;
	if (event->delta() > 0)
		fractal->zoom_on(event->scenePos().x(), event->scenePos().y());
	else
		fractal->zoom_off();
}
