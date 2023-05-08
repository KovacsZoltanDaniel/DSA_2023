#include "linkedd_list.h"

Node * createList(int number);

int main() {
    Node *head = NULL;
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
    number = 2345234;
    head = NULL;
    head = createList(number);
    printf("\nRendezett lista: ");
    printList(head);
    return 0;
}
Node *createList(int number) {
    Node *head = NULL;
    while (number != 0){
        orderedList(&head, number % 10);
        number /= 10;
    }
    return head;
}