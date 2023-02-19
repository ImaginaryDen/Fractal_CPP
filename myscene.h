#ifndef MYSCENE_H
#define MYSCENE_H

#include "IGetFractal.h"
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QPainter>
#include <QDebug>
#include <fractal_base.h>
#include <QGraphicsSceneWheelEvent>

class MyScene : public QGraphicsScene
{
	Q_OBJECT

public:
    MyScene(IGetFractal *fractal);
    ~MyScene();
    bool drow = 1;
private:
	void mousePressEvent(QGraphicsSceneMouseEvent * event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void wheelEvent(QGraphicsSceneWheelEvent *event);

    IGetFractal *cur_fractal;
    QPointF     previousPoint;
};

#endif // MYSCENE_H
