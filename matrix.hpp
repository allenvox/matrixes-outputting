#pragma once

enum flags
{
    RIGHT_D,
    LEFT_D,
    SPIRAL_CENTER,
    SPIRAL_START
};

int **getRandomMatrix(int N, int maxValue);
int *matrixToArray(int N, int **matrix, int flag);