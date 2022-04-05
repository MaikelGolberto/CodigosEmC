#include<stdio.h>
#include<stdlib.h>

char* CarregarFrase(void);

int main(void){
//Declaração de variáveis
	char *frase;
	int i;
//Início do Programa
	printf("Exercicio 2\n\n");
//Chamando a função CarregarFrase
	frase = CarregarFrase();
//Exibindo a frase digitada pela função CarregarFrase
	printf("\nVoce digitou:\n");
//Atribuindo o valor "-1" para a variável "i"
	i = -1;
//Do/while para percorrer a variável frase e assim exibir a frase digitada
	do {
		i++;
		printf("%c", frase[i]);	
	} while (frase[i] != '.');
//Liberação do espaço da memória alocado
	free(frase);
//Final do programa
	return EXIT_SUCCESS;
}

char* CarregarFrase(void) {
//Declaração de Variáveis
	int i, qtd;
	char *frase, *fraseTemp;
//Início da Função
//Atribuindo o valor "10" para a variável "qtd" para usar como referência no tamanho da criação da memória dinâmica
	qtd = 20;
//Alocação de memória dinâmica
	frase = (char *) malloc (qtd * sizeof(char));
	if (frase == NULL) {
		printf("Memoria insuficiente");
		exit(EXIT_FAILURE);
	}
//Digitando a frase
	printf("Digite uma frase (encerre com ponto final): \n");
	
	i = 0;
//Do/while para atribuir um caractere digitado para a posição "i" da variável frase	
	do {
		scanf("%c", &frase[i]);
		i++;
//Verifica se vai ser precisa aumentar o tamanho do espaço de memória alocado
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
//Verifica se foi usado todo o espaço de memória alocado, caso não tenha sido usado tudo, faz a liberação de memória do excedente
	if (qtd > i) {
		fraseTemp = (char *) realloc (frase, i * sizeof(char));
		if (fraseTemp == NULL) {
			printf("Erro de memoria!\n");
		} else {
			frase = fraseTemp;
		}		
	} 
//Final da função CarragarFrase
	return frase;
}
