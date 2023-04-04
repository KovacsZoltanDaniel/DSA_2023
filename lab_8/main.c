#include "linked.list.h"

int main() {
    int number1 = 234, number2 = 987;
    Node *head1 = NULL;
    Node *head2 = NULL;
    int next_number1;
    int next_number2;
    while (number1 > 0) {
        next_number1 = number1 % 10;
        insertAtEnd(&head1, next_number1);
        number1 /= 10;
    }
    while (number2 > 0) {
        next_number2 = number2 % 10;
        insertAtEnd(&head2, next_number2);
        number2 /= 10;
    }
    printList(head1);
    printf("\n");
    printList(head2);
    Node *sum = NULL;
    sum = newNode(head1->data + head2->data);
    int next;
    while (head1 != NULL || head2 != NULL){
        if(head1->data + head2->data > 9){
            next =head1->data + head2->data - 10;
        }
        else {
            next = 0;
        }
        insertAtEnd(&sum, (head1->data + head2->data + next) % 10);
        deleteFromBeginning(&head1);
        deleteFromBeginning(&head2);
    }
    printf("\n");
    printList(sum);
    return 0;
}
