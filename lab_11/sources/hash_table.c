//
// Created by Dani on 2023. 05. 16..
//

#include "../headers/hash_table.h"


int hashCode(int key) {
    return key % CAPACITY;
}

void createHashArray(HashTable *pHashTable) {
    pHashTable->items = (HashItem *) malloc(CAPACITY * sizeof(HashItem));
    if(!pHashTable->items)
    {
        printf("MEMORY_ALLOCATION_ERROR_MESSAGE");
        exit(-1);
    }
    pHashTable->size = 0;
    for (int i = 0; i < CAPACITY; ++i) {
        pHashTable->items[i] = dummyData;
    }
}



void insert(HashTable *hashTable, int key, int data) {
    if (hashTable->size >= CAPACITY) {
        printf("Hash table is full\n");
        return;
    }
    HashItem item = {key, data};
    int index = hashCode(key);
    int i = 0;
    while (hashTable->items[(index + i) % CAPACITY].key != dummyData.key) {
        i++;
    }
    hashTable->items[(index + i) % CAPACITY] = item;
    hashTable->size++;
}

int size(HashTable hashTable) {
    return hashTable.size;
}

void display(HashTable hashTable) {
    if (hashTable.size == 0){
        printf("The hash table is empty\n");
        return;
    }
    printf("index\t->\tkey\t->\tvalue\t->\thash\n");
    for (int i = 0; i < CAPACITY; ++i) {
        if (hashTable.items[i].key != dummyData.key){
            printf("%d\t->\t%d\t->\t%d\t->\t%d\n",
                   i, hashTable.items[i].key,hashTable.items[i].data,
                   hashCode(hashTable.items[i].key));
        }
    }
    printf("\n\n");
}

int search(HashTable hashTable, int key) {
    int index = hashCode(key);
    int i = 0;
    if (hashTable.items[index].key == dummyData.key){
        return -1;
    }
    while (i < CAPACITY && hashTable.items[(index + i) % CAPACITY].key != key) {
        i++;
    }
    if(i == CAPACITY){
        return -1;
    }
    return (index+i)%CAPACITY;
}

void delete(HashTable *hashTable, int key) {
    int pos = search(*hashTable,key);
    if (pos == -1){
        printf("Could not delete item with key: %d\n", key);
        return;
    }
    hashTable->items[pos] = dummyData;
    hashTable->size--;
    printf("Item with key (%d) deleted...\n", key);
}

void destroyHashArray(HashTable *pHashTable) {
    pHashTable->size = 0;
    free(pHashTable->items);
    pHashTable = NULL;
}
