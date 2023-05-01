#include "fractalnewton.h"

QRgb FractalNewton::get_color(double x, double y)
{
	int size = min(win_height, win_width);
	complex<double>	value(
				4 * (x + this->x * this->zoom
					- win_height * 0.5L) / (size * this->zoom),
				4 * (y + this->y * this->zoom
					  - win_width * 0.5L) / (size * this->zoom));

	for (int i = 0; i < sensibility; ++i)
	{
		value -= ((pow(value, 3) - complex<double>(1, 0)) / (complex<double>(3, 0) * pow(value, 2)));
		for (size_t d = 0; d < roots.size(); ++d)
		{
			complex<double> difference = value - roots[d];

			if (abs(difference.imag()) < tolerance && abs(difference.real()) < tolerance)
				return colors[d];
		}
	}
	return (Qt::black);
}
