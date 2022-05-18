#include "DFS.hpp"


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
void Matriz_arq(){
 FILE *arq_m;
	ifstream arq;
	string m;
	int n;	
	//string Matriz[n][n];	
arq.open("Matriz_DFS.txt");
	if(arq.is_open()){
			getline(arq, m);
			n = stoi(m);
			}
			arq.close();
		//n=n-1;
string Matriz[n][n];
arq_m = fopen("Matriz_DFS.txt","r");
			for ( int l = 0; l < n ; l++){
				for (int c = 0; c < n; ){
					m = fgetc(arq_m);
						if(m == "1"|| m == "0"){
							Matriz[l][c] = m;
                   				cout<<Matriz[l][c];
								   c++;
			}
			
			      
			}
			
			// if(getc(arq_m)==1||getc(arq_m)==0){
			// m = getc(arq_m);

			}

}





