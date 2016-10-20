#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void Bolha(int *vetor, int N){
	int i,j,aux;
	for(i = N; i > 0 ;i--){
		for(j = 2 ; j <= i ;j++){
			if(vetor[j-1] > vetor[j]){
				aux = vetor[j-1];
				vetor[j-1] = vetor[j];
				vetor[j] = aux;
			}
		}
	}
}

void SelecaoDireta(int *vetor,int N){
	int i,j,menor,aux;
	for(i = 1; i < N; i++){
		menor = i;
		for(j = i+1; j <= N; j++){
			if(vetor[j] < vetor[menor]){
				menor=j;
			}
			aux = vetor[menor];
			vetor[menor] = vetor[i];
			vetor[i] = aux;
		}
	}
}

void InsercaoDireta(int *vetor,int N){
	int i,j;
	for(i = 2; i <= N; i++){
		vetor[0] = vetor[i];
		j = i-1;
		while(vetor[0]<vetor[j]){
			vetor[j+1] = vetor[j];
			j--;
		}
		vetor[j+1] = vetor[0];
	}
}

int main(){
	srand48(time(0));
	clock_t t1,t2;
	int op,i,n;
	char opcao;
	double tempo;
	int *vetor;
	do{
		do{
			system("clear");
			printf("\t\tEscolha o Tamanho\n");
			printf("1 - 10.000\n");
			printf("2 - 20.000\n");
			printf("3 - 40.000\n");
			printf("4 - 80.000\n");
			printf("5 - 160.000\n");
			printf("0 - Sair\n");
			printf("Opcao: ");
			scanf("%d",&op);
		}while(op!=1&&op!=2&&op!=3&&op!=4&&op!=5&&op!=0);

		switch (op){
			case 1:
				n = 10000;
				vetor=(int *)malloc(n * sizeof(int));
				break;
			case 2:
				n = 20000;
				vetor=(int *)malloc(n * sizeof(int));
				break;
			case 3:
				n = 40000;
				vetor=(int *)malloc(n * sizeof(int));
				break;
			case 4: 
				n = 80000;
				vetor=(int *)malloc(n * sizeof(int));
				break;
			case 5:
				n = 160000;
				vetor=(int *)malloc(n * sizeof(int));
				break;
			case 0:
				break;
			default :
				break;
		}
		if(op!=0){
			for(i = 0; i < n ; i++){
				vetor[i]=drand48()*1000;
			}
			i=5;
			tempo=0;
			while(i>0){
				t1=clock();
				Bolha(vetor,n);
				t2=clock();
				tempo+=((double)t2 - (double)t1)/(double)CLOCKS_PER_SEC;
				i--;
			}
			printf("\nTempo Medio - Bolha para vetor de tamanho %d = %.3e",n,tempo/5);
			
			i=5;
			tempo=0;
			while(i>0){
				t1=clock();
				SelecaoDireta(vetor,n);
				t2=clock();
				tempo+=((double)t2 - (double)t1)/(double)CLOCKS_PER_SEC;
				i--;
			}
			printf("\n\nTempo Medio - Selecao Direta para vetor de tamanho %d = %.3e",n,tempo/5);

			i=5;
			tempo=0;
			while(i>0){
				t1=clock();
				InsercaoDireta(vetor,n);
				t2=clock();
				tempo+=((double)t2 - (double)t1)/(double)CLOCKS_PER_SEC;
				i--;
			}
			printf("\n\nTempo Medio - Insercao Direta para vetor de tamanho %d = %.3e",n,tempo/5);
			
			
		}
		getchar();
		printf("\n\nContinuar? (s/n): ");
		scanf("%c",&opcao);
	}while(opcao=='s'||opcao=='S');
	return 0;
}