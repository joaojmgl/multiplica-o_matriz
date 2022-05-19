#ifndef DFS_HPP 
#define DFS_HPP
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

#define MAXTAM 100


typedef struct Item{
	int val;
	string vaux;
}Item;

typedef struct Pilha{
	Item vet[MAXTAM];
    Item naux;
	int top;
	int base;
}Pilha;

void FPVazia(Pilha *p);
void PUSH(Pilha *p, Item d);
void POP(Pilha *p, Item *d);
void PRemove(Pilha *p, Item d);
void PImprime(Pilha *p);
void Matriz_arq(Pilha *p, Item m);
void Anda_labirinto(Pilha *p /*Item d*/);


#endif


// arroz integral 
// macarrao 
// alface tomate 
// contra file 
// fritas
