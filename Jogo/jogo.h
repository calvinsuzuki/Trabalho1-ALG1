/** 
 * Exercício 2 - Catalogo de jogos
 * 
 * Nome: Calvin Suzuki de Camargo 
 * Número USP: 11232420 
 */

#ifndef JOGO_H
#define JOGO_H

#define TAM 100

typedef struct jogo_ JOGO;

/*
 * Inicializa JOGO
 */
JOGO* Jogo(char* nome, char* produtora, char* ano);

/*
 * Insere um novo jogo em um array de jogos
 */
JOGO* insrtJogo(JOGO* gameList, JOGO* newGame, int nOfGames);

/*
 * Procura um jogo pela produtora em um array de jogos
 */ 
void srcProdutora(JOGO* gameList, char* produtora, int nOfGames);

/*
 * Procura um jogo pelo Ano em um array de jogos
 */ 
void srcAno(JOGO* gameList, char* ano, int nOfGames);

#endif