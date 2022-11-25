#include <iostream>
#include "Matrix.h"

int main()
{
    std::cout << "hello" << std::endl;
    Matrix myMatrix(2, 3);
    myMatrix.T().afficher();
    Matrix secondMatrix(myMatrix);
    // secondMatrix.afficher();
    Matrix troisiemeMatrice(2, 2);
    troisiemeMatrice = myMatrix;
    troisiemeMatrice.afficher();
    troisiemeMatrice[0][0] = 7;
    troisiemeMatrice -= 2;
    troisiemeMatrice *= 2;
    troisiemeMatrice[0][1] = 2.5;
    troisiemeMatrice.afficher();
    std::cout << "is symetric : " << troisiemeMatrice.isSymetric() << std::endl;
    std::cout << troisiemeMatrice[1][0] << std::endl;
    double v1[4] = {1, 2, 3, 4};
    double v2[4] = {1, 1, 1, 1};
    std::cout << "res " << scalarProduct(v1, v2, 4) << std::endl;
    
    
    
    Matrix a(3,3);
    Matrix b(3,1);
    a[0][0] = 1;
    a[0][1] = 2;
    a[0][2] = 3;
    a[1][0] = 4;
    a[1][1] = 5;
    a[1][2] = 6;
    a[2][0] = 7;
    a[2][1] = 8;
    a[2][2] = 9;
    b[0][0] = 1;
    b[1][0] = 2;
    b[2][0] = 3;
    a.afficher();
    b.afficher();
    std::cout<<"debut"<<std::endl;
    a.solve(b);
    return 0;
}