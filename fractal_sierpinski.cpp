#include "fractal_sierpinski.h"
#include <QPainter>

void fractal_Sierpinski::draw_fractal(QImage *img)
{
    int size = min(img->width(), img->height());
    drawSierpinski(img, x, size + y, size, (sensibility / 10) - 1);
}

void fractal_Sierpinski::drawSierpinski(QImage *img, long double x, long double y, int size, int depth)
{
    if (depth <= 0) {
        long double x1 = x;
        long double y1 = y;
        long double x2 = x + size;
        long double y2 = y;
        long double x3 = x + size / 2;
        long double y3 = y - size * sqrt(3) / 2;
        QPolygon polygon;
        polygon << QPoint(x1, y1) << QPoint(x2, y2) << QPoint(x3, y3);
        QPainter painter(img);
        painter.setBrush(Qt::white);
        painter.drawPolygon(polygon);
    } else {
        drawSierpinski(img, x, y, size / 2, depth - 1);
        drawSierpinski(img, x + size / 2, y, size / 2, depth - 1);
        drawSierpinski(img, x + size / 4, y - size / 2, size / 2, depth - 1);
    }
}

void fractal_Sierpinski::dif_coord(long double x, long double y)
{
    this->x -= x;
    this->y -= y;
}
