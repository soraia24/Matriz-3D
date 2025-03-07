#ifndef PUTBOX_H
#define PUTBOX_H
#include "figurageometrica.h"

/**
 * @class PutBox
 * 
 *usada para desenhar um bloco retangular de voxels no espaço 3D. Ela é usada para ativar ou colocar múltiplos voxels dentro de uma caixa ou bloco definido por um conjunto de coordenadas
 */

class PutBox : public FiguraGeometrica
{
    int x0,y0,z0,x1,y1,z1;
     float r,g,b,a;

public:
    PutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1, float _r, float _g, float _b, float _a);
    void draw(Sculptor &t);
    ~PutBox();
};

#endif // PUTBOX_H