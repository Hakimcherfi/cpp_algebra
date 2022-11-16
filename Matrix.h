#include <iostream>

class Matrix
{
    const unsigned int li;
    const unsigned int co;
    double* array;

public:
    Matrix();
    Matrix(Matrix const &autre);
    void afficher() const;
    ~Matrix();

    //+matrice
    //+ scalaire
    //*matrice
    //*scalaire
    // /matrice
    //-matrice
    //-scalaire
    // transposition
    // determinant
    // trace
};