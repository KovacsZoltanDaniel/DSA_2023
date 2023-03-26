//
// Created by Dani on 2023. 03. 21..
//

#include "medicalCenter.h"

void createMedicalCenter(int capacity, MedicalCenter *medicalCenter) {
    medicalCenter->capacity = capacity;
    medicalCenter->front = medicalCenter->rear = -1;
    medicalCenter->patient = (Patient *) calloc(medicalCenter->capacity, sizeof(Patient));
    if (!medicalCenter->patient) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}

void destroyMedicalCenter(MedicalCenter *medicalCenter) {
    medicalCenter->front = medicalCenter->rear = -1;
    free(medicalCenter->patient);
    medicalCenter->capacity = 0;
    medicalCenter = NULL;
}

bool isFull(MedicalCenter medicalCenter) {
    return medicalCenter.front == 0 && medicalCenter.rear == medicalCenter.capacity - 1 || medicalCenter.rear == medicalCenter.front - 1;
}//ha a sor tele van front = 0 rear =cap-1 vagy ha a rear utolerte a frontot tehat rear=front-1

bool isEmpty(MedicalCenter medicalCenter) {
    return medicalCenter.front == -1;
}

void enqueue(MedicalCenter *medicalCenter, Patient newPatient ) {
    if (isFull(*medicalCenter)) {
        printf(FULL_MESSAGE);
        return;
    }
    if (isEmpty(*medicalCenter)) {
        medicalCenter->front = 0;
    }//hogyha ures sorba szurjuk be a legelso elemet akkor a front 0 kell legyen
    medicalCenter->rear = (medicalCenter->rear + 1) % medicalCenter->capacity;
    medicalCenter->patient[medicalCenter->rear] = newPatient;
}

Patient dequeue(MedicalCenter *medicalCenter) {
    Patient save = medicalCenter->patient[medicalCenter->front];
    if(medicalCenter->front == medicalCenter->rear){
        medicalCenter->front = medicalCenter->rear = -1; //ha kiveszem az utolso elemet akkor -1 kell legyen mind2
    }
    else{
        medicalCenter->front = (medicalCenter->front +1) % medicalCenter->capacity;
    }
    return save; //hogy melyiket toroltuk
}

void display(MedicalCenter medicalCenter) {
    if(isEmpty(medicalCenter)){
        printf("there is no one in the medical center!\n");
        return;
    }
    printf("the patients: \n");
    int i = medicalCenter.front;
    if(i != medicalCenter.rear) {
        do {
            printPatient(medicalCenter.patient[i]);
            i = (i + 1) % medicalCenter.capacity;
        } while (i != medicalCenter.rear);
    }
        printPatient(medicalCenter.patient[i]);
    printf("\n");
}

int findPatient(MedicalCenter medicalCenter, char *cnp) {
    if(isEmpty(medicalCenter)){
        printf(EMPTY_MESSAGE);
        return -1;
    }
    int i = medicalCenter.front;
    if(i != medicalCenter.rear) {
        do {
            if(strcmp(medicalCenter.patient[i].CNP, cnp) == 0){
                return i;
            }
            i = (i + 1) % medicalCenter.capacity;
        } while (i != medicalCenter.rear);
        if(strcmp(medicalCenter.patient->CNP, cnp) == 0){
            return i;
        }
    }
    return -1;
}
