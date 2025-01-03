#include <iostream>
#include "sculptor.cpp"
#include "figurageometrica.cpp"
#include "putvoxel.cpp"
#include "cutvoxel.cpp"
#include "putbox.cpp"
#include "cutbox.cpp"
#include "putsphere.cpp"
#include "cutsphere.cpp"
#include "putellipsoid.cpp"
#include "cutellipsoid.cpp"

int main() {
    // Dimensão total do espaço
    Sculptor flor(50, 50, 50);

    // Vaso
    PutBox vaso(18, 32, 0, 14, 0, 10, 0.65, 0.32, 0.17, 1.0); // Marrom
    vaso.draw(flor);
    CutBox recorte1(18, 20, 0, 10, 0, 10);
    recorte1.draw(flor);
    CutBox recorte2(30, 32, 0, 10, 0, 10);
    recorte2.draw(flor);

    // Caule
    PutBox caule(24, 26, 11, 34, 4, 6, 0.0, 1.0, 0.0, 1.0); // Verde
    caule.draw(flor);

    // Folhas
    PutEllipsoid folha1(21, 21, 5, 3, 2, 1, 0.0, 0.8, 0.0, 1.0); // Verde escuro
    folha1.draw(flor);
    PutEllipsoid folha2(28, 21, 5, 4, 2, 1, 0.0, 0.8, 0.0, 1.0); // Verde escuro
    folha2.draw(flor);

    // Excluir as extremidades das folhas
    CutVoxel corte1(19, 22, 5);
    corte1.draw(flor);
    CutVoxel corte2(18, 21, 5);
    corte2.draw(flor);
    CutVoxel corte3(19, 20, 5);
    corte3.draw(flor);
    CutVoxel corte4(23, 22, 5);
    corte4.draw(flor);
    CutVoxel corte5(23, 20, 5);
    corte5.draw(flor);
    CutVoxel corte6(21, 19, 5);
    corte6.draw(flor);

    CutVoxel corte7(27, 22, 5);
    corte7.draw(flor);
    CutVoxel corte8(27, 20, 5);
    corte8.draw(flor);
    CutVoxel corte9(28, 19, 5);
    corte9.draw(flor);
    CutVoxel corte10(31, 22, 5);
    corte10.draw(flor);
    CutVoxel corte11(31, 20, 5);
    corte11.draw(flor);
    CutVoxel corte12(28, 21, 4);
    corte12.draw(flor);
    CutVoxel corte13(21, 21, 4);
    corte13.draw(flor);

    // Pétalas
    PutSphere petala1(20, 36, 5, 4, 1.0, 0.0, 0.0, 1.0); // Vermelho
    petala1.draw(flor);
    PutSphere petala2(30, 36, 5, 4, 1.0, 0.0, 0.0, 1.0); // Vermelho
    petala2.draw(flor);
    PutSphere petala3(25, 41, 5, 4, 1.0, 0.0, 0.0, 1.0); // Vermelho
    petala3.draw(flor);
    PutSphere petala4(25, 31, 5, 4, 1.0, 0.0, 0.0, 1.0); // Vermelho
    petala4.draw(flor);

    // Centro da flor
    PutSphere centro(25, 36, 6, 2, 1.0, 1.0, 0.0, 1.0); // Amarelo
    centro.draw(flor);

    // Exportar para OFF
    flor.writeOFF("flor.off");

    return 0;
}