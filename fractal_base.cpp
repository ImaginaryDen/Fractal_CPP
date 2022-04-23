#include "fractal_base.h"

QRgb fractal_base::iter_color(int itr)
{
	double	index = color.size() * (itr/ sensibility);
	return (color[static_cast<int>( round(index) )]);
}

fractal_base::fractal_base(int width, int height)
{
	x = 0;
	y = 0;
	win_height = height;
	win_width = width;
	zoom = 1;
	sensibility = 100;
	color.push_back(qRgb(255,255,255));
	color.push_back(qRgb(0,0,0));
}

void fractal_base::set_sensibility(int new_sens)
{
	if(new_sens > 10 && new_sens < 1000)
		sensibility = new_sens;
}

void fractal_base::resize(int width, int height)
{
	win_height = height;
	win_width = width;
}
