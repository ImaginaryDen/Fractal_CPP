#ifndef FRACTAL_SIERPINSKI_H
#define FRACTAL_SIERPINSKI_H

#include "fractal_base.h"

class fractal_Sierpinski : public fractal_base
{
public:
    fractal_Sierpinski(int width = 0, int height = 0)
        : fractal_base(width, height)
    {}
    fractal_Sierpinski(const fractal_base& copy) : fractal_base(copy){}

    void draw_fractal(QImage *img) override;
    void drawSierpinski(QImage *img, long double x, long double y, int size, int depth);
    void dif_coord(long double x, long double y) override;
};

#endif // FRACTAL_SIERPINSKI_H
