//
// Created by Dani on 2023. 02. 14..
//

#ifndef HAZI_FELADAT_FUNCTIONS_H
#define HAZI_FELADAT_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
float avg(float number1, float number2);
float maximum(float number1, float number2, float number3);
int *allocate_memory(int n);
void fillWithRandomNumbers(int n, int **pArray, int start, int end);
void printArrayInReverseOrder(int n, int *pArray);
void deallocateMemoryForArray( int **dpArray);
#endif //HAZI_FELADAT_FUNCTIONS_H
