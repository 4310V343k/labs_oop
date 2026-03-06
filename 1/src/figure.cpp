#include "figure.hpp"
#include <wingdi.h>

Figure::Figure(HDC hdc, int initX, int initY, bool initVisible, COLORREF initRGB)
    : Point(hdc, initX, initY, initVisible, initRGB) {};

void Figure::Draw() {
    _visible = true;
    HBRUSH oldBrush = (HBRUSH)SelectObject(_hdc, GetStockObject(NULL_BRUSH));
    HPEN blackPen = CreatePen(PS_SOLID, 3, RGB(20, 20, 20));
    HPEN colorPen = CreatePen(PS_SOLID, 3, _RGB);
    HPEN oldPen = (HPEN)SelectObject(_hdc, blackPen);

    // заднее колесо
    Ellipse(_hdc, _x, _y + 20, _x + 30, _y + 50);
    // переднее колесо
    Ellipse(_hdc, _x + 50, _y + 20, _x + 80, _y + 50);

    // рама от заднего колеса к передней части
    SelectObject(_hdc, colorPen);
    MoveToEx(_hdc, _x + 15, _y + 35, nullptr);
    LineTo(_hdc, _x + 60, _y + 15);
    LineTo(_hdc, _x + 65, _y + 35); // к колесу

    MoveToEx(_hdc, _x + 60, _y + 15, nullptr);
    LineTo(_hdc, _x + 55, _y); // к рулю
    
    SelectObject(_hdc, blackPen);
    LineTo(_hdc, _x + 50, _y); // руль
    
    SelectObject(_hdc, colorPen);
    MoveToEx(_hdc, _x + 33, _y + 25, nullptr);
    LineTo(_hdc, _x + 33, _y + 8); // к сиденью

    SelectObject(_hdc, blackPen);
    LineTo(_hdc, _x + 28, _y + 8); // сиденье
    LineTo(_hdc, _x + 40, _y + 8); // сиденье

    SelectObject(_hdc, oldPen);
    DeleteObject(blackPen);
    DeleteObject(colorPen);
    SelectObject(_hdc, oldBrush);
}

void Figure::Hide() {
    _visible = false;
    HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));
    HBRUSH oldBrush = (HBRUSH)SelectObject(_hdc, brush);
    RECT Rect;
    // эллипс рисуется очень смешно, на один пиксель в каждую сторону больше
    Rect.top = _y-1;
    Rect.left = _x-1;
    Rect.right = _x + 81;
    Rect.bottom = _y + 51;
    FillRect(_hdc, &Rect, brush);
    SelectObject(_hdc, oldBrush);
    DeleteObject(brush);
}

void Figure::MoveTo(int NewX, int NewY) {
    Hide();
    _x = NewX;
    _y = NewY;
    Draw();
}

void Figure::Control() {
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
