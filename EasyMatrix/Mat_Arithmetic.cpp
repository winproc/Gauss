#include "Matrix.h"


// todo: complete full implementation
Matrix Matrix::Multiply(Matrix Mat1, Matrix Mat2) {
    if (Mat1.Rows == Mat2.Columns) {

        Matrix resultantMat(Mat2.Columns, Mat1.Rows);
        resultantMat.Data = std::vector<double>();

        for (int i = 1; i <= Mat1.Rows; i++) {
            std::vector<double> Row = Mat1.GetRow(i);

            for (int iy = 1; iy <= Mat2.Columns; iy++) {

                std::vector<double> Column = Mat2.GetColumn(iy);

                int Sum = 0;
                for (int cm = 0; cm < Row.size(); cm++) {
                    Sum = Sum + Row[cm] * Column[cm];
                }

                resultantMat.Data.push_back(Sum);

            }
        }

        return resultantMat;
    }
    else if (Mat2.Rows == Mat1.Columns) {
        throw std::invalid_argument("Operation not supported");
    }
    else {
        throw std::logic_error("Rows and columns of either matrices do not match");
    }
}