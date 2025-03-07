#include "cutellipsoid.h"

CutEllipsoid::CutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz)
{
    xcenter=_xcenter;
    ycenter=_ycenter;
    zcenter=_zcenter;
    rx=_rx;
    ry=_ry;
    rz=_rz;
}

CutEllipsoid::~CutEllipsoid()
{

}


void CutEllipsoid::draw(Sculptor &t){
    float dx,dy,dz;
    int x1 = xcenter-rx, x2 = xcenter+rx, y1 = ycenter-ry,
        y2 = ycenter+ry, z1 = zcenter-rz, z2 = zcenter+rz;
    for(int i=x1; i<x2; i++){
        dx=((static_cast<float>(i)-xcenter)/rx)*((static_cast<float>(i)-xcenter)/rx);
        for(int j=y1; j<y2; j++){
            dy=((static_cast<float>(j)-ycenter)/ry)*((static_cast<float>(j)-ycenter)/ry);
            for (int k=z1; k<z2; k++) {
                dz=((static_cast<float>(k)-zcenter)/rz)*((static_cast<float>(k)-zcenter)/rz);
                if(dx+dy+dz<=1){
                    t.cutVoxel(i,j,k);
                }
            }
        }
    }
}

