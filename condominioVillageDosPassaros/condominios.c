
#ifndef _CONDOMINIONS_C_

#define _CONDOMINIONS_C_

#include "condominios.h"

typedef struct _condominio_{

    int indice; /* variável usada como indice para navegação no vetor */
    int curApart; /* posição do primeiro apartamento vago do andar*/
    int curAndar; /* posição do primeiro andar com um apartamento vago */
    int maxAndar; /* máximo de andares do predio*/
    int maxApart; /* máximo de apartamentos por andar do predio*/
    float mens; /* valor pago por cada inquilino por mes */
    char nomeCond[50]; /* nome do predio */
    void** element; /* vetor que contém os moradores do predio */
}Cond;

typedef struct _apartamento_{

    char donoAp[50]; /* String contendo o nome do dono do apartamento */
    int nmrMorad; /* numero de moradores do apartamento */
    int nmrAp; /* numero do apartamento */
}Apart;

int getCurApart(Cond* c){
    return c->curApart;
}

int getCurAndar(Cond* c){
    return c->curAndar;
}

int getSizeV(Cond* c){
    return c->maxAndar * c->maxApart;
}

int getIndice(Cond* c){
    return c->indice;
}

char* getNomeCond(Cond* c){
    return c->nomeCond;
}

void* returnElement(Cond* c, int i){
    return c->element[i];
}

char* getNomeDono(Apart* a){
    return a->donoAp;
}

int getNmrMorad(Apart* a){
    return a->nmrMorad;
}

int getNmrAp(Apart* a){
    return a->nmrAp;
}

Cond* condCreate(int andares, int aparts, float valor, char* nomePredio){

    Cond* c;
    if(andares > 0 && aparts > 0 && valor > 0.0 && nomePredio != NULL){
        c = (Cond*)malloc(sizeof(Cond));
        if(c != NULL){
            c->element = (void**)malloc(sizeof(void*)*(andares*aparts));
            if(c->element != NULL){
                c->indice = 0;
                c->curApart = 1;
                c->curAndar = 1;
                c->maxAndar = andares;
                c->maxApart = aparts;
                c->mens = valor;
                strcpy(c->nomeCond, nomePredio);
                return c;
            }
            free(c);
        }
        return NULL;
    }
    return NULL;
}

int condDestroyer(Cond* c){

    if(c != NULL){
        if(c->indice == 0){
            free(c->element);
            free(c);
            return TRUE;
        }else {
            while(c->indice >= 0){
                free(c->element[c->indice]);
                c->indice--;
            }
            free(c->element);
            free(c);
            return TRUE;
        }
    }
    return FALSE;
}

int condInsert(Cond* c, void* elementF){

    if(c != NULL){
        if(c->indice < (c->maxAndar) * (c->maxApart)){
            c->element[c->indice] = elementF;
            c->indice++;
            c->curApart++;
            if(c->curApart == 5){
                c->curAndar++;
                c->curApart = 1;
            }
            return TRUE;
        }else {
            return FALSE;
        }
    }
    return FALSE;
}

void* condSearch(Cond* c, void* key, int(*cmp)(void*, void*)){

    int i = 0;
    if(c != NULL){
        if(c->indice > 0){
            while(cmp(c->element[i], key)!=TRUE && i < c->indice){
                i++;
            }
            if(cmp(c->element[i], key)==TRUE){
                return c->element[i];
            }
        }
    }
    return NULL;
}

void* condRemove(Cond* c, void* key, int(*cmp)(void*, void*)){

    int i = 0, j;
    void *aux;
    if(c != NULL){
        if(c->indice > 0){
            while(cmp(c->element[i], key)!=TRUE && i < c->indice){
                i++;
            }
            if(cmp(c->element[i], key)==TRUE){
               aux = c->element[i];
               free(c->element[i]);
               for(j = i; j < c->indice - 1; j++){
                    c->element[j] = c->element[j+1];
               }
               free(c->element[j+1]);
               c->indice--;
               return aux;
            }
            return NULL;
        }
    }
    return NULL;
}

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

int searchNome(Cond* c, char* nomePredio, char* nomeDono){

    Apart *aux = NULL;
    if(strcmp(nomePredio, c->nomeCond) == 0){
        aux = (Apart*)condSearch(c, (void*)nomeDono, cmpNome);
    }
    if(aux != NULL){
        return TRUE;
    }else {
        return FALSE;
    }
}

int removeNome(Cond* c, char* nomePredio, char* nomeDono){
    Apart *aux = NULL;
    if(strcmp(nomePredio, c->nomeCond) == 0){
        aux = (Apart*)condRemove(c, (void*)nomeDono, cmpNome);
    }
    if(aux != NULL){
        return TRUE;
    }else {
        return FALSE;
    }
}

#endif //_CONDOMINIONS_C
