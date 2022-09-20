#include "matrix.hpp"
#include "operations.hpp"
#include <iostream>

using namespace std;

int **getRandomMatrix(int N, int maxValue)
{
    int **matrix = new int *[N];
    for (int i = 0; i < N; i++)
    {
        matrix[i] = new int[N];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] = rand() % maxValue;
        }
    }
    return matrix;
}

int *outputRightDiagonals(int N, int **matrix)
{
    int *D = new int[N * N];
    int count = 0;
    // get top triangle
    for (int i = 1; i <= N; i++)
    {
        int *next = new int[2];
        next[0] = 0;
        next[1] = N - i;
        for (int j = 0; j <= N - i; j++)
        {
            D[count] = matrix[next[0]][next[1]];
            count++;
            next = getDownLeft(next);
        }
    }
    // get bottom triangle
    for (int i = 1; i < N; i++)
    {
        int *next = new int[2];
        next[0] = N - i;
        next[1] = N - 1;
        for (int j = N; j > N - i; j--)
        {
            D[count++] = matrix[next[0]][next[1]];
            next = getDownLeft(next);
        }
    }
    return D;
}

int *outputLeftDiagonals(int N, int **matrix)
{
    int *D = new int[N * N];
    int count = 0;
    // get top triangle
    for (int i = 0; i < N; i++)
    {
        int *next = new int[2];
        next[0] = 0;
        next[1] = 0 + i;
        for (int j = 0; j < N - i; j++)
        {
            D[count++] = matrix[next[0]][next[1]];
            next = getDownRight(next);
        }
    }
    // get bottom triangle
    for (int i = 1; i < N; i++)
    {
        int *next = new int[2];
        next[0] = N - i;
        next[1] = 0;
        for (int j = N; j > N - i; j--)
        {
            D[count++] = matrix[next[0]][next[1]];
            next = getDownRight(next);
        }
    }
    return D;
}

int *outputSpiralCenter(int N, int **matrix)
{
    int *D = new int[N * N];
    int i, j, count = N * N - 1, thickness = 0;
    while (count >= 0)
    {
        // upper wall
        for (j = thickness; j < N - thickness; j++)
        {
            if (count % N < 0)
            {
                break;
            }
            D[count--] = matrix[thickness][j];
        }
        // right wall
        for (i = thickness + 1; i < N - thickness; i++)
        {
            if (count % N < 0)
            {
                break;
            }
            D[count--] = matrix[i][N - thickness - 1];
        }
        // bottom wall
        for (j = N - thickness - 2; j >= thickness; j--)
        {
            if (count % N < 0)
            {
                break;
            }
            D[count--] = matrix[N - thickness - 1][j];
        }
        // left wall
        for (i = N - thickness - 2; i > thickness; i--)
        {
            if (count % N < 0)
            {
                break;
            }
            D[count--] = matrix[i][thickness];
        }
        thickness++;
    }
    return D;
}

int *outputSpiralStart(int N, int **matrix)
{
    int *D = new int[N * N];
    int i, j, count = 0, thickness = 0;
    while (count < N * N)
    {
        // upper wall
        for (j = thickness; j < N - thickness; j++)
        {
            if (count % N > N)
            {
                break;
            }
            D[count++] = matrix[thickness][j];
        }
        // right wall
        for (i = thickness + 1; i < N - thickness; i++)
        {
            if (count % N > N)
            {
                break;
            }
            D[count++] = matrix[i][N - thickness - 1];
        }
        // bottom wall
        for (j = N - thickness - 2; j >= thickness; j--)
        {
            if (count % N > N)
            {
                break;
            }
            D[count++] = matrix[N - thickness - 1][j];
        }
        // left wall
        for (i = N - thickness - 2; i > thickness; i--)
        {
            if (count % N > N)
            {
                break;
            }
            D[count++] = matrix[i][thickness];
        }
        thickness++;
    }
    return D;
}

int *matrixToArray(int N, int **matrix, int flag)
{
    int *D = new int[N * N];
    switch (flag)
    {
    case RIGHT_D:
        D = outputRightDiagonals(N, matrix);
        break;
    case LEFT_D:
        D = outputLeftDiagonals(N, matrix);
        break;
    case SPIRAL_CENTER:
        D = outputSpiralCenter(N, matrix);
        break;
    case SPIRAL_START:
        D = outputSpiralStart(N, matrix);
        break;
    }
    return D;
}