#include<stdio.h> 

char* receber_dado(char *dado){
    scanf("%[^\n]%*c", dado); 
    return dado;
}