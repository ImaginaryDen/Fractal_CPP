#ifndef IGETFRACTAL_H
#define IGETFRACTAL_H

#include "fractal_base.h"
class IGetFractal{
public:
   virtual fractal_base *get_curent_fractal() = 0;
};

#endif // IGETFRACTAL_H
