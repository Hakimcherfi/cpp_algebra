#include "Matrix.h"

Matrix::Matrix()
{
    li = 1;
    co = 1;
    array = 0;
}

void Matrix::afficher() const
{
    std::cout <<array;
    for (unsigned int i = 0; i < li; i++)
    {
        for (unsigned int j = 0; j < co; j++)
        {
            ;//std::cout << array[i][j];
        }
        std::cout << std::endl;
    }
}

Matrix::Matrix(Matrix const &autre)
{
}

Matrix::~Matrix()
{
}