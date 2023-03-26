//
// Created by Dani on 2023. 03. 21..
//

#include "../headers/patient.h"

void printPatient(Patient patient) {
    printf(" %s\n", patient.nev);
    printf("\tCNP: %s\n", patient.CNP);
    printf("\tIllness: %s\n", getBetegseg(patient.betegsegek));
    printf("\tDate of birth: %i/%i/%i\n", patient.birthDate.day, patient.birthDate.month,patient.birthDate.year);
}

void readPatientDetails(Patient *patient) {
    scanf("\n%[^\n]", patient->nev);
    scanf("%s", patient->CNP);
    char disease[20];
    scanf("%s", disease);
    patient->betegsegek = getDiseaseByChar(disease);
    scanf("%d%d%d", &patient->birthDate.day, &patient->birthDate.month, &patient->birthDate.year);

}

char *getBetegseg(enum Betegsegek betegsegek) {
    switch (betegsegek) {
        case INFLUENZA : {
            return "INFLUENZA";
        }
        case DIABETES : {
            return "DIABETES";
        }
        case CANCER : {
            return "CANCER";
        }
        case HYPERTENSION : {
            return "HYPERTENSION";
        }
        case ASTHMA : {
            return "ASTHMA";
        }
        case HEPATITIS : {
            return "HEPATITIS";
        }
        case DEPRESSION : {
            return "DEPRESSION";
        }
        case MIGRAINES : {
            return "MIGRAINES";
        }
        case ANEMIA : {
            return "ANEMIA";
        }
        case OBESITY : {
            return "OBESITY";
        }
        case ALLERGIES : {
            return "ALLERGIES";
        }
        default:  {
            return "ERROR";
        }
    }
}

enum Betegsegek getDiseaseByChar(char *disease) {
    for (int i = 0; i < 11; ++i) {
        if(strcmp(getBetegseg(i),disease) == 0) {
            return i;
        }
    }
    return 0;
}
