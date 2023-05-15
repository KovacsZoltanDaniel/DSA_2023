//
// Created by kovac on 2023. 05. 15..
//

#ifndef FELADAT_4_BS_TREE_H
#define FELADAT_4_BS_TREE_H
#include <stdlib.h>
#include <stdio.h>
#include <constant.h>
#include <stdbool.h>
#include <string.h>

typedef struct Person
{
    char nume[34];
    double parc_atlag, teszt_atlag, laborjegy;
    int gender;
}Person;

typedef struct Node{
    Person info;
    struct Node *left, *right;
}Node;

//create a new node
Node *createNewNode(Person newData);
Node *insert(Node *node, Person key);
//inorder traversal
void inorderTraversal(Node *root);

#endif //FELADAT_4_BS_TREE_H
