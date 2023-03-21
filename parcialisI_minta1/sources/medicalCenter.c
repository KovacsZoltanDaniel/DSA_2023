//
// Created by Dani on 2023. 03. 21..
//

#include "medicalCenter.h"

void createQueuecircular(int capacity, MedicalCenter *queue) {
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->patient = (Patient *) calloc(queue->capacity, sizeof(Patient));
    if (!queue->patient) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}

void destroyQueuecircular(MedicalCenter *queue) {
    queue->front = queue->rear = -1;
    free(queue->patient);
    queue->capacity = 0;
    queue = NULL;
}

bool isFull(MedicalCenter queue) {
    return queue.front == 0 && queue.rear == queue.capacity - 1 || queue.rear == queue.front - 1;
}

bool isEmpty(MedicalCenter queue) {
    return queue.front == -1;
}

void enqueue(MedicalCenter *queue, int item) {
    if (isFull(*queue)) {
        printf(FULL_MESSAGE);
        return;
    }
    if (isEmpty(*queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->patient[queue->rear] = item;
}