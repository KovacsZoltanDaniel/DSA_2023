#include "hash_table.h"

int main() {
    HashTable table;
    createHashArray(&table);
    srand(time(0));
    int key = rand() % 20, data = rand()%100;
    while (size(table)<CAPACITY){
        printf("key: %d, value: %d\n", key,data);
        insert(&table, key, data);
        display(table);
        key = key + rand() % 20 + 1;
        data = rand() % 100;
    }
    printf("The size of the hash table is: %d\n", size(table));
    printf("Search for (key): ");
    scanf("%d", &key);
    int pos = search(table,key);
    if (pos != -1){
        printf("The given key is present in the hash table, at position: %d\n", pos);
        delete(&table, key);
    }
    else{
        printf("Key not found\n");
    }
    printf("The size of the hash table is: %d\n", size(table));
    display(table);
    destroyHashArray(&table);
    return 0;
}
