#include "print.hpp"
#include <iostream>
using namespace std;

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