#include <iostream>
#include <math.h>

class Matrix
{
private:
    const unsigned int li;
    const unsigned int co;
    double **array;

public:
    Matrix(unsigned int li = 2, unsigned int co = 2);
    Matrix(Matrix const &autre);
    Matrix &operator=(Matrix const &autre);
    Matrix &operator+=(Matrix const &autre);
    Matrix &operator+=(double const &scalaire);
    Matrix &operator-=(Matrix const &autre);
    Matrix &operator-=(double const &scalaire);
    Matrix &operator*=(double const &scalaire);
    Matrix &operator*=(Matrix const &autre);
    double *operator[](unsigned int li);
    Matrix getSubmatrix(unsigned int const &li, unsigned int const &co) const;
    bool isEqual(Matrix const &b) const;
    bool isSymetric() const;
    void afficher() const;
    ~Matrix();

    Matrix T() const; // transpose
    //  * matrice non carree
    //  / matrice
    //  determinant
    //  inverse
    //  allocations plusieurs valeurs
    //  vecteurs propres et valeurs propres
    //
    double trace() const;
    double determinant() const;
};

Matrix operator+(Matrix const &a, Matrix const &b);
Matrix operator+(Matrix const &a, double const &scalaire);
Matrix operator-(Matrix const &a, Matrix const &b);
Matrix operator-(Matrix const &a, double const &scalaire);
Matrix operator*(Matrix const &a, double const &scalaire);
Matrix operator*(Matrix const &a, Matrix const &b);
bool operator==(Matrix const &a, Matrix const &b);
double scalarProduct(double const *v1, double const *v2, unsigned int const &n);