#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<conio.h> 
#define filename "C:\\Users\\ADMIN\\Documents\\C programming\\C co ban\\week5\\binaryimage.txt"
const K 4
int m,n,j;
int *b;
int *a;
int *nhap(FILE *in){
	
	int i;
	fscanf(in,"%d %d",&m,&n);
	printf("%d %d\n",m,n);
	a=(int*)malloc(sizeof(int)*(m*n+1));
	b=(int*)malloc(sizeof(int)*(m*n+1));
	for(i=0;i<m*n;i++){
		b[i]=0;
	}
	
		for(i=0;i<m*n;i++){
		fscanf(in,"%d",&a[i]);
		printf("%d ",a[i]);
		if((i+1)%n==0) printf("\n");
	}
	fclose(in);
	return a;
}
int di(int i){
	int dt; 
	for(i=0;i<m*n;i++){
  
		if(a[i]==1){
		
		if(i>=0&&i<m*n&&a[i]=1){
		a[i]=j+K;
      //going down
      if(di(i+n))
         return 1;
      //going right
      if(di(i+1))
         return 1;
      //going left
      if(di(i-1))
         return 1;
      //backtracking
	}
	}
	}
return 0;
}
int main(){
	int i;
	int *A;
	FILE* in;
	in=fopen(filename,"r");
	if(in == NULL) {
      perror("Error in opening file");
      return 0;
   	}
	A=nhap(in);
	di(0);
	for(i=0;i<m*n;i++){
	    if(b[i]==1){
	    	printf("%d ",b[i]);
		}
		else printf("%d ",b[i]);
	//	if(b[i]==0)
	//	printf("  ");
		if((i+1)%n==0) printf("\n");
	}
	free(A);
	return 0;
}
