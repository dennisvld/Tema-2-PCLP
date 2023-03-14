#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

int Awords(char *cuv) {
    int l = strlen(cuv);
    int cifra;
    int i;
    int max = cuv[1] - '0';
    int poz = 1;
    for (i = 2; i < l; i++) {
        cifra = cuv[i] - '0';
        if (cifra > max) {
            max = cifra;
            poz = i;
            }
            }
    return poz;
    }

char Bwords(char *cuv) {
    int l = strlen(cuv);
    int i, pal = 1, prim = 1;
    char rez;
    for (i = 1; i <= l / 2; i++) {
        if (cuv[i] - '0' != cuv[l - i] - '0') {
            pal = 0;
            break;
        }
    }
    int x = (cuv[l - 2] - '0') * 10 + (cuv[l - 1] - '0');
    for (i = 2; i < x / 2; i++) {
        if (x % i == 0) {
            prim = 0;
            break;
        }
    }
    if (pal == 1) {
        if (prim == 1) {
            rez = 'l';
        } else {
            rez = 'r';
        }
    } else {
        if (prim == 1) {
            rez = 'u';
        } else
            rez = 'd';
    }
    return rez;
}

int Cwords(char *cuv) {
    int l = strlen(cuv);
    int n = cuv[1] - '0';
    int i, s = 0, poz = 3;
    int k = cuv[2] - '0';
    for (i = 0; i < k; i++) {
        s = s + (cuv[poz] - '0');
        poz = poz + k;
        if (poz - 3 >= n) {
            poz = poz - 3;
            poz = poz % n;
            poz = poz + 3;
        }
    }
    return s % 4;
}

void SolveTask1() {
    int n, m, i, j;
    scanf("%d%d", &n, &m);
    char *cuv;
    char *linie;
    int rez, pas = 1;
    char rezb;
    int drum[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            drum[i][j] = 0;
        }
    }
    drum[0][0] = 1;
    pas++;
    linie = (char *)malloc(300 * sizeof(char));
    gets(linie);
    gets(linie);
    cuv = strtok(linie, " \n");
    i = 0;
    j = 0;
    while (cuv != NULL) {
        if (cuv[0] == 'a') {
            rez = Awords(cuv);
            if (rez == 1) {
                j++;
                drum[i][j] = pas;
                pas++;
            }
            if (rez == 2) {
                i--;
                drum[i][j] = pas;
                pas++;
            }
            if (rez == 3) {
                j--;
                drum[i][j] = pas;
                pas++;
            }
            if (rez == 4) {
                i++;
                drum[i][j] = pas;
                pas++;
            }
        }
        if (cuv[0] == 'b') {
            rezb = Bwords(cuv);
            if (rezb == 'r') {
                j++;
                drum[i][j] = pas;
                pas++;
            }
            if (rezb == 'u') {
                i--;
                drum[i][j] = pas;
                pas++;
            }
            if (rezb == 'l') {
                j--;
                drum[i][j] = pas;
                pas++;
            }
            if (rezb == 'd') {
                i++;
                drum[i][j] = pas;
                pas++;
            }
        }
        if (cuv[0] == 'c') {
            rez = Cwords(cuv);
            if (rez == 2) {
                j++;
                drum[i][j] = pas;
                pas++;
            }
            if (rez == 1) {
                i--;
                drum[i][j] = pas;
                pas++;
            }
            if (rez == 0) {
                j--;
                drum[i][j] = pas;
                pas++;
            }
            if (rez == 3) {
                i++;
                drum[i][j] = pas;
                pas++;
            }
        }
        cuv = strtok(NULL, " ,\n");
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", drum[i][j]);
        }
        printf("\n");
    }
}
