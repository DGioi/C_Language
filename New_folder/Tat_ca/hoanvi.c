#include<stdio.h>
	int n,dem=0,tmp;
	int a[100];
void print(){
	int i;
	for(i=0;i<n;i++)
	printf(" %d ",a[i]);
	printf("\n");
}
void lk(){
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		a[i]=i+1;
	}
	while(1){
		i=n-2;
		dem++;
		print();
		while(i>=0&&a[i+1]<a[i]) i--;
		if(i<0) break;
		for(j=n-1;j>i;j--){
			if(a[j]>a[i]){
				tmp=a[j];
				a[j]=a[i];
				a[i]=tmp;
				for(j=i+1;j<(n+i+1)/2;j++){
		       	tmp=a[j];
		     	a[j]=a[n-j+i];
		       	a[n-j+i]=tmp;
	        	}
				break;
			}
		}
	}
}
int main(){
	lk();
	return 0;
}

