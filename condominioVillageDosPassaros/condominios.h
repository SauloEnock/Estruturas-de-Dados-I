
#ifndef _CONDOMINIOS_H_

#define _CONDOMINIOS_H_

#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _condominio_ Cond;

typedef struct _apartamento_ Apart;

    #ifndef _CONDOMINIONS_C_

        int getCurApart(Cond* c); /* retorna o primeiro apartamento vago do andar */
        int getCurAndar(Cond* c); /* retorna o primeiro andar com apartamento vago*/
        int getIndice(Cond* c); /* retorna o valor(int) indice de navegaçãodo vetor */
        int getSizeV(Cond* c); /* retorna retorn o tamanho total do vetor */
        char* getNomeDono(Apart* a); /* retorna o nome do dono do apartamento */
        int getNmrMorad(Apart* a); /* retorna o numero de moradores do apartamento */
        int getNmrAp(Apart* a); /* retorna o numero do apartamento */
        void* returnElement(Cond* c, int i); /* retorna o elemento da posição i(int) do vetor */
        Cond* condCreate(int andares, int aparts, float valor, char* nomeCondF); /* cria e retorna um predio */
        int condDestroyer(Cond* c); /* destroi(libera a memoria utilizada) o(pelo) predio */
        int condInsert(Cond* c, void* elementF); /* insere um elemento no vetor */
        void* condSearch(Cond* c, void* key, int(*cmp)(void*, void*)); /* procura um elemento no vetor */
        Apart* apartCreate(int curApartF, int curAndarF, int nmrP, char* nomePF); /* cria e retorna um apartamento */
        int cmpNome(void *a, void *b); /* função de comparação de Strings */
        int searchNome(Cond* c, char* nomePredio, char* nomeDono); /* verifica se o predio procurado é o certo antes de chamar "condSearch" */
        int removeNome(Cond* c, char* nomePredio, char* nomeDono); /* verifica se o predio procurado é o certo antes de utilizar "condSearch" para identificar e remover o elemento */

    #else

        extern int getCurApart(Cond* c);
        extern int getCurAndar(Cond* c);
        extern int getIndice(Cond* c);
        extern int getSizeV(Cond* c);
        extern char* getNomeDono(Apart* a);
        extern int getNmrMorad(Apart* a);
        extern int getNmrAp(Apart* a);
        extern void* returnElement(Cond* c, int i);
        extern Cond* condCreate(int andares, int aparts, float valor, char* nomeCondF);
        extern int condDestroyer(Cond* c);
        extern int condInsert(Cond* c, void* elementF);
        extern void* condSearch(Cond* c, void* key, int(*cmp)(void*, void*));
        extern Apart* apartCreate(int curApartF, int curAndarF, int nmrP, char* nomeP);
        extern int cmpNome(void *a, void *b);
        extern int searchNome(Cond* c, char* nomePredio, char* nomeDono);
        extern int removeNome(Cond* c, char* nomePredio, char* nomeDono);

    #endif //_CONDOMINIONS_C

#endif //_CONDOMINIOS_H_
