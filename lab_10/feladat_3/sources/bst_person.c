//
// Created by kovac on 2023. 05. 15..
//

#include "../headers/bst_person.h"

Node *createNewNode(Person newData) {
    Node *newNode = malloc(sizeof(Node));
    if (!newNode) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    newNode->info = newData;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insert(Node *node, Person key) {
    if (node == NULL) {
        return createNewNode(key);
    }
    if (strcmp(key.nev, node->info.nev) < 0){
        node->left = insert(node->left, key);
    }
    else {
        node->right = insert(node->right,key);
    }
    return node;
}
void inorderTraversal(Node *root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%s \n", root->info.nev);
    inorderTraversal(root->right);
}
Node *minValueNode(Node *node) {
    Node *current = node;
    while (current != NULL && current->left != NULL){
        current = current->left;
    }
    return current;
}

Node *maxValueNode(Node *node) {
    Node *current = node;
    while (current != NULL && current->right != NULL ){
        current = current->right;
    }
    return current;
}