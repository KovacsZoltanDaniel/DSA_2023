//
// Created by kovac on 2023. 05. 15..
//

#ifndef FELADAT_3_BST_PERSON_H
#define FELADAT_3_BST_PERSON_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <constant.h>
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

//create a node
Node * createNewNode(Person newData);
//insert a node
Node * insert(Node *node, Person key);
//inorder traversal
void inorderTraversal(Node *root);
//find the min number
Node * minValueNode(Node *node);
//find the max number
Node * maxValueNode(Node *node);
//deleting a node
Node *deleteNode(Node *root, int key);
#endif //FELADAT_3_BST_PERSON_H
