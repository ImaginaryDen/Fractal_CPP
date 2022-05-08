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
	complex<double>	const_value;

public:
	fractal_base(int width = 0, int height = 0);
	fractal_base(const fractal_base& copy);

	fractal_base	&operator =(const fractal_base &copy);
	bool			operator ==(const fractal_base *other);
	bool			operator !=(const fractal_base *other);

	virtual ~fractal_base(){}
	virtual QRgb	get_color(double x, double y)
		{return qRgb(static_cast<int>(x) % 255, static_cast<int>(y) % 255, static_cast<int>(x*y) % 255);}

	QRgb			iter_color(int itr);
	void			set_sensibility(int new_sens);
	void			resize(int width, int height);
	void			set_coord(long double x, long double y);
	void			dif_coord(long double x, long double y);
	void			draw_fractal(QImage *img);
	void			zoom_on(long double x, long double y);
	void			zoom_off();
	int				get_sensibility();
	long double		get_zoom();
	long double		get_y();
	long double		get_x();

	friend void draw_fractal_tread(fractal_base *fractal , QImage *img, int start, int size);
};

#endif // FRACTAL_BASE_H
