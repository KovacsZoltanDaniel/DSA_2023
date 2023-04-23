#include "student.h"

int main() {
    STUDENT student;
    int n;
    if (!freopen("datumok.txt", "r", stdin)) {
        printf(FILE_OPENING_ERROR_MESSAGE);
        exit(FILE_OPENING_ERROR_CODE);
    }
    scanf("%i", &n);
    createStudentsDate(n, &student);
    readStudentsDate(&student);
    printStudentsDate(student);
    freopen("CON", "r", stdin);
    return 0;
}