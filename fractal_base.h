#ifndef FRACTAL_BASE_H
#define FRACTAL_BASE_H

#include <vector>
#include <QRgb>
#include <complex>
#include <cmath>

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
};

#endif // FRACTAL_BASE_H
