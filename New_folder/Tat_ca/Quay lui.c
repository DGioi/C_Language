#include<stdio.h>
int a[100],n,dem=0;
void solution(){
	dem++;
	int i;
	for(i=0;i<n;i++) printf("%d",a[i]);
	printf("\n");
}
int check(int k,int v){
	int i;
	for(i=0;i<k-1;i++) if(a[i]==v) return 0;
	return 1;
}
void try(int k){
	int v;
	for(v=1;v<=n;v++){
		if(check(k,v)){
			a[k-1]=v;
			if(k==n) solution();
			else try(k+1);
	
		}
	}
}
	
int main(){
	scanf("%d",&n);
	try(1);;
	printf("\n So hoan vi: %d",dem);
	return 0;
}


