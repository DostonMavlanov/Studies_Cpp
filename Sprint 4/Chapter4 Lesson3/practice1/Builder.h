#include "Wall.h"

class Builder{
public:
    double CalcBricksNeeded(const Wall& wall) const {
        double height = wall.GetHeight();
        double width = wall.GetWidth();
        return height * width * 5;
    }
};