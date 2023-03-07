//
// Created by Dani on 2023. 03. 07..
//

#include "../headers/array.h"

void createIntArray(int capacity, IntArray *pArray) {
    pArray->capacity = capacity;
    pArray->size = 0;
    pArray->elements =(int*) calloc(capacity,sizeof(int));
    if (!pArray->elements) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}

void printArray(IntArray array) {
    if (isEmpty(array)) {
        printf("ARRAY_EMPTY_MESSAGE");
        printf("\n");
        return;
    }
    printf("The elements of the array: ");
    for (int i = 0; i < array.size; ++i) {
        printf("%i ", array.elements[i]);
    }
    printf("\n");
}

bool isFull(IntArray array) {
    return array.size == array.capacity;
}

bool isEmpty(IntArray array) {
    return array.size == 0;
}

int getItemAt(IntArray array, int position) {
        if(position > array.size){
            return -1;
        }
        else{
            printf("%i ", array.elements[position-1]);
        }
    return 0;
}
