#ifndef MATRIZ_NOVA_H
#define MATRIZ_NOVA_H
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string>
#include <iostream>
using namespace std;
#define MAX 100
typedef struct Item{
    int val;
    string vall;
}Item;
typedef struct Lista{
    Item vet[MAX];
	int first;
	int last;
	
}Lista;

void nova_matriz(Lista *l,Lista *L);
void FLVazia(Lista *l);
void LInsert(Lista *l, Item d);
void LImprime(Lista *l);
void Coordenadas(Lista *L);
void Transposta(Lista *l, Lista *L);
#endif
