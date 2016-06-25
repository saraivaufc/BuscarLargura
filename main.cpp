#include <stdio.h>
#include <stdlib.h>
#include "funcoes.cpp"
#include "fila.h"
#include "teste.cpp"

int main(){
	char tipo;
	printf("Vc quer Manual ou Automatico (m/a):");
	scanf("%c",&tipo);

	if(tipo == 'a'){
/*
 * Altere aqui para alternar os testes, para cada teste, existe uma imagem
 * nessa mesma pasta referente ao grafo do teste
 */
		int teste;
		printf("Vc quer TESTE1 ou TESTE2 (1/2):");
		scanf("%d",&teste);
			int quant_pc;
			int **matriz;
		if(teste == 1){
			quant_pc=6;
			matriz=cria_matriz(quant_pc);
			teste1(matriz);
		}else{
			quant_pc=9;
			matriz=cria_matriz(quant_pc);
			teste2(matriz);
		}
		system("clear");
		Fila * f=cria_fila(matriz, quant_pc);
		anda(f,1);
	}else if(tipo == 'm'){
		int quant_pc;
		printf("Quantos Computadores você quer:");
		scanf("%d",&quant_pc);
		int **matriz=cria_matriz(quant_pc);
		carrega_matriz(matriz, quant_pc);
		system("clear");
		Fila * f=cria_fila(matriz, quant_pc);
		anda(f,1);
	}
	return 0;
}
