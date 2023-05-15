//
// Created by kovac on 2023. 05. 15..
//

#include "../headers/bs_tree.h"

Node *createNewNode(Person newData) {
    Node *newNode = malloc(sizeof(Node));
    if (!newNode) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    newData.laborjegy = newData.parc_atlag * 0.6 + newData.parc_atlag * 0.4; // beállítjuk a laborjegyet
    newNode->info = newData;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


Node *insert(Node *node, Person key) {
    //if the tree is empty
    if (node == NULL)
        return createNewNode(key);

    //find the right place and insert the node
    if (key.laborjegy < node->info.laborjegy)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    return node;
}

void inorderTraversal(Node *root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%s laborjegye: %.2lf\n", root->info.nume, root->info.laborjegy);
    inorderTraversal(root->right);
}

