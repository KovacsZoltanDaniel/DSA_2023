//
// Created by Dani on 2023. 05. 23..
//

#ifndef FELADAT_MOVIE_H
#define FELADAT_MOVIE_H
#include <stdio.h>
#include <stdlib.h>
#include <constant.h>
#include <string.h>
enum Mufaj {VIGJATEK, HORROR, DRAMA, AKCIO};
typedef struct Film{
    char cim[20];
    int hossz;
    int kiadasiEv;
    enum Mufaj mufaj;
}Film;
typedef struct Node{
    Film info;
    struct Node *left, *right;
}Node;

char* getMufaj(enum Mufaj mufaj);
enum Mufaj getMufajByChar(char *mufaj);
//create a node
Node * createNewNode(Film newData);
//insert a node
Node * insert(Node *node, Film key);
//inorder traversal
void inorderTraversal(Node *root);
//find the min number
Node * minValueNode(Node *node);
//find the max number
Node * maxValueNode(Node *node);
//deleting a node
Node *deleteNode(Node *root, Film key);
void destroyBinaryTree(Node **root);

#endif //FELADAT_MOVIE_H
