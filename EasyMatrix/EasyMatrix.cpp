// EasyMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Gauss.h"

int main()
{

    std::vector<double> KernelData{
        1.0, 1.0, 1.0,
        0.0, 0.0, 0.0,
        1.0, 2.0, 1.0
    };

    Matrix Sobel(&KernelData);
    Matrix Identity(3);

    Matrix Dot = Matrix::Multiply(Identity, Sobel);
    std::cout;
}


