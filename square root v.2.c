#include<stdio.h>
//maybe you need string.h library, my program run well on dev c++ 5.11
int main(){
	char answer[5];
	program :
	system("cls");
	int a,b,c,i,m,x;
	//m for copy c value to enter to 'for' syntax just for negative value (because increment type)
	//x for catch the value (1 of the root)
	a=1;
	x=0;
	printf("Square root counter (base on c factor on ax^2+bx+c=0)\n");
	printf("-----------------------------------------------------\n");
	printf("Note : \n");
	printf("1. Value of a always equal with 1\n");
	printf("2. Value b and c cant decimal type\n\n");
	printf("Please entry the value of b and c on x^2 + bx + c = 0\n\n");
	printf("Value b = ");
	scanf("%i",&b);
	printf("Value c = ");
	scanf("%i",&c);
	printf("Square root which you entry is x^2 + %ix + %i = 0\n",b,c);
	if(c!=0){
	printf("\nCounting progress (2 values, which the sum value will be equal with b and the multiplication same with c) :\n");
	}
	if(c==0){
		printf("The result of that meet is (x + %i)x=0\n",b);
		printf("with the root values are\n");
		printf("x1 = %i\nx2 = 0\n",-b);
		printf("This equation have two real root and different root values, because the values of X1 different with X2\n");
	}else{
	m=c;
	if(c<0){
		m=c*-1;
	}
	for(i=-m;i<=m;i++){
		if((c%i)==0){
			printf("\t%i\t%i\twith the sum value same with %i\n",i,(c/i),(i+(c/i)));
			if((i+(c/i))==b){
				x=i;
			}
		}
		if(i==-1){	//this part to avoid 0 values, because program will be stopped if 0 values enter to this looping.
			i=0;
		}
	}
	if(x!=0){
		printf("\nBased on the progress, we got :\n");
		printf("(x+(%i))(x+(%i))=0\n",x,(c/x));
		printf("with the root values\n");
		printf("x1 = %i and\n",x*-1);
		printf("x2 = %i\n",(c/x)*-1);
		if((x*-1)==((c/x)*-1)){
			printf("This equation have same root values, Because value of X1 same with X2\n");
		}else{
			printf("This equation have two real root and different root values, because the values of X1 different with X2\n");
		}		
	}else{
		printf("\nroot values not found (cant find the result of 2 values which the sum same with b). Remember, cant find decimal type!");
	}
	}
	getch();
	system("cls");
	printf("Are you have another square equation to count('yes' if you want to count again)? \n");
	scanf("%s",&answer);
	if((strcmp(answer,"yes"))==0){
		goto program;
	}
	printf("Thanks for use this application");
	getch();
}
