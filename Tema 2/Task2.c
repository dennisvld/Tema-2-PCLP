#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#define MAXSIZE 1001
char *Caesar(int *cheie) {
    int copie = 0;
    char *linie = NULL;
    int l = 0, i = 0;
    linie = (char *)calloc(MAXSIZE, sizeof(char));
    gets(linie);
    l = strlen(linie);
    for (i = 0; i < l; i++) {
        if (linie[i] >= 48 && linie[i] <= 57) {
            copie = *cheie;
            while (copie > 10) {
                copie = copie - 10;
            }
            if (linie[i] - copie < 48) {
                linie[i] = linie[i] + 10 - copie;
            } else {
                linie[i] = linie[i] - copie;
            }
        }
        if (linie[i] >= 65 && linie[i] <= 90) {
            copie = *cheie;
            while (copie > 26) {
                copie = copie - 26;
            }
            if (linie[i] - copie < 65) {
                linie[i] = linie[i] + 26 - copie;
            } else {
                linie[i] = linie[i] - copie;
            }
        }
        if (linie[i] >= 97 && linie[i] <= 122) {
            copie = *cheie;
            while (copie > 26) {
                copie = copie - 26;
            }
            if (linie[i] - copie < 97) {
               linie[i] = linie[i] + 26 - copie;
            } else {
                linie[i] = linie[i] - copie;
            }
        }
    }
    return linie;
}

void Vigenere() {
    char *linie = NULL;
    int l = 0, s = 0, i = 0, poz = 0;
    int copie = 0;
    int *cheie = (int *)malloc(11 * sizeof(int));
    linie = (char *)malloc(11 * sizeof(char));
    gets(linie);
    l = strlen(linie);
    for (i = 0; i < l; i++) {
        cheie[i] = linie[i] - 'A';
    }
    free(linie);
    linie = (char *)malloc(MAXSIZE * sizeof(char));
    gets(linie);
    s = strlen(linie);
    poz = 0;
    for (i = 0; i < s; i++) {
        if (linie[i] >= 65 && linie[i] <= 90) {
            if (linie[i] - cheie[poz] < 65) {
                linie[i] = linie[i] - cheie[poz] + 26;
            } else {
                linie[i] = linie[i] - cheie[poz];
            }
        }
        if (linie[i] >= 97 && linie[i] <= 122) {
            if (linie[i] - cheie[poz] < 97) {
                linie[i] = linie[i] - cheie[poz] + 26;
            } else {
                linie[i] = linie[i] - cheie[poz];
            }
        }
        if (linie[i] >= 48 && linie[i] <= 57) {
            copie = cheie[poz];
            while (copie > 10) {
                copie = copie - 10;
            }
            if (linie[i] - copie < 48) {
                linie[i] = linie[i] - copie + 10;
            } else {
                linie[i] = linie[i] - copie;
            }
        }
        if (poz != l - 1) {
            poz++;
        } else {
            poz = 0;
        }
    }
    printf("%s\n", linie);
}

void Addition() {
    int cheie = 0, lnr1 = 0, lnr2 = 0;
    int i = 0, poz = 0, cifra1 = 0, cifra2 = 0;
    int sum = 0, rest = 0, j = 0, p = 0;
    char *nr1 = NULL, *nr2 = NULL, *revsum = NULL, *linie = NULL;
    revsum = (char *)malloc(MAXSIZE* sizeof(char));
    linie = (char *)malloc(MAXSIZE * sizeof(char));
    poz = 0;
    scanf("%d", &cheie);
    gets(linie);
    nr1 = Caesar(&cheie);
    nr2 = Caesar(&cheie);
    lnr1 = strlen(nr1);
    lnr2 = strlen(nr2);
    rest = 0;
    if (lnr1 > lnr2) {
        i = lnr1 - 1;
        p = lnr1 - 1;
        while (i != lnr2 - 1) {
            i--;
        }
        for (j = i; j >= 0; j--) {
            cifra1 = nr1[p] - '0';
            p--;
            cifra2 = nr2[j] - '0';
            sum = rest + cifra1 + cifra2;
            rest = 0;
            if (sum > 9) {
                rest = 1;
                revsum[poz] = sum % 10 + '0';
                poz++;
            } else {
                revsum[poz] = sum + '0';
                poz++;
            }
        }
            while (p != -1 && rest == 1) {
                cifra1 = nr1[p] - '0';
                p--;
                sum = cifra1 + 1;
                rest = 0;
                if (sum > 9) {
                    rest = 1;
                    revsum[poz] = sum % 10 + '0';
                    poz++;
                } else {
                    revsum[poz] = sum + '0';
                    poz++;
                }
            }
            while (p != -1) {
                revsum[poz] = nr1[p];
                p--;
                poz++;
            }
            if (p == -1 && rest == 1) {
                revsum[poz] = 1 + '0';
                poz++;
                rest = 0;
            }
    } else {
        i = lnr2 - 1;
        p = lnr2 - 1;
        while (i != lnr1 - 1) {
            i--;
        }
        for (j = i; j >= 0; j--) {
            cifra1 = nr1[j] - '0';
            cifra2 = nr2[p] - '0';
            p--;
            sum = rest + cifra1 + cifra2;
            rest = 0;
            if (sum > 9) {
                rest = 1;
                revsum[poz] = sum % 10 + '0';
                poz++;
            } else {
                revsum[poz] = sum + '0';
                poz++;
            }
        }
            while (p != -1 && rest == 1) {
                cifra2 = nr2[p] - '0';
                p--;
                sum = cifra2 + 1;
                rest = 0;
                if (sum > 9) {
                    rest = 1;
                    revsum[poz] = sum % 10 + '0';
                    poz++;
                } else {
                    revsum[poz] = sum + '0';
                    poz++;
                }
            }
            while (p != -1) {
                revsum[poz] = nr2[p];
                p--;
                poz++;
            }
            if (p == -1 && rest == 1) {
                revsum[poz] = 1 + '0';
                poz++;
                rest = 0;
            }
    }
    int ok = 0;
    for (i = poz - 1; i >= 0; i--) {
        if(revsum[i]!='0') {
           ok=1; 
        }
        if(ok == 1) {
        printf("%c", revsum[i]);
    }}
    printf("\n");
}

void SolveTask2() {
    char *cod;
    int cheie;
    char *linie;
    cod = (char *)malloc(300 * sizeof(char));
    gets(cod);
    gets(cod);
    if (strcmp(cod, "caesar") == 0) {
        scanf("%d", &cheie);
        linie = (char *)malloc(MAXSIZE * sizeof(char));
        gets(linie);
        linie = Caesar(&cheie);
        printf("%s\n", linie);
    }
    if (strcmp(cod, "vigenere") == 0) {
        Vigenere();
    }
    if (strcmp(cod, "addition") == 0) {
        Addition();   
    }
}
