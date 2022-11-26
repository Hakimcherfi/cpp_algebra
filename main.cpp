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
    Matrix a(2,2);
    Matrix b(2,1);
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 1;
    a[1][1] = 1;
    b[0][0] = 3.0000;
    b[1][0] = 2;
    a.afficher();
    b.afficher();
    Matrix x1(a.solve(b));
    Matrix x2(a.solveLS(b));
    x1.afficher();
    x2.afficher();
    a[1][0] = 3;
    a[1][1] = 4;
    a.afficher();
    a.cofactorMatrix().afficher();
    a.inverse().afficher();
    Matrix test(3,3);
    test[0][0] = 2;
    test[0][1] = 3;
    test[1][1] = 4;
    test[2][2] = 1;
    test[2][0] = -1;
    test.afficher();
    (test.inverse()*test).afficher();
    (test*(test.inverse())).afficher();
    return 0;
}