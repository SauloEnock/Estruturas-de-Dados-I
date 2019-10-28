
#ifndef _APARTAMENTO_C_

#define _APARTAMENTO_C_

#include "apartamento.h"

typedef struct _apartamento_{
    char donoAp[50]; /* String contendo o nome do dono do apartamento */
    int nmrMorad; /* numero de moradores do apartamento */
    int nmrAp; /* numero do apartamento */
}Apart;

Apart* apartCreate(int curApartF, int curAndarF, int nmrP, char* nomePF){
    Apart* p;
    if(curApartF > 0 && curAndarF > 0 && nmrP > 0 && nomePF != NULL){
        p = (Apart*)malloc(sizeof(Apart));
        if(p != NULL){
            p->nmrAp = (curAndarF * 100) + curApartF;
            p->nmrMorad = nmrP;
            strcpy(p->donoAp, nomePF);
            return p;
        }
        free(p);
    }
    return NULL;
}

int cmpNome(void *a, void *b){

    Apart *pa;
    char *pb;
    pa = (Apart*)a;
    pb = (char*)b;
    if(strcmp(pb, pa->donoAp) == 0){
        return TRUE;
    }else {
        return FALSE;
    }
}

char* getNomeDono(Apart* temp){
    if(temp != NULL){
        return temp->donoAp;
    }
    return NULL;
}

int getNmrApart(Apart *temp){
    if(temp != NULL){
        return temp->nmrAp;
    }
    return -1;
}

int getNmrMorad(Apart *temp){
    if(temp != NULL){
        return temp->nmrMorad;
    }
    return -1;
}

int setNomeDono(Apart* a, Apart* temp){
    if(a != NULL){
        strcpy(a->donoAp, temp->donoAp);
        return TRUE;
    }
    return FALSE;
}

int setNomeDono2(Apart* a, char* temp){
    if(a != NULL){
        strcpy(a->donoAp, temp);
        return TRUE;
    }
    return FALSE;
}

int setNomeNmrMorad(Apart* a, Apart* temp){
    if(a != NULL){
        a->nmrMorad = temp->nmrMorad;
        return TRUE;
    }
    return FALSE;
}

#endif //_CONDOMINIO_C
