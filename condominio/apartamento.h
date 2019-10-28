
#ifndef _APARTAMENTO_H_

#define _APARTAMENTO_H_

#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _apartamento_ Apart;

    #ifndef _APARTAMENTO_C_

        Apart* apartCreate(int curApartF, int curAndarF, int nmrP, char* nomePF);
        char* getNomeDono(Apart* temp);
        int cmpNome(void *a, void *b);
        int getNmrApart(Apart *temp);
        int getNmrMorad(Apart *temp);
        int setNomeDono(Apart* a, Apart* temp);
        int setNomeDono2(Apart* a, char* temp);
        int setNomeNmrMorad(Apart* a, Apart* temp);

    #else

        extern Apart* apartCreate(int curApartF, int curAndarF, int nmrP, char* nomePF);
        extern char* getNomeDono(Apart* temp);
        extern int cmpNome(void *a, void *b);
        extern int getNmrApart(Apart *temp);
        extern int getNmrMorad(Apart *temp);
        extern int setNomeDono(Apart* a, Apart* temp);
        extern int setNomeDono2(Apart* a, char* temp);
        extern int setNomeNmrMorad(Apart* a, Apart* temp);

    #endif //_APARTAMENTO_C

#endif //_APARTAMENTO_H_
