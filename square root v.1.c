#include<stdio.h>

int main(){
	int a,b,c,i,j;
	a=1;
	printf("b = ");
	scanf("%i",&b);
	printf("c = ");
	scanf("%i",&c);
	
	for(i=-b-100;i<=b+100;i++){
		for(j=b+100;j>=-b-100;j--){
			if(i+j==b){
				if(i*j==c){
					printf("the root is %i and %i\n",i,j);
				}
			}
		}
	}
	getch();
}
