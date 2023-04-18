#include<stdio.h>
int main(){
	float dem=0;
	short a[100],n,i,j;
	printf("Nhap vao gia tri n:");
	scanf("%hd",&n);
	for(i=0;i<n;i++) {
	 a[i]=0;
	 printf("%hd",a[i]); dem+=1.0/n;
		}
	printf("\n");
	for(i=n-1;i>=0;i--){
		if(a[i]==0){
			a[i]=1;
			for(j=n-1;j>i;j--) a[j]=0;
			for(i=0;i<n;i++){
				printf("%hd",a[i]); dem+=1.0/n;
				if(i==n-1) printf("\n");
			}
		continue;
		}
	}
	printf(" so xau nhi phan:%.0f",dem);
   return 0;
}
