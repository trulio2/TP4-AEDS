#include <stdio.h>

void main(){
	int a=97;
	while(a<123){
	 printf("%c %d\n",a,a);
	 a++;
	}
	a=97;
	a-=32;
	printf("%d %c\n",a,a);
}