//
// Created by Dani on 2023. 04. 04..
//

#include "../headers/linked.list.h"

Node *newNode(int new_data) {
    Node *new_node = (Node *) malloc(1 * sizeof(Node));
    if (!new_node) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

bool isEmpty(Node *head) {
    return head == NULL;
}

void insertAtBeginning(Node **head_ref, int new_data) {
    // Allocate memory to a node
    Node *new_node = newNode(new_data);
    new_node->next = (*head_ref);
    // Move head to new node
    (*head_ref) = new_node;
}

void insertAfter(Node *prev_ref, int new_data) {
    if (prev_ref == NULL) {
        printf(NULL_POINTER_EXCEPTION_ERROR_MESSAGE);
        return;
    }
    Node *new_node = newNode(new_data);
    new_node->next = prev_ref->next;
    prev_ref->next = new_node;
}

void insertAtEnd(Node **head_ref, int new_data) {
    Node *new_node = newNode(new_data);
    if (isEmpty(*head_ref)) {
        *head_ref = new_node;
        return;
    }
    Node *last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

void deleteFromBeginning(Node **head_ref) {
    if (isEmpty(*head_ref)) {
        printf(NULL_POINTER_EXCEPTION_ERROR_MESSAGE);
        return;
    }
    Node *temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}

void deleteFromEnd(Node **head_ref) {
    if (isEmpty(*head_ref)) {
        printf(NULL_POINTER_EXCEPTION_ERROR_MESSAGE);
        return;
    }
    Node *last = *head_ref, *prev;
    while (last->next != NULL) {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    free(last);
}

void deleteNode(Node **head_ref, int key) {
    Node *temp = *head_ref, *prev;
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
// Find the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
// If the key is not present
    if (temp == NULL) return;
// Remove the node
    prev->next = temp->next;
    free(temp);
}

bool searchNode(Node *head_ref, int key) {
    Node *current = head_ref;
    while (current != NULL) {
        if (current->data == key)
            return
                    true;
        current = current->next;
    }
    return false;
}

void sortLinkedList(Node *head_ref) {
    if(isEmpty(head_ref)){
        printf(NULL_POINTER_EXCEPTION_ERROR_MESSAGE);
        return;
    }
    Node *first = head_ref;
    while (first != NULL){
        Node *current = first->next;
        while (current != NULL){
            if(first->data > current->data){
                int aux = first->data;
                first->data = current->data;
                current->data = aux;
            }
            current = current->next;
        }
        first = first->next;
    }
}

void printList(Node *node) {
    Node * temp = node;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList(Node **head) {
    while (*head != NULL){
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    *head = NULL;
}
