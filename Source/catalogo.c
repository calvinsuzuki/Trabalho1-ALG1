/** 
* Exercício 2 - Catalogo de jogos
* 
* Nome - Guilherme Barros Villela  
* Número USP - 12549936 
*/ 
#include "catalogo.h"
#include <string.h> 
#include <stdio.h>
#include <stdlib.h> 

struct catalogo_t 
{
    JOGO **joguinho;
    int tamanho_catalogo;
};

CATALOGO *make_catalogo(){
   
    //Aloca Memória
    CATALOGO *catalogo = (CATALOGO*) calloc (1,sizeof(CATALOGO));
    
    //Pra caso de merda na alocação
    if (catalogo == NULL)
    {
        exit(1);
    }

    catalogo->joguinho = NULL;
    catalogo->tamanho_catalogo = 0; 
    
   
    return catalogo;
}

CATALOGO *adicionar_ao_catalogo(CATALOGO *catalogo, char* nome){
    CATALOGO *catalogo_backup = catalogo;

    //Realoca para adicionar um jogo ao catalogo 
    catalogo_backup->joguinho = (JOGO**) realloc(catalogo->joguinho,
                                ((catalogo->tamanho_catalogo)+1)*sizeof(JOGO**));
    if (catalogo_backup != NULL){
        catalogo->joguinho = catalogo_backup->joguinho;
    }
    else{
        exit(1);
    }

    char ano[101], produtora[101];
    receber_dado(produtora);
    receber_dado(ano);
    catalogo->joguinho[catalogo->tamanho_catalogo] = set_jogo(nome, produtora, ano);
    catalogo->tamanho_catalogo++;
    catalogo_backup = NULL;
    return catalogo;  
} 

void search(CATALOGO *catalogo){
    char EAF[15], *lista, *lista_backup;
    int count = 0;
    lista = (char*) calloc (1, sizeof(char));
    lista_backup = lista;
    while (1)
    {
        scanf("%[^\n]%*c", EAF); 

        //Adiciona o espaço de um nome de jogo por realloc
        lista_backup = (char*) realloc(lista, 101*sizeof(char)*(count+1)); 
        if (lista_backup != NULL){
            lista = lista_backup;
            count++;
        }
        else{
            exit(1);
        }

        //Define o tipo de busca 
        if (strcmp(EAF, "E") == 0 || strcmp(EAF, "E\r") == 0){
                search_empresa(lista, catalogo);
        }
        else if (strcmp(EAF, "A") == 0 || strcmp(EAF, "A\r") == 0){
            search_ano(lista, catalogo);
        }
        else if (strcmp(EAF, "F") == 0 || strcmp(EAF, "F\r") == 0){
            printf("%s", lista);
            free(lista);
            lista = NULL;
            lista_backup = NULL;
            return;
        }
    }
}

void search_empresa(char *lista, CATALOGO *catalogo){
    char empresa[101];
    int count = 0;
    scanf("%[^\n]%*c", empresa);
    for (size_t i = 0; i < (catalogo->tamanho_catalogo); i++){
        if (strcmp(get_produtora(catalogo->joguinho[i]), empresa) == 0)
        {
            strcat(strcat(lista, get_nome(catalogo->joguinho[i])),"\n");
            count++;
        }
    }
        if (count == 0)
        {
            strcat(strcat(lista, "Nada encontrado"),"\n");
        }
}

void search_ano(char *lista, CATALOGO *catalogo){
    char ano[101];
    int count = 0;
        scanf("%[^\n]%*c", ano);
        for (size_t j = 0; j < (catalogo->tamanho_catalogo); j++){
            if (strcmp(get_ano(catalogo->joguinho[j]), ano) == 0)
            {
                strcat(strcat(lista, get_nome(catalogo->joguinho[j])),"\n");
                count++;
            }
        }
            if (count == 0)
            {
                strcat(strcat(lista, "Nada encontrado"),"\n");
            }
}

bool catalogo_apagar(CATALOGO **catalogo, CATALOGO *catalogoo)
{
    if (*catalogo != NULL)
    {
        for (size_t i = 0; i < catalogoo->tamanho_catalogo; i++)
        {
            jogo_apagar(&(catalogoo->joguinho[i]));
        }
        free((catalogoo->joguinho));
        free (*catalogo);
        *catalogo = NULL;
        return true;
    }
    return false;
}