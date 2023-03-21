//
// Created by Dani on 2023. 03. 21..
//

#include "../headers/patient.h"

void printPatient(Patient patient) {
    printf(" %s\n", patient.nev);
    printf("\tCNP: %s\n", patient.CNP);
    printf("\tDate of birth: %i/%i/%i\n", patient.birthDate.year, patient.birthDate.month,patient.birthDate.day);
    printf("\tIllness: %s\n", getBetegseg(patient.betegsegek));
}

void readPatientDetails(Patient *patient) {
    scanf("\n%[^\n]\n", patient->nev);
    scanf("%s", patient->CNP);
    scanf("%i%i%i", &patient->birthDate.year, &patient->birthDate.month, &patient->birthDate.day);
    scanf("%i", &patient->betegsegek);
}

char *getBetegseg(enum Betegsegek betegsegek) {
    switch (betegsegek) {
        case 0 : {
            return "INFLUENZA";
        }
        case 1 : {
            return "DIABETES";
        }
        case 2 : {
            return "CANCER";
        }
        case 3 : {
            return "HYPERTENSION";
        }
        case 4 : {
            return "ASTHMA";
        }
        case 5 : {
            return "HEPATITIS";
        }
        case 6 : {
            return "DEPRESSION";
        }
        case 7 : {
            return "MIGRAINES";
        }
        case 8 : {
            return "ANEMIA";
        }
        case 9 : {
            return "OBESITY";
        }
        case 10 : {
            return "ALLERGIES";
        }
        default:  {
            return "ERROR";
        }
    }
}
