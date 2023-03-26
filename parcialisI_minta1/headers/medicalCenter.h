//
// Created by Dani on 2023. 03. 21..
//

#ifndef PARCIALISI_MINTA1_MEDICALCENTER_H
#define PARCIALISI_MINTA1_MEDICALCENTER_H
#include <patient.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
    int capacity;
    int front;
    int rear;
    Patient *patient;
}MedicalCenter;

void createMedicalCenter(int capacity, MedicalCenter *medicalCenter);
void destroyMedicalCenter(MedicalCenter *medicalCenter);
bool isFull(MedicalCenter medicalCenter);
bool isEmpty(MedicalCenter medicalCenter);
void enqueue(MedicalCenter *medicalCenter, Patient newPatient);
Patient dequeue(MedicalCenter *medicalCenter);
void display(MedicalCenter medicalCenter);
int findPatient(MedicalCenter medicalCenter, char *cnp);

#endif //PARCIALISI_MINTA1_MEDICALCENTER_H
