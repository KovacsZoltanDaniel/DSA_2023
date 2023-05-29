//
// Created by Dani on 2023. 05. 28..
//

#include "catalog.h"

Node *insert1(Node *node, Movie key) {
    if(node == NULL){
        return createNewNode(key);
    }
    if(node->info.hossz < key.hossz){
        node->right = insert1(node->right,key);
    }
    else {
        node->left = insert1(node->left,key);
    }
    return node;
}

Node *insert2(Node *node, Movie key) {
    if(node == NULL){
        return createNewNode(key);
    }
    if(strcmp(node->info.cim,key.cim) < 0){
        node->right = insert2(node->right,key);
    }
    else {
        node->left = insert2(node->left,key);
    }
    return node;
}

void printMovies(Node *root) {
    if (root == NULL) return;
    printMovies(root->left);
    printMovie(root->info);
    printMovies(root->right);
}

void ujFilm(Node *root1, Node *root2, Movie key) {
    insert1(root1,key);
    insert2(root2,key);
}

Node *leghosszabb(Node *node) {
    Node *current = node;
    while (current != NULL && current->right != NULL){
        current = current->right;
    }
    return current;
}

Node *keres(Node *root, char *cim) {
    if (root == NULL)
    {
        printf("Nincs ilyen cimu film");
        exit(-5);
    }

    else if (strcmp(cim, root->info.cim) < 0)
        return keres(root->left, cim);
    else if (strcmp(cim, root->info.cim) > 0)
        return keres(root->right, cim);
    else if(strcmp(cim,root->info.cim) == 0){
        printf("Talalat: %s", root->info.cim);
        return root;
    }
    return root;
}
Node *minValueNode(Node *node) {
    Node *current=node;
    while(current!=NULL && current->left!=NULL)
        current=current->left;
    return current;
}
Node *delete(Node *root, char *cim) {
    if (root == NULL)
        return root;
    if (strcmp(cim, root->info.cim) < 0)
        root->left = delete(root->left, cim);
    else if (strcmp(cim, root->info.cim) > 0)
        root->right = delete(root->right, cim);
    else {
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return (temp);
        }
        Node *temp = minValueNode(root->right);
        root->info = temp->info;
        root->right = delete(root->right, temp->info.cim);
    }
    return root;
}
