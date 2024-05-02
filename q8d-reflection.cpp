#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;

// Transformation Matrix
void calculateReflectionMatrix(float reflectionMatrix[3][3])
{
    // defining the 3X3 reflection matrix (about x-axis and y=0)

    reflectionMatrix[0][0] = 1;
    reflectionMatrix[0][1] = 0;
    reflectionMatrix[0][2] = 0;
    reflectionMatrix[1][0] = 0;
    reflectionMatrix[1][1] = -1;
    reflectionMatrix[1][2] = 0;
    reflectionMatrix[2][0] = 0;
    reflectionMatrix[2][1] = 0;
    reflectionMatrix[2][2] = 1;
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
void divideByHomogeneousFactor(float positionVector[3][3])
{
    for (int i = 0; i < 3; ++i)
    {
        float w = positionVector[i][2];
        positionVector[i][0] /= w;
        positionVector[i][1] /= w;
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
    float reflectionMatrix[3][3];
    calculateReflectionMatrix(reflectionMatrix);

    float positionVector[3][3] = {
        {50, 30, 1},
        {20, 20, 1},
        {40, 60, 1}};

    float result[3][3];

    // [X]* = [X] * [T]
    multiplication(positionVector, reflectionMatrix, result);

    divideByHomogeneousFactor(result);

    // Display original points
    cout << "Original Points:" << endl;
    displayMatrix(positionVector);

    // Display reflection matrix
    cout << "Homogeneous Reflection Matrix:" << endl;
    displayMatrix(reflectionMatrix);

    // Display matrix after Reflection
    cout << "Transformed Points:" << endl;
    displayMatrix(result);

    // Display result
    int gd = DETECT, gm;
    displayGraphics(positionVector, "Before Reflection");
    displayGraphics(result, "After Reflection");
    getch();
    closegraph();

    return 0;
}
