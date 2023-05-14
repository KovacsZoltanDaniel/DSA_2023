//
// Created by Dani on 2023. 05. 14..
//

#include "../headers/binary_tree.h"

Node *createNewNode(int newData) {
    Node *newItem = (Node *) malloc(sizeof(Node));
    if(!newItem){
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    newItem->info = newData;
    newItem->left = NULL;
    newItem->right = NULL;
    return newItem;
}

Node *insertLeft(Node *root, int newData) {
    root->left = createNewNode(newData);
    return root->left;
}

Node *insertRight(Node *root, int newData) {
    root->right = createNewNode(newData);
    return root->right;
}

void preorderTraversal(Node *root) {
    if(root == NULL)return;
    printf("%d ", root->info);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(Node *root) {
    if(root == NULL)return;
    inorderTraversal(root->left);
    printf("%d ", root->info);
    inorderTraversal(root->right);
}

void postorderTraversal(Node *root) {
    if(root == NULL)return;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->info);
}

void destroyBinaryTree(Node **root) {
    if((*root)->right == NULL && (*root)->left == NULL){
        free(*root);
        *root = NULL;
        return;
    }
    destroyBinaryTree(&(*root)->left);
    destroyBinaryTree(&(*root)->right);
    free(*root);
    *root = NULL;
}

