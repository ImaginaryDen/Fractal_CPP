#ifndef FRACTALPIFAGORTREE_H
#define FRACTALPIFAGORTREE_H

#include "fractal_base.h"

class FractalPifagorTree : public fractal_base
{
public:
	FractalPifagorTree(int width = 0, int height = 0)
		: fractal_base(width, height)
	{}
	FractalPifagorTree(const fractal_base& copy) : fractal_base(copy){}

	void draw_fractal(QImage *img) override;
	void drawPifagorTree(QImage *img, int x, int y, int size, int angle, int depth);
	void dif_coord(long double x, long double y) override;
};

#endif // FRACTALPIFAGORTREE_H
