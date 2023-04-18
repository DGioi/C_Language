#include<stdio.h>
int main(){
	int n,s=0,i,k,a=1;
    printf("nhap va mot so");
    scanf("%d",&n);
    for(i=1;n>a;i+=2)
	  for (k=1;k<=i;k++){
	   a=a*10; if (k==i)  s=s+n%a;}
    printf("%d",s);
    return 0;
}
