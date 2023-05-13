#include "bst_person.h"
int main() {
    freopen("A_csoport.txt", "r", stdin);
    int n,m;
    Person person;
    Node *root1 = NULL, *root2 = NULL;
    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%[^\n]\n", person.nev);
        scanf("%f%f\n", &person.parc_atlag, &person.teszt_atlag);
        root1 = insert(root1,person);
    }
    freopen("B_csoport.txt", "r", stdin);
    scanf("%d\n", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%[^\n]\n", person.nev);
        scanf("%f%f\n", &person.parc_atlag, &person.teszt_atlag);
        root2 = insert(root2,person);
    }
    printf("Az A csoport diakjai atlag szerint csokkeno sorrendbe: \n");
    inorderTraversal(root1);
    printf("A B csoport diakjai atlag szerint csokkeno sorrendbe: \n");
    inorderTraversal(root2);
    freopen("CON", "r", stdin);
    return 0;
}
