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

bool busca_f(char *nome);
int main (void){  
    char nome[101];
    CATALOGO *catalogo;
    catalogo = make_catalogo();
    receber_dado(nome);
    while (busca_f(nome) == false)
    {
        adicionar_ao_catalogo(catalogo, nome);
        receber_dado(nome);
    }
    search(catalogo);
    catalogo_apagar(&catalogo, catalogo);
    return 0;
}

bool busca_f(char *nome){ 
    if (strcmp(nome, "F") == 0|| 
    strcmp(nome, "F\r") == 0){
        return true;
    }
    else {
        return false;
    }
}
