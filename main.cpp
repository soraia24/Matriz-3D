#include "sculptor.cpp"
#include <iostream>

int main() {
    // Dimensão total do espaço
    Sculptor flor(50, 50, 50);

// Vaso
flor.setColor(0.65, 0.32, 0.17, 1.0); // Marrom
flor.putBox(20, 30, 0, 10, 0, 10);   // Base do vaso
flor.putBox(18, 32, 10, 14, 0, 10);  // Parte superior do vaso

// Caule 
flor.setColor(0.0, 1.0, 0.0, 1.0); // Verde
flor.putBox(24, 26, 11, 31, 4, 6); // 

// Folhas
flor.setColor(0.0, 0.8, 0.0, 1.0); // Verde escuro
flor.putBox(20, 24, 22, 24, 2, 4); // Folha esquerda
flor.putBox(26, 30, 22, 24, 6, 8); // Folha direita

// Pétalas
flor.setColor(1.0, 0.0, 0.0, 1.0); // Vermelho
flor.putSphere(23, 32, 5, 4); // Pétala esquerda
flor.putSphere(27, 32, 5, 4); // Pétala direita
flor.putSphere(25, 32, 3, 4); // Pétala inferior
flor.putSphere(25, 32, 7, 4); // Pétala superior

// Centro da flor
flor.setColor(1.0, 1.0, 0.0, 1.0); // Amarelo
flor.putSphere(25, 32, 5, 2); // Centro

// Exportar para OFF
flor.writeOFF("flor.off");

    return 0;
}
