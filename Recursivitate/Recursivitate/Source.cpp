#include <stdio.h>
int inversare_numar(int numar, int* vector, int* i) {
    if (numar == 0) {
        return *i;
    }
    vector[*i] = numar % 10;
    (*i)++;
    return inversare_numar(numar / 10, vector, i);
}

int main() {
    int numar;
    int vector[10];
    int i = 0;
    scanf("%d", &numar);
    int lungime = inversare_numar(numar, vector, &i);
    for (int j = 0; j < lungime; j++) {
        printf("%d", vector[j]);
    }
    return 0;
}
