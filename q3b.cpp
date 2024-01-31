#include <iostream>
#include <graphics.h>
using namespace std;

void bresenhamline(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int d = 2 * dy - dx;
    int dup = 2 * (dy - dx);
    int ddown = 2 * dy;
    int x = x1, y = y1;

    while (x2 >= x) // assumption
    {
        cout << "(" << x << "," << y << ")\n";
        if (x == x2 && y == y2)
            break;

        if (d < 0)
        {
            putpixel(x, y, 12);
            d = d + ddown;
        }
        else if (d >= 0)
        {
            putpixel(x, y, 12);
            y += 1;
            d = d + dup;
        }
        x += 1;
    }
}

int main()
{

    int x1, y1, x2, y2;
    cout << "Enter values for (x1,y1) : ";
    cin >> x1 >> y1;
    cout << "Enter values for (x2,y2) : ";
    cin >> x2 >> y2;
    cout << "Resulting Points Using Bresenham's Algorithm ->\n";

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    bresenhamline(x1, y1, x2, y2);
    getch();
    return 0;
}
