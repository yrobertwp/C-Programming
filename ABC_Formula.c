#include<stdio.h>
#include<math.h>

int main(){
	
	float a,b,c,D,x1,x2;
	char yes[3]    ="yes",
		 answer[5];
program:	
	system("cls");
	printf("ABC Formula\n");
	printf("-----------\n\n");
	printf("Please entry values of a,b, and c base on \n[ aX^2 + bX + c ]\n\n");
	printf("Value a = ");
	scanf("%f",&a);
	printf("Value b = ");
	scanf("%f",&b);
	printf("Value c = ");
	scanf("%f",&c);
	printf("\nSquare root which you entry is %2.0fX^2 +%2.0fX +%2.0f \n",a,b,c);
	
	D=((b*b)-(4*a*c));
	x1=(-b+(sqrt(D)))/(2*a);
	x2=(-b-(sqrt(D)))/(2*a);
	
	if(D>0){
		printf("Because value of D base on square equation more than 0, that is:\n D = %3.0f\n",D);
		printf("So this equation have two real root and different root values, that is: \n");
		printf("X1 = %5.2f\nX2 = %5.2f\n",x1,x2);
	}else if(D==0){
		printf("Because value of D base on square equation equal with 0\n");
		printf("So this equation have same root values, that is: \n");
		printf("X1 = %5.2f\nX2 = %5.2f\n",x1,x2);
	}else if(D<0){
		printf("Because value of D base on square equation less than 0, that is:\n D = %3.0f\n",D);
		printf("So this equation have imaginer root values, and you cant count it\n");
	}
	
	getch();
	
	system("cls");
	printf("Are you have another square equation to count('yes' if you want to count again)? ");
	scanf("%s",&answer);
	if((strcmp(answer,yes))==0){
		goto program;
	}
	printf("\nThank you for use this application");
	getch();
}
