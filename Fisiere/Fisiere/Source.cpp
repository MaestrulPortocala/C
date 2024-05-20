#include <stdio.h>
#include <string.h>
struct Disciplina {
    char denumire[100];
    int nota;
};
struct Student {
    char nume[30];
    char prenume[30];
    struct Disciplina d[10];
    float medie;
};
int main()
{
    struct Student vectorStud[30];
    FILE* f1 = fopen("Text.txt", "r");
    if (f1 == NULL) {
        printf("Eroare\n");
        return -1;
    }
    int n = 0;
    int i = 0;

    while (fscanf(f1, "%s", vectorStud[i].nume) != EOF) {
        fscanf(f1, "%s", vectorStud[i].prenume);
        while (n < 3) {
            fscanf(f1, "%s", vectorStud[i].d[n].denumire);
            fscanf(f1, "%d", &vectorStud[i].d[n].nota);
            n++;
        }
        i++;
        n = 0;
    }
    int suma[3];
    for (int j = 0; j < i; j++) {
        suma[j] = 0;
    }
    for (int j = 0; j < i; j++) {
        for (int k = 0; k < i; k++) {
            suma[j] = suma[j] + vectorStud[j].d[k].nota;
        }
    }
    for (int j = 0; j < i; j++) {
        vectorStud[j].medie = suma[j] / i;
    }
    float temp1;
    char temp[30];
    for (int j = 0; j < i - 1; j++) {
        for (int k = 0; k < i - j - 1; k++) {
            if (vectorStud[k].medie > vectorStud[k + 1].medie) {
                temp1 = vectorStud[k].medie;
                vectorStud[k].medie = vectorStud[k + 1].medie;
                vectorStud[k + 1].medie = temp1;
                strcpy(temp, vectorStud[k].nume);
                strcpy(vectorStud[k].nume, vectorStud[k + 1].nume);
                strcpy(vectorStud[k + 1].nume, temp);
                strcpy(temp, vectorStud[k].prenume);
                strcpy(vectorStud[k].prenume, vectorStud[k + 1].prenume);
                strcpy(vectorStud[k + 1].prenume, temp);
            }
        }
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%s ", vectorStud[j].nume);
        printf("%s ", vectorStud[j].prenume);
        printf("%f ", vectorStud[j].medie);
    }
    return 0;
}
/* datele care trebuie puse intr-un fisier text:
Ion Vasile Matematica 8 Istorie 10 Religie 9
Muica Cristi Matematica 6 Istorie 10 Religie 5
Herepean Vlad Matematica 5 Istorie 8 Religie 10*/
