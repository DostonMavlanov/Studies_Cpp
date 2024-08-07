#pragma once

class Wall{
public:
    enum class Color{
        BLUE,
        GREEN,
        RED,
        WHITE,
        YELLOW
    };

    Wall (double width, double heght);
    double GetHeght() const;
    double GetWidth() const;
    void SetColor(Color color);
    Color GetColor() const;
    bool IsDoorInstalled() const;
    void SetDoorInstalled();

private:
    double width_;
    double heght_;
    Color color_;
    bool is_door_installed;
};