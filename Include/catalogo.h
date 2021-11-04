/** 
 * Trabalho 1 - Lista de Jogos
 * 
 * Nome: Calvin Suzuki de Camargo 
 * Número USP: 11232420 
 * Nome: Guilherme Barros Villela
 * Número USP: 12549936
 */

#ifndef CATALOGO_H 
#define CATALOGO_H
#include"jogo.h"
#include "Util.h"

typedef struct catalogo_t CATALOGO;

CATALOGO *catalogo_create();
bool catalogo_insert( CATALOGO *catalogo, JOGO *jogo );
bool catalogo_apagar( CATALOGO **catalogo );

//Funções no catalogo
CATALOGO* catalogo_importFromFile(char* fileName);
CATALOGO* catalogo_remove_duplicates(CATALOGO* catalogo); 
void catalogo_search_empresa(char *lista, CATALOGO *catalogo);
void catalogo_search_ano(char *lista, CATALOGO *catalogo);
void catalogo_print(CATALOGO* catalogo);
JOGO* catalogo_search_index(CATALOGO *catalogo, int index);

#endif //CATALOGO_H