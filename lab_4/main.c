#include "array.h"
#include <constant.h>
int main() {
    IntArray array;
    int capacity = 10;
    createIntArray(capacity,&array);
    printArray(array);
    int value = 1;
    for (int i = 0; i < array.capacity/2; ++i) {
        insertAt(&array,i,value++);
    }
    printArray(array);
    while (!isFull(array)){
        if(value % 2 == 0){
            insertFirst(&array,value++);
        }
        else insertLast(&array,value++);
    }
    printArray(array);
    printf("Give me an integer number: ");
    int src;
    scanf("%i", &src);
    int res = search(array, src);
    if(res == -1){
        printf(NOT_FOUND_MESSAGE);
    }
    else {
        printf("found %i at position: %i\n", src, res+1);
        printf("Give me another integer number: ");
        int new;
        scanf("%i", &new);
        if(update(&array, res, new)){
            printf("update unsuccessful\n");
        }
        printArray(array);
        deleteItemAt(&array,res);
        printArray(array);
    }
    srand(time(0));
    while (!isEmpty(array)){
        int position = rand()%array.capacity;
        printf("item at position %i = %i\n", position,getItemAt(array,position));
        deleteItemAt(&array,position);
    }

    deallocateIntArray(&array);
    return 0;

}
