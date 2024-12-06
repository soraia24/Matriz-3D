#include "sculptor.cpp"
#include <iostream>

int main () {
      Sculptor s(10, 10, 10);

    // Defina a cor azul e a opacidade total
    s.setColor(0.0, 0.0, 1.0, 1.0);

    // Adicione um cubo
    s.putBox(2, 7, 2, 7, 2, 7); // Definindo as coordenadas mínima e máxima do cubo

    // Salve o modelo em um arquivo OFF
    s.writeOFF("cubo_azul.off");

    std::cout << "Cubo azul criado e salvo como cubo_azul.off" << std::endl;

    return 0;
}