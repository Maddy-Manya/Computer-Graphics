#include <iostream>
#include <graphics.h>
using namespace std;

void CirclePoints(int h, int k, int x, int y, int color)
{
    putpixel(h + x, k + y, color);
    putpixel(h + x, k - y, color);
    putpixel(h - x, k - y, color);
    putpixel(h - x, k + y, color);
    putpixel(h + y, k + x, color);
    putpixel(h - y, k + x, color);
    putpixel(h + y, k - x, color);
    putpixel(h - y, k - x, color);
}

void MidpointCircle(int h, int k, int r, int color)
{
    int x = 0;
    int y = r;
    double d = 5.0 / 4.0 - r;
    CirclePoints(h, k, x, y, color);

    while (y > x)
    {
        if (d < 0)
            d += 2.0 * x + 3.0;
        else
        {
            d += 2.0 * (x - y) + 5.0;
            y--;
        }
        x++;
        CirclePoints(h, k, x, y, color);
    }
}

int main()
{
    int h, k, r;
    cout << "Enter value for radius : ";
    cin >> r;
    cout << "Enter value for center : ";
    cin >> h >> k;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    MidpointCircle(h, k, r, 11);
    getch();
    return 0;
}
