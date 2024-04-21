#include <iostream>
#include <graphics.h>
using namespace std;

int vertices[1000], v;

void left_edge(int xmin, int ymin, int xmax, int ymax)
{
    int temp[100], j = 0, count = 0, x1, y1, x2, y2;
    for (int i = 0; i < 2 * v; i += 2)
    {
        x1 = vertices[i];
        y1 = vertices[i + 1];
        x2 = vertices[i + 2];
        y2 = vertices[i + 3];

        // case-1: outside -> outside
        if (x1 < xmin && x2 < xmin)
        {
            // do nothing
        }

        // case-2: inside -> inside
        else if (x1 >= xmin && x2 >= xmin)
        {
            temp[j] = x2;
            temp[j + 1] = y2;
            j += 2;
            count++;
        }

        // case-3: outside -> inside
        else if (x1 < xmin && x2 >= xmin)
        {
            int x = xmin;
            int y = y1 + (xmin - x1) * (float)(y2 - y1) / (x2 - x1);
            temp[j] = x;
            temp[j + 1] = y;
            temp[j + 2] = x2;
            temp[j + 3] = y2;
            j += 4;
            count += 2;
        }

        // case-4: inside -> outside
        else
        {
            int x = xmin;
            int y = y1 + (xmin - x1) * (float)(y2 - y1) / (x2 - x1);
            temp[j] = x;
            temp[j + 1] = y;
            j += 2;
            count++;
        }
    }
    v = count;
    temp[j] = temp[0];
    temp[j + 1] = temp[1];

    // updating vertices with new selected edges
    for (int i = 0; i < 2 * (v + 1); i++)
    {
        vertices[i] = temp[i];
    }
}

void right_edge(int xmin, int ymin, int xmax, int ymax)
{
    int temp[100], j = 0, count = 0, x1, y1, x2, y2;
    for (int i = 0; i < 2 * v; i += 2)
    {
        x1 = vertices[i];
        y1 = vertices[i + 1];
        x2 = vertices[i + 2];
        y2 = vertices[i + 3];

        // case-1: outside -> outside
        if (x1 > xmax && x2 > xmax)
        {
            // do nothing
        }

        // case-2: inside -> inside
        if (x1 <= xmax && x2 <= xmax)
        {
            temp[j] = x2;
            temp[j + 1] = y2;
            j += 2;
            count += 1;
        }

        // case-3: outside -> inside
        else if (x1 > xmax && x2 <= xmax)
        {
            int x = xmax;
            int y = y1 + (xmax - x1) * (float)(y2 - y1) / (x2 - x1);
            temp[j] = x;
            temp[j + 1] = y;
            temp[j + 2] = x2;
            temp[j + 3] = y2;
            j += 4;
            count += 2;
        }

        // case-4: inside -> outside
        else
        {
            int x = xmax;
            int y = y1 + (xmax - x1) * (float)(y2 - y1) / (x2 - x1);
            temp[j] = x;
            temp[j + 1] = y;
            j += 2;
            count += 1;
        }
    }
    v = count;
    temp[j] = temp[0];
    temp[j + 1] = temp[1];

    // updating vertices with new selected edges
    for (int i = 0; i < 2 * (v + 1); i++)
    {
        vertices[i] = temp[i];
    }
}

void bottom_edge(int xmin, int ymin, int xmax, int ymax)
{
    int temp[100], j = 0, count = 0, x1, y1, x2, y2;
    for (int i = 0; i < 2 * v; i += 2)
    {
        x1 = vertices[i];
        y1 = vertices[i + 1];
        x2 = vertices[i + 2];
        y2 = vertices[i + 3];

        // case-1: outside -> outside
        if (y1 < ymin && y2 < ymin)
        {
            // do nothing
        }

        // case-2: inside -> inside
        else if (y1 >= ymin && y2 >= ymin)
        {
            temp[j] = x2;
            temp[j + 1] = y2;
            j += 2;
            count++;
        }

        // case-3: outside -> inside
        else if (y1 < ymin && y2 >= ymin)
        {
            int x = x1 + (float)((ymin - y1) * (x2 - x1)) / (y2 - y1);
            int y = ymin;
            temp[j] = x;
            temp[j + 1] = y;
            temp[j + 2] = x2;
            temp[j + 3] = y2;
            j += 4;
            count += 2;
        }

        // case-4: inside -> outside
        else
        {
            int x = x1 + (float)((ymin - y1) * (x2 - x1)) / (y2 - y1);
            int y = ymin;
            temp[j] = x;
            temp[j + 1] = y;
            j += 2;
            count++;
        }
    }
    v = count;
    temp[j] = temp[0];
    temp[j + 1] = temp[1];

    // updating vertices with new selected edges
    for (int i = 0; i < 2 * (v + 1); i++)
    {
        vertices[i] = temp[i];
    }
}

void top_edge(int xmin, int ymin, int xmax, int ymax)
{
    int temp[100], j = 0, count = 0, x1, y1, x2, y2;
    for (int i = 0; i < 2 * v; i += 2)
    {
        x1 = vertices[i];
        y1 = vertices[i + 1];
        x2 = vertices[i + 2];
        y2 = vertices[i + 3];

        // case-1: outside -> outside
        if (y1 > ymax && y2 > ymax)
        {
            // do nothing
        }

        // case-2: inside -> inside
        else if (y1 <= ymax && y2 <= ymax)
        {
            temp[j] = x2;
            temp[j + 1] = y2;
            j += 2;
            count++;
        }

        // case-3: outside -> inside
        else if (y1 > ymax && y2 <= ymax)
        {
            int x = x1 + (ymax - y1) * (float)(x2 - x1) / (y2 - y1);
            int y = ymax;
            temp[j] = x;
            temp[j + 1] = y;
            temp[j + 2] = x2;
            temp[j + 3] = y2;
            j += 4;
            count += 2;
        }

        // case-4: inside -> outside
        else
        {
            int x = x1 + (ymax - y1) * (float)(x2 - x1) / (y2 - y1);
            int y = ymax;
            temp[j] = x;
            temp[j + 1] = y;
            j += 2;
            count++;
        }
    }
    v = count;
    temp[j] = temp[0];
    temp[j + 1] = temp[1];

    // updating vertices with new selected edges
    for (int i = 0; i < 2 * (v + 1); i++)
    {
        vertices[i] = temp[i];
    }
}

int main()
{
    int gd = DETECT, gm;

    // Initialize graphics
    initwindow(640, 480, "Before Clipping");
    int xmin = 50;
    int ymin = 50;
    int xmax = 300;
    int ymax = 200;
    setcolor(15);
    rectangle(xmin, ymin, xmax, ymax);

    cout << "Enter the number of vertices: ";
    cin >> v;

    for (int i = 0; i < 2 * v; i += 2)
    {
        cout << "Enter coordinates of vertex " << (i / 2 + 1) << ": ";
        cin >> vertices[i] >> vertices[i + 1];
    }

    setcolor(14);
    vertices[2 * v] = vertices[0];
    vertices[2 * v + 1] = vertices[1];
    drawpoly(v + 1, vertices);

    // After Clipping Window
    initwindow(640, 480, "After Clipping");
    setcolor(15);
    rectangle(xmin, ymin, xmax, ymax);

    // calling clipping functions
    left_edge(xmin, ymin, xmax, ymax);
    right_edge(xmin, ymin, xmax, ymax);
    bottom_edge(xmin, ymin, xmax, ymax);
    top_edge(xmin, ymin, xmax, ymax);

    setcolor(9);
    drawpoly(v + 1, vertices);

    getch();
    closegraph();
    return 0;
}
