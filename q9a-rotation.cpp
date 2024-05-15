#include <iostream>
#include <cmath>
#include <graphics.h>
#define PI 3.14159265
using namespace std;

// Transformation Matrix for 3D Rotation
void calculateRotationMatrix(float angleX, float angleY, float angleZ, float rotationMatrix[4][4]) {
    float radX = angleX * PI / 180;
    float radY = angleY * PI / 180;
    float radZ = angleZ * PI / 180;

    float cosX = cos(radX), sinX = sin(radX);
    float cosY = cos(radY), sinY = sin(radY);
    float cosZ = cos(radZ), sinZ = sin(radZ);

    // X-axis rotation matrix
    float rotationMatrixX[4][4] = {
        {1, 0, 0, 0},
        {0, cosX, -sinX, 0},
        {0, sinX, cosX, 0},
        {0, 0, 0, 1}
    };

    // Y-axis rotation matrix
    float rotationMatrixY[4][4] = {
        {cosY, 0, sinY, 0},
        {0, 1, 0, 0},
        {-sinY, 0, cosY, 0},
        {0, 0, 0, 1}
    };

    // Z-axis rotation matrix
    float rotationMatrixZ[4][4] = {
        {cosZ, -sinZ, 0, 0},
        {sinZ, cosZ, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };

    // Combine all rotations
    float tempMatrix[4][4];

    // Combine X, Y, and Z rotations
    multiplication(rotationMatrixY, rotationMatrixX, tempMatrix); // YX rotation
    multiplication(rotationMatrixZ, tempMatrix, rotationMatrix); // Z(YX) rotation
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
    float angleX, angleY, angleZ;
    cout << "Enter rotation angles in degrees (X Y Z): ";
    cin >> angleX >> angleY >> angleZ;

    float rotationMatrix[4][4];
    calculateRotationMatrix(angleX, angleY, angleZ, rotationMatrix);

    // Define 3D points using homogeneous coordinates
    float points[][4] = {
        {50, 30, 40, 1}, // Point 1
        {20, 20, 30, 1}, // Point 2
        {40, 60, 50, 1}  // Point 3
    };

    int numPoints = sizeof(points) / sizeof(points[0]);

    // Apply rotation transformation
    for (int i = 0; i < numPoints; ++i) {
        applyTransformation(points[i], rotationMatrix);
    }

    // Display original and transformed points
    displayGraphics(points, numPoints, "3D Rotation and Projection");
    getch();
    closegraph();

    return 0;
}
