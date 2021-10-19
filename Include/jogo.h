/** 
 * Exercício 2 - Catalogo de jogos
 * 
 * Nome: Calvin Suzuki de Camargo 
 * Número USP: 11232420 
 * Nome: Guilherme Barros Villela
 * Número USP: 12549936
 */
#ifndef JOGO_H
#define JOGO_H 
#include "util.h"
#include <stdbool.h>

typedef struct jogo_t JOGO;

JOGO *set_jogo(char* nome, char* produtora, char* ano);
char *get_produtora(JOGO* joguinho);
char *get_ano(JOGO* joguinho);
char *get_nome(JOGO* joguinho);
bool jogo_apagar(JOGO **jogo);

#endif //JOGO_H  