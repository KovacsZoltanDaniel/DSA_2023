//
// Created by Dani on 2023. 02. 28..
//

#include "../headers/functions.h"

void readStudentDetails(Student_t *pStudent) {
    scanf("%[^\n]\n",pStudent->name);
    scanf("\n%s",pStudent->neptunCode);
    scanf("\n%s\n",pStudent->birthPlace);
    scanf("%i%i%i", &pStudent->Date_t.year, &pStudent->Date_t.month, &pStudent->Date_t.day);
    scanf("%i",&pStudent->Gender);
    scanf("%f", &pStudent->examResult);
}

void printStudent(Student_t student) {
    printf("Name: %s\n", student.name);
    printf("Neptun Code: %s\n", student.neptunCode);
    printf("Birth place: %s\n", student.birthPlace);
    printf("Date: %i/%i/%i\n", student.Date_t.year,student.Date_t.month,student.Date_t.day);
    printf("Gender: %s\n", getGender(student.Gender));
    printf("Exam result: %.2f\n", student.examResult);
}

char *getGender(enum Gender gender) {
    switch (gender) {
        case 0 : {
            return "MALE";
        }
        case 1 : {
            return "FEMALE";
        }
        default: {
            "ERROR";
        }
    }
    return NULL;
}
