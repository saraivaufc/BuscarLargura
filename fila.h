#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo_{
	int id_pc;
	struct Nodo_ * prox;
	struct Nodo_ * ant;
}Nodo;

typedef struct Fila_{
	int tam;
	Nodo * primeiro;
	Nodo * ultimo;
	int **matriz;
	int tam_matriz;
}Fila;

Nodo * cria_nodo(int id){
	Nodo * novo=(Nodo *) malloc(sizeof(Nodo));
	novo->id_pc=id;
	novo->prox=NULL;
	novo->ant=NULL;
	return novo;
}

Fila * cria_fila(int **matriz, int tam_matriz){
	Fila * nova=(Fila *) malloc(sizeof(Fila));
	nova->tam=0;
	nova->primeiro=NULL;
	nova->ultimo=NULL;
	nova->matriz=matriz;
	nova->tam_matriz=tam_matriz;
	return nova;
}

void insere_fila(Fila * f, int id){
	Nodo * novo=cria_nodo(id);
	if(f->tam == 0){
		f->ultimo=novo;
		f->primeiro=novo;
	}else{
		f->ultimo->prox=novo;
		novo->ant=f->ultimo;
		f->ultimo=novo;
	}
	f->tam++;
}

int remove_fila(Fila * f){
	int x=-1;
	if(f->tam == 0){
		printf("Fila Vazia...\n");
	}else{
		x=f->primeiro->id_pc;
		Nodo * a=f->primeiro;
		f->primeiro=f->primeiro->prox;
		free(a);
		f->tam--;
	}
	return x;
}

int esta_contido_fila(Fila * f, int valor){
	for(Nodo * aux=f->primeiro; aux != NULL ; aux=aux->prox){
		if(aux->id_pc == valor){
			return 1;
		}
	}
	return 0;
}

void mostra_fila(Fila * f){
	for(Nodo * aux=f->primeiro; aux != NULL ; aux=aux->prox){
		printf("[%2d]",aux->id_pc);
	}
	printf("\n");
}

#endif
