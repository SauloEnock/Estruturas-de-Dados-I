
#ifndef _CONDOMINIO_H_

#define _CONDOMINIO_H_

#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _node_ Node;

typedef struct _condominio_ Cond;

    #ifndef _CONDOMINIO_C_

        Cond* condCreate(int andares, int aparts, char* nomePredio);
        int condDestroyer(Cond* temp);
        int condInsert(Cond* temp, void* elm);
        int clean_stdin();
        int getCurApart(Cond* temp);
        int getCurAndar(Cond* temp);
        char* getNomeCond(Cond *temp);
        int isEmpty(Cond* temp);
        int isFull(Cond* temp);
        int condSize(Cond* temp);
        int condTrueSize(Cond* temp);
        void* listarNmrApart(Cond* temp, int n);
        void* listarNomeDono(Cond* temp, int n);
        void* listarNmrMorad(Cond* temp, int n);
        char* condRemove(Cond* temp, void* key, char* nomeP, int(*cmp)(void*, void*));
        int condSearch(Cond* temp, void* key, char* nomeP, int(*cmp)(void*, void*));

    #else

        extern Cond* condCreate(int andares, int aparts, char* nomePredio);
        extern int condDestroyer(Cond* temp);
        extern int condInsert(Cond* temp, void* elm);
        extern int clean_stdin();
        extern int getCurApart(Cond* temp);
        extern int getCurAndar(Cond* temp);
        extern char* getNomeCond(Cond *temp);
        extern int isEmpty(Cond* temp);
        extern int isFull(Cond* temp);
        extern int condSize(Cond* temp);
        extern int condTrueSize(Cond* temp);
        extern void* listarNmrApart(Cond* temp, int n);
        extern void* listarNomeDono(Cond* temp, int n);
        extern void* listarNmrMorad(Cond* temp, int n);
        extern char* condRemove(Cond* temp, void* key, char* nomeP, int(*cmp)(void*, void*));
        extern int condSearch(Cond* temp, void* key, char* nomeP, int(*cmp)(void*, void*));

    #endif //_CONDOMINIO_C

#endif //_CONDOMINIO_H_
