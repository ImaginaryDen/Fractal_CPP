#ifndef FRACTAL_MANDELBROT_H
#define FRACTAL_MANDELBROT_H

#include "fractal_base.h"

class fractal_mandelbrot : public fractal_base
{
public:
	fractal_mandelbrot(int width = 0, int height = 0);
	fractal_mandelbrot(const fractal_base& copy) : fractal_base(copy){}
	~fractal_mandelbrot() override{}

private:
	QRgb get_color(double x, double y) override;
};

#endif // FRACTAL_MANDELBROT_H
