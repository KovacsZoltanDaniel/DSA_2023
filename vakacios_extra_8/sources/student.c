//
// Created by kovac on 2023. 04. 22..
//

#include "../headers/student.h"

void createStudentsDate(int maxAdat, STUDENT *students) {
    students->maxAdat = maxAdat;
    students->size = 0;
    students->adatok = (student *) malloc(students->maxAdat * sizeof(student));
    if(!students->adatok){
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}

void printStudentsDate(STUDENT students) {
    if(isEmptyy(students)){
        printf(EMPTY_MESSAGE);
        printf("\n");
        return;
    }
    printf("the birth date of the students:\n");
    for (int i = 0; i < students.size; ++i) {
        printf("%i/%i/%i\n", students.adatok[i].year, students.adatok[i].month, students.adatok[i].day);
    }
    printf("\n");
    printf("%i", students.size);
}

void readStudentsDate( STUDENT *students) {
    scanf("%i%i%i", &students->adatok[students->size].year, &students->adatok[students->size].month, &students->adatok[students->size].day);
    students->size++;
}

bool isFulll(STUDENT students) {
    return students.size == students.maxAdat;
}

bool isEmptyy(STUDENT students) {
    return students.size == 0;
}

void printAdultStudentsCount(STUDENT students) {
    int count = 0;
    for (int i = 0; i < students.size; ++i) {
        if (isEighteenOrAbove(students.adatok[i], 2022, 4, 29)) {
            count++;
        }
    }
    printf("\nA diakok szama akik betoltottek a 18-at ekkor: 2022.04.29: %d\n", count);
}
bool isEighteenOrAbove(student x, int year, int month, int day) {
    if (year - x.year > 18) {
        return true;
    } else if (year - x.year == 18) {
        if (month > x.month) {
            return true;
        } else if (month == x.month) {
            if (day >= x.day) {
                return true;
            }
        }
    }
    return false;
}

void destroyStudents(STUDENT *students) {
    students->size = students->maxAdat = 0;
    free(students->adatok);
    students->adatok = NULL;
}
