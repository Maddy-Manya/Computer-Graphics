#include <iostream>
#include <graphics.h>
using namespace std;

int TOP = 8;
int BOTTOM = 4;
int RIGHT = 2;
int LEFT = 1;

int compute_outcode(float x, float y, float xmin, float ymin, float xmax, float ymax)
{
    int code = 0;
    if (y > ymax)
        code |= TOP;
    else if (y < ymin)
        code |= BOTTOM;
    if (x > xmax)
        code |= RIGHT;
    else if (x < xmin)
        code |= LEFT;
    return code;
}

void lineclipping(float xmin, float ymin, float xmax, float ymax, float x1, float y1, float x2, float y2)
{
    bool accept = false;
    bool done = false;
    int outcode1 = compute_outcode(x1, y1, xmin, ymin, xmax, ymax);
    int outcode2 = compute_outcode(x2, y2, xmin, ymin, xmax, ymax);

    do
    {

        // trivially accept
        if ((outcode1 | outcode2) == 0)
        {
            accept = true;
            done = true;
        }
        // trivially rejection
        else if (outcode1 & outcode2)
            done = true;

        // partially inside
        else
        {
            float x, y, slope = (y2 - y1) / (x2 - x1);
            int outcodeout = outcode1 ? outcode1 : outcode2;

            if (outcodeout & TOP)
            {
                x = x1 + (1 / slope) * (ymax - y1);
                y = ymax;
            }
            else if (outcodeout & BOTTOM)
            {
                x = x1 + (1 / slope) * (ymin - y1);
                y = ymin;
            }
            else if (outcodeout & RIGHT)
            {
                y = y1 + slope * (xmax - x1);
                x = xmax;
            }
            else
            {
                y = y1 + slope * (xmin - x1);
                x = xmin;
            }

            // updating the outside point to clipped point
            if (outcodeout == outcode1)
            {
                x1 = x;
                y1 = y;
                outcode1 = compute_outcode(x1, y1, xmin, ymin, xmax, ymax);
            }
            else
            {
                x2 = x;
                y2 = y;
                outcode2 = compute_outcode(x2, y2, xmin, ymin, xmax, ymax);
            }
        }
    } while (!done);

    if (accept)
    {
        setcolor(10);
        line(x1, y1, x2, y2);
    }

    else
    {
        setcolor(8);
        line(x1, y1, x2, y2);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    rectangle(20, 70, 90, 20);
    lineclipping(20, 20, 90, 70, 10, 30, 80, 90);
    lineclipping(20, 20, 90, 70, 20, 200, 100, 100);

    getch();
    return 0;
}
