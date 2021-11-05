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
bool catalogo_push( CATALOGO *catalogo, JOGO *jogo );
bool catalogo_insert( CATALOGO *catalogo, JOGO *jogo, int index );
bool catalogo_apagar( CATALOGO **catalogo );

//Funções no catalogo
bool catalogo_remove( CATALOGO *catalogo, int index );
<<<<<<< HEAD
CATALOGO* catalogo_importFromFile(char* fileName);
void catalogo_remove_duplicates(CATALOGO* catalogo); 
void catalogo_srcProdutora (CATALOGO *catalogo, char *produtora);
void catalogo_srcAno(CATALOGO *catalogo, char *ano);
=======
CATALOGO* catalogo_import_from_file(char* fileName);
CATALOGO* catalogo_remove_duplicates(CATALOGO* catalogo); 
void catalogo_src_produtora (CATALOGO *catalogo, char *produtora);
void catalogo_src_ano(CATALOGO *catalogo, char *ano);
>>>>>>> 8e6dddcc5dfb779c1f0386d26722ee17e6a276de
void catalogo_print (CATALOGO* catalogo);
JOGO* catalogo_src_index (CATALOGO *catalogo, int index);


#endif //CATALOGO_H