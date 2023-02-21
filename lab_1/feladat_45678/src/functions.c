//
// Created by Dani on 2023. 02. 14..
//

#include "../headers/functions.h"

int *allocateMemoryForArray1(int n) {
    int *array;
    array = (int *) malloc(n * sizeof(int));
    if (!array) {
        printf("error when allocating memory!");
        exit(-2);
    }
    return array;
}

void allocateMemoryForArray2(int n, int **dpArray) {
    (*dpArray) = (int *) malloc(n * sizeof(int));
    if (!(*dpArray)) {
        printf("error when allocating memory!");
        exit(-2);
    }
}

void deallocateMemoryForArray(int n, int **dpArray) {
    free(*dpArray);
}

void readArray(int *n, int **dpArray, const char *input) {
    if (!freopen(input, "r", stdin)) {
        printf("error2");
        exit(-1);
    }
    scanf("%i", n);
    (*dpArray) = allocateMemoryForArray1(*n);
    for (int i = 0; i < *n; ++i) {
        scanf("%i", &(*dpArray)[i]);
    }
}

void printArray(int n, int *pArray, const char *output) {
    freopen(output, "w", stdout);
    for (int i = 0; i < n; ++i) {
        printf("%i  ", pArray[i]);
    }
}
