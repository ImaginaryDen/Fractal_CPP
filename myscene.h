#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QDebug>
#include <fractal_base.h>
#include <QGraphicsSceneWheelEvent>

class MyScene : public QGraphicsScene
{
	Q_OBJECT

public:
	MyScene(fractal_base **fractal, QObject *parent = 0);
	~MyScene();
private:
	void mousePressEvent(QGraphicsSceneMouseEvent * event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void wheelEvent(QGraphicsSceneWheelEvent *event);

	QPointF     previousPoint;
	fractal_base	**fractal;
};

#endif // MYSCENE_H
