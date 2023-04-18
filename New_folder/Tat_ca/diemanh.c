#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<conio.h> 
#define filename "C:\\Users\\ADMIN\\Documents\\C programming\\C co ban\\week5\\diemvavunganh.txt"
int m,n;
int *b;
int *a;
int *nhap(FILE *in){
	
	int i;
	fscanf(in,"%d %d",&m,&n);
	a=(int*)malloc(sizeof(int)*(m*n+1));
	b=(int*)malloc(sizeof(int)*(m*n+1));
	for(i=0;i<m*n;i++){
		b[i]=0;
	}
		for(i=0;i<m*n;i++){
		fscanf(in,"%d",&a[i]);
	}
	return a;
}
int di(int i,int j){
	if(i>=0&&i<m*n&&a[i]==1){
      a[i]=j+2;
      b[j]++;
      di(i+n,j);
      if((i+1)%n!=0)
      di(i+1,j);
      di(i-n,j);
      if((i)%n!=0)
      di(i-1,j);
	}
 return 0;
}
int main(){
	int i,j=-1;
	int *A;
	FILE* in;
	in=fopen(filename,"r");
	if(in == NULL) {
      perror("Error in opening file");
      return 0;
   	}
	A=nhap(in);
	for(i=0;i<m*n;i++){
		if(a[i]==1){
			j++;
			di(i,j);
		}
		}
	printf("\n");
	for(i=0;i<m*n;i++){
	    
		if(a[i]!=0)
		printf("* ");
		else printf("%d ",a[i]);
		if((i+1)%n==0) printf("\n");
	}
	for(i=0;i<=j;i++){
		printf("\nDien tich vung thu %d :%d",i+1,b[i]);
	}
	free(A);
	return 0;
}
