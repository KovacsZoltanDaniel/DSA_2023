//
// Created by Dani on 2023. 03. 21..
//

#ifndef PARCIALISI_MINTA1_MEDICALCENTER_H
#define PARCIALISI_MINTA1_MEDICALCENTER_H
#include <patient.h>

typedef struct {
    int capacity;
    int front;
    int rear;
    Patient *patient;
}MedicalCenter;

void createQueuecircular(int capacity, MedicalCenter *queue);
void destroyQueuecircular(MedicalCenter *queue);
bool isFull(MedicalCenter queue);
bool isEmpty(MedicalCenter queue);

#endif //PARCIALISI_MINTA1_MEDICALCENTER_H
