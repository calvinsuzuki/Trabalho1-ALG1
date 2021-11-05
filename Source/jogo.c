/** 
 * Trabalho 1 - Lista de Jogos
 * 
 * Nome: Calvin Suzuki de Camargo 
 * Número USP: 11232420 
 * Nome: Guilherme Barros Villela
 * Número USP: 12549936
 */
#include "../Include/jogo.h"
#include <string.h> 
#include <stdio.h>
#include <stdlib.h>

struct jogo_t 
{
    char *nome;
    char *produtora; 
    char *ano;
    int index;
};

JOGO* jogo_create(char* nome, char* ano, char* produtora) {
    //Aloca Memória
    JOGO *joguinho = (JOGO*) malloc( sizeof(JOGO) );
    
    //Erro na alocação
    if (joguinho == NULL)
    {
        exit(1);
    }

    joguinho->nome =       (char*) malloc(strlen(nome) * sizeof(char) + 1);
    joguinho->produtora =  (char*) malloc(strlen(produtora) * sizeof(char) + 1);
    joguinho->ano =        (char*) malloc(strlen(ano) * sizeof(char) + 1);

    //Erro na alocação
    if ( joguinho->nome == NULL || joguinho->ano == NULL || joguinho->produtora == NULL) {

        exit(1);
    }
    strcpy(joguinho->nome, nome);
    strcpy(joguinho->produtora, produtora);
    strcpy(joguinho->ano, ano);
    joguinho->index = 0; 

    free( nome ); free( ano ); free( produtora );

    return joguinho;
}

char *jogo_getAno(JOGO *joguinho){
    return joguinho->ano;
}
char *jogo_getProdutora(JOGO* joguinho){
    return joguinho->produtora;
}
char *jogo_getNome(JOGO* joguinho){
    return joguinho->nome;
}
int jogo_getIndex(JOGO* joguinho){
    return joguinho->index;
}

void jogo_setIndex(JOGO* joguinho, int index){
    joguinho->index = index;
}

bool jogo_apagar(JOGO **jogo)
{
    if (*jogo != NULL)
    {   
        free( (*jogo)->ano );
        free( (*jogo)->produtora );
        free( (*jogo)->nome );
        free (*jogo);
        *jogo = NULL;
        return true;
    }
    return false;
}