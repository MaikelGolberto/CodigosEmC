/*
	Estruturas de Dados I - Turma: Ci�ncia da Computa��o - Noturno 
N�mero do Exerc�cio: 2 - Vetor e Aloca��o
Nome do Arquivo: Exercicio2AlocacaoDinamica.c
N�mero do Grupo: 01
	Autores:
		Aluno: Danillo da Paz Cutrim				RGM/Matr�cula: 27593886	
		Aluno: Jo�o Gabriel Kreimer Torres			RGM/Matr�cula: 28017188	
		Aluno: Maikel Golberto Gontijo				RGM/Matr�cula: 26837218   
		Aluno: Robert Henrique Rodrigues Moreira	RGM/Matr�cula: 26730421 
*/

#include<stdio.h>
#include<stdlib.h>

char* CarregarFrase(void);

int main(void){
//Declara��o de vari�veis
	char *frase;
	int i;
//In�cio do Programa
	printf("Exercicio 2\n\n");
//Chamando a fun��o CarregarFrase
	frase = CarregarFrase();
//Exibindo a frase digitada pela fun��o CarregarFrase
	printf("\nVoce digitou:\n");
//Atribuindo o valor "-1" para a vari�vel "i"
	i = -1;
//Do/while para percorrer a vari�vel frase e assim exibir a frase digitada
	do {
		i++;
		printf("%c", frase[i]);	
	} while (frase[i] != '.');
//Libera��o do espa�o da mem�ria alocado
	free(frase);
//Final do programa
	return EXIT_SUCCESS;
}

char* CarregarFrase(void) {
//Declara��o de Vari�veis
	int i, qtd;
	char *frase, *fraseTemp;
//In�cio da Fun��o
//Atribuindo o valor "10" para a vari�vel "qtd" para usar como refer�ncia no tamanho da cria��o da mem�ria din�mica
	qtd = 20;
//Aloca��o de mem�ria din�mica
	frase = (char *) malloc (qtd * sizeof(char));
	if (frase == NULL) {
		printf("Memoria insuficiente");
		exit(EXIT_FAILURE);
	}
//Digitando a frase
	printf("Digite uma frase (encerre com ponto final): \n");
	
	i = 0;
//Do/while para atribuir um caractere digitado para a posi��o "i" da vari�vel frase	
	do {
		scanf("%c", &frase[i]);
		i++;
//Verifica se vai ser precisa aumentar o tamanho do espa�o de mem�ria alocado
		if (i == qtd) {
			qtd = qtd + 10;
			fraseTemp = (char *) realloc (frase, qtd * sizeof(char));
			if (fraseTemp == NULL) {
				printf("Memoria insuficiente");
				exit(1);
			} else {
				frase = fraseTemp;
			}
		}
	} while (frase[i - 1] != '.');
//Verifica se foi usado todo o espa�o de mem�ria alocado, caso n�o tenha sido usado tudo, faz a libera��o de mem�ria do excedente
	if (qtd > i) {
		fraseTemp = (char *) realloc (frase, i * sizeof(char));
		if (fraseTemp == NULL) {
			printf("Erro de memoria!\n");
		} else {
			frase = fraseTemp;
		}		
	} 
//Final da fun��o CarragarFrase
	return frase;
}
