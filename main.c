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

int main() {

	CATALOGO* catalogo = Catalogo();

	addJogos( catalogo );

	buscaJogos( catalogo );

	destroyCatalogo( catalogo ); // jogos gratuitos! So que nao...
	
	return 0;
}