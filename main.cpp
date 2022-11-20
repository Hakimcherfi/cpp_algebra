#include <iostream>
#include "Matrix.h"

int main()
{
    std::cout << "hello" << std::endl;
    Matrix myMatrix(2, 3);
    myMatrix.T().afficher();
    Matrix secondMatrix(myMatrix);
    //secondMatrix.afficher();
    Matrix troisiemeMatrice(2, 3);
    troisiemeMatrice = myMatrix;
    troisiemeMatrice.afficher();
    troisiemeMatrice[0][0] = 7;
    troisiemeMatrice-=2;
    troisiemeMatrice*=2;
    troisiemeMatrice.afficher();
    std::cout << troisiemeMatrice[1][0] << std::endl;
    return 0;
}