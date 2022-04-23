#ifndef FRACTAL_MANDELBROT_H
#define FRACTAL_MANDELBROT_H

#include "fractal_base.h"

class fractal_mandelbrot : public fractal_base
{
public:
	fractal_mandelbrot(int width = 0, int height = 0);


	// fractal_base interface
public:
	QRgb get_color(double x, double y);
};

#endif // FRACTAL_MANDELBROT_H
