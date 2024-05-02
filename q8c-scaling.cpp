#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;

// Transformation Matrix
void calculateScalingMatrix(float sx, float sy, float scalingMatrix[3][3])
{
    // defining the 3X3 scaling matrix
    scalingMatrix[0][0] = sx;
    scalingMatrix[0][1] = 0;
    scalingMatrix[0][2] = 0;
    scalingMatrix[1][0] = 0;
    scalingMatrix[1][1] = sy;
    scalingMatrix[1][2] = 0;
    scalingMatrix[2][0] = 0;
    scalingMatrix[2][1] = 0;
    scalingMatrix[2][2] = 1;
}

// Matrix Multiplication
void multiplication(float mat1[3][3], float mat2[3][3], float result[3][3])
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            result[i][j] = 0;
            for (int k = 0; k < 3; ++k)
            {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

// Dividing by homogeneous factor to get ordinary coordinates
void divideByHomogeneousFactor(float points[3][3])
{
    for (int i = 0; i < 3; ++i)
    {
        float w = points[i][2];
        points[i][0] /= w;
        points[i][1] /= w;
    }
}

// Display a matrix
void displayMatrix(float matrix[3][3])
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Display the result
void displayGraphics(float points[3][3], const char *title)
{
    initwindow(800, 600, title);
    setcolor(RED);

    for (int i = 0; i < 3; ++i)
    {
        int next = (i + 1) % 3;
        line(points[i][0], points[i][1], points[next][0], points[next][1]);
    }
}

int main()
{
    float sx, sy;
    cout << "Enter scaling factors sx and sy: ";
    cin >> sx >> sy;

    float scalingMatrix[3][3];
    calculateScalingMatrix(sx, sy, scalingMatrix);

    float positionVector[3][3] = {
        {50, 30, 1},
        {20, 20, 1},
        {40, 60, 1}};

    float result[3][3];

    // [X]* = [X] * [T]
    multiplication(positionVector, scalingMatrix, result);

    divideByHomogeneousFactor(result);

    // Display original points
    cout << "Original Points:" << endl;
    displayMatrix(positionVector);

    // Display scaling matrix
    cout << "Homogeneous Scaling Matrix:" << endl;
    displayMatrix(scalingMatrix);

    // Display matrix after Scaling
    cout << "Transformed Points:" << endl;
    displayMatrix(result);

    // Display result
    int gd = DETECT, gm;
    displayGraphics(positionVector, "Before Scaling");
    displayGraphics(result, "After Sclaing");
    getch();
    closegraph();

    return 0;
}
