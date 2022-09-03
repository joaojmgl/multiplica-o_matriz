 # Maxima soma 

## Proposta apresentada:
 - Nesta trabalho foi proposto implementar um sistema de multiplicação de matrizes baseado-se em estratégia de segmentação em arquivos. Devia se receber coordenadas de um arquivo txt e recortar uma matriz de acordo com as coordenadas recebidas de outro arquivo onde ira conter uma matriz gigante. 

 ## Logica utilizada :

### Função ```Coordenadas()``` :

1. Primeiramente nesta função extraimos do arquivo txt *coordenadas,txt* as coordenadas da nossa nova matriz:
```c++
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
```
- Observe que utilizamos devido ao uma falha na leitura do codigo o ```get()``` estava extraindo caracteres indesejados do arquivo logo foi necessario a criação de uma estrutura de comparação para everiguar se o caracter recebido era um inteiro.

### Função ```nova_matriz()``` :

2. A função ```nova_matriz()``` tem como objetivo extrair da matriz gigante uma nova matriz com as coordenadas recebidas da função interior:
```c++
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

```
- Nesta primeira parte utilizei uma estrutura de repetição para extrair as coordenadas da lista de cordenadas inteiras.

```c++
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
```
- Apos isto, entramos em uma cadeia de estruturas de comparação. Primeiramente o `getline()` ignora as linhas nescessarias e a proxima estrutura de comparação verifica se o cursor do arquivo ja esta na coluna correta para começar inserir os numeros em uma lista.

### Função ```Transposta()```:

Esta é a função mais importante do codigo ela tem a função de fazer três coisas especificas, adquirir a matriz trasposta da nossa matriz original, calcular a multiplicação da matriz transposta pela matriz original e salvar o resultado em uma hash onde a chave sera as coordenadas ij.
```c++
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
``` 
-  Utilizei a mesma estrutura que na função anterior para extrair as coordenadas. Porem, neste caso utilazamos de uma lista auxiliar para salvar as string e contatenamos ela para criar as keys que serão utilizadas para nossa hash.

```c++
auto search = Mat->find(key);
		if (search == Mat->end()) {

```
- Nesta parte do algoritmo verificamos se existe a key que estamos preste a utilizar na nossa hash. Caso não exista a key ainda :
```c++
Matriz=new int*[linha];
			for (int j = 0; j != coluna; j++)
			{	
				Matriz[j]=new int[coluna];
				for (int c=0; c != linha; c++)
				{
					
					Matriz[j][c]=l->vet[cont].val;
					cont++;
					
				}
				
			}

			Matriz_transposta = new int*[coluna];

			for (int j = 0; j < coluna; j++) {
				Matriz_transposta[j] = new int[linha];
				for (int c = 0; c < linha; c++) {
					Matriz_transposta[j][c] = Matriz[c][j];
				}
			}

			Matriz_nova = new int*[linha];
			int soma=0;
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
				}
			
				
			}
			Mat->emplace(key,Matriz_nova);

```
- Primeiramente salvei os item da lista de onde estava salvo a matriz em vetor ```Matriz```. Apos,  obtive a ```Matriz_transposta``` utilizando uma estrutura de repetição *for* , em seguida , calculei a multiplicação entre a ```matriz``` e a ```Matriz_transposta``` e salvei em uma nova matriz(```Matriz_nova```). Por ultimo, pegamos a key adquirida no inicio da função e salvei a nova matriz na hash.

- Caso o if não seja atendido e a key ja exista a seguite parte é executada:
```c++
else{
				
			for (auto item: *Mat) 
			{
				if (item.first == key) 
				 {
				matrizprint = item.second;
				}
			}
			for (int j = 0; j < linha; j++) 
			{;
				for (int c = 0; c < coluna; c++) 
				{
					cout << matrizprint[j][c] << " ";
				}
				cout << endl;
		 	}
		}
```
- Primeiramente entramos em um loop **for** que compara a key recebida com todas a key's da hash, caso a condição abaixo do **if** seja atendido salvaremos o conteudo da hash na matriz auxliar ```matrizprint``` e logo abaixo printamos a matriz correspondete a key solicitada.
## Funcionamento 
   
 ### Funcionamento Makefile:
                                                                   
 |      Comandos       |        Função       |
 | ------------------- | ------------------- |
 |         Make        |  Compila o Programa |
 |       Make run      | Executa o algoritmo |
 
 ### Funcionamento Aquivo *"coordenadas.txt e Matriz.txt"*:
 
 - O arquivo deve ser um aquivo txt.
 - O arquivo coordenadas deve ser escrito numero a numero     separado por virgulas e apenas uma coordenada por linha.
 - O aquivo "Matriz.txt" de conter uma matriz NxM, contudo o arquivo deve conter uma coluna vazia a mais.
   ```


## Resultados esperados:

- Dados essas coordenadas:

<p align="center">
  <img src="img/coordenadas.png">
</p>
 
- E esta matriz:

<p align="center">
  <img src="img/Matriz.png">
</p>

- Os resultados são esses:

<p align="center">
  <img src="img/Primeira_coordenada.png">
</p>

- Da primeira coordenada.

<p align="center">
  <img src="img/Segunda_matriz.png">
</p>

- Da segunda coordenada.

<p align="center">
  <img src="img/coordenadas_repetidas.png">
</p>

- Em caso de coordenadas repetidas.