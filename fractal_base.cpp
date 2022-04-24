#include "fractal_base.h"

QRgb fractal_base::iter_color(int itr)
{
	double index;
	double temp_q = (color.size() - 1) * ((double)itr / sensibility);
	double	temp = modf(temp_q, &index);
	if (itr >= sensibility)
		return color.back();
	int r = qRed(color[index])
			+ (qRed(color[index + 1]) - qRed(color[index])) * temp;
	int g = qGreen(color[index])
			+ (qGreen(color[index + 1]) - qGreen(color[index])) * temp;
	int b = qBlue(color[index])
			+ (qBlue(color[index + 1]) - qBlue(color[index])) * temp;
	return qRgb(r, g, b);
}

fractal_base::fractal_base(int width, int height)
{
	x = 0.5;
	y = 0;
	win_height = height;
	win_width = width;
	zoom = 5;
	sensibility = 100;
	color.push_back(qRgb(0,0 , 0));
	color.push_back(qRgb(255, 255, 51));
	color.push_back(qRgb(0, 0, 51));
	color.push_back(qRgb(20, 0, 0));
	color.push_back(qRgb(255,0,127));

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

void fractal_base::set_coord(long double x, long double y)
{
	this->x = x;
	this->y = y;
}

void fractal_base::dif_coord(long double x, long double y)
{
	this->x += x / zoom;
	this->y += y / zoom;
}

void draw_fractal_tread(fractal_base *fractal , QImage *img, int start, int size)
{
	int height = fractal->win_height;
	for(int i = start; i < size; i++)
		for(int j = 0; j < height; j++)
			img->setPixel(i, j, fractal->get_color(i, j));
}

void fractal_base::draw_fractal(QImage *img)
{
	int	width = img->width();
	int	height = img->height();
	int	count_treadth = std::thread::hardware_concurrency();
	int diff_width = width / count_treadth;

	vector<thread>	arr_tread;
	resize(width, height);
	for(int i = 0; i < count_treadth; i++)
		arr_tread.push_back(thread(draw_fractal_tread, this, img, i * diff_width, (i + 1) * diff_width));
	for(auto &var : arr_tread)
		var.join();
}

void fractal_base::zoom_on(long double x, long double y)
{
	zoom *= 2;
	this->x -= (win_height / 2.0L - x) / zoom;
	this->y -= (win_width / 2.0L - y) / zoom;
}

void fractal_base::zoom_off()
{
	if(zoom > 1)
		zoom /= 2;
}

int fractal_base::get_sensibility()
{
	return sensibility;
}

