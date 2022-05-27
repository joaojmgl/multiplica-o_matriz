#include "DFS.hpp"
int n;
string vetaux[MAXTAM];
// string Matriz[n][n];

void FPVazia(Pilha *p){
	p->base = (Block*) malloc (sizeof(Block));
	p->top  = p->base;
	p->base->prox = NULL;
}

void Push(Pilha *p, Item d){
	Block *aux = (Block*) malloc (sizeof(Block));
	aux->data = d;
	aux->prox = p->top;
	p->top = aux;
}

void Pop(Pilha *p, Item *d){
	Block *aux;

	if(p->base == p->top || p == NULL){
		printf("PILHA VAZIA!\n");
		return;
	}
	
	aux = p->top;
	p->top = aux->prox;
	*d = aux->data;
	free(aux);
}


void PImprime(Pilha *p){
	Block *aux;

	aux = p->top;
	while(aux != p->base){
		printf("%d\n", aux->data.val);
		aux = aux->prox;
	}

}
void Matriz_arq( Item_1 d){
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


void Anda_labirinto(){
Pilha column,lines;
Item co,li;	
string Matriz[n][n];
bool Limite=false;
int aux=0,l,c,Coluna=0,Linha=0;
for ( l = 0; l < n; l++){
  	for ( c = 0; c < n; c++){ 
		Matriz[l][c]=vetaux[aux];
     	aux++;
		cout<<Matriz[l][c]<<" ";
  	} 
	  cout<<endl;
}

FPVazia(&column);
FPVazia(&lines);
l=0;c=0;	 
li.val= l;
co.val= c;
Push(&lines,li );
Push(&column, co );
Matriz[l][c]="I";
while (Limite==false){
	

	
		
			if(l<(n-1)&&Matriz[l+1][c]=="0"){
				 while (l!=(n-1)&&Matriz[l+1][c]=="0"){
					
					    l++; 
						li.val=l;
						Push(&lines, li);
						Matriz[l][c]="v"; 	
						Linha++;
						cout<<"baixo"<<endl;
						cout<<c<<endl;
						cout<<l<<endl;			
					
					
				}		
			}
				else if(c<(n-1)&&Matriz[l][c+1]=="0"){
					while (c!=(n-1)&&Matriz[l][c+1]=="0"){
					
					c++;
					co.val = c;
					Push(&column,co);
					Matriz[l][c]=">";
					Coluna++;
					cout<<"direita"<<endl;
					
				
			}	
		}
	
	
			
				else if(Coluna!=0&&c>0){
					    cout<<"POP Coluna"<<endl;
						Matriz[l][c]="P";
						co.val = c;
						Pop(&column,&co);
						Coluna--;
						c--;
								
					
					
				}
		
	
		
			else if(Linha!=0&&l>0){
				    cout<<"POP Linha"<<endl;
					Matriz[l][c]="P";
					li.val = l;
					Pop(&lines,&li);
					Linha--;
					l--;
					
					
				
			} 

			 if((n-1)*(n-1)==l*c){
						Limite=true;
			}
}
 
 for ( l = 0; l < n; l++){
  	for ( c = 0; c < n; c++){ 
		 cout<<Matriz[l][c]<<" ";
  	}
	  cout<<endl;
}


}


