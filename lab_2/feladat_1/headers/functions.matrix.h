//
// Created by Dani on 2023. 02. 21..
//

#ifndef FELADAT_1_FUNCTIONS_MATRIX_H
#define FELADAT_1_FUNCTIONS_MATRIX_H
#include <stdlib.h>
#include <stdio.h>
#include "constant.h"
//1
int *allocateMemoryForArray1(int n);
void readArray(int *n, int **dpArray, const char *input);
void printArray(int n, int *pArray, const char *output);
//2
 int numberOfEvenNumbers(int n, int *pArray);
 //3
 int sumOfPositiveNumbers(int n, int *pArray);
 //4
void deallocateMemoryForArray(int n, int **dpArray);
//5
int** allocateMemoryForMatrix1(int rows, int cols);
void allocateMemoryForMatrix2(int rows, int cols, int ***dpMatrix);
//6
void readMatrix(int *pRows, int *pCols, int ***dpArray, const char *input);
//7
void printMatrix(int rows, int cols, int **pMatrix, const char *output);
//8
int minimumValueOfRow(int cols, int *pRow);
//9
int* rowMinimums(int rows, int cols, int **pMatrix);
//10
int minimumValueOfMatrix(int rows, int cols, int **pMatrix);
//11
float averageOfMatrixElements(int rows, int cols, int **pMatrix);
//12
void deallocateMemoryForMatrix(int rows, int ***dpMatrix);
//hazi feladat
//1
float average(int n, int *pArray);
//2
int numberOfOddNumbers(int n, int *pArray);
//3
int productOfNegativeNumbers(int n, int *pArray);
//4
int maximumValueOfColumn(int rows, int columnIndex, int **pMatrix);
//5
int* columnMaximums(int rows, int cols, int **pMatrix);
//6
int maximumValueOfMatrix(int rows, int cols, int **pMatrix);
//7
 int sumOfMatrixElements(int rows, int cols, int **pMatrix);
#endif //FELADAT_1_FUNCTIONS_MATRIX_H
