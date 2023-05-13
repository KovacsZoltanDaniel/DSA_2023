#include "linkedd_list.h"

Node *createList(int number);

int convertListNumber(Node *node);

int reversed(int number);

int main() {
    Node *head = NULL;
    freeList(&head);
    int number;
    scanf("%i", &number);
    while (number != 0) {
        int digit = number % 10;
        insertAtEnd(&head, digit);
        number /= 10;
    }
    printf("\nRendezes elott: ");
    printList(head);
    printf("\nRendezes utan: ");
    sortLinkedList(head);
    printList(head);
    int result = convertListNumber(head);
    printf("\na legnagyobb szam: %i", result);
    int result2 = reversed(result);
    printf("\na legkisebb szam: %i",result2);
    number = 2345234;
    freeList(&head);
    head = createList(number);
    printf("\nRendezett lista: ");
    printList(head);
    freeList(&head);
    return 0;
}

Node *createList(int number) {
    Node *head = NULL;
    while (number != 0) {
        orderedList(&head, number % 10);
        number /= 10;
    }
    return head;
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

int reversed(int number) {
    int rev = 0;
    while (number > 0) {
        rev = rev * 10 + number % 10;
        number = number / 10;
    }
    return rev;
}

