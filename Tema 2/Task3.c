#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

typedef struct Bigram
{
    char *bigrama;
    int nr_ap;
    int prop;
} Bigram;

void SolveTask3()
{
    char *linie, *cuv, *ngram, *copie, *parcurgere;
    int nr, l, i, j, nrtotal = 0, ok, nrprop = 1;
    Bigram *V = (Bigram *)malloc(1001 * sizeof(Bigram));
    linie = (char *)malloc(1000 * sizeof(char));
    gets(linie);
    gets(linie);
    copie = (char *)malloc(1000 * sizeof(char));
    ngram = (char *)malloc(1000 * sizeof(char));
    strcpy(copie, linie);
    l = strlen(linie);
    for (i = 0; i < l; i++)
    {
        if (strchr(",!?.;", linie[i]))
        {
            j = i;
            while (j < l)
            {
                if (j == l - 1)
                {
                    linie[j] = ' ';
                    j++;
                    continue;
                }
                linie[j] = linie[j + 1];
                j++;
            }
        }
    }
    cuv = strtok(copie, " ,!?;.\n");
    strcpy(ngram, cuv);
    strcat(ngram, " ");
    while (cuv != NULL)
    {
        ok = 1;
        cuv = strtok(NULL, " ,!?;.\n");
        if (cuv == NULL)
        {
            memset(linie, 0, sizeof(linie));
            memset(copie, 0, sizeof(copie));
            gets(linie);
            if (linie == NULL)
            {
                break;
            }
            if (linie[0] < 39 || linie[0] > 90)
            {
                gets(linie);
                if (linie[0] < 39 || linie[0] > 90)
                {
                    break;
                }
            }
            if (linie != NULL)
            {
                l = strlen(linie);
                strcpy(copie, linie);
                for (i = 0; i < l; i++)
                {
                    if (strchr(",!?.;", linie[i]))
                    {
                        j = i;
                        while (j < l)
                        {
                            if (j == l - 1)
                            {
                                linie[j] = ' ';
                                j++;
                                continue;
                            }
                            linie[j] = linie[j + 1];
                            j++;
                        }
                    }
                }
                cuv = strtok(copie, " ,!?;.\n");
                strcat(ngram, cuv);
                ok = 1;
                nr = 1;
                for (i = 0; i < nrtotal; i++)
                {
                    if (strcmp(V[i].bigrama, ngram) == 0)
                    {
                        V[i].nr_ap += nr;
                        nr = 0;
                        memset(ngram, 0, sizeof(ngram));
                        strcpy(ngram, cuv);
                        strcat(ngram, " ");
                        ok = 0;
                        nrprop++;
                        break;
                    }
                }
                if (ok == 0)
                {
                    continue;
                }
                V[nrtotal].bigrama = (char *)malloc(1002 * sizeof(char));
                strcpy(V[nrtotal].bigrama, ngram);
                V[nrtotal].nr_ap = nr;
                nr = 0;
                V[nrtotal].prop = nrprop;
                nrprop++;
                nrtotal++;
                memset(ngram, 0, sizeof(ngram));
                strcpy(ngram, cuv);
                strcat(ngram, " ");
                continue;
            }
        }
        strcat(ngram, cuv);
        nr = 0;
        parcurgere = strstr(linie, ngram);
        while (parcurgere != NULL)
        {
            if (strcmp(parcurgere, linie) == 0)
            {
                parcurgere += strlen(ngram);
                if (parcurgere[0] == ' ')
                {
                    nr++;
                }
                parcurgere -= strlen(ngram);
                parcurgere++;
                parcurgere = strstr(parcurgere, ngram);
                continue;
            }
            parcurgere--;
            if (parcurgere[0] == ' ')
            {
                parcurgere += (strlen(ngram) + 1);
                if (parcurgere[0] == ' ' || parcurgere[0] == '\n')
                {
                    nr++;
                }
                parcurgere -= (strlen(ngram) + 1);
            }
            parcurgere += 2;
            parcurgere = strstr(parcurgere, ngram);
        }
        if (nr == 0)
        {
            nr = 1;
        }
        for (i = 0; i < nrtotal; i++)
        {
            if (strcmp(V[i].bigrama, ngram) == 0)
            {
                if (V[i].prop != nrprop)
                {
                    V[i].nr_ap += nr;
                    V[i].prop = nrprop;
                }
                nr = 0;
                memset(ngram, 0, sizeof(ngram));
                strcpy(ngram, cuv);
                strcat(ngram, " ");
                ok = 0;
                break;
            }
        }
        if (ok == 0)
        {
            continue;
        }
        V[nrtotal].bigrama = (char *)malloc(1002 * sizeof(char));
        strcpy(V[nrtotal].bigrama, ngram);
        V[nrtotal].nr_ap = nr;
        nr = 0;
        V[nrtotal].prop = nrprop;
        nrtotal++;
        memset(ngram, 0, sizeof(ngram));
        strcpy(ngram, cuv);
        strcat(ngram, " ");
    }
    printf("%d\n", nrtotal);
    for (i = 0; i < nrtotal; i++)
    {
        printf("%s %d\n", V[i].bigrama, V[i].nr_ap);
    }
}