#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "figurageometrica.h"

/**
 * @class PutVoxel
 * 
 *usada para representar um único voxel no espaço tridimensional, com a capacidade de ser desenhado (através do método draw) em um "mundo 3D" modelado por Sculptor.
 */


class PutVoxel : public FiguraGeometrica
{
    int x, y, z;
    float r,g,b,a;

public:
    PutVoxel(int _x, int _y, int _z, float _r, float _g, float _b, float _a);
    void draw(Sculptor &t);
    ~PutVoxel();
};

#endif // PUTVOXEL_H