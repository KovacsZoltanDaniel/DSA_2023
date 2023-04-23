//
// Created by Dani on 2023. 03. 19..
//

#include "regular_queue.h"


void createQueue(int capacity, Queue *queue) {
    queue->capacity = capacity;
    queue->front = -1;
    queue->rear = -1;
    queue->elements =(char **)malloc(CAR_PLATE_NUMBER_LIMIT * sizeof(char*));
    if(!queue->elements){
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    for (int i = 0; i < queue->capacity; ++i) {
        queue->elements[i] = (char *) malloc(CAR_PLATE_NUMBER_LIMIT * sizeof (char));
        if(!queue->elements[i]){
            printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
            MEMORY_ALLOCATION_ERROR_CODE;
        }
    }
}

void destroyQueue(Queue *queue) {
    for (int i = 0; i < queue->capacity; ++i) {
        free(queue->elements[i]);
    }
    free(queue->elements);
    queue->rear = -1;
    queue->front = -1;
    queue->capacity = 0;
    queue = NULL;
}

bool isFullqueue(Queue queue) {
    return queue.rear == queue.capacity-1;
}

bool isEmptyqueue(Queue queue) {
    return queue.front == -1  ;
}
//FIFO first in first out
void enqueue(Queue *queue, char *item) {
    if(isFullqueue(*queue)){
        printf(FULL_MESSAGE);
        return;
    }
    ///egyetlen elem van vagyis ha meg o az elso akkor 0 ra kell allitani mert -1 en volt mindketto
    if(queue->front == -1){
        queue->front =  0;
    }
        queue->rear ++;
    strcpy(queue->elements[queue->rear], item);
}

char *dequeue(Queue *queue) {
    if(isEmptyqueue(*queue)){
        printf(EMPTY_MESSAGE);
        return NULL;
    }
    ///ha csak egy elem van
        int position = queue->front;
    if(queue->front == queue->rear){
        queue->front = queue->rear = -1;
    }
    else {
        queue->front++;
    }
    return queue->elements[position];
}

void display(Queue queue) {
    if(isEmptyqueue(queue)){
        printf(EMPTY_MESSAGE);
        return;
    }
    printf("The elements of the queue:\n");
    for (int i = queue.front; i <= queue.rear ; ++i) {
        printf("\t- %s\n", queue.elements[i]);
    }
    printf("\n");
}
