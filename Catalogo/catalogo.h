/** 
 * Exercício 2 - Catalogo de jogos
 * 
 * Nome: Calvin Suzuki de Camargo 
 * Número USP: 11232420 
 */

#ifndef CATALOGO_H
#define CATALOGO_H

#include "Jogo/jogo.h"

typedef struct catalogo_ CATALOGO;

/*
 *  Inicializa CATALOGO
 */
CATALOGO* Catalogo();

/*
 *  Adiciona novos jogos em um 'catalogo'
 */
CATALOGO* addJogos(CATALOGO* catalogo);

CATALOGO* buscaJogos(CATALOGO* catalogo);

/*
 *  Libera a memoria alocada do vetor de jogos
 */
void destroyCatalogo(CATALOGO* catalogo);

#endif