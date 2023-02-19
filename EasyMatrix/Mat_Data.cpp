#include "Matrix.h"

std::vector<double> Matrix::GetRow(int nRow) {
    std::vector<double> RowData;

    int Offset = (nRow - 1) * this->Rows;
    for (int i = 0; i < this->Columns; i++) {
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