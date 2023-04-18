#include<stdio.h>
main(){
	int n,m;
	printf("Enter a positive or negative integer:");
	scanf("%i",&n);
	printf("\nYou entered %i.\n",n);
	printf("its absolutre value is %i.\n",n<0?-n:n);
	
	printf("\nEnter two integers(e.g.1 2):)");
	scanf("%i%i",&n,&m);
	
	printf("\nYou entered %i and %i.\n",n,m);
	
	printf("%i is the larger value.\n",n>m?n:m);
}
