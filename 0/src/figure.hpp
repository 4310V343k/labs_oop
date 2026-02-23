#pragma once
#include "point.hpp"

class Figure : public Point {
public:
    Figure(HDC hdc, int initX, int initY, bool initVisible, COLORREF initRGB);
    void Draw();
    void Hide();
    void MoveTo(int NewX, int NewY);
    void Control();
};
