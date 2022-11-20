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
    Matrix &operator+=(Matrix const &autre);
    Matrix &operator+=(double const &scalaire);
    Matrix &operator-=(Matrix const &autre);
    Matrix &operator-=(double const &scalaire);
    Matrix &operator*=(double const &scalaire);
    double *operator[](unsigned int li);
    //*matrice
    //  /matrice
    Matrix T() const; // transpose
    // determinant
    double trace() const;
};

Matrix operator+(Matrix const &a, Matrix const &b);
Matrix operator+(Matrix const &a, double const &scalaire);
Matrix operator-(Matrix const &a, Matrix const &b);
Matrix operator-(Matrix const &a, double const &scalaire);
Matrix operator*(Matrix const &a, double const &scalaire);