#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produs {
    unsigned short ID;
    char denumire[30];
    unsigned short cantitate;
    float pret;
};
int comparare(const void* a, const void* b) {
    const struct produs* p1 = (const struct produs*)a;
    const struct produs* p2 = (const struct produs*)b;
    return p1->pret - p2->pret;
}
int comparare1(const void* a, const void* b) {
    const struct produs* p1 = (const struct produs*)a;
    const struct produs* p2 = (const struct produs*)b;
    return p2->cantitate - p1->cantitate;
}
int main() {
    struct produs vprod[4];
    FILE* f1 = fopen("Text.txt", "r");
    if (f1 == NULL) {
        printf("Eroare\n");
        return -1;
    }
    int i = 0;
    while (fscanf(f1, "%hu %s %hu %f", &vprod[i].ID, vprod[i].denumire, &vprod[i].cantitate, &vprod[i].pret) != EOF) {
        i++;
    }
    qsort(vprod, i, sizeof(struct produs), comparare);
    for (int i = 0; i < 3; i++) {
        printf("%hu %s %hu %f", vprod[i].ID, vprod[i].denumire, vprod[i].cantitate, vprod[i].pret);
        printf("\n");
    }
    qsort(vprod, i, sizeof(struct produs), comparare1);

    for (int i = 0; i < 3; i++) {
        printf("%hu %s %hu %f", vprod[i].ID, vprod[i].denumire, vprod[i].cantitate, vprod[i].pret);
        printf("\n");
    }
    return 0;
}
