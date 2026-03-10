#define WIN32_LEAN_AND_MEAN
#include "figure.hpp"

HWND hwnd = GetConsoleWindow();
HDC hdc = GetDC(hwnd);

int main()
{
    // белый фон
    Sleep(100);
    RECT r;
    GetClientRect(hwnd, &r);
    HBRUSH bg = CreateSolidBrush(RGB(255, 255, 255));
    FillRect(hdc, &r, bg);
    DeleteObject(bg);

    // создание и первичная отрисовка объектов
    Point point(hdc, 100, 100, true, RGB(255, 0, 0));
    point.Show();

    Figure figure(hdc, 200, 200, true, RGB(0, 255, 0));
    figure.Show();

    // управление объектами
    point.Control();

    figure.Control();

    return 0;
}
