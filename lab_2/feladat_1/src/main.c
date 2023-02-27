#include "functions.matrix.h"

int main() {

    //1 dimenzios tomb
    int *a;
    int x;
    printf("1 dimenzios tomb feladatok: \n");
    readArray(&x,&a,"data.in");
    printArray(x,a,"CON");
    //2
    printf("%i paros elem van\n", numberOfEvenNumbers(x,a));
    //3
    printf("a pozitiv szamok osszege: %i\n", sumOfPositiveNumbers(x,a));
    //4
    //deallocateMemoryForArray(x,&a);
    //matrix
    int **matrix, n, m;
    printf("matrix feladatok: \n");
    //6
    readMatrix(&n,&m,&matrix,"matrix.in");
    //7
    printMatrix(n,m,matrix,"CON");
    //8
    int row;
    printf("olvasd be a keresett sort: ");
    scanf("%i", &row);
    printf("a sor legkisebb eleme: %i\n", minimumValueOfRow(m,matrix[row -1]));
    //9
    for (int i = 0; i < n; ++i) {
        printf("a matrix %i soranak a minimuma: %i\n", i+1, rowMinimums(n,m,matrix)[i]);
    }
    //10
    printf("a matrix legkisebb eleme: %i\n", minimumValueOfMatrix(n,m,matrix));
    //11
    printf("a matrix eleminek atlaga: %.2f", averageOfMatrixElements(n,m,matrix));
    //12
    //deallocateMemoryForMatrix(n,&matrix);
    //Hazi feladat
    //1
    printf("\n\t\tHazi feladat:\n 1 dimenzios tomb feladatok:\n");
    printf(" a tomb atlaga: %.2f\n", average(x,a));
    //2
    printf("%i paros elem van\n", numberOfOddNumbers(x,a));
    //3
    printf("a negativ szamok szorzata: %i\n", productOfNegativeNumbers(x,a));
    printf("2 dimenzios tomb feladatok:\n");
    //4
    int index;
    printf("olvass be egy adott oszlopot: ");
    scanf("%i", &index);
    printf("a kivalasztott oszlop maximuma: %i\n", maximumValueOfColumn(n,index-1,matrix));
    //5
    for (int i = 0; i < m; ++i) {
        printf("a matrix %i oszlopanak a maximuma: %i\n", i+1,columnMaximums(n,m,matrix)[i]);
    }
    //6
    printf("a matrix legnagyobb eleme: %i\n", maximumValueOfMatrix(n,m,matrix));
    //7
    printf("a matrix elemeinek teljes osszege: %i", sumOfMatrixElements(n,m,matrix));
    deallocateMemoryForArray(x,&a);
    deallocateMemoryForMatrix(row,&matrix);
    return 0;
}
