//
// Created by Dani on 2023. 02. 28..
//

#ifndef LAB_3_FUNCTIONS_H
#define LAB_3_FUNCTIONS_H
#include <constant.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Student_t{
    char name[50];
    char neptunCode[8];
    char birthPlace[25];
    struct Date_t{
        int year, month, day;
    }Date_t;
    enum Gender{
    MALE,
    FEMALE,
    }Gender;
    float examResult;
}Student_t;
void readStudentDetails(Student_t *pStudent);
void printStudent(Student_t student);
char * getGender(enum Gender gender);
#endif //LAB_3_FUNCTIONS_H
