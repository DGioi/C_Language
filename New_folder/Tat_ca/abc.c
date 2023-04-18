#include<stdio.h>

int main(){
	int i=8;
/*	printf("%d ",i);
	i++;
	printf("%d ",i);
	i--;
	printf("%d ",i);
	i++;
	printf("%d ",i);
	--i;
	printf("%d ",i);
	++i;
	printf("%d ",i);
	*/
	printf("%d %d %d %d %d %d %d %d %d ",i,i++,i--,++i,--i,i++);
	printf("\n%d %d",--i,i);
	printf("\n%d",i);
	return 0;
}
