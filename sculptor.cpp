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