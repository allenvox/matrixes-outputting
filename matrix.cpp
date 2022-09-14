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

int *matrixToArray(int N, int **matrix, int flag)
{
    int *D = new int[N * N];
    int count = 0;
    if (flag == RIGHT_D)
    {
        // get top triangle
        for (int i = 1; i <= N; i++)
        {
            int *next = new int[2];
            next[0] = 0;
            next[1] = N - i;
            for (int j = 0; j <= N - i; j++)
            {
                cout << "next is " << next[0] << " " << next[1] << endl;
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
                cout << "next is " << next[0] << " " << next[1] << endl;
                D[count] = matrix[next[0]][next[1]];
                count++;
                next = getDownLeft(next);
            }
        }

        if (count != N * N)
        {
            cout << "Very bad" << endl;
        }
    }
    else if (flag == LEFT_D)
    {
        // get top triangle
        for (int i = 0; i < N; i++)
        {
            int *next = new int[2];
            next[0] = 0;
            next[1] = 0 + i;
            for (int j = 0; j < N - i; j++)
            {
                cout << "next is " << next[0] << " " << next[1] << endl;
                D[count] = matrix[next[0]][next[1]];
                count++;
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
                cout << "next is " << next[0] << " " << next[1] << endl;
                D[count] = matrix[next[0]][next[1]];
                count++;
                next = getDownRight(next);
            }
        }

        if (count != N * N)
        {
            cout << "Very bad" << endl;
        }
    }
    else if (flag == SPIRAL_CENTER)
    {
    }
    else if (flag == SPIRAL_START)
    {
    }
    return D;
}