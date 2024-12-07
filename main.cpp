#include "sculptor.cpp"
#include <iostream>

int main() {
    // Dimensão total do espaço
    Sculptor flor(50, 50, 50);

    // Vaso
    flor.setColor(0.65, 0.32, 0.17, 1.0); // Marrom
    flor.putBox(20, 30, 0, 10, 0, 10);   // Base do vaso
    flor.putBox(21, 29, 10, 20, 1, 9);  // Parte superior do vaso

    // Caule
    flor.setColor(0.0, 1.0, 0.0, 1.0); // Verde
    flor.putBox(24, 26, 20, 40, 4, 6); // Caule

    // Folhas
    flor.setColor(0.0, 0.8, 0.0, 1.0); // Verde escuro
    flor.putBox(20, 24, 30, 32, 2, 4); // Folha esquerda
    flor.putBox(26, 30, 30, 32, 6, 8); // Folha direita

    // Pétalas
    flor.setColor(1.0, 0.0, 0.0, 1.0); // Vermelho
    flor.putSphere(23, 42, 5, 4); // Pétala esquerda
    flor.putSphere(27, 42, 5, 4); // Pétala direita
    flor.putSphere(25, 42, 3, 4); // Pétala inferior
    flor.putSphere(25, 42, 7, 4); // Pétala superior

    // Centro da flor
    flor.setColor(1.0, 1.0, 0.0, 1.0); // Amarelo
    flor.putSphere(25, 42, 5, 2); // Centro

    // Exportar para OFF
    flor.writeOFF("flor.off");

    return 0;
}
