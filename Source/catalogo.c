/** 
 * Trabalho 1 - Lista de Jogos
 * 
 * Nome: Calvin Suzuki de Camargo 
 * Número USP: 11232420 
 * Nome: Guilherme Barros Villela
 * Número USP: 12549936
 */
#include "catalogo.h"
#include <string.h> 
#include <stdio.h>
#include <stdlib.h> 

typedef struct node_st NODE;
static void node_destroy( NODE* );

struct node_st
{
    JOGO *jogo;
    NODE *next;
    NODE *prev;
};

struct catalogo_t 
{
    NODE *begin;
    NODE *end;
    int len;
};

CATALOGO *catalogo_create() {

    CATALOGO *catalogo = (CATALOGO*) malloc( sizeof(CATALOGO) );

    if( catalogo != NULL ) {
        catalogo->begin = NULL;
        catalogo->end = NULL;
        catalogo->len = 0;
    }

    return catalogo;

}

bool catalogo_insert( CATALOGO *catalogo, JOGO *jogo ) {

    if ( catalogo != NULL ) {

        NODE *newNode = (NODE *) malloc( sizeof(NODE) );
        newNode->jogo = jogo;

        // Caso lista vazia
        if ( catalogo->begin == NULL && catalogo->end == NULL ) {

            // O começo da lista é o novoNó
            catalogo->begin = newNode;
            // O anterior é ele mesmo                       
            newNode->prev = newNode;
        }
        else {

            // O fim da lista aponta para o novoNo
            catalogo->end->next = newNode;
            // O anterior do novoNo é fim antigo
            newNode->prev = catalogo->end;            
        }

        // O proximo é o começo da lista
        newNode->next = catalogo->begin;
        // O fim da lista é o novoNó
        catalogo->end = newNode;
        // Incrementa o tamanho da lista
        catalogo->len++;

        return true;

    }

    return false;
}

bool catalogo_remove( CATALOGO *catalogo ) {

    
}

bool catalogo_apagar( CATALOGO **catalogo ) {
    if (*catalogo != NULL)
    {
        node_destroy((*catalogo)->begin);

        free( *catalogo );

        *catalogo = NULL;

        return true;
    }

    return false;
}

static void node_destroy( NODE *node ) {

    if( node != NULL ) {

        if( node->next != NULL )
            destroy_nodes( node->next );

        jogo_apagar( &node->jogo );

        node->prev = NULL;
        free( node );
        node = NULL;
    }
}