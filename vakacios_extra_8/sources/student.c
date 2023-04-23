//
// Created by kovac on 2023. 04. 22..
//

#include "../headers/student.h"

void createStudentsDate(int maxAdat, STUDENT *students) {
    students->maxAdat = maxAdat;
    students->size = 0;
    students->adatok = (student *) malloc(students->maxAdat * sizeof(student));
}

void printStudentsDate(STUDENT students) {
    printf("the birth date of the students:\n");
    for (int i = 0; i < students.size; ++i) {
        printf("%i/%i/%i\n", students.adatok->year, students.adatok->month, students.adatok->day);
    }
    printf("\n");
}

void readStudentsDate(STUDENT *students) {
    for (int i = 0; i < students->size; ++i) {
        scanf("%i%i%i", &students->adatok->year, &students->adatok->month, &students->adatok->day);
    }
}
