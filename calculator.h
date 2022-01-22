#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "matrix.h"


class Calculator
{
public:
    Calculator();
    ~Calculator();

    Matrix sum(Matrix matrix1, Matrix matrix2);
    Matrix multiply(Matrix matrix1, Matrix matrix2);
    Matrix Transpose(Matrix matrix);
    Matrix Adjungate(Matrix matrix);
    Matrix minor_matrix(int i, int j, Matrix matrix);
    int determinant(Matrix matrix);
};

#endif // CALCULATOR_H
