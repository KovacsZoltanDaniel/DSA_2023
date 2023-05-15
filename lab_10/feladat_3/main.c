#include "bst_person.h"

int main() {
    Node *root = NULL;
    int n;
    if(!freopen("person.txt", "r",stdin)){
        printf(FILE_OPENING_ERROR_MESSAGE);
        exit(FILE_OPENING_ERROR_CODE);
    }
    scanf("%i", &n);
    for (int i = 0; i < n; ++i) {
        Person x;
        scanf("%s%i%i%i%i", x.nev, &x.data.year, &x.data.month, &x.data.day, &x.gender);
        root = insert(root,x);
    }
    inorderTraversal(root);
    freopen("CON", "r", stdin);
    return 0;
}
