/** 
 * Trabalho 1 - Lista de Jogos
 * 
 * Nome: Calvin Suzuki de Camargo 
 * Número USP: 11232420 
 * Nome: Guilherme Barros Villela
 * Número USP: 12549936
 */

//  - Caso o usuário entre com a letra “r”, verifica e remove possíveis jogos duplicados no catálogo. 
//  - Caso o usuário entre com a letra “p” (seguido “produtora” - nome da produtora como input), 
// retorna todos os jogos da produtora – mesma função do ex2. 
//  - Caso o usuário entre com a letra “a” (seguido por “ano”), retorna todos os jogos lançados no 
// ano desejado pelo usuário. 
//  - Caso o usuário entre com a letra “i”, imprime o nome de todos os jogos conforme a ordem do 
// catálogo. 
//  - Caso o usuário entre com a letra “u” (seguido por um inteiro “Int”), imprime o jogo na posição 
// “int” do catálogo. 
//  - Caso o usuário entre com a letra “mr” (seguido por dois inteiros “int 1” e “int 2”), o programa 
// deve mover “int 2” casas para a direita o jogo em “int 1”. Ex: mr 3 6  -> o usuário deve mover 6 casas 
// para a direita o jogo que está na casa 3. 
//  - Caso o usuário entre com a letra “ml” (seguido por dois inteiros “int 1” e “int 2”), o programa 
// deve mover “int 2” casas para a esquerda o jogo em “int 1”. Ex: mr 3 6  -> o usuário deve mover 6 casas 
// para a esquerda o jogo que está na casa 3. 
//  - Caso o usuário entre com a letra “f”, o programa deve encerrar e desalocar toda a memória 
// alocada

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