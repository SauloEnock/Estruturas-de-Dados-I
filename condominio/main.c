
#include "condominio.h"
#include "apartamento.h"

int main(int args, char* argv[]){

    Cond *cond = NULL;
    int out = TRUE;
    int opcao, flag;
    char buffer;

    while(out == TRUE){

        printf("\n");
        printf(" [1] Criar\n");
        printf(" [2] Inserir\n");
        printf(" [3] Remover Morador\n");
        printf(" [4] Procurar Morador\n");
        printf(" [5] Listar Moradores\n");
        printf(" [6] Destruir Condominio\n");
        printf(" [0] Sair\n");
        printf(" Opcao escolhida: ");
        flag = scanf("%d%c", &opcao, &buffer);

        if(opcao == 1 && flag == 2 && buffer == '\n'){
            printf("\n [OPCAO 1 - CRIAR CONDOMINIO]\n");
            if(cond == NULL){
                printf("\n Numero maximo de andares por predio: ");
                int nAndar; scanf("%d", &nAndar);
                printf(" Numero maximo de apartamentos por andar: ");
                int nApart; scanf("%d", &nApart);
                printf(" Nome do predio: ");
                char nomeP[50]; scanf("%s", nomeP);
                cond = condCreate(nAndar, nApart, nomeP);
                if(cond != NULL){
                    printf("\n [Condominio criado com sucesso!]\n");
                }else {
                    printf("\n [Falha na criacao do condominio!]\n");
                }
            }else {
                printf("\n [O condominio ja existe!]\n");
            }
        }else if(opcao == 2 && flag == 2 && buffer == '\n'){
            printf("\n [OPCAO 2 - INSERIR MORADOR]\n");
            if(cond != NULL && isFull(cond) != TRUE){
                printf("\n Nome do dono: ");
                char nomeP[50]; scanf("%s", nomeP);
                printf(" Numero de moradores: ");
                int nMorad; scanf("%d", &nMorad);
                Apart *a;
                a = apartCreate(getCurApart(cond), getCurAndar(cond), nMorad, nomeP);
                int i = condInsert(cond, (void*)a);
                if(i == TRUE){
                    printf("\n [Elemento adicionado com sucesso!]\n");
                }else {
                    printf("\n [Falha na adicao do elemento!]\n");
                }
            }else{
                printf("\n [O condominio esta cheio ou nao existe!]\n");
            }
        }else if(opcao == 3 && flag == 2 && buffer == '\n'){
            printf("\n [OPCAO 3 - REMOVER MORADOR]\n");
            if(cond != NULL && isEmpty(cond) != TRUE){
                printf("\n Nome do predio: ");
                char nomeP[50]; scanf("%s", nomeP);
                printf(" Nome do dono: ");
                char nomeP2[50]; scanf("%s", nomeP2);
                void *aux = NULL;
                aux = condRemove(cond, (void*)nomeP2, nomeP, cmpNome);
                if(aux != NULL){
                    printf("\n Elemento [%s] removido com sucesso!\n", (char*)aux);
                }else {
                    printf("\n Falha na remocao!\n");
                }
            }else {
                printf("\n [A condominio esta vazio ou nao existe!]\n");
            }
        }else if(opcao == 4 && flag == 2 && buffer == '\n'){
            printf("\n [OPCAO 4 - PROCURAR MORADOR]\n");
            if(cond != NULL && isEmpty(cond) != TRUE){
                printf("\n Nome do predio: ");
                char nomeP[50]; scanf("%s", nomeP);
                printf(" Nome do dono: ");
                char nomeP2[50]; scanf("%s", nomeP2);
                int verif = condSearch(cond, (void*)nomeP2, nomeP, cmpNome);
                if(verif == TRUE){
                    printf("\n Elemento [%s] encontrado com sucesso!\n", nomeP2);
                    printf("\n Tamanho lista = %d", condSize(cond));
                }else {
                    printf("\n Elemento nao encontrado!\n");
                }
            }else {
                printf("\n [A condominio esta vazio ou nao existe!]\n");
            }
        }else if(opcao == 5 && flag == 2 && buffer == '\n'){
            printf("\n [OPCAO 5 - LISTAR MORADORES]\n");
            if(cond != NULL && isEmpty(cond) != TRUE){
                printf("\n\n [Condominio %s]", getNomeCond(cond));
                for(int i = 0; i < condTrueSize(cond); i++){
                    if(strcmp((char*)listarNomeDono(cond, i), "***") != 0){
                        printf("\n\n ---Apartamento [%d]---", (int)listarNmrApart(cond, i));
                        printf("\n >>Nome do Dono: %s", (char*)listarNomeDono(cond, i));
                        printf("\n >>Numero de Moradores: %d", (int)listarNmrMorad(cond, i));
                    }
                }
            }else {
                printf("\n [A condominio esta vazio ou nao existe!]\n");
            }
        }else if(opcao == 6 && flag == 2 && buffer == '\n'){
            printf("\n [OPCAO 6 - DESTRUIR CONDOMINIO]\n");
            if(cond != NULL){
                int verif = condDestroyer(cond);
                if(verif == TRUE){
                    printf("\n Condominio destruido com sucesso!\n");
                    cond = NULL;
                }else {
                    printf("\n Falha na destruicao!\n");
                }
            }else {
                printf("\n [A condominio esta vazio ou nao existe!]\n");
            }
        }else if(opcao == 0 && flag == 2 && buffer == '\n'){
            printf("\n [SAIR]\n");
            if(cond == NULL){
                out = FALSE;
            }else {
                printf("\n Destrua o condominio antes de sair do programa!\n");
            }
        }else {
            clean_stdin();
            printf("\n [OPCAO INVALIDA!]\n");
        }
    }

    return 0;
}
