#include "sculptor.h"
#include "math.h"
#include <iostream>
#include <fstream>

// Construtor
Sculptor::Sculptor(int _nx, int _ny, int _nz) : nx(_nx), ny(_ny), nz(_nz) {
    // Alocar memória para a matriz 3D de Voxel
    v = new Voxel**[nx];
    for (int i = 0; i < nx; i++) {
        v[i] = new Voxel*[ny];
        for (int j = 0; j < ny; j++) {
            v[i][j] = new Voxel[nz];
            for (int k = 0; k < nz; k++) {
                v[i][j][k].show = false; // Inicializa com o voxel "invisível"
            }
        }
    }
}

// Destrutor
Sculptor::~Sculptor() {
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            delete[] v[i][j]; // Libera "quartos"
        }
        delete[] v[i]; // Libera "andares"
    }
    delete[] v; // Libera "corredores"
}

// Define a cor e a transparência
void Sculptor::setColor(float red, float green, float blue, float alpha) {
    r = red; 
    g = green; 
    b = blue; 
    a = alpha;
}

// Adiciona um voxel
void Sculptor::putVoxel(int x, int y, int z) {
    if (x >= 0 && x < nx && y >= 0 && y < ny && z >= 0 && z < nz) {
        v[x][y][z].show = true;
        v[x][y][z].r = r;
        v[x][y][z].g = g;
        v[x][y][z].b = b;
        v[x][y][z].a = a;
    } else {
        std::cout << "Coordenadas fora dos limites" << std::endl;
    }
}

// Remove um voxel
void Sculptor::cutVoxel(int x, int y, int z) {
    if (x >= 0 && x < nx && y >= 0 && y < ny && z >= 0 && z < nz) {
        v[x][y][z].show = false;
    }
}

// Adiciona uma caixa
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1) {
    for (int i = x0; i <= x1; i++) {
        for (int j = y0; j <= y1; j++) {
            for (int k = z0; k <= z1; k++) {
                putVoxel(i, j, k);
            }
        }
    }
}

// Remove uma caixa
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1) {
    for (int i = x0; i <= x1; i++) {
        for (int j = y0; j <= y1; j++) {
            for (int k = z0; k <= z1; k++) {
                cutVoxel(i, j, k);
            }
        }
    }
}

// Adiciona uma esfera
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius) {
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                if ((i - xcenter) * (i - xcenter) +
                    (j - ycenter) * (j - ycenter) +
                    (k - zcenter) * (k - zcenter) <= radius * radius) {
                    putVoxel(i, j, k);
                }
            }
        }
    }
}

// Remove uma esfera
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius) {
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                if ((i - xcenter) * (i - xcenter) +
                    (j - ycenter) * (j - ycenter) +
                    (k - zcenter) * (k - zcenter) <= radius * radius) {
                    cutVoxel(i, j, k);
                }
            }
        }
    }
}

// Adiciona um elipsoide
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                if ((float)(i - xcenter) * (i - xcenter) / (rx * rx) +
                    (float)(j - ycenter) * (j - ycenter) / (ry * ry) +
                    (float)(k - zcenter) * (k - zcenter) / (rz * rz) <= 1.0) {
                    putVoxel(i, j, k);
                }
            }
        }
    }
}

// Remove um elipsoide
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                if ((float)(i - xcenter) * (i - xcenter) / (rx * rx) +
                    (float)(j - ycenter) * (j - ycenter) / (ry * ry) +
                    (float)(k - zcenter) * (k - zcenter) / (rz * rz) <= 1.0) {
                    cutVoxel(i, j, k);
                }
            }
        }
    }
}

void Sculptor::writeOFF(const char* filename)
{
    int n_v = 0; /* número de vértices */
    int n_f = 0; /* número de faces */
    int ni = 0; /* iteração atual */

    std::ofstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "Houve um erro ao gerar o arquivo " << filename << std::endl;
        return;
    }

    file << "OFF" << std::endl;

    // Contar os vértices e faces
    for (int xi = 0; xi < nx; xi++) {
        for (int yi = 0; yi < ny; yi++) {
            for (int zi = 0; zi < nz; zi++) {
                if (v[xi][yi][zi].show) {
                    n_v += 8;
                    n_f += 6;
                }
            }
        }
    }

    file << n_v << " " << n_f << " " << 0 << std::endl;

    // Escrever vértices
    for (int xi = 0; xi < nx; xi++) {
        for (int yi = 0; yi < ny; yi++) {
            for (int zi = 0; zi < nz; zi++) {
                if (v[xi][yi][zi].show) {
                    file << xi - 0.5 << " " << yi - 0.5 << " " << zi - 0.5 << std::endl;
                    file << xi - 0.5 << " " << yi + 0.5 << " " << zi - 0.5 << std::endl;
                    file << xi + 0.5 << " " << yi + 0.5 << " " << zi - 0.5 << std::endl;
                    file << xi + 0.5 << " " << yi - 0.5 << " " << zi - 0.5 << std::endl;
                    file << xi - 0.5 << " " << yi - 0.5 << " " << zi + 0.5 << std::endl;
                    file << xi - 0.5 << " " << yi + 0.5 << " " << zi + 0.5 << std::endl;
                    file << xi + 0.5 << " " << yi + 0.5 << " " << zi + 0.5 << std::endl;
                    file << xi + 0.5 << " " << yi - 0.5 << " " << zi + 0.5 << std::endl;
                }
            }
        }
    }

    // Escrever faces
    for (int xi = 0; xi < nx; xi++) {
        for (int yi = 0; yi < ny; yi++) {
            for (int zi = 0; zi < nz; zi++) {
                if (v[xi][yi][zi].show) {
                    file << "4 " << ni << " " << ni + 1 << " " << ni + 2 << " " << ni + 3 << std::endl;
                    file << "4 " << ni + 4 << " " << ni + 5 << " " << ni + 6 << " " << ni + 7 << std::endl;
                    file << "4 " << ni << " " << ni + 4 << " " << ni + 7 << " " << ni + 3 << std::endl;
                    file << "4 " << ni + 1 << " " << ni + 5 << " " << ni + 6 << " " << ni + 2 << std::endl;
                    file << "4 " << ni << " " << ni + 3 << " " << ni + 2 << " " << ni + 1 << std::endl;
                    file << "4 " << ni + 4 << " " << ni + 7 << " " << ni + 6 << " " << ni + 5 << std::endl;
                    ni += 8;
                }
            }
        }
    }

    file.close();
}
