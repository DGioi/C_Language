#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<conio.h> 
#define filename "C:\\Users\\ADMIN\\Documents\\C programming\\C co ban\\week4\\doduong01.txt"
int m,n,x,y,p,q;
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
	fscanf(in,"%d %d",&x,&y);
	printf("%d %d\n",x,y);
	getc(in);
	fscanf(in,"%d %d",&p,&q);
	printf("%d %d\n",p,q);
	fclose(in);
	return a;
}
int di(int i){
	if(i>=0&&i<m*n&&b[i]==0&&a[i]==1){
		//if safe to visit then visit the cell
      b[i]= 1;
      //going down
      di(i+n);
      //going right
      di(i+1);
      //going up
      di(i-n);
      //going left
      di(i-1);
         
      //backtracking
      //b[i]=0;
      //return 0;
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
	di(x*n+y);
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
