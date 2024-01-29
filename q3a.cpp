#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

void ddaline(float x1, float y1, float x2, float y2)
{
    float m = (y2 - y1) / (x2 - x1);
    float x = x1, y = y1;
    while (x2 > x)
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
        else if (m < 1)
        {
            putpixel(x, y, 12);
            x += 1;
            y = y + m;
        }
        else
        {
            putpixel(x, y, 12);
            x += 1;
            y += 1;
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