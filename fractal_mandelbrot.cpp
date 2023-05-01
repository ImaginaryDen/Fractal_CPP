#include "fractal_mandelbrot.h"

fractal_mandelbrot::fractal_mandelbrot(int width, int height)
	: fractal_base(width, height)
{}

QRgb fractal_mandelbrot::get_color(double x, double y)
{
	int size = min(win_height, win_width);
	complex<double>	value(
				4 * (x + this->x * this->zoom
					- win_height * 0.5L) / (size * this->zoom),
				4 * (y + this->y * this->zoom
					  - win_width * 0.5L) / (size * this->zoom));
	complex<double> start_value = value;

	for (int i = 0; i < sensibility; i++)
	{
		value *= value;
		value += start_value;
		if (abs(value) > 2)
			return (iter_color(i));
	}
	return (iter_color(sensibility));
}
