#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int ** cria_matriz(int tam){
	int ** matriz=(int **) malloc(tam * sizeof(int *));
	for(int i=0;i<tam;i++){
		matriz[i]=(int *) malloc(tam * sizeof(int));
	}
	return matriz;
}

void liga_pcs(int **matriz, int x, int y){
	matriz[x-1][y-1]++;
	matriz[y-1][x-1]++;
	return;
}

void imprime_matriz(int ** matriz, int tam){
	system("clear");
	printf("     ");
	for(int i=0;i<tam;i++){
		printf("%2d  ",i+1);
	}
	printf("\n");
	
	for(int i=0;i<tam;i++){
		printf("%2d  ",i+1);
		for(int k=0;k<tam;k++){
			printf("[%2d]",matriz[i][k]);
		}
		printf("\n");
	}
	printf("\n");
}

void carrega_matriz(int **matriz, int tam){
	int L,C;
	while(1){
		imprime_matriz(matriz, tam);
		printf("Escolha a linha e a coluna referente aos computadores que estaram ligados.\n");
		printf("Digite -1 para sair...\n");
		printf("O Computtador: "); scanf("%d",&L);
		if(L == -1)
			return;
		printf("Se conecta com o computador: "); scanf("%d",&C);
		if(C == -1){
			break;
		}if(L == -1 || C == -1){
			break;
		}
		liga_pcs(matriz, L, C);
	}
}

void ativar(Fila * f, int id){
	for(int i=0;i<f->tam_matriz;i++){
		f->matriz[i][id-1]=-1;
	}
	return;
}

void inativa(Fila * f, int id){
	for(int i=0;i<f->tam_matriz;i++){
		f->matriz[i][id-1]=-1;
		f->matriz[id-1][i]=-1;
	}
	return;
}

void anda(Fila * f, int inicial){
	ativar(f,inicial);
	insere_fila(f, inicial);
	
	while(f->tam > 0){
		mostra_fila(f);
		int id=remove_fila(f);
		//printf("\nRaiz=%d\n",id);
		printf("Mensagem processada por: %d\n",id);
		if(id == -1){
			printf("Lista Vazia...\n");
			break;
		}
		for(int i=0;i<f->tam_matriz;i++){
			if(f->matriz[id-1][i] == 1){
				//printf("Ativa:%d\n",i);
				ativar(f, id);
				if(esta_contido_fila(f,i+1) != 1)
					insere_fila(f,i+1);
				f->matriz[id-1][i]=0;
			}
		}
		//printf("Inativa:%d\n",id);
		inativa(f,id);
	}
}
