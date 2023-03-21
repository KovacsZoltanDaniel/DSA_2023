//
// Created by Dani on 2023. 03. 21..
//

#ifndef PARCIALISI_MINTA1_PATIENT_H
#define PARCIALISI_MINTA1_PATIENT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <constant.h>

enum Betegsegek { INFLUENZA, DIABETES, CANCER,
    HYPERTENSION, ASTHMA, HEPATITIS, DEPRESSION, MIGRAINES,
    ANEMIA, OBESITY, ALLERGIES };
typedef struct {
    int year;
    int month;
    int day;
}Date_t;
typedef struct {
    char nev[40];
    char CNP[14];
    Date_t birthDate;
    enum Betegsegek betegsegek;
}Patient;
void printPatient(Patient patient);
void readPatientDetails(Patient *patient);
char *getBetegseg(enum Betegsegek betegsegek);
#endif //PARCIALISI_MINTA1_PATIENT_H
