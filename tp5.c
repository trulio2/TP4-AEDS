#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void shellSort_knuth(int *v, int n) {
    int i , j , x;
    int h = 1;
    while(h < n) {
        h = 3*h+1;
    }
    while ( h > 1) {
        h /= 3;
        for(i = h; i < n; i++) {
            x = v[i];
            j = i - h;
            while (j >= 0 && x < v[j]) {	
                v [j + h] = v[j];
                j -= h;
            }
            v [j + h] = x;
        }
    }
}

void shellSort_japalok(int *v, int n) {
    int i , j , x,k=1;
    int h = 1;
    while(h < n) {
        h = (pow(9,k)-pow(4,k))/(5*pow(4,k-1));
        k++;
    }
    k--;
    while ( h > 1) {
        k--;
		if(k < 0)
			h = 1;
		else
			h = (pow(9,k)-pow(4,k))/(5*pow(4,k-1));

        for(i = h; i < n; i++) {
            x = v[i];
            j = i - h;
            while (j >= 0 && x < v[j]) {	
                v [j + h] = v[j];
                j -= h;
            }
            v [j + h] = x;
        }
    }
}

void oi_amostra_o_vetor(int *v,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d\n",v[i]);
	}

}


void main(int idx){
	srand48(time(0));
	int i,*v,n=500000+1000000*drand48()*8;
	//printf("Digite o tamanho do vetor: ");	
	//scanf("%d",&n);
	v=(int*)malloc(n*sizeof(int));
	printf("\n%d\n",n);
	for(i=0;i<n;i++){
		v[i]=drand48()*n;
	}
	//oi_amostra_o_vetor(v,n);
	//getchar();
	//getchar();
	shellSort_japalok(v,n);
	//oi_amostra_o_vetor(v,n);
	
}