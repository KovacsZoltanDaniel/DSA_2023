#include "linkedd_list.h"

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
    while (number != 0) {
        int digit = number % 10;
        orderedList(&head, digit);
        number /= 10;
    }
    printf("\nRendezett lista: ");
    printList(head);
    return 0;
}
