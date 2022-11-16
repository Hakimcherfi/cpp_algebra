#include "Matrix.h"

Matrix::Matrix():li(3),co(4)
{
    array = 
    for (unsigned int i = 0; i < li; i++)
    {
        for (unsigned int j = 0; j < co; j++)
        {
            array[i][j] = i+j;
        }
    }
}

void Matrix::afficher() const
{
    for (unsigned int i = 0; i < li; i++)
    {
        for (unsigned int j = 0; j < co; j++)
        {
            std::cout << array[i][j];
        }
        std::cout << std::endl;
    }
}
/*
Matrix::Matrix(Matrix const &autre)
{
}
*/
Matrix::~Matrix()
{
}