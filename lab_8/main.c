#include "linked.list.h"

Node *createList(int number);

Node *addition(Node **first, Node **second);

void addZeros(Node *node);

int convertListNumber(Node *node);

void deleteDigit(Node **node, int digit);

int main() {
    int num1 = 230, num2 = 987;
    Node *node1 = NULL, *node2 = NULL, *result = NULL;//headek
    node1 = createList(num1);
    printList(node1);
    node2 = createList(num2);
    printList(node2);
    //addition
    result = addition(&node1, &node2);
    printf("the sum of the two integers: ");
    printList(result);
    //convert result to number
    int sum = convertListNumber(result);
    printf("the sum of the two integers: %i\n", sum);
    //add 0
    addZeros(result);
    printf("After adding 0: ");
    printList(result);
    //insert number
    printf("Digit: ");
    int digit;
    scanf("%i", &digit);
    insertAtBeginning(&result, digit);
    insertAtEnd(&result,digit);
    printf("After inserting digit as first and last node: ");
    printList(result);
    printf("Search for %i: ", digit);
    if(searchNode(result,digit)){
        printf("is present\n");
    }
    else{
        printf("is not present!\n");
    }
    //delete
    deleteDigit(&result, digit);
    printf("After delete: ");
    printList(result);
    deleteFromEnd(&result);
    printf("After deleting last node: ");
    printList(result);
    //sort
    printf("after sorting: ");
    sortLinkedList(result);
    printList(result);
    freeList(&result);
    freeList(&node1);
    freeList(&node2);
    return 0;
}

Node *createList(int number) {
    Node *head1 = NULL;
    while (number != 0) {
        insertAtEnd(&head1, number % 10);
        number /= 10;
    }
    return head1;
}

Node *addition(Node **first, Node **second) {
    Node *result = NULL;
    int mod = 0, div = 0;
    while (!isEmpty(*first) && !isEmpty(*second)) {
        mod = (div + (*first)->data + (*second)->data) % 10;
        div = (div + (*first)->data + (*second)->data) / 10;
        insertAtEnd(&result, mod);
        deleteFromBeginning(first);
        deleteFromBeginning(second);
    }
    while (!isEmpty(*first)) {
        mod = (div + (*first)->data) % 10;
        div = (div + (*first)->data) / 10;
        insertAtEnd(&result, mod);
        deleteFromBeginning(first);
    }
    while (!isEmpty(*second)) {
        mod = (div + (*second)->data) % 10;
        div = (div + (*second)->data) / 10;
        insertAtEnd(&result, mod);
        deleteFromBeginning(second);
    }
    if (div != 0) {
        insertAtEnd(&result, div);
    }
    *first = NULL;
    *second = NULL;
    return result;
}

int convertListNumber(Node *node) {
    int sum = 0, p = 1;
    Node *temp = node;
    while (temp != NULL) {
        sum = p * temp->data + sum;
        p *= 10;
        temp = temp->next;
    }
    return sum;
}

void addZeros(Node *node) {
    Node *temp = node;
    while (temp != NULL){
        if(temp->data % 2 == 0){
            insertAfter(temp,0);
            temp = temp->next;
        }
        temp = temp->next;
    }
}

void deleteDigit(Node **node, int digit) {
    while (searchNode(*node,digit)){
        deleteNode(node,digit);
    }
}
