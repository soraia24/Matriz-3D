#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "sculptor.h"
#include <iostream>

/**
 * @class FiguraGeometrica
 * 
* A classe FiguraGeometrica é uma classe base abstrata, usada para representar diferentes tipos de figuras geométricas em um modelo 3D. Ela define a interface que deve ser seguida por todas as classes que representam formas geométricas, como PutVoxel, PutSphere, PutEllipsoid, entre outras. */


using namespace std;

class FiguraGeometrica
{
public:
    FiguraGeometrica();
    virtual void draw(Sculptor &t)=0;
    virtual  ~FiguraGeometrica();

};

#endif // FIGURAGEOMETRICA_H