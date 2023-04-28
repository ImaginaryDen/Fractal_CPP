#include "fractalpifagortree.h"
#include <QPainter>

void FractalPifagorTree::draw_fractal(QImage *img)
{
	int x = img->width() / 2;
	int y = img->height() - 50;
	int size = min(img->width(), img->height()) / 3;
	int angle = 90;

	drawPifagorTree(img, x, y, size, angle, sensibility / 10 - 1);
}

void FractalPifagorTree::drawPifagorTree(QImage *img, int x, int y, int size, int angle, int depth)
{
	if (depth <= 0) {
				return;
	}

	// Calculate the endpoints of the line segments.
	int x1 = x;
	int y1 = y;
	int x2 = x + size * std::cos(qDegreesToRadians(angle));
	int y2 = y - size * std::sin(qDegreesToRadians(angle));

	{
		QPainter painter(img);
		QPen pen(Qt::white, 1);
		painter.setPen(pen);
		painter.drawLine(x1, y1, x2, y2);
	}
	// Calculate the sizes and angles for the sub-trees.
	int leftSize = size * 0.7;
	int leftAngle = angle + 45;
	int rightSize = size * 0.6;
	int rightAngle = angle - 35;

	// Draw the left sub-tree.
	drawPifagorTree(img, x2, y2, leftSize, leftAngle, depth - 1);

	// Draw the right sub-tree.
	drawPifagorTree(img, x2, y2, rightSize, rightAngle, depth - 1);
}

void FractalPifagorTree::dif_coord(long double x, long double y)
{
	this->x -= x;
	this->y -= y;
}
