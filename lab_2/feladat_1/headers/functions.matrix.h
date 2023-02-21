//
// Created by Dani on 2023. 02. 21..
//

#ifndef FELADAT_1_FUNCTIONS_MATRIX_H
#define FELADAT_1_FUNCTIONS_MATRIX_H
#include <stdlib.h>
#include <stdio.h>
#include "constant.h"
int** allocateMemoryForMatrix1(int rows, int cols);
void allocateMemoryForMatrix2(int rows, int cols, int ***dpMatrix);
void deallocateMemoryForMatrix(int rows, int ***dpMatrix);
void readMatrix(int *pRows, int *pCols, int ***dpArray, const char *input);
void printMatrix(int rows, int cols, int **pMatrix, const char *output);
int minimumValueOfRow(int cols, int *pRow);
int* rowMinimums(int rows, int cols, int **pMatrix);
#endif //FELADAT_1_FUNCTIONS_MATRIX_H
