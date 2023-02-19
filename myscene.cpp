#include "myscene.h"

MyScene::MyScene(IGetFractal *fractal)
    : QGraphicsScene(0), cur_fractal(fractal)
{}

MyScene::~MyScene()
{

}

void MyScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	previousPoint = event->scenePos();
    drow = 1;
}
#include <ctime>
#include <iostream>
void MyScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    auto fractal = cur_fractal->get_curent_fractal();
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
    drow = 1;
}

void MyScene::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    auto fractal = cur_fractal->get_curent_fractal();
	if (!fractal)
		return;
	if (event->delta() > 0)
		fractal->zoom_on(event->scenePos().x(), event->scenePos().y());
	else
		fractal->zoom_off();
    drow = 1;
}
