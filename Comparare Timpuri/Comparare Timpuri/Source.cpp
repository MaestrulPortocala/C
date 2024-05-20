#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int ordonare(const void* x, const  void* y) {
    return (*(int*)x - *(int*)y);
}
int main()
{
    srand(time(NULL));
    int valori_N[] = { 100, 1000, 10000, 100000 };
    for (int i = 0; i < 4; i++) {
        int N = valori_N[i];
        int* tablou = (int*)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            tablou[j] = rand() % 1000;
        }
        int valoare = tablou[rand() % N];
        printf("N=%d\n", N);
        printf("Cautare secventiala:\n");
        clock_t start = clock();
        for (int j = 0; j < N; j++) {
            if (tablou[j] == valoare) {
                break;
            }
        }
        clock_t end = clock();
        double timp_secvential = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Timpul este %lf\n", timp_secvential);
        printf("Cautare binara\n");
        qsort(tablou, N, sizeof(int), ordonare);
        start = clock();
        int stanga = 0;
        int dreapta = N;
        while (stanga < dreapta) {
            int mijloc = stanga + (dreapta - stanga) / 2;
            if (tablou[mijloc] == valoare) {
                break;
            }
            else if (tablou[mijloc] < valoare) {
                stanga = mijloc + 1;
            }
            else {
                dreapta = mijloc - 1;
            }
        }
        end = clock();
        double timp_binar = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Timpul este %lf\n", timp_binar);
        if (N == 100) {
            for (int j = 0; j < N; j++) {
                printf("%d ", tablou[j]);
            }
        }
    }
    return 0;
}
