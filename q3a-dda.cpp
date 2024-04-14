#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;

void ddaline(int x1, int y1, int x2, int y2)
{
    float m = (y2 - y1) / (x2 - x1);
    float x = x1;
    float y = y1;
    while (x2 >= x)
    {
        cout << "(" << round(x) << "," << round(y) << ")\n";
        if (x == x2 && y == y2)
            break;

        if (m > 1)
        {
            putpixel(x, y, 12);
            y += 1;
            x = x + (1 / m);
        }
        else if (m <= 1)
        {
            putpixel(x, y, 12);
            x += 1;
            y = y + m;
        }
    }
}

int main()
{

    int x1, y1, x2, y2;
    cout << "Enter values for (x1,y1) : ";
    cin >> x1 >> y1;
    cout << "Enter values for (x2,y2) : ";
    cin >> x2 >> y2;
    cout << "Resulting Points Using DDA's Algorithm ->\n";

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    ddaline(x1, y1, x2, y2);
    getch();
    return 0;
}