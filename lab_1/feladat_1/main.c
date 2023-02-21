#include <stdio.h>
void osszeg(int n, int m);

int main() {
    int n =12744, m = 10530;
    osszeg(n,m);
    return 0;
}

void osszeg(int n, int m) {
int osszeg ;
osszeg = n + m;
    printf("a ket szam osszeg: %i",osszeg);
}
