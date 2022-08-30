#include "matriz_nova.hpp"


void FLVazia(Lista *l){
	l->first = 0;
	l->last  = 0;
}

void LInsert(Lista *l, Item d){
	if (l->last >= MAX){
		printf("LISTA CHEIA!\n");
	}else{
		l->vet[l->last] = d;
		l->last ++;
	}
}



void LImprime(Lista *l){
	for(int i=l->first; i<l->last; i++){
		cout << l->vet[i].val << endl ;
	    
	}
}

void Coordenadas(Lista *L){
string n;
ifstream arq_coord;
Item aux;
FLVazia(L);
arq_coord.open("coordenadas.txt");
if (arq_coord.is_open()){
	while(!arq_coord.eof()){
		getline(arq_coord,n,',');
		aux.val = stoi(n);
		LInsert(L, aux);

	}
}
LImprime(L);
}


void nova_matriz(Lista *l)
	{
FLVazia(l);
bool L1= true; 
string n,m,z;
int line_couter = 0;
Item aux;
ifstream arq;
int space_couter = 0;
arq.open("Matriz.txt");
	if (arq.is_open())
		{
		while(!arq.eof())
			{
			if (L1==true){
				getline(arq, n);
				line_couter++;		
			}
			if (line_couter>=2&&line_couter<=4){//maximo e minimo do i 
				L1=false;
				m = arq.get();
				if (m == " "){ 
				space_couter++;	
				}
				if (m != " "){   
					if (space_couter>=2&&space_couter<=4){//minimo e maximo de j 
						z+=m;
					}
				}else{
					if( z != "\0"){
						aux.val = stoi(z);
						LInsert(l, aux);
						z = "\0";
					}
				}         
				if(space_couter == 5){   
						L1 = true;
						space_couter = 0;
				}  
			}
 		}
	}
LImprime(l);

}


