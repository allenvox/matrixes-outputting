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
int *outputRightDiagonals(int N, int **matrix);
int *outputLeftDiagonals(int N, int **matrix);
int *outputSpiralCenter(int N, int **matrix);
int *outputSpiralStart(int N, int **matrix);