/** 
 * Exercício 2 - Catalogo de jogos
 * 
 * Nome: Calvin Suzuki de Camargo 
 * Número USP: 11232420 
 */

#include "Catalogo/catalogo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct catalogo_ {
    JOGO* gameList;
    int nOfGames;
};

/*
 *  Inicializa CATALOGO
 */
CATALOGO* Catalogo() {

    CATALOGO* catalogo = (CATALOGO*) malloc(sizeof(CATALOGO));

    if( catalogo != NULL) {

        catalogo->nOfGames = 0;
        return catalogo;
    }
    
    return NULL;
}

/*
 *  Adiciona novos jogos em um 'catalogo'
 */
CATALOGO* addJogos(CATALOGO* catalogo) {

    JOGO* newGame = NULL;
    char nome[TAM], produtora[TAM], ano[TAM];

    // Adiciona jogos no catalogo ate receber o nome 'F'
    do {

        scanf("%[^\n]%*c", nome);

        // Compara "F\r" e "F" para contornar '\r \n'
        if( strcmp(nome, "F\r") != 0 && strcmp(nome, "F") != 0 ) {

            scanf("%[^\n]%*c", produtora);

            scanf("%[^\n]%*c", ano);

            // Adiciona jogo na lista de jogos
            newGame = Jogo(nome, produtora, ano);
            
            catalogo->nOfGames++;
            catalogo->gameList = insrtJogo(catalogo->gameList, newGame, catalogo->nOfGames);
            newGame = NULL;
        }

    } while( strcmp(nome, "F\r") != 0 && strcmp(nome, "F") != 0 );

    free( newGame );

    return catalogo;
}

CATALOGO* buscaJogos(CATALOGO* catalogo) {

    char nome[TAM], produtora[TAM], ano[TAM];

    // Busca jogos no catalogo ate receber o comando 'F'
    do {

        scanf("%[^\n]%*c", nome);

        // Se comando 'A'
        if ( strcmp(nome, "A\r") == 0 || strcmp(nome, "A") == 0 ) {

            scanf("%[^\n]%*c", ano);
            srcAno( catalogo->gameList, ano, catalogo->nOfGames );
        } 
        // Se comando 'E'
        else if ( strcmp(nome, "E\r") == 0 || strcmp(nome, "E") == 0 ) {

            scanf("%[^\n]%*c", produtora);
            srcProdutora( catalogo->gameList, produtora, catalogo->nOfGames );
        }

    } while( strcmp(nome, "F\r") != 0 && strcmp(nome, "F") != 0);

    return catalogo;
} 

/*
 *  Libera a memoria alocada do vetor de jogos
 */
void destroyCatalogo(CATALOGO* catalogo) {

    free(catalogo->gameList);
    free(catalogo);
    return;
}
