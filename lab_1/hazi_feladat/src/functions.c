//
// Created by Dani on 2023. 02. 14..
//

#include "../header/functions.h"

float avg(float number1, float number2) {
    float atlag;
    atlag = (number1+number2)/2;
    return atlag;
}

float maximum(float number1, float number2, float number3) {

        if(number1>number2&&number1>number3)
            return number1;
        else if(number2>number3)
            return number2;
        else
            return number3;

}
int *allocate_memory(int n) {
    int * array;
    array=(int*)malloc(n*sizeof(int));
    if(!array)
        exit(-1);
    return array;
}
void fillWithRandomNumbers(int n, int **pArray, int start, int end) {
    (*pArray) = allocate_memory(n);
    for (int i = 0; i < n; ++i) {
        (*pArray)[i] = rand() % (end - start + 1) + start;
    }
}
void printArrayInReverseOrder(int n, int *pArray) {
        for (int i = n-1; i >= 0; --i) {
            printf("%i  ", pArray[i]);
        }
    }
void deallocateMemoryForArray( int **dpArray) {
    free(*dpArray);
}