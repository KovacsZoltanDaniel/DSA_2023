//
// Created by Dani on 2023. 02. 21..
//

#include "../headers/functions.matrix.h"

int **allocateMemoryForMatrix1(int rows, int cols) {
    int **pmatrix;
    pmatrix = (int **) malloc(rows * sizeof(int *));
    if (!pmatrix) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    for (int i = 0; i < rows; ++i) {
        pmatrix[i] = (int *) malloc(cols * sizeof(int));
        if (!pmatrix[i]) {
            printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
            exit(MEMORY_ALLOCATION_ERROR_CODE);
        }
    }
    return pmatrix;
}

void allocateMemoryForMatrix2(int rows, int cols, int ***dpmatrix) {
    *dpmatrix = (int **) malloc(rows * sizeof(int *));
    if (!(*dpmatrix)) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    for (int i = 0; i < rows; ++i) {
        *dpmatrix[i] = (int *) malloc(cols * sizeof(int));
        if (!(*dpmatrix[i])) {
            printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
            exit(MEMORY_ALLOCATION_ERROR_CODE);
        }
    }
}

void readMatrix(int *pRows, int *pCols, int ***dpArray, const char *input) {
    if (!freopen(input, "r", stdin)) {
        printf(FILE_OPEN_ERROR_MESSAGE);
        exit(FILE_OPEN_ERROR_CODE);
    }
    scanf("%i%i", pRows, pCols);
    (*dpArray) = allocateMemoryForMatrix1(*pRows, *pCols);
    for (int i = 0; i < *pRows; ++i) {
        for (int j = 0; j < *pCols; ++j) {
            scanf("%i ", &(*dpArray)[i][j]);
        }
    }
    freopen("CON", "r", stdin);
}

void printMatrix(int rows, int cols, int **pMatrix, const char *output) {
    freopen(output, "w", stdout);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%i ", pMatrix[i][j]);
        }
        printf("\n");
    }
    freopen("CON", "w", stdout);
}

void deallocateMemoryForMatrix(int rows, int ***dpMatrix) {
    for (int i = 0; i < rows; ++i) {
        free((*dpMatrix)[i]);
        (*dpMatrix)[i] = NULL;
    }
    free(*dpMatrix);
    (*dpMatrix) = NULL;
}
