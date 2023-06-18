//
// Created by kovac on 2023. 06. 18..
//

#include "../headers/dinamic_hash_table.h"

HashItem createHashItem(char *key, char *data);

Node *newNode(HashItem new_data) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    if(!new_node){
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

bool isEmpty(Node *head) {
    return head == NULL;
}

void insertFirst(Node **head_ref, HashItem new_data) {
    Node *new_node = newNode(new_data);
    if(isEmpty(*head_ref)){
        *head_ref = new_node;
        return;
    }
    new_node->next = (*head_ref);
    (*head_ref = new_node);

}

void deleteFromBeginning(Node **head_ref) {
    if(isEmpty(*head_ref)){
        printf(NULL_POINTER_EXCEPTION_ERROR_MESSAGE);
        return;
    }
    Node *temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}

void deleteNode(Node **head_ref, char *key) {
    if(isEmpty(*head_ref)){
        printf(NULL_POINTER_EXCEPTION_ERROR_MESSAGE);
        return;
    }
    if(strcmp((*head_ref)->data.key, key) == 0 ){
        deleteFromBeginning(head_ref);
        return;
    }
    Node *temp = (*head_ref)->next;
    Node *prev = (*head_ref);
    while (temp != NULL && strcmp(temp->data.key,key) != 0){
        prev = temp;
        temp = temp->next;
    }
    if(temp != NULL){
        prev->next =  temp->next;
        free(temp);
    }

}

bool searchNode(Node *head_ref, char *key) {
    Node *current = head_ref;
    while (current != NULL){
        if(strcmp(current->data.key,key) == 0) {
            return true;
        }
            current = current->next;
    }
    return false;
}
void printNodeData(HashItem item){
    printf("\tkey (%s): value (%s)\n", item.key, item.data);
}
void printList(Node *node) {
    while (node != NULL){
        printNodeData(node->data);
        node = node->next;
    }
}

void freeLis(Node **head) {
    while (*head != NULL){
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    *head = NULL;
}

int hashCode(char *key){
    int bucketIndex;
    int sum = 0, factor = 31;
    for (int i = 0; i < strlen(key); ++i) {
        sum = (((sum % capacity) + (((int)key[i]) *factor) %capacity)) %capacity;
        factor = ((factor % __INT16_MAX__) *(31 % __INT16_MAX__)) % __INT16_MAX__;
    }
    bucketIndex = sum;
    return bucketIndex;
}

void createHashArray(HashTable *pHashTable) {
    for (int i = 0; i < capacity; ++i) {
        pHashTable->items[i] =  NULL;
    }
}

void insert(HashTable *hashTable, char *key, char *data) {
    int index = hashCode(key);
    printf("key (%s) -> index (%d)\n", key,index);
    HashItem  item = createHashItem(key,data);
    insertFirst(&hashTable->items[index], createHashItem(key,data));
}

void display(HashTable hashTable) {
    for (int i = 0; i < capacity; ++i) {
        if(hashTable.items[i] != NULL){
            printf("%i index has the following list items:\n",i);
            printList(hashTable.items[i]);
            printf("\n");
        }
    }

}

bool search(HashTable hashTable, char *key) {
    int index = hashCode(key);
    return searchNode(hashTable.items[index], key);
}

void delete(HashTable *hashTable, char *key) {
    int index = hashCode(key);
    if(!search(*hashTable,key)){
        printf("Could not delete key(%s)!\n", key);
        return;
    }
    deleteNode(&hashTable->items[index],key);
    printf("Item with key (%s) deleted!\n",key);
}

void destroy(HashTable *hashTable) {
    for (int i = 0; i < capacity; ++i) {
        freeLis(&hashTable->items[i]);
        hashTable->items[i] = NULL;
    }
    hashTable = NULL;
}

HashItem createHashItem(char *key, char *data) {
    HashItem result;
    strcpy(result.key,key);
    strcpy(result.data,data);
    return result;
}
