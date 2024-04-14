#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;

void ddaline(int x1, int y1, float m)
{
    float x = x1;
    float y = y1;
    for (int i = 0; i < 1000; i++)
    {
        cout << "(" << round(x) << "," << round(y) << ")\n";
        putpixel(round(x), round(y), 12);

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

    int x1, y1, m;
    cout << "Enter values for (x1,y1) : ";
    cin >> x1 >> y1;
    cout << "Enter value for slope : ";
    cin >> m;
    cout << "Resulting Points Using DDA's Algorithm ->\n";

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    ddaline(x1, y1, m);
    getch();
    return 0;
}