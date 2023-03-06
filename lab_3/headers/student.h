//
// Created by Dani on 2023. 02. 28..
//

#ifndef LAB_3_STUDENT_H
#define LAB_3_STUDENT_H
#include <constant.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 enum Gender{FEMALE, MALE};
typedef  struct {
    int year;
    int month;
    int day;
}Date_t;
typedef struct Student_t{
    char name[50];
    char neptunCode[8];
    char birthPlace[25];
    Date_t birthDate;
    enum Gender gender;
    float examResult;
}Student_t;
void printStudent(Student_t student);
void readStudentDetails(Student_t *pStudent);
char * getGender(enum Gender gender);
void allocateMemoryForStudents(Student_t **dpStudents, int numberOfStudents);
void readAllStudentsDetails(Student_t **dpStudents, int *numberOfStudents, const char *input);
void printAllStudents(Student_t *pStudents, int numberOfStudents, const char *destination);
int getNumberOfStudentsByGender(Student_t *pStudents, int numberOfStudents, enum Gender gender);
void printStudentsFromSpecificCity(Student_t *pStudents, int numberOfStudents, const char *city);
void* findStudentByNeptunCode(Student_t *pStudents, int numberOfStudents, const char* neptunCode);
void sortStudentsByName(Student_t *pStudents, int numberOfStudents);
int ABCcmp(const void *a, const void *b);
int compareByAgeAndExam(const void *a, const void *b);
void sortStudentsByAgeAndExam(Student_t *pStudents, int numberOfStudents);

#endif //LAB_3_STUDENT_H
