/** 
 * Trabalho 1 - Lista de Jogos
 * 
 * Nome: Calvin Suzuki de Camargo 
 * Número USP: 11232420 
 * Nome: Guilherme Barros Villela
 * Número USP: 12549936
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
    CATALOGO *catalogo = (CATALOGO*) calloc (1,(sizeof(JOGO**) + sizeof(int)));
    
    //Pra caso de merda na alocação
    if (catalogo == NULL)
    {
        exit(1);
    }

    catalogo->joguinho = NULL;
    catalogo->tamanho_catalogo = 0; 
    
   
    return catalogo;
}

CATALOGO *adicionar_ao_catalogo(CATALOGO *catalogo){
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
    char *produtora, *ano, *nome;
    nome = readLine(); //Mudar pra CSV
    produtora = readLine(); //Mudar pra CSV
    ano = readLine(); //Mudar pra CSV
    catalogo->joguinho[catalogo->tamanho_catalogo] = set_jogo(nome, produtora, ano);
    catalogo->tamanho_catalogo++;
    catalogo_backup = NULL;
    return catalogo;  
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