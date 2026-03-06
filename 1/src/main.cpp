#define WIN32_LEAN_AND_MEAN
#include "figure.hpp"

#include <thread>
// #include <chrono>

HWND hwnd = GetConsoleWindow();
HDC hdc = GetDC(hwnd);

int X1 = 100, Y1 = 100,
    X2 = 200, Y2 = 200;

void loop(Point **objects) {

    // первая отрисовка
    for (int i = 0; objects[i] != nullptr; i++) {
        objects[i]->Draw();
    }

    for (int i = 0; objects[i] != nullptr; i++) {
        bool next_object = false;
        while (!next_object) {
        }
    }
}

int main() {
    // белый фон
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    RECT r;
    GetClientRect(hwnd, &r);
    HBRUSH bg = CreateSolidBrush(RGB(255, 255, 255));
    FillRect(hdc, &r, bg);
    DeleteObject(bg);

    Point point(hdc, 100, 100, true, RGB(255, 0, 0));
    point.Draw();

    Figure figure(hdc, 200, 200, true, RGB(0, 255, 0));
    figure.Draw();

    point.Control();

    figure.Control();

    return 0;
}
