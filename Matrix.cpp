#include "Matrix.h"

Matrix::Matrix(unsigned int li, unsigned int co) : li(li), co(co)
{
    array = new double *[this->li];
    for (unsigned int i = 0; i < li; i++)
    {
        array[i] = new double[this->co];
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

double *Matrix::operator[](unsigned int li) const
{
    return array[li];
}

Matrix operator*(Matrix const &a, double const &scalaire)
{
    Matrix result(a);
    result *= scalaire;
    return result;
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

bool Matrix::isEqual(Matrix const &b) const
{
    if (li == b.li && co == b.co)
    {
        for (unsigned int i = 0; i < li; i++)
        {
            for (unsigned int j = 0; j < co; j++)
            {
                if (array[i][j] != b.array[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

bool operator==(Matrix const &a, Matrix const &b)
{
    return a.isEqual(b);
}

bool Matrix::isSymetric() const
{
    if (li == co)
    {
        if (*this == this->T())
            return true;
    }
    return false;
}

double scalarProduct(double const *v1, double const *v2, unsigned int const &n)
{
    double result(0);
    for (unsigned int i = 0; i < n; i++)
    {
        result += (v1[i] * v2[i]);
    }
    return result;
}

Matrix &Matrix::operator*=(Matrix const &b)
{
    // Uniquement si matrice carre car ne change pas les dimensions !!
    if (co == b.co && co == b.li) // uniquement produit avec matrice carre
    {
        Matrix a(*this);
        Matrix bT(b.T());
        for (unsigned int i = 0; i < li; i++)
        {
            for (unsigned int j = 0; j < b.co; j++)
            {
                array[i][j] = scalarProduct(a[i], (bT)[j], co);
            }
        }
    }
    return *this;
}

unsigned int Matrix::getCo() const
{
    return this->co;
}

unsigned int Matrix::getLi() const
{
    return this->li;
}

Matrix operator*(Matrix const &a, Matrix const &b)
{
    // matche uniquement si b est carree
    if (b.getCo() == a.getCo())
    {
        Matrix result(a);
        result *= b;
        return result;
    }
    else if (a.getCo() == b.getLi())
    {
        Matrix result(a.getLi(), b.getCo());
        for (unsigned int i = 0; i < result.getLi(); i++)
        {
            for (unsigned int j = 0; j < result.getCo(); j++)
            {
                result[i][j] = scalarProduct(a[i], (b.T())[j], a.getCo());
            }
        }
        return result;
    }
    else // lever exception, dimensions incompatibles
    {
        return Matrix(1, 1);
    }
}

Matrix Matrix::submatrix(unsigned int const &li, unsigned int const &co) const
{
    Matrix result(this->li - 1, this->co - 1);
    for (unsigned int i = 0; i < this->li; i++)
    {
        if (i < li)
        {
            for (unsigned int j = 0; j < this->co; j++)
            {
                if (j < co)
                {
                    result.array[i][j] = this->array[i][j];
                }
                if (j > co)
                {
                    result.array[i][j - 1] = this->array[i][j];
                }
            }
        }
        if (i > li)
        {
            for (unsigned int j = 0; j < this->co; j++)
            {
                if (j < co)
                {
                    result.array[i - 1][j] = this->array[i][j];
                }
                if (j > co)
                {
                    result.array[i - 1][j - 1] = this->array[i][j];
                }
            }
        }
    }
    return result;
}

double Matrix::determinant() const
{
    if (li == co)
    {
        if (this->li == 1) // matrix is scalar
        {
            return this->array[0][0];
        }
        else // matrix is not scalar
        {
            double res(0);
            for (unsigned int i = 0; i < co; i++)
            {
                if (this->array[0][i] != 0)
                {
                    res += pow(-1, i) * this->array[0][i] * this->submatrix(0, i).determinant();
                }
            }
            return res;
        }
    }
    else
    {
        return 0;
    }
}

Matrix Matrix::cofactorMatrix() const
{
    if (li == co)
    {
        Matrix result(li, co);
        for (unsigned int i = 0; i < li; i++)
        {
            for (unsigned int j = 0; j < co; j++)
            {
                result[i][j] = pow(-1, i + j) * (this->submatrix(i, j).determinant());
            }
        }
        return result;
    }
    else
    {
        return *this;
    }
}

Matrix &Matrix::operator/=(double const &scalaire)
{
    return (*this) *= (1 / scalaire);
}

Matrix operator/(Matrix const &a, double const &scalaire)
{
    Matrix result(a);
    result /= scalaire;
    return result;
}

void Matrix::permutRows(unsigned int const &r1, unsigned int const &r2)
{
    if (r1 <= li && r2 <= li)
    {
        double *permutMatrix = new double[co];
        permutMatrix = array[r1];
        array[r1] = array[r2];
        array[r2] = permutMatrix;
    }
    else
    {
        std::cout << "rows out of range, no permutation applied" << std::endl;
    }
}

Matrix Matrix::solve(Matrix const &b) const
{
    if (this->li == b.li)
    {
        Matrix triangular = *this;
        Matrix b2 = b;
        double pivot;
        for (unsigned int i = 0; i < li; i++)
        {
            for (unsigned int j = i + 1; j < li; j++)
            {
                if (triangular[i][i] == 0) // On a un zero : on doit permuter des lignes
                {
                    for (unsigned int k = i + 1; k < li; k++)
                    {
                        if (triangular[k][i] != 0)
                        {
                            triangular.permutRows(i, k);
                            b2.permutRows(i, k);
                            k = li;
                        }
                    }
                }
                if (triangular[i][i] != 0)
                {
                    pivot = (triangular[j][i]) / (triangular[i][i]);
                    if (pivot != 0)
                    {
                        b2[j][0] = b2[j][0] - pivot * b2[i][0];
                        for (unsigned int k = 0; k < co; k++)
                        {
                            triangular[j][k] = triangular[j][k] - pivot * triangular[i][k];
                        }
                    }
                }
            }
        }
        Matrix res(co, 1);
        for (unsigned int i = co; i < li; i++) // check if there is a solution
        {
            if (b2[i][0] != 0) // true if no solution
            {
                std::cout << "No solution" << std::endl;
                return Matrix(this->co, 1);
            }
        }
        std::cout << "Solution exist" << std::endl;
        double previousComponent;
        for (unsigned int i = this->co; i > 0; i--)
        {
            previousComponent = 0;
            pivot = triangular[i - 1][i - 1];
            if (pivot != 0) // check if infinity of solutions
            {
                for (unsigned int j = this->co; j > i; j--)
                {
                    previousComponent += triangular[i - 1][j - 1] * res[j - 1][0];
                }
                res[i - 1][0] = (b2[i - 1][0] - previousComponent) / pivot;
            }
            else
            {
                std::cout << "Infinity of solutions" << std::endl;
                res[i - 1][0] = 0;
            }
        }
        return res;
    }
    else
    {
        ; // pas de solution
        return Matrix(this->co, 1);
    }
}

Matrix Matrix::solveLS(Matrix const &b) const
{
    Matrix transposed = this->T();
    return Matrix(transposed * (*this)).solve(transposed * b);
}

Matrix Matrix::inverse() const
{
    if (this->determinant() != 0)
    {
        return (this->cofactorMatrix().T()) * (1 / (this->determinant()));
    }
    else
    {
        std::cout << "Not invertible" << std::endl;
        return *this;
    }
}