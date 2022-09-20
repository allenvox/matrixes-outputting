#include <iostream>
#include "print.hpp"
#include "matrix.hpp"
using namespace std;

int main()
{
    srand(time(NULL));
    int N = rand() % 10 + 1;
    int maxValue = 99;
    int **matrix = getRandomMatrix(N, maxValue);
    printMatrix(N, matrix);
    int flag = SPIRAL_CENTER;
    int *D = matrixToArray(N, matrix, flag);
    cout << " " << endl;
    printArray(N * N, D);
    return 0;
}