#include "linkedd_list.h"

Node * createList(int number);
int concatenateDigits(Node *head, int order);

int main() {
    int num = 437;
    Node *head = NULL;
    while (num != 0) {
        int digit = num % 10;
        insertAtEnd(&head, digit);
        num /= 10;
    }
    printf("A lista elemei: ");
    printList(head);

    int smallest = concatenateDigits(head, 1); // legkisebb szám
    int largest = concatenateDigits(head, 2); // legnagyobb szám

    printf("A legkisebb szam: %d\n", smallest);
    printf("A legnagyobb szam: %d\n", largest);

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
    while (number != 0){
        orderedList(&head, number % 10);
        number /= 10;
    }
    return head;
}

int concatenateDigits(Node *head, int order) {
    int number = 0;
    Node *current = head;
    while (current != NULL) {
        number = number * 10 + current->data;
        current = current->next;
    }
    if (order == 1) { // növekvő sorrendben
        return number;
    } else { // csökkenő sorrendben
        int reversedNumber = 0;
        while (number != 0) {
            int digit = number % 10;
            reversedNumber = reversedNumber * 10 + digit;
            number /= 10;
        }
        return reversedNumber;
    }
}
