/** 
* Exercício 2 - Catalogo de jogos
* 
* Nome - Guilherme Barros Villela 
* Número USP - 12549936 
*/ 
#include "jogo.h"
#include <string.h> 
#include <stdio.h>
#include <stdlib.h>

struct jogo_t 
{
    char nome[101];
    char produtora[101]; 
    char ano[101];
};

JOGO* set_jogo(char* nome, char* produtora, char* ano){
    //Aloca Memória
    JOGO *joguinho = (JOGO*) calloc (1,sizeof(JOGO));
    
    //Pra caso de merda na alocação
    if (joguinho == NULL)
    {
        exit(1);
    }
    
    //Pega um nome
    strcpy(joguinho->nome, nome);
    strcpy(joguinho->produtora, produtora);
    strcpy(joguinho->ano, ano);

    return joguinho;
}

char *get_ano(JOGO *joguinho){
    return joguinho->ano;
}
char *get_produtora(JOGO* joguinho){
    return joguinho->produtora;
}
char *get_nome(JOGO* joguinho){
    return joguinho->nome;
}

bool jogo_apagar(JOGO **jogo)
{
    if (*jogo != NULL)
    {
        free (*jogo);
        *jogo = NULL;
        return true;
    }
    return false;
}