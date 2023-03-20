//
// Created by Dani on 2023. 03. 19..
//

#include "circular_queue.h"

void createQueuecircular(int capacity, Queue2 *queue) {
    queue->capacity = capacity;
    queue->front = queue->rear =-1;
    ///allocate memory
    queue->elements =(int *) calloc(queue->capacity, sizeof(int));
    if(!queue->elements){
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}

void destroyQueuecircular(Queue2 *queue) {
    queue->rear = queue->front = -1;
    free(queue->elements);
    queue->capacity = 0;
    queue = NULL;
}

bool isFullcircular(Queue2 queue) {
    return queue.front == 0 && queue.rear == queue.capacity-1 || queue.rear == queue.front-1;
}

bool isEmptycircular(Queue2 queue) {
    return queue.front == -1;
}

void enqueuecircular(Queue2 *queue, int item) {
    if(isFullcircular(*queue)){
        printf(FULL_MESSAGE);
        return;
    }
    if(isEmptycircular(*queue)){
        queue->front = 0;
    }
    queue->rear = (queue->rear +1) % queue->capacity;
    queue->elements[queue->rear] = item;
}

int dequeuecircular(Queue2 *queue) {
    if(isEmptycircular(*queue)){
        printf(EMPTY_MESSAGE);
        return INT_MIN;
    }
        int save = queue->elements[queue->front];
    if(queue->front == queue->rear){
        queue->front = -1;
        queue->rear = -1;
    }
    else {
        queue->front = (queue->front + 1) % queue->capacity;
    }
    return save;

}

void displaycircular(Queue2 queue) {
    if(isEmptycircular(queue)){
        printf("The queue is: ");
        printf(EMPTY_MESSAGE);
        return;
    }
    int i = queue.front;
    do {
        printf("%i \n", queue.elements[i]);
        i = (i+1) % queue.capacity;
    }
    while (i != queue.rear);
    printf("%i \n", queue.elements[i]);
    printf("\n");
}
