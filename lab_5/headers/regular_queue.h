//
// Created by Dani on 2023. 03. 19..
//

#ifndef LAB_5_REGULAR_QUEUE_H
#define LAB_5_REGULAR_QUEUE_H
#include <stdio.h>
#include <stdlib.h>
#include <constant.h>
#include <string.h>
#include <stdbool.h>
typedef struct{
    int capacity;
    int front;
    int rear;
    char **elements;
}Queue;
#define CAR_PLATE_NUMBER_LIMIT 10
void createQueue(int capacity, Queue *queue);
/**
* Deallocates the elements array -> free
* @param queue
*/
void destroyQueue(Queue* queue);
/**
* Checks whether the queue is full or not
* @param queue
* @return true/false
*/
bool isFullqueue(Queue queue);
/**
* Checks whether the queue is empty or not
* @param queue
* @return true/false
*/
bool isEmptyqueue(Queue queue);
/**
* Adds a new item to the end of the queue
* @param queue
* @param item
*/
void enqueue(Queue* queue, char* item);
/**
* Removes the first item from the queue
* @param queue
* @return
*/
char* dequeue(Queue* queue);
/**
* Prints all items of the queue
* @param queue
*/
void display(Queue queue);
#endif //LAB_5_REGULAR_QUEUE_H
