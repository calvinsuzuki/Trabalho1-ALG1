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

static void node_destroy( NODE *node, NODE *nodeEnd );
static CATALOGO* catalogo_organize( CATALOGO *catalogo );

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

bool catalogo_push( CATALOGO *catalogo, JOGO *jogo ) {

    if ( catalogo != NULL ) {

        NODE *newNode = (NODE *) malloc( sizeof(NODE) );
        newNode->jogo = jogo;

        // Caso lista vazia
        if ( catalogo->begin == NULL && catalogo->end == NULL ) {

            // O começo da lista é o novoNó
            catalogo->begin = newNode;
            // O anterior é ele mesmo                       
            newNode->prev = newNode;    
            // O index dele é 0
            jogo_set_index(newNode->jogo, 0);
        }
        else {

            // O fim da lista aponta para o novoNo
            catalogo->end->next = newNode;
            // O anterior do novoNo é fim antigo
            newNode->prev = catalogo->end;         
            // O index dele é igual ao index anterior +1
            jogo_set_index(newNode->jogo, jogo_get_index(newNode->prev->jogo)+1);   
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

bool catalogo_insert( CATALOGO *catalogo, JOGO *jogo, int index ) {

    if ( catalogo != NULL ) {

        if ( catalogo->begin == NULL && catalogo->end == NULL ){

            
        }

        return true;

    }

    return false;
}

static NODE* node_getFromDepth( NODE* begin, int depth ) {

    if ( begin != NULL ) {    

        NODE *node = begin;

        for( int i = 0; i < depth; i++ ) {
            if( node->next != NULL)
                node = node->next;
        }

        return node;
    }

    return NULL;
}

static CATALOGO* catalogo_organize( CATALOGO *catalogo ) {

    NODE *node = catalogo->begin;

    if( catalogo != NULL ) {

        for( int i = 0; i < catalogo->len; i++ ) {

            if( node != NULL && node->next != NULL ) {

                jogo_set_index(node->jogo, i); 

                node = node->next;
            }
        }

        return catalogo;
    }

    return NULL;
}

bool catalogo_remove( CATALOGO *catalogo, int index ) {

    if ( catalogo != NULL ) {

        if ( catalogo->len == 0 ) { // Caso o catalogo esteja vazio
            return false;
        }

        NODE *node = catalogo->begin;

        for( int i = 0; i < catalogo->len; i++ ) {

            if( jogo_get_index( node->jogo ) == index ) {
                if (node == catalogo->begin)
                {
                    catalogo->begin = node->next;
                }
                if (node == catalogo->end)
                {
                    catalogo->end = node->prev;
                }   
                node->prev->next = node->next;
                node->next->prev = node->prev;

                jogo_apagar( &node->jogo );
                node->prev = NULL;
                node->next = NULL;
                free( node );
                node = NULL;
                catalogo->len--;

                catalogo_organize(catalogo);

                return true;

            }
            else {

                node = node->next;
            }
        }
    }

    return false;
}

bool catalogo_apagar( CATALOGO **catalogo ) {

    if (*catalogo != NULL)
    {   
        node_destroy( (*catalogo)->begin, (*catalogo)->end );
        //printf("\nnodes destroyed!!\n\n");
        free( *catalogo );
        *catalogo = NULL;
        return true;
    }

    return false;
}

static void node_destroy( NODE *node, NODE *nodeEnd ) {

    if( node != NULL ) {

        // printf("DELETE GAME %d: %s\n", get_index(node->jogo), get_nome(node->jogo));
        if( node->next != NULL && node != nodeEnd) 
            node_destroy( node->next, nodeEnd );

        jogo_apagar( &node->jogo );
        node->prev = NULL;
        node->next = NULL;
        free( node );
        node = NULL;
    }
}

CATALOGO* catalogo_import_from_file(char* fileName) {

    FILE *csv;
    CATALOGO *catalogo = catalogo_create();
    char junk, *nome, *ano, *produtora;

    if ( catalogo == NULL ) { // Erro na alocacao
        exit(1);
    }    

    csv = fopen( fileName, "r" );

    if ( csv == NULL ) {
        printf("Erro na leitura do arquivo!!\n");
        exit(1);
    }

    fseek(csv, 3, SEEK_CUR); // Ignora os 3 primeiros chars

    while( !feof(csv) ) {

        nome = (char *) calloc(100, sizeof(char) );
        ano = (char *) calloc(100, sizeof(char) );
        produtora = (char *) calloc(100, sizeof(char) );

        fscanf(csv, "%[^;]%*c", nome);

        if( strcmp(nome, "") == 0 ) break;  // Caso leitura de string vazia    

        fscanf(csv, "%[^;]%*c", ano);

        fscanf(csv, "%[^(\n|\r)]", produtora);      

        catalogo_push( catalogo, jogo_create( nome, ano, produtora ) );

        fscanf(csv, "%c", &junk); // Captura o proximo caractere do arquivo

        if (junk == '\r') {

            fseek(csv, 1, SEEK_CUR); // Pula o '/n'
        }        
    }

    free( nome ); free( ano ); free( produtora );
    
    fclose(csv);

    return catalogo;
}

void catalogo_remove_duplicates(CATALOGO* catalogo){
    int counter = 1, index_aux = 1;
    NODE* node = catalogo->begin, *node_auxiliar = node;
    while (counter < catalogo->len)
    {
        for (size_t i = 0; i < (catalogo->len-counter); i++)
        {
            if (strcmp(jogo_get_nome(node->jogo), jogo_get_nome(node_auxiliar->next->jogo)) == 0)
            {
                catalogo_remove(catalogo, jogo_get_index(node_auxiliar->next->jogo));
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
}

void catalogo_src_produtora(CATALOGO *catalogo, char *produtora) {

    NODE *node;
    bool notFound = true; 

    if( catalogo->begin == NULL ) { // Catalogo vazio!
        printf( "Nada encontrado\n" );
        return;
    }        
    else {
        node = catalogo->begin;
    }

    do {        
        if( strcmp( jogo_get_produtora(node->jogo), produtora) == 0 ) {

            printf( "%s\n", jogo_get_nome(node->jogo) );
            notFound = false;
        }

        if ( node->next != NULL)
            node = node->next;

    } while (node != catalogo->begin); 

    if( notFound ) {

        printf( "Nada encontrado\n" );        
    }

    return;
}

void catalogo_src_ano(CATALOGO *catalogo, char *ano) {
    NODE *node;
    bool notFound = true; 

    if( catalogo->begin == NULL ) { // Catalogo vazio!
        printf( "Nada encontrado\n" );
        return;
    }        
    else {
        node = catalogo->begin;
    }

    do {        
        if( strcmp( jogo_get_ano(node->jogo), ano) == 0 ) {

            printf( "%s\n", jogo_get_nome(node->jogo) );
            notFound = false;
        }

        if ( node->next != NULL)
            node = node->next;

    } while (node != catalogo->begin); 

    if( notFound ) {

        printf( "Nada encontrado\n" );        
    }

    return;
}

void catalogo_print(CATALOGO* catalogo) {
    NODE* node = catalogo->begin;
    do
    {
        printf( "%s\n", jogo_get_nome(node->jogo) );
        node = node->next;
    } while (node != catalogo->begin);  
}

JOGO* catalogo_src_index(CATALOGO *catalogo, int index) {
    NODE *node = catalogo->begin;
    for (size_t j = 0; j < index; j++){
        node = node->next;
    }
    return node->jogo;
}