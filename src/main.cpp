#include "matriz_nova.hpp"
Lista l,L,coord;
Item d;

int main()
{
unordered_map<string,int**>Mat;
Coordenadas(&L, &coord);
nova_matriz(&l,&L);
Transposta(&l, &L,&Mat,&coord);
	

		


	return 0;
}

