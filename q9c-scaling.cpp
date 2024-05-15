#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;

// Transformation Matrix for 3D Scaling
void calculateScalingMatrix(float sx, float sy, float sz, float scalingMatrix[4][4]) {
    // defining the 4x4 scaling matrix
    scalingMatrix[0][0] = sx;
    scalingMatrix[0][1] = 0;
    scalingMatrix[0][2] = 0;
    scalingMatrix[0][3] = 0;
    scalingMatrix[1][0] = 0;
    scalingMatrix[1][1] = sy;
    scalingMatrix[1][2] = 0;
    scalingMatrix[1][3] = 0;
    scalingMatrix[2][0] = 0;
    scalingMatrix[2][1] = 0;
    scalingMatrix[2][2] = sz;
    scalingMatrix[2][3] = 0;
    scalingMatrix[3][0] = 0;
    scalingMatrix[3][1] = 0;
    scalingMatrix[3][2] = 0;
    scalingMatrix[3][3] = 1;
}

// Matrix Multiplication
void multiplication(float mat1[4][4], float mat2[4][4], float result[4][4]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < 4; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

// Apply Transformation to a Point
void applyTransformation(float point[4], float transformationMatrix[4][4]) {
    float tempX = point[0], tempY = point[1], tempZ = point[2], tempW = point[3];
    point[0] = tempX * transformationMatrix[0][0] + tempY * transformationMatrix[0][1] +
               tempZ * transformationMatrix[0][2] + tempW * transformationMatrix[0][3];
    point[1] = tempX * transformationMatrix[1][0] + tempY * transformationMatrix[1][1] +
               tempZ * transformationMatrix[1][2] + tempW * transformationMatrix[1][3];
    point[2] = tempX * transformationMatrix[2][0] + tempY * transformationMatrix[2][1] +
               tempZ * transformationMatrix[2][2] + tempW * transformationMatrix[2][3];
    point[3] = tempX * transformationMatrix[3][0] + tempY * transformationMatrix[3][1] +
               tempZ * transformationMatrix[3][2] + tempW * transformationMatrix[3][3];
}

// Display the result
void displayGraphics(float points[][4], int numPoints, const char* title) {
    initwindow(800, 600, title);
    setcolor(RED);

    for (int i = 0; i < numPoints; ++i) {
        int next = (i + 1) % numPoints;
        line(points[i][0], points[i][1], points[next][0], points[next][1]);
    }
}

int main() {
    float sx, sy, sz;
    cout << "Enter scaling factors sx, sy, sz: ";
    cin >> sx >> sy >> sz;

    float scalingMatrix[4][4];
    calculateScalingMatrix(sx, sy, sz, scalingMatrix);

    // Define 3D points using homogeneous coordinates
    float points[][4] = {
        {50, 30, 40, 1}, // Point 1
        {20, 20, 30, 1}, // Point 2
        {40, 60, 50, 1}  // Point 3
    };

    int numPoints = sizeof(points) / sizeof(points[0]);

    // Apply scaling transformation
    for (int i = 0; i < numPoints; ++i) {
        applyTransformation(points[i], scalingMatrix);
    }

    // Display original and transformed points
    displayGraphics(points, numPoints, "3D Scaling");
    getch();
    closegraph();

    return 0;
}
