#pragma once

#include "location.hpp"
#include <windows.h>

class Point : public Location {
protected:
    HDC _hdc;
    bool _visible;
    COLORREF _RGB;

public:
    Point(HDC hdc, int initX, int initY, bool initVisible, COLORREF initRGB);
    void Draw();
    void Hide();
    void MoveTo(int NewX, int NewY);
    void Control();
};
