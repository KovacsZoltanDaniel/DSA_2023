#include "patient.h"
#include "medicalCenter.h"

void firstExercise();

void secondExercise();


int main() {
    //firstExercise();
    secondExercise();

    return 0;
}

void firstExercise() {
    Patient patient1 = {"George Smith", "1978708261284", {1999, 2, 22}, INFLUENZA};
    printPatient(patient1);
    Patient patient2;
    readPatientDetails(&patient2);
    //printPatient(patient2);
    char x[20];
    strcpy(x, patient2.CNP);
    strcat(x, ".txt");
    freopen(x, "w", stdout);
    printPatient(patient2);
    freopen("CON", "w", stdout);
}

void secondExercise() {
    int capacity, counter = 0, noPatients = 0, old = 0, k=0,db=0;
    printf("capacity: ");
    scanf("%i", &capacity);
    MedicalCenter medicalCenter;
    createMedicalCenter(capacity, &medicalCenter);
    srand(time(0));
    display(medicalCenter);
    if(!freopen("input.txt", "r", stdin)){
        printf(FILE_OPENING_ERROR_MESSAGE);
        exit(FILE_OPENING_ERROR_CODE);
    }
    for (int i = 0; i < capacity * 5; ++i) {
        int option = rand()%2;
        switch (option) {
            case 0 : {
                if(!isFull(medicalCenter)){
                    //beolvasas
                    Patient patient;
                    readPatientDetails(&patient);
                    //varakozas
                    enqueue(&medicalCenter, patient);
                    printf("the following patient joined the queue: ");
                    printf("%s\n",patient.nev);
                    if(2023- patient.birthDate.year >= 50){
                        old ++;
                    }
                    if(patient.betegsegek == DIABETES){
                        printf("%s with diabetes\n", patient.nev);
                        k++;
                    }
                }
                else {
                    counter++;
                }
                break;
            }
            case 1 : {
                if(!isEmpty(medicalCenter)){
                   Patient patient = dequeue(&medicalCenter);
                    printf("the following patient can go home: ");
                    printf("%s\n",patient.nev);
                    db++;
                }
                else {
                    noPatients++;
                }
                break;
            }
            default:
                printf("Invalid option");
        }
        /*if(i % 3 == 0){
            display(medicalCenter);
        }*/
    }
    printf("\n\nStill waiting:.....\n");
    freopen("CON", "r", stdin);
    display(medicalCenter);
    printf("number of cases when there was no room: %i\n",counter);
    printf("number of cases when there was no patients: %i\n",noPatients);
    printf("add a cnp number: ");
    char cnp[14];
    scanf("%s", cnp);
    int pos = findPatient(medicalCenter,cnp);
    if(pos != -1){
        printf("The patient is still waiting\n");
    }
    else {
        printf("There is no patient with tis cnp\n");
    }
    printf("older than 50: %i\n", old);
    printf("%i diabetes\n", k);
    if(isEmpty(medicalCenter)){
        printf("ok");
    }
    else {
        printf("nook");
    }
    /*while ( !isEmpty(medicalCenter)){
        dequeue(&medicalCenter);
        db++;
    }
    printf("%i ossz\n",db);*/
    destroyMedicalCenter(&medicalCenter);
}
