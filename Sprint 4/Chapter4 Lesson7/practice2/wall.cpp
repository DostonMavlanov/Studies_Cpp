#include "wall.h"

Wall::Wall(double width, double heght) 
    : width_(width), heght_(heght), color_(Color::WHITE), is_door_installed(false)
{
}

double Wall::GetHeght() const {
    return heght_;
}

double Wall::GetWidth() const {
    return width_;
}

void Wall::SetColor(Color color) {
    color_ = color;
}

Wall::Color Wall::GetColor() const {
    return color_;
}

bool Wall::IsDoorInstalled() const {
    return is_door_installed;
}

void Wall::SetDoorInstalled(){
    is_door_installed = true;
}








