#include<stdio.h>
#define LEN 10000
int a[LEN];
int n;
void printSolution(){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}
int check(int k,int v){
	for(int i=0;i<k;i++){
		if(a[i]==v) return 0;
	}
	return 1;
}
void trry(int k){
	int i;
	for(i=1;i<=n;i++){
	if (check(k,i)){
	a[k]=i;
	if(k==n-1) printSolution();
	else trry(k+1);
	}
	}
}
int main(){
	scanf("%d",&n);
	trry(0);
	return 0;
}
