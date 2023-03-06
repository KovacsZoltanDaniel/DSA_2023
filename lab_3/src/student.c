//
// Created by Dani on 2023. 02. 28..
//

#include "../headers/student.h"
//1 diak

void printStudent(Student_t student) {

    printf(" %s\n", student.name);
    printf("\tNeptun Code: %s\n", student.neptunCode);
    printf("\tBirth place: %s\n", student.birthPlace);
    printf("\tDate of birth: %i/%i/%i\n", student.birthDate.year, student.birthDate.month, student.birthDate.day);
    printf("\tGender: %s\n", getGender(student.gender));
    printf("\tExam result: %.2f\n", student.examResult);
}

void readStudentDetails(Student_t *pStudent) {
    scanf("%[^\n]", pStudent->name);
    scanf("%s\n", pStudent->neptunCode);
    scanf("%[^\n]", pStudent->birthPlace);
    scanf("%i%i%i", &pStudent->birthDate.year, &pStudent->birthDate.month, &pStudent->birthDate.day);
    scanf("%i", &pStudent->gender);
    scanf("%f\n", &pStudent->examResult);
}

char *getGender(enum Gender gender) {
    switch (gender) {
        case 0 : {
            return "FEMALE";
        }
        case 1 : {
            return "MALE";
        }
        default: {
            "ERROR";
        }
    }
}

//2diak
void allocateMemoryForStudents(Student_t **dpStudents, int numberOfStudents) {
    *dpStudents = (Student_t *) malloc(numberOfStudents * sizeof(Student_t));
    if (!(*dpStudents)) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}

void readAllStudentsDetails(Student_t **dpStudents, int *numberOfStudents, const char *input) {
    if (!freopen(input, "r", stdin)) {
        printf(FILE_OPENING_ERROR_MESSAGE);
        exit(FILE_OPENING_ERROR_CODE);
    }
    scanf("%i\n", numberOfStudents);
    allocateMemoryForStudents(dpStudents, *numberOfStudents);
    for (int i = 0; i < *numberOfStudents; ++i) {
        readStudentDetails((*dpStudents) + i);
    }
    freopen("CON", "r", stdin);
}

void printAllStudents(Student_t *pStudents, int numberOfStudents, const char *destination) {
    freopen(destination, "w", stdout);
    for (int i = 0; i < numberOfStudents; ++i) {
        printStudent(pStudents[i]);
    }
    freopen("CON", "w", stdout);
}

int getNumberOfStudentsByGender(Student_t *pStudents, int numberOfStudents, enum Gender gender) {
    int db = 0;
    for (int i = 0; i < numberOfStudents; ++i) {
        if (pStudents[i].gender == gender) {
            db++;
        }
    }
    return db;
}

void printStudentsFromSpecificCity(Student_t *pStudents, int numberOfStudents, const char *city) {
    for (int i = 0; i < numberOfStudents; ++i) {
        if (strcmp(pStudents[i].birthPlace, city) == 0) {
            printStudent(pStudents[i]);
        }
    }
}

void *findStudentByNeptunCode(Student_t *pStudents, int numberOfStudents, const char *neptunCode) {
    for (int i = 0; i < numberOfStudents; ++i) {
        if (strcmp(pStudents[i].neptunCode, neptunCode) == 0) {
            return pStudents + i;
        }
    }
    return NULL;
}

int ABCcmp(const void *a, const void *b) {
    Student_t *p1 = (Student_t *) a;
    Student_t *p2 = (Student_t *) b;
    return strcmp(p1->name, p2->name);
}

void sortStudentsByName(Student_t *pStudents, int numberOfStudents) {
    qsort(pStudents, numberOfStudents, sizeof(Student_t), ABCcmp);
}

void sortStudentsByAgeAndExam(Student_t *pStudents, int numberOfStudents) {
    qsort(pStudents, numberOfStudents, sizeof(Student_t), compareByAgeAndExam);
}

int compareByAge(const void *a, const void *b) {
    Student_t *p1 = (Student_t *) a;
    Student_t *p2 = (Student_t *) b;
    if (p1->birthDate.year == p2->birthDate.year) {
        if (p1->birthDate.month == p2->birthDate.month) {
            return p1->birthDate.day - p2->birthDate.day;
        }
    }
    return p1->birthDate.year - p2->birthDate.year;
}

int compareByExam(const void *a, const void *b) {
    Student_t *p1 = (Student_t *) a;
    Student_t *p2 = (Student_t *) b;
    if (p1->examResult > p2->examResult) {
        return -1;
    } else if (p1->examResult < p2->examResult) {
        return 1;
    }
    return 0;
}

int compareByAgeAndExam(const void *a, const void *b) {
    int result = compareByAge(a, b);
    if (result == 0) {
        return compareByExam(a, b);
    }
    return result;
}


