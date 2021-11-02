/** 
 * Trabalho 1 - Lista de Jogos
 * 
 * Nome: Calvin Suzuki de Camargo 
 * Número USP: 11232420 
 * Nome: Guilherme Barros Villela
 * Número USP: 12549936
 */

#include "Include/catalogo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	CATALOGO* catalogo = Catalogo();

	addJogos( catalogo );

	buscaJogos( catalogo );

	destroyCatalogo( catalogo );
	
	return 0;
}