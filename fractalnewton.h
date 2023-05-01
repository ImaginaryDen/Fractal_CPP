#ifndef FRACTALNEWTON_H
#define FRACTALNEWTON_H

#include "fractal_base.h"
#include <vector>

class FractalNewton : public fractal_base
{
public:
	FractalNewton(int width = 0, int height = 0) : fractal_base(width, height){}
	FractalNewton(const fractal_base& copy) : fractal_base(copy){}
	~FractalNewton() override{}

private:
	QRgb get_color(double x, double y) override;
	std::vector<complex<double>> roots {complex<double>(1, 0), complex<double>(-0.5, sqrt(3.0) / 2.0), complex<double>(-0.5, -sqrt(3.0) / 2.0)};
	std::vector<QRgb> colors {qRgb(255,0,0), qRgb(0,255,0), qRgb(0,0,255)};
	double tolerance = 0.000001;
};

#endif // FRACTALNEWTON_H
