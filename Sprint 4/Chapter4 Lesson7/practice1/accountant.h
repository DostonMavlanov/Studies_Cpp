#pragma once
#include "square_calculation.h"
#include "wall.h"

class Accountant{
public:
    double CalcPaintNeeded(const Wall& wall) const {
        double width = wall.GetWidth();
        double height = wall.GetHeight();
        return CalcSquare(width, height) * 0.4;
    }

    double CalcBricksNeeded(const Wall& wall) const {
        double width = wall.GetWidth();
        double height = wall.GetHeight();
        return CalcSquare(width, height) * 5;
    }
};