#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define norte 1
#define sul 2
#define leste 3
#define oeste 4
#define nordeste 5
#define sudeste 6
#define noroeste 7
#define sudoeste 8
int tamanho;

void imprime(char matriz[][20]){
    int i,j;
    printf("\n");
    for(i=0;i<tamanho;i++){
      for(j=0;j<20;j++){
          printf("%c ",matriz[i][j]);
      }
      printf("\n");
    }
    printf("\n");
}

void imprime2(char matriz[][tamanho],int tam){
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
int verifica_espaco(int linha,int coluna, int tamanho_palavra,int posicao,int tam){
    if(posicao==norte){
      if(tamanho_palavra<=(linha+1)){
        return 1;
      }else{
        return 0;
      }
    }
    else if(posicao==sul){
      if(tamanho_palavra<=tam-linha){
        return 1;
      }else{
        return 0;
      }
    }
    else if(posicao==leste){
      if(tamanho_palavra<=tam-coluna){
        return 1;
      }else{
        return 0;
      }
    }
    else if(posicao==oeste){
      if(tamanho_palavra<=(coluna+1)){
        return 1;
      }else{
        return 0;
      }
    }
    else if(posicao==nordeste){
      if(tamanho_palavra<=(linha+1) && tamanho_palavra<=tam-coluna){
        return 1;
      }else{
        return 0;
      }
    }
    else if(posicao==sudeste){
      if(tamanho_palavra<=tam-linha && tamanho_palavra<=tam-coluna){
        return 1;
      }else{
        return 0;
      }
    }
    else if(posicao==noroeste){
      if(tamanho_palavra<=(linha+1) && tamanho_palavra<=(coluna+1)){
        return 1;
      }else{
        return 0;
      }
    }
    else if(posicao==sudoeste){
      if(tamanho_palavra<=tam-linha && tamanho_palavra<=(coluna+1)){
        return 1;
      }else{
        return 0;
      }
    }
}
int cruzamento_e_montagem(char matriz[][tamanho], char *palavra,int posicao,int tamanho_palavra,int linha,int coluna){
    int i,j,k=0;
    if(posicao==norte){
      for(i=linha;i>(linha-tamanho_palavra);i--){
        if(matriz[i][coluna]!='-' && matriz[i][coluna]!=palavra[k]){
          return 0;
        }
        k++;
      }
      //SE A VERIFICACAO NAO DEU ERRADO, GRAVA A PALAVRA NA MATRIZ
      k=0;
      for(i=linha;i>(linha-tamanho_palavra);i--){
        matriz[i][coluna]=palavra[k];
        k++;
      }
      return 1;
    }
    else if(posicao==sul){
      for(i=linha;i<(linha+tamanho_palavra);i++){
        if(matriz[i][coluna]!='-' && matriz[i][coluna]!=palavra[k]){
          return 0;
        }
        k++;
      }
      k=0;
      for(i=linha;i<(linha+tamanho_palavra);i++){
        matriz[i][coluna]=palavra[k];
        k++;
      }
      return 1;
    }
    else if(posicao==leste){
      for(i=coluna;i<(coluna+tamanho_palavra);i++){
        if(matriz[linha][i]!='-' && matriz[linha][i]!=palavra[k]){
          return 0;
        }
        k++;
      }
      k=0;
      for(i=coluna;i<(coluna+tamanho_palavra);i++){
        matriz[linha][i]=palavra[k];
        k++;
      }
      return 1;
    }
    else if(posicao==oeste){
      for(i=coluna;i>(coluna-tamanho_palavra);i--){
        if(matriz[linha][i]!='-' && matriz[linha][i]!=palavra[k]){
          return 0;
        }
        k++;
      }
      k=0;
      for(i=coluna;i>(coluna-tamanho_palavra);i--){
        matriz[linha][i]=palavra[k];
        k++;
      }
      return 1;
    }
    else if(posicao==nordeste){
      i=linha;
      for(j=coluna;j<(coluna+tamanho_palavra);j++){
        if(matriz[i][j]!='-' && matriz[i][j]!=palavra[k]){
          return 0;
        }
        k++;
        i--;
      }
      k=0;
      i=linha;
      for(j=coluna;j<(coluna+tamanho_palavra);j++){
        matriz[i][j]=palavra[k];
        k++;
        i--;
      }
      return 1;
    }
    else if(posicao==sudeste){
      i=linha;
      for(j=coluna;j<(coluna+tamanho_palavra);j++){
        if(matriz[i][j]!='-' && matriz[i][j]!=palavra[k]){
          return 0;
        }
        k++;
        i++;
      }
      k=0;
      i=linha;
      for(j=coluna;j<(coluna+tamanho_palavra);j++){
        matriz[i][j]=palavra[k];
        k++;
        i++;
      }
      return 1;
    }
    else if(posicao==noroeste){
      i=linha;
      for(j=coluna;j>(coluna-tamanho_palavra);j--){
        if(matriz[i][j]!='-' && matriz[i][j]!=palavra[k]){
          return 0;
        }
        k++;
        i--;
      }
      k=0;
      i=linha;
      for(j=coluna;j>(coluna-tamanho_palavra);j--){
        matriz[i][j]=palavra[k];
        k++;
        i--;
      }
      return 1;
    }
    else if(posicao==sudoeste){
      i=linha;
      for(j=coluna;j>(coluna-tamanho_palavra);j--){
        if(matriz[i][j]!='-' && matriz[i][j]!=palavra[k]){
          return 0;
        }
        k++;
        i++;
      }
      k=0;
      i=linha;
      for(j=coluna;j>(coluna-tamanho_palavra);j--){
        matriz[i][j]=palavra[k];
        k++;
        i++;
      }
      return 1;
    }
}
int secundaria(char matriz[][tamanho], int tam, char *vetor){
    int linha,coluna,tamanho_palavra,posicao,i=0;

    for(tamanho_palavra=0;vetor[tamanho_palavra]!=' ';tamanho_palavra++){}

    do{
      if(i>3000) return 0;
      posicao=drand48()*7+1;
      linha=drand48()*tam;
      coluna=drand48()*tam;
      i++;
    }while(verifica_espaco(linha,coluna,tamanho_palavra,posicao,tam)==0 ||
           cruzamento_e_montagem(matriz,vetor,posicao,tamanho_palavra,linha,coluna)==0);
           printf("Posição = %d\n",posicao);
    return 1;
}


void principal(int tam, char depression[40][20]){
    int i,j,z=0,teste;
    char matriz[tam][tam],vetor[20];
    tamanho=tam;
    for(i=0;i<tam;i++){
      for(j=0;j<tam;j++){
        matriz[i][j]='-';
      }
    }
    int n=0,numero_palavra;
    numero_palavra=drand48()*10;
    while(n<15){
      for(i=0;i<20;i++){
        vetor[i]=depression[numero_palavra][i];
      }
      
      teste=secundaria(matriz,tam,vetor);
      if(teste==1){
      	printf("Palavra %d = ",z);
        for(i=0;i<20;i++){
       	  printf("%c",vetor[i]);
        }
      	numero_palavra+=2;
     	n++;
     	z++;
     }
     else numero_palavra+=1;

    }
    imprime2(matriz,tam);
    for(i=0;i<tam;i++){
      for(j=0;j<tam;j++){
        if(matriz[i][j]=='-'){
          matriz[i][j]=drand48()*26+97;
        }
      }
    }
    imprime2(matriz,tam);
    FILE* cp=fopen("caça-palavras.txt","w");
    for(i=0;i<tam;i++){
    	for(j=0;j<tam;j++){
    		fprintf(cp,"%c",matriz[i][j]);
    	}
    	fprintf(cp,"\n");
    }
    
    
}
int main(int idx){
  srand48(time(0));
  int i,j,tam;
  char op,letra;

  do{
    system("clear");
    printf("1-Tamanho 15x15\n2-Tamanho 20x20\nEscolha a option: ");
    scanf("%c",&op );
    printf("\n");

  }while(op!='1' && op!='2');
  if(op=='1') tam=15;
  else tam=20;

  do{
    system("clear");
    printf("1-Fruits\n2-Animals\nEscolha a option: ");
    scanf("%c",&op);
    printf("\n");

  }while(op!='1' && op!='2');

  FILE *arquivo;
  
  char depression[40][20];
  
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
      fscanf(arquivo,"%c",&letra);
      if(letra=='\n'||feof(arquivo))
        break;
      depression[i][j]=letra;
    }
    if(feof(arquivo))
      break;
    }
    tamanho=40;
    principal(tam,depression);
    fclose(arquivo);

  return 0;
}
