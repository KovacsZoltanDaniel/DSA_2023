#include "bs_tree.h"

int main() {
    int n, m;
    Node *root1 = NULL, *root2 = NULL;
    if (!freopen("Acsoport.txt", "r", stdin)) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        Person person;
        scanf("%[^\n]\n", person.nume);
        scanf("%lf%lf%i\n", &person.parc_atlag, &person.teszt_atlag, &person.gender);
        root1 = insert(root1, person);
    }
    freopen("CON", "r", stdin);
    if (!freopen("Bcsoport.txt", "r", stdin)) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    scanf("%d\n", &m);
    for (int i = 0; i < m; i++) {
        Person person;
        scanf("%[^\n]\n", person.nume);
        scanf("%lf%lf%i\n", &person.parc_atlag, &person.teszt_atlag, &person.gender);
        root2 = insert(root2, person);
    }
    freopen("CON", "r", stdin);
    printf("\nAz 'A' csoport diakjai novekvo sorrenben: \n");
    inorderTraversal(root1);
    printf("\nA 'B' csoport diakjai novekvo sorrenben: \n");
    inorderTraversal(root2);

    return 0;
}
