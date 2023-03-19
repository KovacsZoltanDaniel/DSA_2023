//
// Created by Dani on 2023. 03. 14..
//

#include "../headers/stack.h"

void createStack(int capacity, Stack *stack) {
    stack->capacity = capacity;
    stack->top = -1;
    stack->elements = (int *) calloc(stack->capacity, sizeof(int));
    if(!stack->elements){
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}

void destroyStack(Stack *stack) {
    stack->capacity = 0;
    stack->top = -1;
    free(stack->elements);
    stack = NULL;
}

bool isFull(Stack stack) {
    return stack.top == stack.capacity-1;;
}

bool isEmpty(Stack stack) {
    return stack.top == -1;
}

void push(Stack *stack, int item) {
    if(isFull(*stack)) {
        printf(FULL_MESSAGE);
        return;
    }
    stack->elements[++stack->top] = item;
}

int pop(Stack *stack) {
    if (isEmpty(*stack)) {
        printf(EMPTY_MESSAGE);
        return INT_MIN;
    }
    int save = stack->elements[stack->top]; //Legfelso elemet lementsuk
    stack->elements[stack->top--] = 0;
    return save;
}

int peek(Stack stack) {
    if (isEmpty(stack)) {
        printf(EMPTY_MESSAGE);
        return INT_MIN;
    }
    return stack.elements[stack.top];
}

int size(Stack stack) {
    return stack.top+1; //mivel "le van maradva " vagyis 0 tol indexelunk
}

int calculateOperation(int value1, int value2, char *token) {
    char operation = token[0];
    switch (operation) {
        case '+' : return value2 + value1;
        case '-' : return value2 - value1;
        case '*' : return value2 * value1;
        case '/' : return value2 / value1;
        case '%' : return value2 % value1;
        default :
            displayErrorMessage(INVALID_OPERATOR);
            return STACK_EXCEPTION_ERROR_CODE;
    }

}
void displayErrorMessage(enum StackException exception) {
    switch (exception) {
        case   INCORRECT_EXPRESSION :
            printf(INCORRECT_EXPRESSION_MESSAGE);
            break;
        case INVALID_OPERATOR :
            printf(INVALID_OPERATOR_MESSAGE);
            break;
        case INVALID_OPERAND :
            printf(INVALID_OPERAND_MESSAGE);
            break;
        default:
            printf(UNKNOWN_EXCEPTION_MESSAGE);
            break;
    }
    exit(STACK_EXCEPTION_ERROR_CODE);
}

void checkToken(char *token) {
    for (int i = 0; i < strlen(token); ++i) {
        if(!isdigit(token[i])){
            displayErrorMessage(INVALID_OPERAND);
        }
    }
}

