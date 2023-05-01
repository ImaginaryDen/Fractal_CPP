#include "fractalkochsnowflake.h"
#include <QPainter>

void FractalKochSnowflake::draw_fractal(QImage *img)
{
	int x = img->width() / 5;
	int y = img->height() * 3 / 4;
	int size = min(img->width(), img->height()) * 3 / 4;
	int angle = 0;

	QPainter painter(img);
	painter.setPen(QPen(Qt::white, 1));

	drawSnowflake(painter, x, y, size, angle, sensibility / 10 - 1);
	drawSnowflake(painter, x + size * std::cos(qDegreesToRadians(60)), y - size * std::sin(qDegreesToRadians(60)), size, angle - 120, sensibility / 10 - 1);
	drawSnowflake(painter, x + size * std::cos(qDegreesToRadians(0)) , y, size, angle + 120, sensibility / 10 - 1);
}

void FractalKochSnowflake::drawSnowflake(QPainter &painter, int x, int y, int size, int angle, int depth)
{
	if (depth <= 0) {
		// Draw a line segment.
		int x2 = x + size * std::cos(qDegreesToRadians(angle));
		int y2 = y - size * std::sin(qDegreesToRadians(angle));
		painter.drawLine(x, y, x2, y2);
	} else {
		// Calculate the sizes and angles for the sub-segments.
		int subSize = size / 3;
		int leftAngle = angle;
		int rightAngle = angle - 60;
		int middleAngle = angle + 60;

		// Draw the left segment.
		drawSnowflake(painter, x, y, subSize, leftAngle, depth - 1);

		// Draw the right segment.
		drawSnowflake(painter, x + subSize * std::cos(qDegreesToRadians(leftAngle)),
								  y - subSize * std::sin(qDegreesToRadians(leftAngle)), subSize,
								  rightAngle, depth - 1);
		// Draw the middle segment.
		drawSnowflake(painter, x + subSize * std::cos(qDegreesToRadians(leftAngle)) + subSize * std::cos(qDegreesToRadians(rightAngle)),
					  y - subSize * std::sin(qDegreesToRadians(leftAngle)) - subSize * std::sin(qDegreesToRadians(rightAngle)) , subSize,
					  middleAngle, depth - 1);
		drawSnowflake(painter, x + 2 * subSize * std::cos(qDegreesToRadians(leftAngle)),
								  y -  2 * subSize * std::sin(qDegreesToRadians(leftAngle)), subSize,
								  leftAngle, depth - 1);
	}
}

void FractalKochSnowflake::dif_coord(long double x, long double y)
{
	this->x -= x;
	this->y -= y;
}
