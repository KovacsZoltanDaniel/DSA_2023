//
// Created by kovac on 2023. 04. 22..
//

#ifndef VAKACIOS_EXTRA_8_STUDENT_H
#define VAKACIOS_EXTRA_8_STUDENT_H
#include <stdio.h>
#include <stdlib.h>
#include <constant.h>
typedef struct {
    int year;
    int month;
    int day;
}student;
typedef struct {
    int maxAdat;
    int size;
    student *adatok;
} STUDENT;
void createStudentsDate(int maxAdat, STUDENT *students);
void readStudentsDate(STUDENT *students);
void printStudentsDate(STUDENT students);
#endif //VAKACIOS_EXTRA_8_STUDENT_H
