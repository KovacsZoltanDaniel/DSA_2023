//
// Created by kovac on 2023. 05. 15..
//

#ifndef FELADAT_2_BST_H
#define FELADAT_2_BST_H
#include <stdio.h>
#include <stdlib.h>
#include <constant.h>
typedef struct Node{
    int info;
    struct Node *left, *right;
}Node;
//create a node
Node * createNewNode(int newData);
//insert a node
Node * insert(Node *node, int key);
//inorder traversal
void inorderTraversal(Node *root);
//find the min number
Node * minValueNode(Node *node);
//find the max number
Node * maxValueNode(Node *node);
//deleting a node
Node *deleteNode(Node *root, int key);
void destroyBinaryTree(Node **root);
#endif //FELADAT_2_BST_H
