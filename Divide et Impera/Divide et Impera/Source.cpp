#include<stdio.h>
#include<string.h>
int divide(char* prop, int st, int dr, int i, int* contor) {
    if (st == dr) {
        if (prop[st] == '.' || prop[st] == ',' || prop[st] == ';' || prop[st] == ':' || prop[st] == '?' || prop[st] == '!') {
            (*contor)++;
            return 0;
        }

    }
    else {
        int m = (st + dr) / 2;
        divide(prop, st, m, i, contor);
        divide(prop, m + 1, dr, i, contor);
    }
}
int main() {
    char prop[100];
    int i = 0;
    int contor = 0;
    fgets(prop, 100, stdin);
    divide(prop, 0, strlen(prop) - 1, i, &contor);
    printf("%d", contor);
}
