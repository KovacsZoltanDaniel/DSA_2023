//
// Created by Dani on 2023. 05. 02..
//

#ifndef LAB_9_BST_PERSON_H
#define LAB_9_BST_PERSON_H
#include <stdio.h>
#include <stdlib.h>
#include <constant.h>
#include <string.h>
typedef struct {
    int year;
    int month;
    int day;
}Date;
typedef struct {
    char nev[16];
    Date data;
    int gender;
}Person;
typedef struct Node{
    Person info;
    struct Node *left, *right;
}Node;

Node * createNewNode(Person newData);
//insert a node
Node * insert(Node *node, Person key);
//inorder traversal
void inorderTraversal(Node *root);
#endif //LAB_9_BST_PERSON_H
