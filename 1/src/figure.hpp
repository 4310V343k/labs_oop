#pragma once
#include <windows.h>

class Location
{
protected:
    int _x;
    int _y;

public:
    Location(int initX, int initY);
};

class Point : public Location
{
protected:
    HDC _hdc;
    bool _visible;
    COLORREF _RGB;

public:
    Point(HDC hdc, int initX, int initY, bool initVisible, COLORREF initRGB);
    void Show();
    void Hide();
    void MoveTo(int NewX, int NewY);
    void Control();
};

class Figure : public Point
{
public:
    Figure(HDC hdc, int initX, int initY, bool initVisible, COLORREF initRGB);
    void Show();
    void Hide();
    void MoveTo(int NewX, int NewY);
    void Control();
};
