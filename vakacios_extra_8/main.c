#include "student.h"

int main() {
    STUDENT student;
    int  maxAdat = 10;
    if (!freopen("datumok.txt", "r", stdin)) {
        printf("FILE_OPENING_ERROR_MESSAGE");
        exit("FILE_OPENING_ERROR_CODE");
    }
    createStudentsDate(maxAdat, &student);
    printStudentsDate(student);
    while (!isFulll(student)) {
        readStudentsDate(&student);
    }
    printStudentsDate(student);
    printAdultStudentsCount(student);
    freopen("CON", "r", stdin);
    destroyStudents(&student);
    return 0;
}