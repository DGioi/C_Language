#include<stdio.h>
#define LEN 100
int a[LEN];
int n;
void printSolution(){
	int i;
	for(i=0;i<n;i++){
		printf("%d",a[i]);
	}
	printf("\n");
}
void try(int k,int n){
	
	int i;
	for(i=0;i<2;i++){
	a[k]=i;
	if(k==n-1) printSolution();
	else try(k+1,n);
	}
}
int main(){
	scanf("%d",&n);
	try(0,n);
	return 0;
}
