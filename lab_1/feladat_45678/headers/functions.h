//
// Created by Dani on 2023. 02. 14..
//

#ifndef FELADAT_45678_FUNCTIONS_H
#define FELADAT_45678_FUNCTIONS_H
#include <stdlib.h>
#include <stdio.h>
 int* allocateMemoryForArray1(int n);
 void allocateMemoryForArray2(int n, int **dpArray);
void deallocateMemoryForArray(int n, int **dpArray);
void readArray(int *n, int **dpArray, const char *input);
void printArray(int n, int *pArray, const char *output);
#endif //FELADAT_45678_FUNCTIONS_H
