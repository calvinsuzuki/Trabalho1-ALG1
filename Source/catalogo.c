/** 
 * Trabalho 1 - Lista de Jogos
 * 
 * Nome: Calvin Suzuki de Camargo 
 * Número USP: 11232420 
 * Nome: Guilherme Barros Villela
 * Número USP: 12549936
 */

#include "Include/catalogo.h"
#include <string.h> 
#include <stdio.h>
#include <stdlib.h> 

typedef struct node_st NODE;

static void node_destroy( NODE* );
//static *NODE node_search( int );

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

static void node_destroy( NODE *node );
// static *NODE node_search( int index );

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

bool catalogo_remove( CATALOGO *catalogo, int index ) {

    if ( catalogo != NULL ) {

        if ( catalogo->len == 0 ) { // Caso o catalogo esteja vazio
            return false;
        }

        NODE *node = catalogo->begin;

        for( int i = 0; i < catalogo->len; i++ ) {

            if( get_index( node->jogo ) == index ) {

                node->prev->next = node->next;
                node->next->prev = node->prev;

                node->prev = NULL;
                node->next = NULL;
                free( node );

                return true;

            }
            else {

                node = node->next;
            }
        }
    }

    return false;
}

// static *NODE node_search( int index ) {

//     if( node != NULL ) {

//         if( get_index(node->jogo) == index ) {
//             return node;
//         }

//         else if( node->next != NULL ) {
//             node_comp( node->next )
//         } 
//     }
// }



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
            node_destroy( node->next );

        jogo_apagar( &node->jogo );

        node->prev = NULL;
        free( node );
        node = NULL;
    }
}

CATALOGO* catalogo_remove_duplicates(CATALOGO* catalogo){
    int counter = 0, index_aux = 1;
    NODE* node = catalogo->begin, *node_auxiliar = node;
    while (counter < catalogo->len)
    {
        for (size_t i = 0; i < (catalogo->len-counter); i++)
        {
            if (strcmp(get_nome(node->jogo), get_nome(node_auxiliar->next->jogo)) == 0)
            {
                catalogo_remove(catalogo, index_aux);
            }
            else
            {
                node_auxiliar = node_auxiliar->next;
                index_aux++;
            }
        }
        counter++;
        node = node->next;
        node_auxiliar = node; 
    }
    return catalogo;     
}