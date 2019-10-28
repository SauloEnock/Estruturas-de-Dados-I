
#ifndef _CONDOMINIO_C_

#define _CONDOMINIO_C_

#include "condominio.h"
#include "apartamento.h"

typedef struct _node_{
    void* data; /* elemento do nó */
    struct _node_ *next; /* ponteiro apontando para o próximo nó */
}Node;

typedef struct _condominio_{

    int curApart; /* posição do primeiro apartamento vago do andar*/
    int curAndar; /* posição do primeiro andar com um apartamento vago */
    int maxAndar; /* máximo de andares do predio*/
    int maxApart; /* máximo de apartamentos por andar do predio*/
    char nomeCond[50]; /* nome do predio */
    Node* head; /* Início da lista */
}Cond;

Cond* condCreate(int andares, int aparts, char* nomePredio){
    Cond *cond = (Cond*)malloc(sizeof(Cond));
    if(cond != NULL){
        cond->head = NULL;
        cond->curAndar = 1;
        cond->curApart = 1;
        cond->maxAndar = andares;
        cond->maxApart = aparts;
        strcpy(cond->nomeCond, nomePredio);
        return cond;
    }
    return NULL;
}

int condDestroyer(Cond* temp){
    Node* prev;
    Node* aux;
    if(temp != NULL){
        if(temp->head == NULL){
            free(temp);
            return TRUE;
        }else {
            prev = NULL;
            aux = temp->head;
            while(aux->next != NULL){
                prev = aux;
                aux = aux->next;
                free(prev);
            }
            free(aux);
            return TRUE;
        }
    }
    return FALSE;
}

int isEmpty(Cond* temp){
    if(temp != NULL){
        if(temp->head == NULL){
            return TRUE;
        }
    }
    return FALSE;
}

int isFull(Cond* temp){
    if(temp != NULL){
        if(condSize(temp) == (temp->maxAndar * temp->maxApart)){
            return TRUE;
        }
    }
    return FALSE;
}

int condSize(Cond* temp){
    int nmr = 0;
    Node *current;
    if(temp != NULL){
        current = temp->head;
        if(current != NULL){
            while(current != NULL){
                if(strcmp(getNomeDono(current->data), "***") != 0){ nmr++; }
                current = current->next;
            }
        }
    }
    return nmr;
}

int condTrueSize(Cond* temp){
    int nmr = 0;
    Node *current;
    if(temp != NULL){
        current = temp->head;
        if(current != NULL){
            while(current != NULL){
                nmr++;
                current = current->next;
            }
        }
    }
    return nmr;
}

int clean_stdin(){
    while (getchar()!='\n');
    return 1;
}

int getCurApart(Cond* temp){
    if(temp != NULL){
        return temp->curApart;
    }
    return NULL;
}

int getCurAndar(Cond* temp){
    if(temp != NULL){
        return temp->curAndar;
    }
    return NULL;
}

void* listarNomeDono(Cond* temp, int n){
    void* dataF;
    Node* current;
    if(temp != NULL){
        current = temp->head;
        for(int i = 0; i < n; i++){
            current = current->next;
        }
        dataF = (void*)getNomeDono(current->data);
        return dataF;
    }
    return NULL;
}

void* listarNmrApart(Cond* temp, int n){
    void* dataF;
    Node* current;
    if(temp != NULL){
        current = temp->head;
        for(int i = 0; i < n; i++){
            current = current->next;
        }
        dataF = (void*)getNmrApart(current->data);
        return dataF;
    }
    return NULL;
}

void* listarNmrMorad(Cond* temp, int n){
    void* dataF;
    Node* current;
    if(temp != NULL){
        current = temp->head;
        for(int i = 0; i < n; i++){
            current = current->next;
        }
        dataF = (void*)getNmrMorad(current->data);
        return dataF;
    }
    return NULL;
}

char* getNomeCond(Cond *temp){
    if(temp != NULL){
        return temp->nomeCond;
    }
    return NULL;
}

int condInsert(Cond* temp, void* elm){
    Node *aux;
    Node *newNode;
    int flag = FALSE;
    if(temp != NULL){
        newNode = (Node*)malloc(sizeof(Node));
        if(newNode != NULL){
            newNode->data = elm;
            newNode->next = NULL;
            if(temp->head == NULL){
                temp->head = newNode;
            }else {
                aux = temp->head;
                while(aux->next != NULL && strcmp(getNomeDono(aux->data), "***") != 0){
                    aux = aux->next;
                }
                if(strcmp(getNomeDono(aux->data), "***") == 0){
                    setNomeDono(aux->data, elm);
                    setNomeNmrMorad(aux->data, elm);
                    flag = TRUE;
                }else {
                    aux->next = newNode;
                }
            }
            if(flag != TRUE){
                temp->curApart++;
                if(temp->curApart == temp->maxApart + 1){
                    temp->curAndar++;
                    temp->curApart = 1;
                }
            }
            return TRUE;
        }
    }
    return FALSE;
}

char* condRemove(Cond* temp, void* key, char* nomeP, int(*cmp)(void*, void*)){
    //void* dataF;
    Node *previous;
    Node *current;
    if(temp != NULL){
        previous = NULL;
        current = temp->head;
        if(current != NULL){
            if(strcmp(nomeP, temp->nomeCond) == 0){
                while(current->next != NULL && cmp(key, getNomeDono(current->data)) != TRUE){
                    previous = current;
                    current = current->next;
                }
                if(cmp(key, getNomeDono(current->data)) == TRUE && previous != NULL){
                    //previous->next = current->next;
                    setNomeDono2(current->data, "***");
                    return key;
                }else if(cmp(key, getNomeDono(current->data)) == TRUE){
                    //temp->head = current->next;
                    setNomeDono2(current->data, "***");
                    return key;
                }
            }
        }
    }
    return NULL;
}

int condSearch(Cond* temp, void* key, char* nomeP, int(*cmp)(void*, void*)){
    Node *current;
    if(temp != NULL){
        current = temp->head;
        if(current != NULL){
            if(strcmp(nomeP, temp->nomeCond) == 0){
                while(current->next != NULL && cmp(key, getNomeDono(current->data)) != TRUE){
                    current = current->next;
                }
                if(cmp(key, getNomeDono(current->data)) == TRUE){ return TRUE; }
            }
        }
    }
    return FALSE;
}



#endif //_CONDOMINIO_C
