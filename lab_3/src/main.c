#include "functions.h"

int main() {
    Student_t student;
    if(!freopen("date.in", "r", stdin)){
        printf(FILE_OPEN_ERROR_MESSAGE);
        exit(FILE_OPEN_ERROR_CODE);
    }
    readStudentDetails(&student);
    printStudent(student);
    freopen("CON", "r", stdin);
    return 0;
}
