//
// Created by Dani on 2023. 03. 14..
//

#ifndef LAB_5_STACK_H
#define LAB_5_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <constant.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
typedef struct {
    int capacity;
    int top;
    int *elements;
}Stack;
/**
* Initializing the capacity and size of stack,
* allocating memory for the @elements array
* @param capacity
* @param stack
*/
void createStack(int capacity, Stack * stack);
/**
* Deallocates the memory
* @param stack
*/
void destroyStack(Stack* stack);
/**
* Checks whether the stack is full
* @param stack
* @return
*/
bool isFull(Stack stack);

/**
* Checks whether the stack is empty
* @param stack
* @return
*/
bool isEmpty(Stack stack);
/**
* Pushes a new item to the stack,
* if it is not full
* @param stack
* @param item
*/
void push(Stack* stack, int item);
/**
* Removes the top element from the stack,
* if it is not empty
* @param stack
* @return
*/
int pop(Stack* stack);
/**
* Returns the top element of the stack,
* if it is not empty
* @param stack
* @return
*/
int peek(Stack stack);
/**
* Returns the size of the stack
* @param stack
* @return
*/
int size(Stack stack);
int calculateOperation(int value1, int value2, char *token);
#endif //LAB_5_STACK_H
