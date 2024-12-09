#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include "sculptor.h"

using namespace std;


// implementacao do construtor da classe Sculptor
Sculptor::Sculptor(int _nx, int _ny, int _nz){


    nx = _nx;
    ny = _ny;
    nz = _nz;
    r = 0.0;
    g = 0.0;
    b = 0.0;
    a = 0.0;

    v = new Voxel **[_nx];

    for(int i = 0; i < _nx; i++ ){

        v[i] = new Voxel *[_ny];
        for(int j = 0; j < _ny; j++){

            v[i][j] = new Voxel [_nz];
            for(int k = 0; k < _nz; k++){

                    this->v[i][j][k].r = 0.0;
                    this->v[i][j][k].g = 0.0;
                    this->v[i][j][k].b = 0.0;
                    this->v[i][j][k].a = 0.0;
                    this->v[i][j][k].show = false;
            }
        }
    }
}

// implementacao do destrutor da classe Sculptor
Sculptor::~Sculptor(){

    for(int i = 0; i < nx; i++ ){

        for(int j = 0; j < ny; j++){

           delete[] v[i][j];
        }
        delete[] v[i];
    }
    delete[] v;

}

// definicao das cores vermelho, verde e azul
void Sculptor::setColor(float red, float green, float blue, float alpha){

    this->r = red;
    this->g = green;
    this->b = blue;
    this->a = alpha;

}

//definicao da funcao putVoxel
void Sculptor::putVoxel(int x, int y, int z){

    this->v[x][y][z].show = true;
    this->v[x][y][z].r = this->r;
    this->v[x][y][z].g = this->g;
    this->v[x][y][z].b = this->b;
    this->v[x][y][z].a = this->a;

}

// definicao da funcao cutVoxel
void Sculptor::cutVoxel(int x, int y, int z){
    this->v[x][y][z].show = false;
}

// ddefinicao da funcao putBox
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int i = x0; i < x1; i++){
        for(int j = y0; j < y1; j++){
            for(int k = z0; k< z1; k++){
                this->putVoxel(i,j,k);
            }
        }
    }
}

//definicao da funcao cutBox
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){

    // desativa os voxels
    for(int i = x0; i < x1; i++){
        for(int j = y0; j < y1; j++){
            for(int k = z0; k< z1; k++){

                this->cutVoxel(i,j,k);
            }
        }
    }
}

// definicao da funcao putEllipsoid
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){

    // verifica se os valores do elipsoide estao dentro da dimensao

    int x0 = (xcenter - rx < 0) ? 0 : xcenter - rx;
    int x1 = (xcenter + rx > this->nx) ? this->nx : xcenter + rx;
    int y0 = (ycenter - ry < 0) ? 0 : ycenter - ry;
    int y1 = (ycenter + ry > this->ny) ? this->ny : ycenter + ry;
    int z0 = (zcenter - rz < 0) ? 0 : zcenter - rz;
    int z1 = (zcenter + rz > this->nz) ? this->nz : zcenter + rz;

     for(int i = x0; i < x1; i++){
        for(int j = y0; j < y1; j++){
            for(int k = z0; k< z1; k++){

                if(pow(i - xcenter, 2) / pow(rx, 2) + pow(j - ycenter, 2) / pow(ry, 2) + pow(k - zcenter, 2) / pow(rz, 2) < 1){

                    this->putVoxel(i,j,k);
                }


            }
        }
    }


}

// definicao da funcao cutEllipsoid
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){

    // verifica se os valores do elipsoide estao dentro da dimensao
    int x0 = (xcenter - rx < 0) ? 0 : xcenter - rx;
    int x1 = (xcenter + rx > this->nx) ? this->nx : xcenter + rx;
    int y0 = (ycenter - ry < 0) ? 0 : ycenter - ry;
    int y1 = (ycenter + ry > this->ny) ? this->ny : ycenter + ry;
    int z0 = (zcenter - rz < 0) ? 0 : zcenter - rz;
    int z1 = (zcenter + rz > this->nz) ? this->nz : zcenter + rz;

     for(int i = x0; i < x1; i++){
        for(int j = y0; j < y1; j++){
            for(int k = z0; k< z1; k++){

                if(pow(i - xcenter, 2) / pow(rx, 2) + pow(j - ycenter, 2) / pow(ry, 2) + pow(k - zcenter, 2) / pow(rz, 2) < 1 ){

                    this->cutVoxel(i,j,k);
                }


            }
        }
    }

}

// definicao da funcao putSphere
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){

    // gera a esfera atraves da funcao putEllipsoid, com o raio unico
    putEllipsoid(xcenter,ycenter,zcenter,radius,radius,radius);
}

//definicao da funcao cutSphere
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){

    // desativa a esfera atraves da funcao cutEllipsoid, com o raio unico
    cutEllipsoid(xcenter,ycenter,zcenter,radius,radius,radius);
}


// definicao da funcao geradora de arquivo
void Sculptor::writeOFF(const char *filename){

    ofstream myFile(filename);
    //Inicia o stream
    if (!myFile.is_open())
    {
        cout << "Erro ao abrir o arquivo: "<< filename << endl;
        exit(1);
    }

    // conta quantos voxels tem
    int vOn = 0, i, j, k;
    for (i = 0; i < nx; i++)
    {
        for (j = 0; j < ny; j++)
        {
            for (k = 0; k < nz; k++)
            {
                if (this->v[i][j][k].show)
                {
                    vOn++;
                }
            }
        }
    }

    // reescrevendo no formato OFF
    myFile << "OFF" << endl;
    myFile << 8 * vOn << " " << 6 * vOn << " 0" << endl;

    for (i = 0; i < nx; i++)
    {
        for (j = 0; j < ny; j++)
        {
            for (k = 0; k < nz; k++)
            {
                if (this->v[i][j][k].show)
                {
                    // mais stream
                    myFile << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
                    myFile << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
                    myFile << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
                    myFile << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
                    myFile << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
                    myFile << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
                    myFile << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
                    myFile << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
                }
            }
        }
    }

    int contVOn = 0;
    for (i = 0; i < nx; i++)
    {
        for (j = 0; j < ny; j++)
        {
            for (k = 0; k < nz; k++)
            {
                if (this->v[i][j][k].show)
                {
                    myFile << "4 " << contVOn * 8 + 0 << " " << contVOn * 8 + 3 << " " << contVOn * 8 + 2 << " " << contVOn * 8 + 1 << " " << this->v[i][j][k].r << ".0 " << this->v[i][j][k].g << ".0 " << this->v[i][j][k].b << ".0 " << this->v[i][j][k].a << ".0" << endl;
                    myFile << "4 " << contVOn * 8 + 4 << " " << contVOn * 8 + 5 << " " << contVOn * 8 + 6 << " " << contVOn * 8 + 7 << " " << this->v[i][j][k].r << ".0 " << this->v[i][j][k].g << ".0 " << this->v[i][j][k].b << ".0 " << this->v[i][j][k].a << ".0" << endl;
                    myFile << "4 " << contVOn * 8 + 0 << " " << contVOn * 8 + 1 << " " << contVOn * 8 + 5 << " " << contVOn * 8 + 4 << " " << this->v[i][j][k].r << ".0 " << this->v[i][j][k].g << ".0 " << this->v[i][j][k].b << ".0 " << this->v[i][j][k].a << ".0" << endl;
                    myFile << "4 " << contVOn * 8 + 0 << " " << contVOn * 8 + 4 << " " << contVOn * 8 + 7 << " " << contVOn * 8 + 3 << " " << this->v[i][j][k].r << ".0 " << this->v[i][j][k].g << ".0 " << this->v[i][j][k].b << ".0 " << this->v[i][j][k].a << ".0" << endl;
                    myFile << "4 " << contVOn * 8 + 3 << " " << contVOn * 8 + 7 << " " << contVOn * 8 + 6 << " " << contVOn * 8 + 2 << " " << this->v[i][j][k].r << ".0 " << this->v[i][j][k].g << ".0 " << this->v[i][j][k].b << ".0 " << this->v[i][j][k].a << ".0" << endl;
                    myFile << "4 " << contVOn * 8 + 1 << " " << contVOn * 8 + 2 << " " << contVOn * 8 + 6 << " " << contVOn * 8 + 5 << " " << this->v[i][j][k].r << ".0 " << this->v[i][j][k].g << ".0 " << this->v[i][j][k].b << ".0 " << this->v[i][j][k].a << ".0" << endl;
                    contVOn++;
                }
            }
        }
    }

    // fecha o arquivo
    myFile.close();
    }