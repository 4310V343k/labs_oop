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

    Figure figure2(hdc, 300, 200, true, RGB(0, 0, 255));
    Point *figure_as_point = &figure2;
    figure_as_point->Show();

    // управление объектами
    point.Control();

    figure.Control();

    // управление объектом производного класса через базовый класс
    // демонстрирует, что при вызове MoveTo из базового класса вызывается ранее (статически, при компиляции) связанный Point::MoveTo
    figure_as_point->Control();

    return 0;
}
