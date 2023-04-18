#include<stdio.h>
int main(){
	int a[100];
	int i,j,n,k,dem;
	printf("Nhap vao n:");
	scanf("%d",&n);
	printf("Nhap vao k:");
	scanf("%d",&k);
	for(i=0;i<k;i++){
		a[i]=i+1;
		printf("%d",a[i]);
	}
	printf("\n"); dem=1;
	i=k-1;

	while(i>=0){
		if(a[i]!=n-k+i+1){
			a[i]+=1;
			for(j=i+1;j<k;j++){
				a[j]=a[i]+j-i;
			}
		 for(j=0;j<k;j++){
			printf("  %d  ",a[j]);
			if(j==k-1) {
				printf("\n"); dem++;
			}
			i=k-1;
		}
		
}
	else {i--; if (a[0]==n-k+1) break;
}
	}
	printf("so to hop: %d",dem);
	return 0;
} 
