// EasyMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stdexcept>

class MatCoord {
public:

    int x = 0;
    int y = 0;

    MatCoord(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

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

    static Matrix DotProduct(Matrix Mat1, Matrix Mat2);

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

std::vector<double> Matrix::GetRow(int nRow) {
    std::vector<double> RowData;

    int Offset = (nRow - 1) * this->Rows;
    for (int i = 1; i <= this->Columns; i++) {
        RowData.push_back(this->Data.at(Offset + i));
    }

    return RowData;
}

std::vector<double> Matrix::GetColumn(int nColumn) {
    std::vector<double> RowData;

    int XOffset = nColumn - 1;
    for (int i = 0; i < this->Rows; i++) {
        RowData.push_back(this->Data.at(this->Columns * i + XOffset));
    }

    return RowData;
}

double Matrix::GetValAtCoord(MatCoord mCoord) {
    return this->Data.at(this->TranslateToIndex(mCoord));
};

void Matrix::SetValAtCoord(MatCoord mCoord, double Val) {
    this->Data.at(this->TranslateToIndex(mCoord)) = Val;
};

int Matrix::TranslateToIndex(MatCoord MC) {
    return (MC.y - 1) * this->Columns + MC.x - 1;
}

MatCoord Matrix::TranslateToCoord(int Index) {

    if (Index < 0 && Index > this->Data.size()) {
        throw std::invalid_argument("Arguments out of bounds");
    };

    MatCoord rCoord(1, 1);

    double RelationalOffset = (Index + 1.0) / this->Columns;
    double XOffsetScaleConstant = 1.0 / this->Columns;

    double xComponent, yComponent;

    yComponent = floor(RelationalOffset) + ceil(RelationalOffset - floor(RelationalOffset));

    xComponent = RelationalOffset - floor(RelationalOffset);
    xComponent = (xComponent ? xComponent : 1.0) / XOffsetScaleConstant;

    rCoord.x = std::max(xComponent, 1.0);
    rCoord.y = std::max(yComponent, 1.0);

    return rCoord;
};

int Matrix::FormSquareMatrix(int len) {

    int FlooredSqrt = sqrt(len);
    if ((sqrt(len) - FlooredSqrt) == 0.0f) {
        return FlooredSqrt;
    }
    else {
        return 0;
    }

}

Matrix Matrix::DotProduct(Matrix Mat1, Matrix Mat2) {
    if (Mat1.Rows == Mat2.Columns) {

        Matrix resultantMat(Mat2.Columns, Mat1.Rows);
        resultantMat.Data = std::vector<double>();

        for (int i = 1; i <= Mat1.Rows; i++) {
            std::vector<double> Row = Mat1.GetRow(i);

            for (int iy = 1; iy <= Mat2.Columns; iy++) {
                
                std::vector<double> Column = Mat2.GetColumn(i);

                int Sum = 0;
                for (int cm = 0; cm < Row.size(); cm++) {
                    Sum = Sum + Row[cm] * Column[cm];
                }

                resultantMat.Data.push_back(Sum);

            }
        }

    }
    else if (Mat2.Rows == Mat1.Columns) {
        throw std::invalid_argument("operation not supported");
    }
    else {
        throw std::logic_error("Rows and columns of either matrices do not match");
    }
}


int main()
{

    std::vector<double> KernelData{
        1.0, 1.0, 1.0,
        0.0, 0.0, 0.0,
        1.0, 1.0, 1.0
    };

    Matrix Sobel(3);

}


