//
// Created by kovac on 2023. 06. 18..
//

#ifndef DINAMIKUS_HASITO_TABLA_DINAMIC_HASH_TABLE_H
#define DINAMIKUS_HASITO_TABLA_DINAMIC_HASH_TABLE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <constant.h>
#include <string.h>

typedef struct {
    char key[20];
    char data[50];
}HashItem;

typedef struct Node {
    HashItem data;
    struct Node* next;
}Node;
#define capacity 13

typedef struct {
    Node *items[capacity];
}HashTable;

Node *newNode (HashItem new_data);
bool isEmpty(Node *head);
void insertFirst(Node **head_ref, HashItem new_data);
void deleteFromBeginning(Node **head_ref);
void deleteNode(Node **head_ref, char *key);
bool searchNode(Node *head_ref, char *key);
void printList(Node *node);
void printNodeData(HashItem item);
void freeLis(Node **head);

void createHashArray(HashTable *pHashTable);
void insert(HashTable *hashTable, char *key, char *data);
void delete(HashTable *hashTable, char *key);
bool search(HashTable hashTable, char *key);
void display(HashTable hashTable);
void destroy(HashTable *hashTable);

#endif //DINAMIKUS_HASITO_TABLA_DINAMIC_HASH_TABLE_H
