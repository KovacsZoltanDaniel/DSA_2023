//
// Created by Dani on 2023. 02. 21..
//

#include "../headers/functions.matrix.h"

//1
int *allocateMemoryForArray1(int n) {
    int *array;
    array = (int *) malloc(n * sizeof(int));
    if (!array) {
        printf("error when allocating memory!");
        exit(-2);
    }
    return array;

}

void readArray(int *n, int **dpArray, const char *input) {
    if (!freopen(input, "r", stdin)) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
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
    printf("\n");
}

//2
int numberOfEvenNumbers(int n, int *pArray) {
    int db = 0;
    for (int i = 0; i < n; ++i) {
        if (pArray[i] % 2 == 0) {
            db++;
        }
    }
    return db;
}

//3
int sumOfPositiveNumbers(int n, int *pArray) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (pArray[i] > 0) {
            sum += pArray[i];
        }
    }
    return sum;
}

//4
void deallocateMemoryForArray(int n, int **dpArray) {
    free(*dpArray);
}

//5
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

//6
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

//7
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

//8
int minimumValueOfRow(int cols, int *pRow) {
    int min = pRow[0];
    for (int i = 0; i < cols; ++i) {
        if (min > pRow[i]) {
            min = pRow[i];
        }
    }
    return min;
}

//9
int *rowMinimums(int rows, int cols, int **pMatrix) {
    int min, *minimum;
    minimum = (int *) malloc(rows * sizeof(int));
    if (!minimum) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    for (int i = 0; i < rows; ++i) {
        min = pMatrix[i][0];
        for (int j = 0; j < cols; ++j) {
            if (min > pMatrix[i][j]) {
                min = pMatrix[i][j];
            }
        }
        minimum[i] = min;
    }
    return minimum;
}

//10
int minimumValueOfMatrix(int rows, int cols, int **pMatrix) {
    int min = pMatrix[0][0];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (min > pMatrix[i][j]) {
                min = pMatrix[i][j];
            }
        }
    }
    return min;
}

//11
float averageOfMatrixElements(int rows, int cols, int **pMatrix) {
    float sum = 0;
    int db = rows * cols;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum += (float) (pMatrix[i][j]);
        }
    }
    float atlag = (sum / (float) db);
    return atlag;
}

//12
void deallocateMemoryForMatrix(int rows, int ***dpMatrix) {
    for (int i = 0; i < rows; ++i) {
        free((*dpMatrix)[i]);
        (*dpMatrix)[i] = NULL;
    }
    free(*dpMatrix);
    (*dpMatrix) = NULL;
}

//hazi feladat
//1
float average(int n, int *pArray) {
    float sum = 0, avg;
    int i;
    for ( i = 0; i < n; ++i) {
        sum += (float )pArray[i];
    }
    avg = sum/(float )i;
    return avg;
}
//2
int numberOfOddNumbers(int n, int *pArray) {
    int db = 0;
    for (int i = 0; i < n; ++i) {
        if (pArray[i] % 2 != 0) {
            db++;
        }
    }
    return db;
}
//3
int productOfNegativeNumbers(int n, int *pArray) {
    int sum = 1;
    for (int i = 0; i < n; ++i) {
        if(pArray[i] < 0){
            sum *= pArray[i];
        }
    }
    return sum;
}
//4
int maximumValueOfColumn(int rows, int columnIndex, int **pMatrix) {
    int max = pMatrix[0][columnIndex] ;
    for (int i = 0; i < rows; ++i) {
            if(max < pMatrix[i][columnIndex]){
                max = pMatrix[i][columnIndex];
            }
    }
    return max;
}

int *columnMaximums(int rows, int cols, int **pMatrix) {
    int *max;
    max = (int *) malloc(rows * sizeof(int));
    if(!max){
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    int maximum;
    for (int i = 0; i < cols; ++i) {
        maximum = pMatrix[i][0];
        for (int j = 0; j < rows; ++j) {
            if(maximum < pMatrix[j][i]){
                maximum = pMatrix[j][i];
            }
        }
        max[i]= maximum;
    }
    return max;
}

int maximumValueOfMatrix(int rows, int cols, int **pMatrix) {
    int max = pMatrix[0][0];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if(pMatrix[i][j] > max){
                max = pMatrix[i][j];
            }
        }
    }
    return max;
}

int sumOfMatrixElements(int rows, int cols, int **pMatrix) {
    int sum = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum += pMatrix[i][j];
        }
    }
    return sum;
}
















