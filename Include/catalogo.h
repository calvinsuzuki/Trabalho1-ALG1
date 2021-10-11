/** 
* Exercício 2 - Catalogo de jogos
* 
* Nome - Guilherme Barros Villela 
* Número USP - 12549936 
*/ 
#ifndef CATALOGO_H 
#define CATALOGO_H
#include"jogo.h"

typedef struct catalogo_t CATALOGO;

CATALOGO *make_catalogo();
CATALOGO *adicionar_ao_catalogo(CATALOGO *catalogo, char* nome);
void search(CATALOGO *catalogo);
void search_empresa(char *lista, CATALOGO *catalogo);
void search_ano(char *lista, CATALOGO *catalogo);
bool catalogo_apagar(CATALOGO **catalogo,CATALOGO *catalogoo);

#endif //CATALOGO_H