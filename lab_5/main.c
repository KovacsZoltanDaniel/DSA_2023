#include "stack.h"
#include "regular_queue.h"
#include "circular_queue.h"


int main() {
    //stack
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
            if(isEmpty(verem)){
                displayErrorMessage(INCORRECT_EXPRESSION);
            }
            int value1 = pop(&verem);
            int value2 = pop(&verem);
            int result = calculateOperation(value1,value2,token); //token = operator
            push(&verem, result); //azert &verem mert valtozik az ertek
        }
        else {
            ///operator => push number to the stack
            checkToken(token);
            int value = atoi(token);
            printf("%i is a number\n", value);
            push(&verem, value);
        }
        token= strtok(NULL,separators);
    }
    int final = pop(&verem);
    if(!isEmpty(verem)){
        displayErrorMessage(INCORRECT_EXPRESSION);
    }
    else {
    printf("The final result is %i\n", final);
    }
    destroyStack(&verem);

    //queue
    Queue  queue;
    createQueue(5, &queue);
    bool mehet = true;
    while (mehet){
        int option;
        printf("\nChoose from the following options:"
               "\n\t- Check if queue is empty: 1"
               "\n\t- Check if queue is full: 2"
               "\n\t- Add a new car to the queue: 3"
               "\n\t- Remove a car from the queue: 4"
               "\n\t- Display the cars waiting in the queue: 5"
               "\n\t- Exit: 0\n\n");
        printf("your option:");
        scanf("%i",&option);
        switch (option) {
            case 0 : {
                printf("The end");
                mehet = false;
                break;
            }
            case 1 : {
                printf("The queue is: %s\n", (isEmptyqueue(queue) ? ("it's EMPTY") : ("it's not EMPTY")));
                break;
            }
            case 2 : {
                printf("The queue is: %s\n", (isFullqueue(queue) ? ("it's FULL") : ("it's not FULL")));
                break;
            }
            case 3 : {
                printf("new car arrived, give valid plate number:");
                char carPlate[CAR_PLATE_NUMBER_LIMIT];
                scanf("%s", carPlate);
                enqueue(&queue,carPlate);
                break;
            }
            case 4 : {
                char *result = dequeue(&queue);
                printf("The removed car is: %s\n", result);
                break;
            }
            case 5 : {
                display(queue);
                break;
            }
            default: {
                printf("INVALID OPTION");
            }
        }
    }
    destroyQueue(&queue);

    //circular queue

    Queue2 intQueue;
    createQueuecircular(6, &intQueue);
    bool aha = true;
    while(aha) {
        printf("Choose from the following options:"
               "\n\t- Check if queue is empty: 1"
               "\n\t- Check if queue is full: 2"
               "\n\t- Add a new item to the queue: 3"
               "\n\t- Remove an item from the queue: 4"
               "\n\t- Display all items waiting in the queue: 5"
               "\n\t- Exit: 0"
               "\n\nChoose an option:");
        int options;
        scanf("%i", &options);
        switch (options) {
            case 0 : {
                printf("The end");
                aha = false;
                break;
            }
            case 1 : {
                printf("The queue is: %s\n", (isEmptycircular(intQueue) ? ("it's EMPTY") : ("it's not EMPTY")));
                break;
            }
            case 2 : {
                printf("The queue is: %s\n", (isFullcircular(intQueue) ? ("it's FULL") : ("it's not FULL")));
                break;
            }
            case 3 : {
                printf("Give an integer number:");
                int value;
                scanf("%i", &value);
                enqueuecircular(&intQueue,value);
                break;
            }
            case 4 : {
               int value = dequeuecircular(&intQueue);
                if(value == INT_MIN) {
                    printf(EMPTY_MESSAGE);
                    break;
                }
                printf("The removed number is: %i\n", value);
                break;
            }
            case 5 : {
                displaycircular(intQueue);
                break;
            }
            default: {
                printf("INVALID OPTION");
            }
        }
    }
    destroyQueuecircular(&intQueue);
return 0;

}

