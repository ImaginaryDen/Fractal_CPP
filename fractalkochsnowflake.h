#ifndef FRACTALKOCHSNOWFLAKE_H
#define FRACTALKOCHSNOWFLAKE_H

#include "fractal_base.h"

class FractalKochSnowflake : public fractal_base
{
public:
	FractalKochSnowflake(int width = 0, int height = 0)
		: fractal_base(width, height)
	{}
	FractalKochSnowflake(const fractal_base& copy) : fractal_base(copy){}

	void draw_fractal(QImage *img) override;
	void drawSnowflake(QPainter &painter, int x, int y, int size, int angle, int depth);
	void dif_coord(long double x, long double y) override;
};

#endif // FRACTALKOCHSNOWFLAKE_H
