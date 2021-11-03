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

JOGO* set_jogo(char* nome, char* produtora, char* ano){
    //Aloca Memória
    JOGO *joguinho = (JOGO*) calloc (1, sizeof(JOGO));
    
    //Pra caso de merda na alocação
    if (joguinho == NULL)
    {
        exit(1);
    }

    joguinho->nome = (char*) calloc(strlen(nome), sizeof(char) + 1);
    joguinho->produtora = (char*) calloc(strlen(nome), sizeof(char) + 1);
    joguinho->ano = (char*) calloc(strlen(nome), sizeof(char) + 1);
    strcpy(joguinho->nome, nome);
    strcpy(joguinho->produtora, produtora);
    strcpy(joguinho->ano, ano);
    joguinho->index = 0; 

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
int get_index(JOGO* joguinho){
    return joguinho->index;
}

void set_index(JOGO* joguinho, int index){
    joguinho->index = index;
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