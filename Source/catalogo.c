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
            // O index dele é 0
            set_index(newNode->jogo, 0);
        }
        else {

            // O fim da lista aponta para o novoNo
            catalogo->end->next = newNode;
            // O anterior do novoNo é fim antigo
            newNode->prev = catalogo->end;         
            // O index dele é igual ao index anterior +1
            set_index(newNode->jogo, get_index(newNode->prev->jogo)+1);   
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

                for (i = i; i < catalogo->len; i++)
                {
                    set_index(node->next->jogo, (get_index(node->prev->jogo) + 1));
                }

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

bool catalogo_apagar( CATALOGO **catalogo ) {

    if (*catalogo != NULL)
    {   

        node_destroy( (*catalogo)->begin, (*catalogo)->end );

        printf("\nnodes destroyed!!\n\n");
        free( *catalogo );

        *catalogo = NULL;

        return true;
    }

    return false;
}

static void node_destroy( NODE *node, NODE *nodeEnd ) {

    if( node != NULL ) {

        printf("DELETE GAME %d: %s\n", get_index(node->jogo), get_nome(node->jogo));

        if( node->next != NULL && node != nodeEnd) 
            node_destroy( node->next, nodeEnd );

        jogo_apagar( &node->jogo );

        node->prev = NULL;
        node->next = NULL;
        free( node );
        node = NULL;
    }
}

CATALOGO* catalogo_importFromFile(char* fileName) {

    FILE *csv;
    CATALOGO *catalogo = catalogo_create();

    if ( catalogo == NULL ) {
        return NULL;
    }

    char junk;
    char* nome = (char *) calloc(100, sizeof(char) );
    char* ano = (char *) calloc(100, sizeof(char) );
    char* produtora = (char *) calloc(100, sizeof(char) );

    csv = fopen(fileName, "r");

    if ( csv == NULL ) {

        printf("Erro na leitura do arquivo!!\n");
        exit(1);
    }

    fseek(csv, 3, SEEK_CUR); // ignore the first 3 characters

    while( !feof(csv) ) {

        fscanf(csv, "%[^;]%*c", nome);
        // printf("String: %s\n", str1);

        if( strcmp(nome, "") == 0 ) break;      

        fscanf(csv, "%[^;]%*c", ano);
        // printf("String: %s\n", str2);

        fscanf(csv, "%[^(\n|\r)]", produtora);      
        // printf("String: %s\n", str3);

        catalogo_insert( catalogo, set_jogo( nome, ano, produtora ) );

        fscanf(csv, "%c", &junk);

        if (junk == '\r') {

            fseek(csv, 1, SEEK_CUR); // Skips '/n'
        }

        nome = (char *) calloc(100, sizeof(char) );
        ano = (char *) calloc(100, sizeof(char) );
        produtora = (char *) calloc(100, sizeof(char) );

    }

    free( nome ); free( ano ); free( produtora );
    
    fclose(csv);

    return catalogo;
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

void catalogo_search_empresa(char *lista, CATALOGO *catalogo) {
    char *empresa;
    int count = 0;
    empresa = readLine();
    NODE *node = catalogo->begin;
    for (size_t i = 0; i < (catalogo->len); i++){
        if (strcmp(get_produtora(node->jogo), empresa) == 0)
        {
            strcat(strcat(lista, get_nome(node->jogo)),"\n");
            count++;
        }
        node = node->next;
    }
        if (count == 0)
        {
            strcat(strcat(lista, "Nada encontrado"),"\n");
        }
}

void catalogo_search_ano(char *lista, CATALOGO *catalogo) {
    char *ano;
    int count = 0;
    ano = readLine();
    NODE *node = catalogo->begin;
        for (size_t j = 0; j < (catalogo->len); j++){
            if (strcmp(get_ano(node->jogo), ano) == 0)
            {
                strcat(strcat(lista, get_nome(node->jogo)),"\n");
                count++;
            }
            node = node->next;
        }
        if (count == 0)
        {
            strcat(strcat(lista, "Nada encontrado"),"\n");
        }
}

void catalogo_print(CATALOGO* catalogo) {
    NODE* node = catalogo->begin;
    do
    {
        printf("%s\n", get_nome(node->jogo));
        node = node->next;
    } while (node != catalogo->begin);
    
    
}

JOGO* catalogo_search_index(CATALOGO *catalogo, int index) {
    NODE *node = catalogo->begin;
    for (size_t j = 0; j < index; j++){
        node = node->next;
    }
    return node->jogo;
}