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

	CATALOGO *catalogo = catalogo_importFromFile("CSV.csv");

	char option[100];

	do
	{	
		scanf(" %[^(\r|\n| )]%*c", option); 

		if (strcmp(option, "r") == 0) // Remove duplicados
		{
			catalogo = catalogo_remove_duplicates(catalogo);
			catalogo_print(catalogo);

		}
		else if (strcmp(option, "p") == 0) // Pesquisa por produtora
		{	
			char *busca = readLine();

			catalogo_srcProdutora( catalogo, busca);

			free ( busca );
		}
		else if (strcmp(option, "a") == 0) // Pesquisa por ano
		{
			char *busca = readLine();

			catalogo_srcAno( catalogo, busca);

			free ( busca );
		}
		else if (strcmp(option, "i") == 0) // Imprime catalogo
		{
			catalogo_print(catalogo);
		}
		else if (strcmp(option, "u") == 0) // Imprime jogo dado uma posicao
		{
			int index; 
			scanf("%d", &index);
			printf( "%s\n", jogo_getNome( catalogo_srcIndex(catalogo, index) ) );
 
		}
		else if (strcmp(option, "f") != 0)
		{
			printf("Comando Inválido \n");
		}
		
	} while( strcmp(option, "f") != 0 );

	catalogo_apagar( &catalogo );

	// Assassin's Creed;2007;Ubisoft
	// Assassin's Creed IV: Black Flag;2013;Ubisoft
	// DmC: Devil May Cry;2013;Ninja Theory
	// Dragon Quest VII;2000;Square Enix
	// Fable;2004;Lionhead Studios
	// Assassin's Creed IV: Black Flag;2013;Ubisoft

	return 0;
}
