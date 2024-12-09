#include "sculptor.cpp"
#include <iostream>

int main() {
    // Dimensão total do espaço
    Sculptor flor(50, 50, 50);

// Vaso
flor.setColor(0.65, 0.32, 0.17, 1.0); // Marrom
flor.putBox(18, 32, 0, 14, 0, 10); 
flor.cutBox(18,20,0,10,0,10);
flor.cutBox(30,32,0,10,0,10);

// Caule 
flor.setColor(0.0, 1.0, 0.0, 1.0); // Verde
flor.putBox(24, 26, 11, 35, 4, 6); // 

// Folhas
flor.setColor(0.0, 0.8, 0.0, 1.0); // Verde escuro
flor.putEllipsoid(21, 21, 4, 3, 2, 1);
flor.putEllipsoid(28, 21, 4, 3, 2, 1);


//Excluir as extremidades da folha
flor.cutVoxel(19, 22, 4);
flor.cutVoxel(30, 22, 4); 
flor.cutVoxel(23, 22, 4);
flor.cutVoxel(23, 20, 4);
flor.cutVoxel(26, 22, 4);
flor.cutVoxel(26, 20, 4);
flor.cutVoxel(19, 20, 4); 
flor.cutVoxel(30, 20, 4); 


// Pétalas
flor.setColor(1.0, 0.0, 0.0, 1.0); // Vermelho
flor.putSphere(20, 36, 5, 4); // Pétala esquerda
flor.putSphere(30, 36, 5, 4); // Pétala direita
flor.putSphere(25, 40, 3, 4); // Pétala inferior
flor.putSphere(25, 31, 5, 4); // Pétala superior



// Centro da flor
flor.setColor(1.0, 1.0, 0.0, 1.0); // Amarelo
flor.putSphere(25, 36, 5, 2); // Centro

// Exportar para OFF
flor.writeOFF("flor.off");

    return 0;
}
