
#include "functions.h"

int main() {
float number1 = 3, number2 = 2, number3 = 8;
    printf("a ket szam atlaga: %.2f\n", avg(number1,number2));
    printf("a 3 szam kozul a legnagyobb: %.2f\n", maximum(number1,number2,number3));
    int n = 8, start = 0, end = 10;
    int *pArray;
    srand(time(0));
    fillWithRandomNumbers(n,&pArray,start,end);
    /*for (int i = 0; i < n; ++i) {
        printf("%i ", pArray[i]);
    }
     ellenorzes, hogy tenyleg forditva irja e ki a program
     */
    printArrayInReverseOrder(n,pArray);
    deallocateMemoryForArray( &pArray);
    return 0;
}
