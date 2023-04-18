#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
int main(){
	int i,n,a,r=0;
	time_t t;
	printf("Nhap vao so may man: ");
	scanf("%d",&n);
	srand(time(&t));
	printf("\n");
	for(i=1;i<=40;i++){
	a=rand()%100;
		
	printf("%-5d",a);
	if(n==a) r=1;
	if(i%10==0) printf("\n");
}
if(r==1) printf("Ban da nhan duoc 1 ty");
else printf("Chuc ban may man :((((");
	return 0;
}
