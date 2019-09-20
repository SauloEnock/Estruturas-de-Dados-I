#define TRUE 1
#define FALSE 0


#include "condominios.h"

int main(int args, char* argv[]){

    Cond *c = NULL;
    int out = TRUE;
    int opcao;

    while(out == TRUE){

        printf("\n");
        printf(" [1] Criar\n");
        printf(" [2] Inserir\n");
        printf(" [3] Remover Elemento\n");
        printf(" [4] Procurar Elemento\n");
        printf(" [5] Listar Elementos\n");
        printf(" [6] Destruir\n");
        printf(" [7] Sair\n");
        printf(" Opcao escolhida: ");
        scanf("%d", &opcao);

        if(opcao == 1){
            printf("\n [OPCAO 1 - CRIAR PREDIO]\n");
            if(c == NULL){
                printf("\n Numero maximo de andares por predio: ");
                int nAndar; scanf("%d", &nAndar);
                printf(" Numero maximo de apartamentos por andar: ");
                int nApart; scanf("%d", &nApart);
                printf(" Valor pago por mes: ");
                float mens; scanf("%f", &mens);
                printf(" Nome do predio: ");
                char nomeP[50]; scanf("%s", nomeP);
                c = condCreate(nAndar, nApart, mens, nomeP);
                if(c!=NULL){
                    printf("\n [Predio criado com sucesso!]\n");
                }else {
                    printf("\n [Falha na criacao do predio!]\n");
                }
            }else {
                printf("\n [O predio ja existe!]\n");
            }
        }else if(opcao == 2){
            printf("\n [OPCAO 2 - INSERIR ELEMENTO]\n");
            if(c != NULL && getIndice(c) < getSizeV(c)){
                printf("\n Nome do dono: ");
                char nomeP[50]; scanf("%s", nomeP);
                printf(" Numero de moradores: ");
                int nMorad; scanf("%d", &nMorad);
                Apart *a;
                a = apartCreate(getCurApart(c), getCurAndar(c), nMorad, nomeP);
                int i = condInsert(c, (void*)a);
                if(i == TRUE){
                    printf("\n [Adicionado com sucesso!]\n");
                }else {
                    printf("\n [Falha na insercao!]\n");
                }
            }else {
                printf("\n [O predio esta cheio ou nao existe!]\n");
            }
        }else if(opcao == 3){
            printf("\n [OPCAO 3 - REMOVER ELEMENTO]\n");
            if(c != NULL && getIndice(c)>0){
                printf("\n Nome do predio: ");
                char nomeP[50]; scanf("%s", nomeP);
                printf(" Nome do dono: ");
                char nomeP2[50]; scanf("%s", nomeP2);
                int i = removeNome(c, nomeP, nomeP2);
                if(i == TRUE){
                    printf("\n [Removido com sucesso!]\n");
                }else {
                    printf("\n [Falha na remocao!]\n");
                }
            }else {
                printf("\n [Predio esta vazio ou nao existe!]\n");
            }
        }else if(opcao == 4){
            printf("\n [OPCAO 4 - PROCURAR ELEMENTO]\n");
            if(c != NULL && getIndice(c)>0){
                printf("\n Nome do predio: ");
                char nomeP[50]; scanf("%s", nomeP);
                printf(" Nome do dono: ");
                char nomeP2[50]; scanf("%s", nomeP2);
                int i = searchNome(c, nomeP, nomeP2);
                if(i == TRUE){
                    printf("\n [Elemento encontrado com sucesso!]\n");
                }else {
                    printf("\n [Elemento nao encontrado!]\n");
                }
            }else {
                printf("\n [Predio esta vazio ou nao existe!]\n");
            }
        }else if(opcao == 5){
            printf("\n [OPCAO 5 - LISTAR ELEMENTO(S)]\n");
            int i = 0;
            Apart *aux;
            if(c != NULL && getIndice(c)>0){
                //aux = (Apart*)returnElement(c, i);
                while(i < getIndice(c)){
                    aux = (Apart*)returnElement(c, i);
                    if (i == 0){printf("\n {Predio %s}\n", getNomeCond(c));}
                    printf("\n Apartamento.: [%d]", getNmrAp(aux));
                    printf("\n Dono.: %s", getNomeDono(aux));
                    printf("\n Numero de moradores.: %d\n", getNmrMorad(aux));
                    i++;
                }
            }else {
                printf("\n [Predio esta vazio ou nao existe!]\n");
            }
        }else if(opcao == 6){
            printf("\n [OPCAO 6 - DESTRUIR PREDIO]\n");
            if(c != NULL){
                int test = condDestroyer(c);
                if(test == TRUE){
                    printf("\n [Predio destruido com sucesso!]\n");
                    c = NULL;
                }else {
                    printf("\n [Falha na destruicao!]\n");
                }
            }else {
                printf("\n [Predio nao existe!]\n");
            }
        }else if(opcao == 7){
            printf("\n [OPCAO 7 - SAIR]\n");
            out = FALSE;
        }
    }

    return 0;
}
