/** 
 * Trabalho 1 - Lista de Jogos
 * 
 * Nome: Calvin Suzuki de Camargo 
 * Número USP: 11232420 
 * Nome: Guilherme Barros Villela
 * Número USP: 12549936
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Include/Util.h"

void bool_print(bool boolean)
{
    if(boolean == true)
    {
        printf("TRUE\n");
    }
    else if(boolean == false)
    {
        printf("FALSE\n");
    }
    else
    {
        printf("ERRO\n");
    }
}
