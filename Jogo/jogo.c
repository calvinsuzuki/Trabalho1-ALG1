/** 
 * Exercício 2 - Catalogo de jogos
 * 
 * Nome: Calvin Suzuki de Camargo 
 * Número USP: 11232420 
 */

#include "Jogo/jogo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct jogo_ {
    char nome[TAM];
    char produtora[TAM];
    char ano[TAM];
};

/*
 * Inicializa JOGO
 */
JOGO* Jogo(char* nome, char* produtora, char* ano) {

    JOGO* jogo = (JOGO*) malloc( sizeof(JOGO) );

    if( jogo != NULL) {

        strcpy(jogo->nome, nome);
        strcpy(jogo->produtora, produtora);
        strcpy(jogo->ano, ano);

        return jogo;
    }

    return NULL;
}

    

/*
 * Insere um novo jogo em um array de jogos
 */
JOGO* insrtJogo(JOGO* gameList, JOGO* newGame, int nOfGames) {
    
    // Se contador = 1, atribua os dados do jogo
    if( nOfGames == 1) {

        JOGO* newGameList = newGame;

        return newGameList;

    } 
    // Se nao, realize push de um novo jogo
    else { 

        JOGO *newGameList = (JOGO*) realloc(gameList, nOfGames * sizeof(JOGO));

        // Caso falha no realloc
        if (newGameList == NULL) return gameList;   

        else {
            // Atribui os dados do jogo
            strcpy(newGameList[nOfGames-1].nome, newGame->nome);
            strcpy(newGameList[nOfGames-1].produtora, newGame->produtora);
            strcpy(newGameList[nOfGames-1].ano, newGame->ano);
            return newGameList;
        }
    }
}

/*
 * Procura um jogo pela produtora
 */ 
void srcProdutora(JOGO* gameList, char* produtora, int nOfGames) {

    int encontrado = 0;
    //char** search = (char**) malloc(3 * sizeof( char** ));

    // Caso lista de jogo seja vazia
    if( nOfGames == 0 ) {
        printf("Nada encontrado\n");
    }

    for(int i = 0; i < nOfGames; i++) {
        if( strcmp(produtora, gameList[i].produtora) == 0) {
            printf("%s\n", gameList[i].nome);
            encontrado = 1;
        }
    }

    if( !encontrado ) {
        printf("Nada encontrado\n");
    }

    return;
}

/*
 * Procura um jogo pelo Ano em um array de jogos
 */ 
void srcAno(JOGO* gameList, char* ano, int nOfGames) {

    int encontrado = 0;

    // Caso lista de jogo seja vazia
    if( nOfGames == 0 ) {
        printf("Nada encontrado\n");
    }

    for(int i = 0; i < nOfGames; i++) {
        if( strcmp(ano, gameList[i].ano) == 0) {
            printf("%s\n", gameList[i].nome);
            encontrado = 1;
        }
    }

    if( !encontrado ) {
        printf("Nada encontrado\n");
    }

    return;
}