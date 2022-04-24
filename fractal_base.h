#ifndef FRACTAL_BASE_H
#define FRACTAL_BASE_H

#include <vector>
#include <QRgb>
#include <complex>
#include <cmath>
#include <string>
#include <QDebug>
#include <QImage>
#include <thread>

using namespace std;
class fractal_base
{
protected:
	long double		x;
	long double		y;
	long double		zoom;
	vector<QRgb>	color;
	int				sensibility;
	int				win_width;
	int				win_height;

	virtual QRgb	iter_color(int itr);
public:
	fractal_base(int width = 0, int height = 0);

	virtual QRgb	get_color(double x, double y) = 0;
	void			set_sensibility(int new_sens);
	void			resize(int width, int height);
	void			set_coord(long double x, long double y);
	void			dif_coord(long double x, long double y);
	void			draw_fractal(QImage *img);
	void			zoom_on(long double x, long double y);
	void			zoom_off();
	int				get_sensibility();

	friend void draw_fractal_tread(fractal_base *fractal , QImage *img, int start, int size);
};

#endif // FRACTAL_BASE_H
