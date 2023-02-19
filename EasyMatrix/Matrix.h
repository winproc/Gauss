#pragma once
#include <vector>
#include <stdexcept>

#include "Helper.h"

class Matrix {
private:

    int Rows;
    int Columns;
    std::vector<double> Data;

    int FormSquareMatrix(int len);

public:

    void SetValAtCoord(MatCoord mCoord, double Val);
    double GetValAtCoord(MatCoord mCoord);

    std::vector<double> GetRow(int nRow);
    std::vector<double> GetColumn(int nColumn);

    static Matrix Multiply(Matrix Mat1, Matrix Mat2);
    static Matrix Add(Matrix Mat1, Matrix Mat2);

    MatCoord TranslateToCoord(int Index);
    int TranslateToIndex(MatCoord MC);

    Matrix(std::vector<double>* Data) {
        this->Data = *Data;
        int nDimSM = FormSquareMatrix(this->Data.size());

        if (nDimSM) {
            Rows = Columns = nDimSM;
        }
        else {
            Rows = this->Data.size();
            Columns = 1;
        }
    }

    Matrix(std::vector<double>* Data, int Rows, int Columns) {
        this->Data = *Data;

        this->Rows = Rows;
        this->Columns = Columns;
    };

    Matrix(int Rows, int Columns) {
        this->Rows = Rows;
        this->Columns = Columns;

        this->Data = std::vector<double>(Rows * Columns, 0.0);
    };

    // Constructor: Create identity matrix
    Matrix(int Dim) {

        std::vector<double> DataLocal(pow(Dim, 2), 0.0);
        this->Rows = this->Columns = Dim;

        MatCoord MC_t(1, 1);
        for (int i = 1; i <= Dim; i++) {
            MC_t.y = MC_t.x = i;
            DataLocal.at(this->TranslateToIndex(MC_t)) = 1.0;
        };

        this->Data = DataLocal;

    };


};