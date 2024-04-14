#include <iostream>
#include <graphics.h>
using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");

    // line-
    line(0, 0, getmaxx(), getmaxy());

    // circle-
    circle(300, 250, 150);

    // polygon-
    int vertices[] =
        {120, 250,
         400, 250,
         400, 350,
         450, 200,
         120, 250};
    drawpoly(5, vertices);
    getch();
    return 0;
}
