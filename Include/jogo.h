/** 
 * Trabalho 1 - Lista de Jogos
 * 
 * Nome: Calvin Suzuki de Camargo 
 * Número USP: 11232420 
 * Nome: Guilherme Barros Villela
 * Número USP: 12549936
 */
#ifndef JOGO_H
#define JOGO_H 
#include "Util.h"
#include <stdbool.h>

typedef struct jogo_t JOGO;

JOGO* jogo_create(char* nome, char* ano, char* produtora);
JOGO* jogo_copy( JOGO *joguinho );
char *jogo_get_produtora(JOGO* joguinho);
char *jogo_get_ano(JOGO* joguinho);
char *jogo_get_nome(JOGO* joguinho);
int jogo_get_index(JOGO* joguinho);
bool jogo_apagar(JOGO **jogo);
void jogo_set_index(JOGO* joguinho, int index); 

#endif //JOGO_H  