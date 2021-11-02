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
#include "util.h"

typedef struct catalogo_t CATALOGO;

CATALOGO *catalogo_create();
bool catalogo_insert( CATALOGO *catalogo, JOGO *jogo );
bool catalogo_apagar( CATALOGO **catalogo );
bool catalogo_isEmpty( CATALOGO *catalogo );


#endif //CATALOGO_H