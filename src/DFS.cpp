#include "DFS.hpp"
int n;
string vetaux[MAXTAM];
// string Matriz[n][n];

void FPVazia(Pilha *p){
	p->top   = 0;
	p->base  = 0;
}


void PUSH(Pilha *p, Item d){
	if (p->top >= MAXTAM){
		printf("PILHA CHEIA!\n");
	}else{
		p->vet[p->top] = d;
		p->top ++;
	}
}

void POP(Pilha *p, Item *d){
	if(p->base == p->top)
		printf("PILHA VAZIA!\n");
	else{
		p->top --;
		*d = p->vet[p->top];
	}
}

void PRemove(Pilha *p, Item d){
	Pilha aux;
	Item rem;

	FPVazia(&aux);

	if(p->base == p->top)
		printf("PILHA VAZIA!\n");
	else{
		while(p->top > p->base){
			POP(p, &rem);
			if(rem.val != d.val)
				PUSH(&aux, rem);
		}

		while(aux.top > aux.base){
			POP(&aux, &rem);
			PUSH(p, rem);
		}
	}
}

void PImprime(Pilha *p){
	for(int i=p->top-1; i>=p->base; i--)
		printf("%d\n", p->vet[i].vall);
	printf("\n");
	
}
void Matriz_arq( Item d){
	FILE *arq_m;
	ifstream arq;
	string m;
	arq.open("Matriz_DFS.txt");
	if(arq.is_open()){
		getline(arq, m);
		n = stoi(m);
	}
	int Total;
	Total=n*n;
	arq.close();
	arq_m = fopen("Matriz_DFS.txt","r");
	for ( int l = 0; l < Total ; ){
		d.vaux = fgetc(arq_m);
		m=d.vaux;
		if(m == "1"|| m == "0"){

			 vetaux[l] = m;
			//  cout<<vetaux[n]<<endl;
								l++;
								
		}
	}
}


void Anda_labirinto(Pilha *p, Item d){	
string Matriz[n][n];
int aux=0;
int l;
int c;

// int x;
for ( l = 0; l < n; l++){
  	for ( c = 0; c < n; c++){ 
		Matriz[l][c]=vetaux[aux];
     	aux++;
		 cout<<Matriz[l][c]<<" ";
  	}
	  cout<<endl;
}
l=0;
c=0;	 
// int Coluna=0;
// int Linha=0;
d.valc=c;
PUSH(p,d);
d.vall=l;
PUSH(p,d);
Matriz[l][c]="X";
while (c!=(n-1)|| l!=(n-1)){
	if (Matriz[l+1][c]=="0"||Matriz[l+1][c]!=Matriz[n-1][c]){
		while (Matriz[l+1][c]=="0"){
			cout << "ATUAL POSIÇÃO: [" << l << "] [" << c << "]" << endl;
			l++; 
			d.vall=l;
			PUSH(p,d);
			Matriz[l][c]="X";
		}
	}

	cout << endl;
	if(Matriz[l][c+1]=="0"||Matriz[l+1][c]!=Matriz[n][c-1]){
		while (Matriz[l][c+1]=="0"){
			cout << "ATUAL POSIÇÃO: [" << l << "] [" << c << "]" << endl;
			c++;
			d.valc=c;
			PUSH(p,d);
			Matriz[l][c]="X";

		}
	}
	

	
}
cout<<c<<endl;
cout<<l<<endl;
 
 for ( l = 0; l < n; l++){
  	for ( c = 0; c < n; c++){ 
		 cout<<Matriz[l][c]<<" ";
  	}
	  cout<<endl;
}
//  PImprime(p);

}


