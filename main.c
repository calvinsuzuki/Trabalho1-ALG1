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

CATALOGO* importCatalogoFromFile();

int main() {

	CATALOGO *catalogo = importCatalogoFromFile();

	catalogo_print( catalogo );

	catalogo_apagar( &catalogo );

	// Assassin's Creed;2007;Ubisoft
	// Assassin's Creed IV: Black Flag;2013;Ubisoft
	// DmC: Devil May Cry;2013;Ninja Theory
	// Dragon Quest VII;2000;Square Enix
	// Fable;2004;Lionhead Studios
	// Assassin's Creed IV: Black Flag;2013;Ubisoft

	return 0;
}

CATALOGO* importCatalogoFromFile() {

	FILE *csv;
	CATALOGO *catalogo = catalogo_create();

	if ( catalogo == NULL ) {
		return NULL;
	}

	char junk;
	char* nome = (char *) calloc(100, sizeof(char) );
    char* ano = (char *) calloc(100, sizeof(char) );
    char* produtora = (char *) calloc(100, sizeof(char) );

	csv = fopen("CSV.csv", "r");

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

