#include "myscene.h"

MyScene::MyScene(fractal_base **fractal, QObject *parent)
	: QGraphicsScene(parent), fractal(fractal)
{}

MyScene::~MyScene()
{

}

void MyScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	previousPoint = event->scenePos();
}

void MyScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	(*fractal)->dif_coord(previousPoint.x() - event->scenePos().x()
					   , previousPoint.y() - event->scenePos().y());
	previousPoint = event->scenePos();
}

void MyScene::wheelEvent(QGraphicsSceneWheelEvent *event)
{
	if (event->delta() > 0)
		(*fractal)->zoom_on(event->scenePos().x(), event->scenePos().y());
	else
		(*fractal)->zoom_off();
}
