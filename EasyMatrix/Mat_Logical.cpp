#include "Matrix.h"

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