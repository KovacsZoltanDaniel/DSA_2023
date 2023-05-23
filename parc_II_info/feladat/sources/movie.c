//
// Created by Dani on 2023. 05. 23..
//

#include "../headers/movie.h"

Node *createNewNode(Film newData) {
    Node *newItem = (Node *) malloc(sizeof(Node));
    if (!newItem) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    newItem->info = newData;
    newItem->left = NULL;
    newItem->right = NULL;
    return newItem;
}


Node *insert(Node *node, Film key) {
    if (node == NULL) {
        return createNewNode(key);
    }
    if (node->info.hossz < key.hossz) {
        node->right = insert(node->right, key);
    } else {
        node->left = insert(node->left, key);
    }
    return node;
}

void inorderTraversal(Node *root) {
    if (root == NULL)return;
    inorderTraversal(root->left);
    printf("Cim: %s \thossz: %i\tkiadasi ev: %i\tmufaj: %s", root->info.cim, root->info.hossz, root->info.kiadasiEv,
           getMufaj(root->info.mufaj));
    inorderTraversal(root->right);
}

Node *minValueNode(Node *node) {
    Node *current = node;
    while (current != NULL && current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node *maxValueNode(Node *node) {
    Node *current = node;
    while (current != NULL && current->right != NULL) {
        current = current->right;
    }
    return current;
}

Node *deleteNode(Node *root, Film key) {
    if (root == NULL) {
        return NULL;
    }
    if (root->info.hossz < key.hossz) {
        root->right = deleteNode(root->right, key);
    } else if (root->info.hossz > key.hossz) {
        root->left = deleteNode(root->left, key);
    } else {
        //node to be deleted
        if (root->right == NULL && root->left == NULL) {
            free(root);
            return NULL;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        } else if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        //van jobb es bal is
        Node *temp = minValueNode(root->right);
        root->info = temp->info;
        deleteNode(root->right, temp->info);
    }
    return root;
}

void destroyBinaryTree(Node **root) {
    if ((*root)->right == NULL && (*root)->left == NULL) {
        free(*root);
        *root = NULL;
        return;
    }
    destroyBinaryTree(&(*root)->left);
    destroyBinaryTree(&(*root)->right);
    free(*root);
    *root = NULL;
}

char *getMufaj(enum Mufaj mufaj) {
    switch (mufaj) {
        case VIGJATEK : {
            return "VIGJATEK";
        }
        case HORROR : {
            return "HORROR";
        }
        case DRAMA : {
            return "DRAMA";
        }
        case AKCIO : {
            return "AKCIO";
        }
        default:  {
            return "ERROR";
        }
    }
}

enum Mufaj getMufajByChar(char *mufaj) {
    for (int i = 0; i < 11; ++i) {
        if(strcmp(getMufaj(i),mufaj) == 0) {
            return i;
        }
    }
    return 0;
}
