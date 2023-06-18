//
// Created by kovac on 2023. 06. 18..
//

#include "../headers/hash_table.h"

int hashCode(int key){
    return  key % capacity;
}

void createHashArray(HashTable *pHashTable) {
    pHashTable->items = (HashItem *) malloc(capacity * sizeof(HashItem));
    if(!pHashTable->items){
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    pHashTable->size = 0;
    for (int i = 0; i < capacity; ++i) {
        pHashTable->items[i] = dummyData;
    }

}

void insert(HashTable *hashTable, int key, int data) {
    if(hashTable->size == capacity){
        printf("Hashtable is full!");
        return;
    }
    HashItem  item = {key,data};
    int index = hashCode(key);
    int i = 0;
    while (hashTable->items[(index + i) % capacity].key != dummyData.key){
        i++;
    }
    hashTable->items[(index + i) % capacity] = item;
    hashTable->size++;
}

int size(HashTable hashTable) {
    return hashTable.size;
}

void display(HashTable hashTable) {
    if(hashTable.size == 0){
        printf("The hashtable is empty!");
        return;
    }
    printf("Index\t->\tkey\t->\tvalue\thash\n");
    for (int i = 0; i < capacity; ++i) {
        if(hashTable.items[i].key != dummyData.key){
            printf("%d\t->\t%d\t->\t%d\t%d\n", i, hashTable.items[i].key, hashTable.items[i].data,
                   hashCode(hashTable.items[i].key));
        }
    }
    printf("\n\n");
}

int search(HashTable hashTable, int key) {
    int index = hashCode(key);
    int i = 0;
    if(hashTable.items[index].key == dummyData.key){
        return -1;
    }
    while (i < capacity && hashTable.items[(index + i) % capacity].key != key){
        i++;
    }
    if(i == capacity){
        return -1;
    }
    return (index + i) % capacity;
}

void delete(HashTable *hashTable, int key) {
    int pos = search(*hashTable, key);
    if(pos == -1){
        printf("Couldn't delete this item with key %d!\n", key);
        return;
    }
    hashTable->items[pos] = dummyData;
    hashTable->size--;
    printf("Item with key (%d) deleted!\n", key);
}

void destroyHashArray(HashTable *pHashTable) {
    pHashTable->size = 0;
    free(pHashTable->items);
    pHashTable = NULL;
}
