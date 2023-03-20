//
// Created by Dani on 2023. 03. 19..
//

#ifndef LAB_5_CIRCULAR_QUEUE_H
#define LAB_5_CIRCULAR_QUEUE_H
#include <stdio.h>
#include <stdlib.h>
#include <constant.h>
#include <string.h>
#include <stdbool.h>
typedef struct{
    int capacity;
    int front;
    int rear;
    int *elements;
}Queue2;
void createQueuecircular(int capacity, Queue2 *queue);
/**
* Deallocates the elements array -> free
* @param queue
*/
void destroyQueuecircular(Queue2* queue);
/**
* Checks whether the queue is full or not
* @param queue
* @return true/false
*/
bool isFullcircular(Queue2 queue);
/**
* Checks whether the queue is empty or not
* @param queue
* @return true/false
*/
bool isEmptycircular(Queue2 queue);
/**
* Adds a new item to the end of the queue
* @param queue
* @param item
*/
void enqueuecircular(Queue2* queue, int item);
/**
* Removes the first item from the queue
* @param queue
* @return
*/
int dequeuecircular(Queue2* queue);
/**
* Prints all items of the queue
* @param queue
*/
void displaycircular(Queue2 queue);
#endif //LAB_5_CIRCULAR_QUEUE_H
