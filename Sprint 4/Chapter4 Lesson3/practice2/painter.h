#include "Wall.h"

class Painter{
public:
    void Paint(Wall& wall, Wall::Color color) const {
        wall.SetColor(color);
    }
};