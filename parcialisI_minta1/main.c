#include "patient.h"

int main() {
    Patient patient1 = {"George Smith", "1978708261284",{1999,2,22},2};
    printPatient(patient1);
    Patient patient2;
    readPatientDetails(&patient2);
    //printPatient(patient2);
    char x[20];
    strcpy(x,patient2.CNP);
    strcat(x,".txt");
    freopen(x,"w", stdout);
    printPatient(patient2);
    freopen("CON", "w", stdout);
    return 0;
}
