#include <iostream>
using namespace std;

enum flags
{
    RIGHT_D,
    LEFT_D,
    SPIRAL_CENTER,
    SPIRAL_START
};

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

void printArray(int size, int *arr)
{
    for (int i = 0; i < size; i++)
    {
        cout << "\t" << arr[i];
    }
    cout << endl;
}

void printMatrix(int N, int **matrix)
{
    cout << N << " x " << N << endl;
    for (int i = 0; i < N; i++)
    {
        printArray(N, matrix[i]);
    }
}

int *getDownLeft(int *start)
{
    int *arr = new int[2];
    arr[0] = start[0] + 1;
    arr[1] = start[1] - 1;
    return arr;
}

int *getDownRight(int *start)
{
    int *arr = new int[2];
    arr[0] = start[0] + 1;
    arr[1] = start[1] + 1;
    return arr;
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
    return D;
}

int main()
{
    srand(time(NULL));
    int N = rand() % 10 + 1;
    int maxValue = 99;
    int **matrix = getRandomMatrix(N, maxValue);
    printMatrix(N, matrix);

    int flag = RIGHT_D;
    int *D = matrixToArray(N, matrix, flag);
    printArray(N * N, D);

    return 0;
}