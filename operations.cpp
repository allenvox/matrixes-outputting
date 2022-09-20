#include "operations.hpp"

int *getRight(int *start)
{
    int *arr = new int[2];
    arr[0] = start[0];
    arr[1] = start[1] + 1;
    return arr;
}

int *getLeft(int *start)
{
    int *arr = new int[2];
    arr[0] = start[0];
    arr[1] = start[1] - 1;
    return arr;
}

int *getDown(int *start)
{
    int *arr = new int[2];
    arr[0] = start[0] + 1;
    arr[1] = start[1];
    return arr;
}

int *getUp(int *start)
{
    int *arr = new int[2];
    arr[0] = start[0] - 1;
    arr[1] = start[1];
    return arr;
}

int *getDownLeft(int *start)
{
    return getDown(getLeft(start));
}

int *getDownRight(int *start)
{
    return getDown(getRight(start));
}