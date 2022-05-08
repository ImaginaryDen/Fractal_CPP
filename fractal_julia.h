#ifndef FRACTAL_JULIA_H
#define FRACTAL_JULIA_H

#include "fractal_base.h"

class fractal_julia : public fractal_base
{
public:
	fractal_julia(int width = 0, int height = 0);
	fractal_julia(const fractal_base& copy) : fractal_base(copy){}

	~fractal_julia() override {}

private:
	QRgb get_color(double x, double y) override;
};

#endif // FRACTAL_JULIA_H
