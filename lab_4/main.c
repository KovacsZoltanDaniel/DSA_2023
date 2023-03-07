#include "array.h"

int main() {
    IntArray array;
    int capacity = 10;
    createIntArray(capacity,&array);
    printArray(array);
    for (int i = 0; i <= array.capacity/2; ++i) {
        array.elements[i] = i+1;
        array.size = i;
    }
    printArray(array);
    int position = 2;
    getItemAt(array,position);
    return 0;
}
