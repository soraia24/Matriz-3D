#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "figurageometrica.h"

/**
 * @class CutVoxel
 * 
 *usada para excluir um único voxel no espaço tridimensional, com a capacidade de ser desenhado (através do método draw) em um "mundo 3D" modelado por Sculptor.
 */

class CutVoxel : public FiguraGeometrica
{
     int x, y, z;
public:
    CutVoxel(int _x, int _y, int _z);
    void draw(Sculptor &t);
    ~CutVoxel();
};

#endif // CUTVOXEL_H