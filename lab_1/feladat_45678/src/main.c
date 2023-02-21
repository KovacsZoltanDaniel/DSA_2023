
#include "functions.h"
int main() {
    int *pArray;
    int n;
    readArray(&n,&pArray,"data.in");
    printArray(n,pArray,"CON");
    return 0;
}
