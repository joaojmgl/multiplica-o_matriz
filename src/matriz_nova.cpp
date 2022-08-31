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
// LImprime(L);
}


void nova_matriz(Lista *l, Lista *L)
	{
FLVazia(l);
bool L1= true; 
bool J1 = false;
bool I1 = true;
bool J2 = false;
bool I2 = false;
string n,m,z;
int line_couter = 0;
Item aux;
ifstream arq;
int space_couter = 0;
arq.open("Matriz.txt");
for(int i=L->first; i<L->last;){
	if(I1 == true){
		aux.i1 = L->vet[i].val;
		i++;
		J1=true;
	
	} if (J1 == true)
	{
	aux.j1 = L->vet[i].val;
		i++;
		I2 = true;
	} if (I2 == true)
	{
	aux.i2 = L->vet[i].val;
		i++;
		J2 = true;
	} if (J2 == true)
	{
	aux.j2 = L->vet[i].val;
		i++;
		I2 = true;
	} if (I2 == true){
		J1=false;
		I2=false;
		J2=false;
	}
	if (arq.is_open())
		{
		while(!arq.eof())
			{
			if (L1==true){
				getline(arq, n);
				line_couter++;		
			}
			if (line_couter>=aux.i1&&line_couter<=aux.i2){//maximo e minimo do i 
				L1=false;
				m = arq.get();
				if (m == " "){ 
				space_couter++;	
				}
				if (m != " "){   
					if (space_couter>=aux.j1&&space_couter<=aux.j2){//minimo e maximo de j 
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
}


