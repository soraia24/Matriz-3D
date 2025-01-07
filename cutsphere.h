#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "figurageometrica.h"

/**
 * @class CutSphere
 * 
 *usada para excluir uma esfera dentro do espaço 3D.
 */

class CutSphere : public FiguraGeometrica
{
    int xcenter, ycenter, zcenter, radius;
public:
    CutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius);
    void draw(Sculptor &t);
    ~CutSphere();

};

#endif // CUTSPHERE_H