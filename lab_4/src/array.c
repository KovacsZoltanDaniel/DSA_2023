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
        printf(EMPTY_MESSAGE);
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
    if(isEmpty(array)){
        printf(EMPTY_MESSAGE);
        return INT_MIN;
    }
        if(position < 0 || position >= array.size){
            return INT_MIN;
        }
    return array.elements[position];
}

void insertFirst(IntArray *pArray, int item) {
    if(isFull(*pArray)){
        printf(FULL_MESSAGE);
        return;
    }
    for (int i = pArray->size; i > 0 ; --i) {
        pArray->elements[i] = pArray->elements[i-1];
    }
    pArray->elements[0] = item;
    pArray->size++;
}

void insertLast(IntArray *pArray, int item) {
    if(isFull(*pArray)){
        printf(FULL_MESSAGE);
        return;
    }
    pArray->elements[pArray->size++] = item;
}

void insertAt(IntArray *pArray, int position, int item) {
    if(isFull(*pArray)){
        printf(FULL_MESSAGE);
        return;
    }
    if(position < 0 || position > pArray->size){
        printf(INVALID_POSITION_MESSAGE);
        return;
    }
    if(position == 0){
        insertFirst(pArray,item);
        return;
    }
    if(position == pArray->size){
        insertLast(pArray,item);
        return;
    }
    for (int i = pArray->size; i > position ; --i) {
        pArray->elements[i] = pArray->elements[i-1];
    }
    pArray->elements[position] = item;
    pArray->size++;
}

void deleteItemAt(IntArray *pArray, int position) {
if(isEmpty(*pArray)){
    printf(EMPTY_MESSAGE);
    return;
}
    for (int i = position; i < pArray->size-1; ++i) {
        pArray->elements[i] = pArray->elements[i+1];
    }
    pArray->elements[pArray->size-1] = 0;
    pArray->size--;
}

int search(IntArray pArray, int item) {
    if(isEmpty(pArray)){
        printf(EMPTY_MESSAGE);
        return -1;
    }
    for (int i = 0; i < pArray.size; ++i) {
        if(pArray.elements[i] == item){
            return i;
        }
    }
    return -1;
}

bool update(IntArray *pArray, int position, int newItem) {
    if(isEmpty(*pArray)){
        printf(EMPTY_MESSAGE);
        return false;
    }
    if (position < 0 || position >= pArray->size){
        printf(INVALID_POSITION_MESSAGE);
        return false;
    }
    pArray->elements[position] = newItem;
    return true;
}

void deallocateIntArray(IntArray *pArray) {
    free(pArray->elements);
    pArray->capacity = pArray->size = 0;
    pArray = NULL;
}
