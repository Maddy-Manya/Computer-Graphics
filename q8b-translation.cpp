#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;

// Transformation Matrix
void calculateTranslationMatrix(float tx, float ty, float translationMatrix[3][3])
{
    // defining the 3X3 translation matrix
    translationMatrix[0][0] = 1;
    translationMatrix[0][1] = 0;
    translationMatrix[0][2] = tx;
    translationMatrix[1][0] = 0;
    translationMatrix[1][1] = 1;
    translationMatrix[1][2] = ty;
    translationMatrix[2][0] = 0;
    translationMatrix[2][1] = 0;
    translationMatrix[2][2] = 1;
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
    float tx, ty;
    cout << "Enter translation values tx and ty: ";
    cin >> tx >> ty;

    float translationMatrix[3][3];
    calculateTranslationMatrix(tx, ty, translationMatrix);

    float positionVector[][3] = {
        {50, 30, 1},
        {20, 20, 1},
        {40, 60, 1}};

    float result[3][3];

    // [X]* = [X] * [T]
    multiplication(positionVector, translationMatrix, result);

    divideByHomogeneousFactor(result);

    // Display original points
    cout << "Original Points:" << endl;
    displayMatrix(positionVector);

    // Display translation matrix
    cout << "Homogeneous Translation Matrix:" << endl;
    displayMatrix(translationMatrix);

    // Display matrix after Translation
    cout << "Transformed Points:" << endl;
    displayMatrix(result);

    // Display result
    int gd = DETECT, gm;
    displayGraphics(positionVector, "Before Translation");
    displayGraphics(result, "After Translation");
    getch();
    closegraph();

    return 0;
}
