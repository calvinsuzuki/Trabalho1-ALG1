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

	CATALOGO *catalogo = catalogo_import_from_file("CSV.csv");

	char option[100];

	do
	{	
		scanf(" %[^(\r|\n| )]%*c", option); 

		if (strcmp(option, "r") == 0) // Remove duplicados
		{
			catalogo_remove_duplicates(catalogo);

		}
		else if (strcmp(option, "p") == 0) // Pesquisa por produtora
		{	
			char *busca = readLine();

			catalogo_src_produtora( catalogo, busca);

			free ( busca );
		}
		else if (strcmp(option, "a") == 0) // Pesquisa por ano
		{
			char *busca = readLine();

			catalogo_src_ano( catalogo, busca);

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
			printf( "%s\n", jogo_get_nome( catalogo_src_index(catalogo, index) ) );
 
		}
		else if (strcmp(option, "mr") == 0) // Move jogo para a direita
		{
			int index, moves; 
			scanf(" %d", &index);
			scanf(" %d", &moves);

			catalogo_move_jogo( catalogo, index, moves );	 
		}
		else if (strcmp(option, "ml") == 0) // Move jogo para a esquerda
		{
			int index, moves; 
			scanf(" %d", &index);
			scanf(" %d", &moves);

			catalogo_move_jogo( catalogo, index, -moves ); 
		}
		else if (strcmp(option, "f") != 0)
		{
			printf("Comando Inválido \n");
		}
		
		
	} while( strcmp(option, "f") != 0 );

	catalogo_apagar( &catalogo );

	return 0;
}
