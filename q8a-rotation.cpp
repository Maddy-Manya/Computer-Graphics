#include <iostream>
#include <cmath>
#include <graphics.h>
#define PI 3.14
using namespace std;

// Transformation Matrix
void calculateRotationMatrix(float angle, float rotationMatrix[3][3])
{
    // converting angle from degree to radian
    float rad = angle * PI / 180;
    float cosA = cos(rad);
    float sinA = sin(rad);

    // defining the 3X3 rotation matrix (clockwise)
    rotationMatrix[0][0] = cosA;
    rotationMatrix[0][1] = -sinA;
    rotationMatrix[0][2] = 0;
    rotationMatrix[1][0] = sinA;
    rotationMatrix[1][1] = cosA;
    rotationMatrix[1][2] = 0;
    rotationMatrix[2][0] = 0;
    rotationMatrix[2][1] = 0;
    rotationMatrix[2][2] = 1;
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
    float angle;
    cout << "Enter rotation angle in degrees: ";
    cin >> angle;

    float rotationMatrix[3][3];
    calculateRotationMatrix(angle, rotationMatrix);

    float positionVector[3][3] = {
        {50, 30, 1},
        {20, 20, 1},
        {40, 60, 1}};

    float result[3][3];

    // [X]* = [X] * [T]
    multiplication(positionVector, rotationMatrix, result);

    divideByHomogeneousFactor(result);

    // Display original points
    cout << "Original Points:" << endl;
    displayMatrix(positionVector);

    // Display rotation matrix
    cout << "Homogeneous Rotation Matrix:" << endl;
    displayMatrix(rotationMatrix);

    // Display matrix after Rotation
    cout << "Transformed Points:" << endl;
    displayMatrix(result);

    // Display result
    int gd = DETECT, gm;
    displayGraphics(positionVector, "Before Rotation");
    displayGraphics(result, "After Rotation");
    getch();
    closegraph();

    return 0;
}
