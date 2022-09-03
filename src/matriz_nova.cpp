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
		cout << l->vet[i].val<<endl;

	}
}


void Coordenadas(Lista *L, Lista *coord){
string n;
ifstream arq_coord;
Item aux;
FLVazia(L);
arq_coord.open("coordenadas.txt");
if (arq_coord.is_open()){
	while(!arq_coord.eof()){
		n=arq_coord.get();
     if(n=="1"||n=="2"||n=="3"||n=="4"||n=="5"||n=="6"||n=="7"||n=="8"||n=="9"||n=="0"){
			aux.val = stoi(n);
			LInsert(L, aux);
			aux.vall=n;
			LInsert(coord, aux);
			}
		

	}

}
}


void nova_matriz(Lista *l, Lista *L)
	{
		

FLVazia(l);
bool L1= true; 
int i1,j1,i2,j2;
string n,m,z;
int line_couter = 0;
Item aux;
ifstream arq;
int space_couter = 0;

for(int i=L->first; i<L->last;){
	arq.open("Matriz.txt");
	i1 = L->vet[i].val;
	i++;
	j1 = L->vet[i].val;
	i++;
	i2 = L->vet[i].val;
	i++;
	j2 = L->vet[i].val;
	i++;
	
	if (arq.is_open())
		{
		while(!arq.eof())
			{
			if (L1==true){
				getline(arq, n);
				line_couter++;		
			}
			if (line_couter>=i1&&line_couter<=i2){//maximo e minimo do i 
				L1=false;
				m = arq.get();
				if (m == " "){ 
				space_couter++;	
				}
				if (m != " "){   
					if (space_couter>=j1&&space_couter<=j2){//minimo e maximo de j 
						z+=m;
					}
				}else{
					if( z != "\0"){
						aux.val = stoi(z);
						LInsert(l, aux);
						z = "\0";
					}
				}         
				if(space_couter ==j2+1){   
						L1 = true;
						space_couter = 0;
				}  
			}
 		}
	}		
			arq.close();
			line_couter = 0 ; 
}

// LImprime(l);
}


void Transposta(Lista *l, Lista *L, unordered_map<string,int**>*Mat,Lista *coord){ 
	int** Matriz_transposta=0;
	int** Matriz=0;
	int** Matriz_nova=0;
	int i1,j1,i2,j2,coluna,linha,cont=0;
	int** matrizprint = 0;
	string key;

	for(int i=L->first; i<L->last;){
		i1 = L->vet[i].val;
		key+=coord->vet[i].vall;
		i++;
		j1 = L->vet[i].val;
		key+=coord->vet[i].vall;
		i++;
		i2 = L->vet[i].val;
		key+=coord->vet[i].vall;
		i++;
		j2 = L->vet[i].val;
		key+=coord->vet[i].vall;
		i++;
		i1-=1;
		j1-=1;
		linha=i2-i1;
		coluna=j2-j1;
		auto search = Mat->find(key);
		if (search == Mat->end()) {
			Matriz=new int*[linha];
			cout<<"Matriz original :"<<endl;
			for (int j = 0; j != coluna; j++)
			{	
				Matriz[j]=new int[coluna];
				for (int c=0; c != linha; c++)
				{
					
					Matriz[j][c]=l->vet[cont].val;
					cont++;
					cout<<Matriz[j][c]<<" ";
					
				}
				cout<<endl;
			}

			Matriz_transposta = new int*[coluna];
			cout<<"Matriz transposta :"<<endl;
			for (int j = 0; j < coluna; j++) {
				Matriz_transposta[j] = new int[linha];
				for (int c = 0; c < linha; c++) {
					Matriz_transposta[j][c] = Matriz[c][j];
					cout<<Matriz_transposta[j][c]<<" ";
				}
				cout<<endl;
			}

			Matriz_nova = new int*[linha];
			int soma=0;
			cout<<"Matriz multiplicada :"<<endl;
			for (int m = 0; m < linha; m++)
			{
				Matriz_nova[m]=new int[linha];
				for (int j  = 0; j < linha; j++)
				{
					soma=0;
					for (int c = 0; c < coluna; c++)
					{
						soma+=(Matriz[m][c]*Matriz_transposta[c][j]);
					}
					Matriz_nova[m][j]=soma;
					
					cout<<Matriz_nova[m][j]<<" ";
				}
				cout<<endl;
			}
			Mat->emplace(key,Matriz_nova);
		}else{
			cout<<"Estas cordenadas ja foram inseridas no sistema:"<<key<<endl;
			for (auto item: *Mat) 
			{
				if (item.first == key) 
				 {
				matrizprint = item.second;
				}
			}
			for (int j = 0; j < linha; j++) 
			{
				for (int c = 0; c < coluna; c++) 
				{  
					cout << matrizprint[j][c] << " ";
				}
				cout << endl;
		 	}
		}

		key.erase();	
	}
	
	
}