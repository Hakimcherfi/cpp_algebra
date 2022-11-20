#include "Matrix.h"

Matrix::Matrix(unsigned int li, unsigned int co) : li(li), co(co)
{
    array = new double *[li];
    for (unsigned int i = 0; i < li; i++)
    {
        array[i] = new double[co];
        for (unsigned int j = 0; j < co; j++)
        {
            array[i][j] = 0;
        }
    }
}

Matrix &Matrix::operator=(Matrix const &autre)
{
    if (this != &autre)
    {
        // Il faut checker les dimensions avant ces lignes !!!!
        for (unsigned int i = 0; i < li; i++)
        {
            for (unsigned int j = 0; j < co; j++)
            {
                array[i][j] = autre.array[i][j];
            }
        }
    }
    return *this;
}

void Matrix::afficher() const
{
    for (unsigned int i = 0; i < li; i++)
    {
        for (unsigned int j = 0; j < co; j++)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

Matrix::Matrix(Matrix const &autre) : li(autre.li), co(autre.co)
{
    array = new double *[li];
    for (unsigned int i = 0; i < li; i++)
    {
        array[i] = new double[co];
        for (unsigned int j = 0; j < co; j++)
        {
            array[i][j] = autre.array[i][j];
        }
    }
}

Matrix Matrix::T() const
{
    Matrix result(this->co, this->li);
    for (unsigned int i = 0; i < result.li; i++)
    {
        for (unsigned int j = 0; j < result.co; j++)
        {
            result.array[i][j] = this->array[j][i];
        }
    }
    return result;
}

double Matrix::trace() const
{
    unsigned int taille(std::min(li, co));
    double result(0);
    for (unsigned int i = 0; i < taille; i++)
    {
        result += array[i][i];
    }
    return result;
}

Matrix::~Matrix()
{
    std::cout << "destructor" << std::endl;
    for (unsigned int i = 0; i < li; i++)
    {
        delete[] array[i];
    }
    delete[] array;
}

Matrix &Matrix::operator+=(Matrix const &autre)
{
    // Que faire si pas de meme dimensions ?
    if (this->li == autre.li && this->co == autre.co)
    {
        for (unsigned int i = 0; i < this->li; i++)
        {
            for (unsigned int j = 0; j < this->co; j++)
            {
                this->array[i][j] = this->array[i][j] + autre.array[i][j];
            }
        }
    }
    return *this;
}

Matrix &Matrix::operator*=(double const &scalaire)
{
    for (unsigned int i = 0; i < li; i++)
    {
        for (unsigned int j = 0; j < co; j++)
        {
            array[i][j] = array[i][j] * scalaire;
        }
    }
    return *this;
}

Matrix operator+(Matrix const &a, Matrix const &b)
{
    Matrix result(a);
    result += b;
    return result;
}

double *Matrix::operator[](unsigned int li)
{
    return array[li];
}

Matrix operator*(Matrix const &a, double const &scalaire)
{
    Matrix result(a);
    result *= scalaire;
    return a;
}

Matrix &Matrix::operator+=(double const &scalaire)
{
    for (unsigned int i = 0; i < li; i++)
    {
        for (unsigned int j = 0; j < co; j++)
        {
            array[i][j] += scalaire;
        }
    }
    return *this;
}

Matrix operator+(Matrix const &a, double const &scalaire)
{
    Matrix result(a);
    result += scalaire;
    return result;
}

Matrix &Matrix::operator-=(double const &scalaire)
{
    return (*this) += (-scalaire);
}

Matrix &Matrix::operator-=(Matrix const &autre)
{
    return (*this) += (autre * (-1));
}

Matrix operator-(Matrix const &a, Matrix const &b)
{
    return a + (b * (-1));
}

Matrix operator-(Matrix const &a, double const &scalaire)
{
    return a + (-1 * scalaire);
}