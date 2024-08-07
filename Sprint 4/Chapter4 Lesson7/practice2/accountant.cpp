#include "accountant.h"
#include "square_calculation.h"

double Accountant::CalcPaintNeeded(const Wall& wall) const {
    double heght = wall.GetHeght();
    double width = wall.GetWidth();
    return CalcSquare(width, heght) * 0.4;
}

double Accountant::CalcBricksNeeded(const Wall& wall) const {
    double heght = wall.GetHeght();
    double width = wall.GetWidth();
    return CalcSquare(width, heght) * 5; 
}