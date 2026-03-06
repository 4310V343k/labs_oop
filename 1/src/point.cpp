#include "point.hpp"

Point::Point(HDC hdc, int initX, int initY, bool initVisible, COLORREF initRGB)
    : Location(initX, initY) {
    _hdc = hdc;
    _visible = initVisible;
    _RGB = initRGB;
}

void Point::Draw() {
    _visible = true;
    SetPixel(_hdc, _x, _y, _RGB);
    SetPixel(_hdc, _x + 1, _y, _RGB);
    SetPixel(_hdc, _x, _y + 1, _RGB);
    SetPixel(_hdc, _x + 1, _y + 1, _RGB);
}

void Point::Hide() {
    _visible = false;
    SetPixel(_hdc, _x, _y, RGB(255, 255, 255));
    SetPixel(_hdc, _x + 1, _y, RGB(255, 255, 255));
    SetPixel(_hdc, _x, _y + 1, RGB(255, 255, 255));
    SetPixel(_hdc, _x + 1, _y + 1, RGB(255, 255, 255));
}

void Point::MoveTo(int newX, int newY) {
    Hide();
    _x = newX;
    _y = newY;
    Draw();
}

void Point::Control() {
    while (true) {
        if (GetAsyncKeyState(VK_RIGHT) & 0x01) {
            MoveTo(_x + 10, _y);
            Sleep(100);
        }
        if (GetAsyncKeyState(VK_LEFT) & 0x01) {
            MoveTo(_x - 10, _y);
            Sleep(100);
        }
        if (GetAsyncKeyState(VK_UP) & 0x01) {
            MoveTo(_x, _y - 10);
            Sleep(100);
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x01) {
            MoveTo(_x, _y + 10);
            Sleep(100);
        }

        if (GetAsyncKeyState(VK_ESCAPE) & 0x01) {
            return;
        }
    }
}
