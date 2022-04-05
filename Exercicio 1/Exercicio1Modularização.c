/*
	Estruturas de Dados I - Turma: Ciência da Computação - Noturno 
Número do Exercício: 1 - Modularização
Nome do Arquivo: Exercicio1Modularização.c
Número do Grupo: 01
	Integrantes do Grupo:
		Aluno: Danillo da Paz Cutrim				RGM/Matrícula: 27593886	
		Aluno: João Gabriel Kreimer Torres			RGM/Matrícula: 28017188	
		Aluno: Maikel Golberto Gontijo				RGM/Matrícula: 26837218   
		Aluno: Robert Henrique Rodrigues Moreira	RGM/Matrícula: 26730421 
*/

#include<stdio.h>
#include<locale.h>

void Ler (int * n1, int * n2, int * n3);
void Ordenar (int * menor, int * meio, int * maior);
int Par (int num);

int main(void) {
	
	setlocale(LC_ALL,"Portuguese");
	
	//Declaração de Variáveis
	int num1, num2, num3, parImpar;
	char continua;
	
	//Início do Programa
	printf("Exercício 1\n\n");
	
	do {
		//Chama o procedimento Ler para o usúario digitar três números inteiros.
		Ler(&num1, &num2, &num3); 
		
		//Chama o procedimento Ordenar para ordenar os números digitados pelo usúario em ordem crescente.
		Ordenar(&num1, &num2, &num3); 
		
		/* Atribui o resultado da função Par para a variável parImpar. Passando como paramêtro a variável num3 que é o maior número 
		após o procedimento Ordenar. */
		parImpar = Par(num3); 
		
		//Verifica se parImpar é verdadeiro ou falso, sendo que a função Par retorna 1 ou 0.
		if (parImpar) { 
			printf("Os números ordenados são: %d %d %d (par)", num1, num2, num3);
		} else { 
			printf("Os números ordenados são: %d %d %d (ímpar)", num1, num2, num3);
		}
		
		printf("\nQuer continuar ? (S/N) ");
		fflush(stdin);
		scanf("%c", &continua);
		printf("\n");
		
	} while (continua != 'N');

	return 0;
}

void Ler (int * n1, int * n2, int * n3){
	
	printf("Digite três números inteiros: ");
	fflush(stdin);
	scanf("%d %d %d", n1, n2, n3);
}

void Ordenar (int * menor, int * meio, int * maior){	
	
	int n1 = *menor,
	n2 = *meio,
	n3 = *maior;
	
	if (n3 >= n1 && n3 >= n2) { //Compara o n3 com n1 e n2 para verificar se n3 é o maior, caso n3 seja o maior...
		*maior = n3; 	//mantém n3 como maior
        if (n2 < n1) { 	//Verifica o meio e o menor
            *meio = n1;  //Caso o n2 seja menor do que o n1, n1 passa a ser o meio
            *menor = n2; //e o n2 passa a ser o menor
        } else {  //Caso o n2 seja maior que o n1 entra nesse else
        	*meio = n2; //mantém n2 como meio
        	*menor = n1; //e n1 como menor
		}
    } else if (n1 >= n2  && n1 >= n3) { //Compara o n1 com n2 e n3 para verificar se n1 é o maior, caso n1 seja o maior...
        *maior = n1;     //maior passa a ser o n1
        if (n2 > n3) {  //Verifica o meio e o menor
        	*meio = n2;  //Caso o n2 seja maior do que o n3, mantém o n2 como meio
			*menor = n3; //e n3 passa a ser o menor
        } else {   //Caso n2 seja menor do que o n3, entra nesse else
        	*meio = n3;  //meio passa a ser o n3
        	*menor = n2; //e menor passa a ser o n2
        }
    } else if (n2 >= n1 && n2 >= n3) { //Compara o n2 com n1 e n3 para verificar se n2 é o maior, caso n2 seja o maior...
        *maior = n2;  //maior passa a ser o n2
		if (n1 < n3) {  //Verifica o meio e o menor
        	*meio = n3;  //Caso o n3 seja maior do que o n1, n3 passa a ser o meio
        	*menor = n1; //e mantém n1 como menor
    	} else {   //Caso o n1 seja maior do que o n3, entra nesse else
        	*meio = n1;  //o meio passa a ser n1
        	*menor = n3; //e n3 passa a ser o menor
    	}
	}
}

int Par (int num) {
	
	int resultado;
	
	if (num % 2 == 0) {
		resultado = 1;
	} else {
		resultado = 0;
	}
	return resultado;
}
