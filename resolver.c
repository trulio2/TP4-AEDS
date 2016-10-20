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

void resolver(char matriz[][tamanho],char depression[][20],int tam){
	int i,j,k=0,l,quarenta=39,tamanho_palavra;
	for(i=0;i<tam;i++){
		for(j=0;j<tam;j++){
			quarenta=39;
			while(quarenta>=0){
				if(matriz[i][j]==depression[quarenta][0]||matriz[i][j]==depression[quarenta][0]-32){
					for(tamanho_palavra=0;depression[quarenta][tamanho_palavra]!=' ';tamanho_palavra++){}
					int tamanho=tamanho_palavra;
					if(j+tamanho<=tam){
							if(matriz[i][j+1]==depression[quarenta][1]||matriz[i][j+1]==depression[quarenta][1]-32){
								for(l=0;l<tamanho;l++){
									if(matriz[i][j+l]==depression[quarenta][l]||(matriz[i][j+l]+32)==depression[quarenta][l]){
										tamanho_palavra--;
									}
									else
										break;
							}
							if(tamanho_palavra==0){
								for (l = 0; l < tamanho; l++){
									if(matriz[i][l+j]>95)
										matriz[i][l+j]-=32;
								}
							}
						}
					}
					if(j-(tamanho-1)>=0){
						tamanho_palavra=tamanho;
						if(matriz[i][j-1]==depression[quarenta][1]||matriz[i][j-1]==depression[quarenta][1]-32){
								for(l=0;l<tamanho;l++){
								
									if(matriz[i][j-l]==depression[quarenta][l]||matriz[i][j-l]==depression[quarenta][l]-32){
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
					
					if(i+tamanho<=tam){
						tamanho_palavra=tamanho;
						if(matriz[i+1][j]==depression[quarenta][1]||matriz[i+1][j]==depression[quarenta][1]-32){
								for(l=0;l<tamanho;l++){
								
									if(matriz[i+l][j]==depression[quarenta][l]||matriz[i+l][j]==depression[quarenta][l]-32){
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
					
					if(i-(tamanho-1)>=0){
						tamanho_palavra=tamanho;
						if(matriz[i-1][j]==depression[quarenta][1]||matriz[i-1][j]==depression[quarenta][1]-32){
								for(l=0;l<tamanho;l++){
								
									if(matriz[i-l][j]==depression[quarenta][l]||matriz[i-l][j]==depression[quarenta][l]-32){
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

					if(j+tamanho<=tam&&i+tamanho<=tam){
						tamanho_palavra=tamanho;
						if(matriz[i+1][j+1]==depression[quarenta][1]||(matriz[i+1][j+1]+32)==depression[quarenta][1]){
								for(l=0;l<tamanho;l++){
									if(matriz[i+l][j+l]==depression[quarenta][l]||(matriz[i+l][j+l]+32)==depression[quarenta][l]){
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

					if(j-(tamanho-1)>=0&&i-(tamanho-1)>=0){
						tamanho_palavra=tamanho;
						if(matriz[i-1][j-1]==depression[quarenta][1]||(matriz[i-1][j-1]+32)==depression[quarenta][1]){
								for(l=0;l<tamanho;l++){
									if(matriz[i-l][j-l]==depression[quarenta][l]||(matriz[i-l][j-l]+32)==depression[quarenta][l]){
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

					if(j+tamanho<=tam&&i-(tamanho-1)>=0){
						tamanho_palavra=tamanho;
						if(matriz[i-1][j+1]==depression[quarenta][1]||(matriz[i-1][j+1]+32)==depression[quarenta][1]){
								for(l=0;l<tamanho;l++){
									if(matriz[i-l][j+l]==depression[quarenta][l]||(matriz[i-l][j+l]+32)==depression[quarenta][l]){
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
					
					if(j-(tamanho-1)>=0&&i+tamanho<=tam){
						tamanho_palavra=tamanho;
						if(matriz[i+1][j-1]==depression[quarenta][1]||(matriz[i+1][j-1]+32)==depression[quarenta][1]){
								for(l=0;l<tamanho;l++){
									if(matriz[i+l][j-l]==depression[quarenta][l]||(matriz[i+l][j-l]+32)==depression[quarenta][l]){
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
				quarenta--;
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
	FILE *arquivo;
	char c,op;
	int i,j;
	while(1){
		fscanf(arq,"%c",&c);
		if(c=='\n') break;
		tamanho++;
	}

	printf("\n%d\n",tamanho);
	
	char matriz[tamanho][tamanho];
	fseek(arq,0,SEEK_SET);
    for ( i = 0; i < tamanho; i++){
    	for (j = 0; j< tamanho;j++){
    		fscanf(arq,"%c",&c);
    		if(c!='\n')
    			matriz[i][j]=c;
    		else {
    			j--;
    		}
    	}
    }
    char depression[40][20];
    do{
    printf("1-Fruits\n2-Animals\nEscolha a option: ");
    scanf("%c",&op);
    printf("\n");

  	}while(op!='1' && op!='2');

  	if(op=='1'){
    	arquivo = fopen("fruits.txt","r");
  	}
  	else{
    	arquivo = fopen("animals.txt","r");
  	}
  	for(i=0;i<40;i++){
    	for(j=0;j<20;j++){
      	depression[i][j]=' ';
    	}
  	}
  	for(i=0;i<40;i++){
    	for(j=0;j<20;j++){
      		fscanf(arquivo,"%c",&c);
      		if(c=='\n'||feof(arquivo))
        		break;
      		depression[i][j]=c;
    	}
    	if(feof(arquivo))
      	break;
    }

    imprime(matriz,tamanho);
    resolver(matriz,depression,tamanho);
    imprime(matriz,tamanho);
    return 0;
}