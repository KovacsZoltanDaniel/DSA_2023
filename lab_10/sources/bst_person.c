//
// Created by Dani on 2023. 05. 02..
//

#include "../headers/bst_person.h"
#include "linkedd_list.h"


Node *createNewNode(Person newData) {
    Node *newNode = malloc(sizeof(Node));
    if (!newNode) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    newNode->info = newData;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->info.laborjegy = newNode->info.parc_atlag * 0.6 + newNode->info.teszt_atlag * 0.4;
    return newNode;
}

Node *insert(Node *node, Person key) {
    //if the tree is empty
    if (node == NULL)
        return createNewNode(key);
//find the right place and insert the node
    if (node->info.laborjegy > key.laborjegy)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}

void inorderTraversal(Node *root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%s \n %.2f\n", root->info.nev,root->info.laborjegy);
    inorderTraversal(root->right);
}
