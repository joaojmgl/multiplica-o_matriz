#include "DFS.hpp"
int n;
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
		printf("%d\n", p->vet[i].val);
	printf("\n");
	
}
void Matriz_arq(Pilha *p , Item d){
	FILE *arq_m;
	ifstream arq;
	string m;
	arq.open("Matriz_DFS.txt");
	if(arq.is_open()){
		getline(arq, m);
		n = stoi(m);
	}
	arq.close();
	arq_m = fopen("Matriz_DFS.txt","r");
	for ( int l = 0; l < MAXTAM ; l++){
		d.vaux = fgetc(arq_m);
		m=d.vaux;
		if(m == "1"|| m == "0"){
			p->vet[l] = d;
			// cout<<p->vet[l].vaux<<endl;
								
								
		}
	}
}


void Anda_labirinto(Pilha *p /*Item d*/){
  string Matriz[n][n];
  int aux=0;
  for (int l = 0; l < n; l++)
  {  for (int c = 0; c < n; c++)
  {  p->vet[aux].vaux=Matriz[l][c];
	 aux++;
	 cout<<Matriz[l][c]<<endl;

  }
  
	
  }
  


	/* fazer metodo da bolha incrementndo a matriz;
percorrer a matriz utilizando os id de baixo/direita/cima/esquerda;
sempre que nao char para onde ir dar um pop e deixar a posição anterior(posição do ultimo push valendo 1;
*/
}


