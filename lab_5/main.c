#include "stack.h"

int main() {
    char operations[] = "2 5 3 6 + * * 15 / 2 -";
    Stack verem;
    createStack(strlen(operations), &verem);
    printf("Stack is : %s\n", (isEmpty(verem)) ? ("empty") : ("not empty"));
    printf("Stack is : %s\n", (isFull(verem)) ? ("full") : ("not full"));
    printf("Size of stack is : %i\n", size(verem));
    char separators[2] = " ";
    char *token = strtok(operations,separators);
    char operators[] = "+-*/%";

    while (token != NULL){
        //printf("%s", token);
        if(strstr(operators,token)){
            ///operator => pop two top elements from the stack
            int value1 = pop(&verem);
            int value2 = pop(&verem);
            int result = calculateOperation(value1,value2,token); //token = operator
            push(&verem, result); //azert &verem mert valtozik az ertek
        }
        else {
            ///operator => push number to the stack
            int value = atoi(token);
            printf("%i is a number\n", value);
            push(&verem, value);
        }
        token= strtok(NULL,separators);
    }
    int final = pop(&verem);
    printf("The final result is %i\n", final);
    destroyStack(&verem);
    return 0;
}
