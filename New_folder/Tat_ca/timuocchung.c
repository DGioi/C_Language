#include<stdio.h>
int main(){
	int a,b,i;
	scanf("%d %d",&a,&b);
	while(a!=b){
		if(a>b) a=a-b;
		if(a<b) b=b-a;
	}
	printf("uoc chung lon nhat %d %d",a,b);
	return 0;
}
