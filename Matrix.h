#include <iostream>

class Matrix
{
private:
    const unsigned int li;
    const unsigned int co;
    double **array;

public:
    Matrix(unsigned int li = 2, unsigned int co = 2);
    Matrix(Matrix const &autre);
    void afficher() const;
    ~Matrix();
    Matrix &operator=(Matrix const &autre);
    //+matrice
    Matrix &operator+=(Matrix const &autre);
    double *operator[](unsigned int li);
    //+ scalaire
    //*matrice
    //*scalaire
    //  /matrice
    //-matrice
    //-scalaire
    Matrix T() const; // transpose
    // determinant
    double trace() const;
};

Matrix operator+(Matrix const &a, Matrix const &b);