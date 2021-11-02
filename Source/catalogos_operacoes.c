/** 
 * Trabalho 1 - Lista de Jogos
 * 
 * Nome: Calvin Suzuki de Camargo 
 * Número USP: 11232420 
 * Nome: Guilherme Barros Villela
 * Número USP: 12549936
 */

#include "Source/catalogo.c"
#include <string.h> 
#include <stdio.h>
#include <stdlib.h> 

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