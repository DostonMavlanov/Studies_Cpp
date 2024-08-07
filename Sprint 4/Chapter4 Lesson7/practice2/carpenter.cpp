#include "carpenter.h"

int Carpenter::CalcShelves(const Wall& wall) const { 
    double heght = wall.GetHeght();
    double width = wall.GetWidth();
    return CalcSquare(width, heght) / 2;
}

void Carpenter::InstallDoor(Wall& wall, const Builder& builder) const {
    builder.HoldDoor();
    wall.SetDoorInstalled();
}
