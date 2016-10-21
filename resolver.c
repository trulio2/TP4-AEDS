#include <stdio.h>
#include <stdlib.h>

int tamanho=0;
void imprime(char matriz[][tamanho],int tam){
    int i,j;
    printf("\n");
    for(i=0;i<tam;i++){
      for(j=0;j<tam;j++){
          printf("%c ",matriz[i][j]);
      }
      printf("\n");
    }
    printf("\n");
}

void resolver(char matriz[][tamanho],char fonte[][20],int tam){
	int i,j,k=0,l,atual,tamanho_palavra;
	for(i=0;i<tam;i++){
		for(j=0;j<tam;j++){
			atual=39;
			while(atual>=0){ //Testa a posição atual da matriz com a primeira letra de todas as palavras a serem encontradas
				if(matriz[i][j]==fonte[atual][0]||matriz[i][j]==fonte[atual][0]-32){
					for(tamanho_palavra=0;fonte[atual][tamanho_palavra]!=' ';tamanho_palavra++){}
					int tamanho=tamanho_palavra;
					if(j+tamanho<=tam){//Leste. Compara se o tamanho da palavra não ultrapassa os limites da matriz
							if(matriz[i][j+1]==fonte[atual][1]||matriz[i][j+1]==fonte[atual][1]-32){
								for(l=0;l<tamanho;l++){//Testa maiusculas e minusculas
									if(matriz[i][j+l]==fonte[atual][l]||(matriz[i][j+l]+32)==fonte[atual][l]){
										tamanho_palavra--;
									}
									else
										break;
							}
							if(tamanho_palavra==0){//Se a palavra foi encontrada
								for (l = 0; l < tamanho; l++){//passa suas letras para maiusculo
									if(matriz[i][l+j]>95)
										matriz[i][l+j]-=32;
								}
							}
						}
					}

					//Os testes abaixo sao exatamente iguais aos de cima, musando apenas o sentido de busca
					if(j-(tamanho-1)>=0){//Oeste
						tamanho_palavra=tamanho;
						if(matriz[i][j-1]==fonte[atual][1]||matriz[i][j-1]==fonte[atual][1]-32){
								for(l=0;l<tamanho;l++){
								
									if(matriz[i][j-l]==fonte[atual][l]||matriz[i][j-l]==fonte[atual][l]-32){
										tamanho_palavra--;
									}
									else
										break;
									
							}
							if(tamanho_palavra==0){
								for (l = 0; l <tamanho; l++){
									if(matriz[i][j-l]>95)
										matriz[i][j-l]-=32;
								}
							}	
						}

					}
					
					if(i+tamanho<=tam){//Sul
						tamanho_palavra=tamanho;
						if(matriz[i+1][j]==fonte[atual][1]||matriz[i+1][j]==fonte[atual][1]-32){
								for(l=0;l<tamanho;l++){
								
									if(matriz[i+l][j]==fonte[atual][l]||matriz[i+l][j]==fonte[atual][l]-32){
										tamanho_palavra--;
									}
									else
										break;
							}
							if(tamanho_palavra==0){
								for (l = 0; l < tamanho; l++){
									if(matriz[i+l][j]>95)
										matriz[i+l][j]-=32;
								}
							}	
						}

					}
					
					if(i-(tamanho-1)>=0){//Norte
						tamanho_palavra=tamanho;
						if(matriz[i-1][j]==fonte[atual][1]||matriz[i-1][j]==fonte[atual][1]-32){
								for(l=0;l<tamanho;l++){
								
									if(matriz[i-l][j]==fonte[atual][l]||matriz[i-l][j]==fonte[atual][l]-32){
										tamanho_palavra--;
									}
									else
										break;
							}
							if(tamanho_palavra==0){
								for (l = 0; l < tamanho; l++){
									if(matriz[i-l][j]>95)
										matriz[i-l][j]-=32;
								}
							}	
						}

					}

					if(j+tamanho<=tam&&i+tamanho<=tam){//Sudeste
						tamanho_palavra=tamanho;
						if(matriz[i+1][j+1]==fonte[atual][1]||(matriz[i+1][j+1]+32)==fonte[atual][1]){
								for(l=0;l<tamanho;l++){
									if(matriz[i+l][j+l]==fonte[atual][l]||(matriz[i+l][j+l]+32)==fonte[atual][l]){
										tamanho_palavra--;
									}
									else
										break;
							}
							if(tamanho_palavra==0){
								for (l = 0; l < tamanho; l++){
									if(matriz[i+l][l+j]>95)
										matriz[i+l][l+j]-=32;
								}
							}
						}

					}

					if(j-(tamanho-1)>=0&&i-(tamanho-1)>=0){//Noroeste
						tamanho_palavra=tamanho;
						if(matriz[i-1][j-1]==fonte[atual][1]||(matriz[i-1][j-1]+32)==fonte[atual][1]){
								for(l=0;l<tamanho;l++){
									if(matriz[i-l][j-l]==fonte[atual][l]||(matriz[i-l][j-l]+32)==fonte[atual][l]){
										tamanho_palavra--;
									}
									else
										break;
							}
							if(tamanho_palavra==0){
								for (l = 0; l < tamanho; l++){
									if(matriz[i-l][j-l]>95)
										matriz[i-l][j-l]-=32;
								}
							}
						}

					}

					if(j+tamanho<=tam&&i-(tamanho-1)>=0){//Nordeste
						tamanho_palavra=tamanho;
						if(matriz[i-1][j+1]==fonte[atual][1]||(matriz[i-1][j+1]+32)==fonte[atual][1]){
								for(l=0;l<tamanho;l++){
									if(matriz[i-l][j+l]==fonte[atual][l]||(matriz[i-l][j+l]+32)==fonte[atual][l]){
										tamanho_palavra--;
									}
									else
										break;
							}
							if(tamanho_palavra==0){
								for (l = 0; l < tamanho; l++){
									if(matriz[i-l][j+l]>95)
										matriz[i-l][j+l]-=32;
								}
							}
						}

					}
					
					if(j-(tamanho-1)>=0&&i+tamanho<=tam){//Sudoeste
						tamanho_palavra=tamanho;
						if(matriz[i+1][j-1]==fonte[atual][1]||(matriz[i+1][j-1]+32)==fonte[atual][1]){
								for(l=0;l<tamanho;l++){
									if(matriz[i+l][j-l]==fonte[atual][l]||(matriz[i+l][j-l]+32)==fonte[atual][l]){
										tamanho_palavra--;
									}
									else
										break;
							}
							if(tamanho_palavra==0){
								for (l = 0; l < tamanho; l++){
									if(matriz[i+l][j-l]>95)
										matriz[i+l][j-l]-=32;
								}
							}
						}

					}
				}
				atual--;
			}
		}
	}
	for(i=0;i<tam;i++){
		for(j=0;j<tam;j++){
			if(matriz[i][j]>90) matriz[i][j]='-';
		}
	}
}

int main(int idx){
	FILE * arq=fopen("caça-palavras.txt","r");
	if(arq==NULL) exit(0);
	FILE *arquivo;
	char c,op;
	int i,j;
	while(1){//Descobre se a matriz e 15x15 ou 20x20
		fscanf(arq,"%c",&c);
		if(c=='\n') break;
		tamanho++;
	}

	printf("\n%d\n",tamanho);

	char matriz[tamanho][tamanho];
	fseek(arq,0,SEEK_SET);
    for ( i = 0; i < tamanho; i++){//Transfere o conteudo do arquivo para a matriz
    	for (j = 0; j< tamanho;j++){
    		do{
    			fscanf(arq,"%c",&c);
    		}while(c=='.'||c==' '||c=='-');
    		if(c!='\n')
    			matriz[i][j]=c;
    		else {
    			j--;
    		}
    	}
    }
    char fonte[40][20];
    do{
    printf("1-Fruits\n2-Animals\nEscolha a opcao: ");
    scanf("%c",&op);
    printf("\n");

  	}while(op!='1' && op!='2');

  	if(op=='1'){
    	arquivo = fopen("fruits.txt","r");
  	}
  	else{
    	arquivo = fopen("animals.txt","r");
  	}
  	if(arquivo==NULL) exit(0);
  	for(i=0;i<40;i++){
    	for(j=0;j<20;j++){
      	fonte[i][j]=' ';
    	}
  	}
  	for(i=0;i<40;i++){
    	for(j=0;j<20;j++){
      		fscanf(arquivo,"%c",&c);
      		if(c=='\n'||feof(arquivo))
        		break;
      		fonte[i][j]=c;
    	}
    	if(feof(arquivo))
      	break;
    }

    imprime(matriz,tamanho);
    resolver(matriz,fonte,tamanho);
    imprime(matriz,tamanho);
    return 0;
}