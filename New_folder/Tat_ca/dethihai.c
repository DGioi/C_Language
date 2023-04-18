#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	int nhom;
	char nd[100];
	char dapan[5][100];
} ct;
ct de[100];
int n;
void nhap(FILE *b){
	char c;
	int i=-1,j;
	while(!feof(b)){
	c=getc(b);
	if(c=='*'){
		i++;
		fscanf(b,"*%d",&de[i].nhom);
		fgets(de[i].nd,100,b);
		j=0;
	}
	if(c=='#'){
		fgets(de[i].dapan[j],100,b);
		j++;
	}
	if(c=='\\') break;
	}
	n=i+1;
}
void print(ct *a,FILE *b){
	int i,j;
	for(i=0;i<n;i++){
		j=0;
		fprintf(b,"\nCau%d:[%d]",i+1,a[i].nhom);
		printf("\nCau%d:[%d]",i+1,a[i].nhom);
		fprintf(b,"%s",a[i].nd);
		printf("%s",a[i].nd);
		while(a[i].dapan[j][0]!='\0'){
			fprintf(b,"\n%c)",97+j);
			printf("\n%c)",97+j);
			fprintf(b,"%s",a[i].dapan[j]);
			printf("%s",a[i].dapan[j]);
			j++;
		}
	}
}
int main(){
	FILE *in=fopen("cauhoi.txt","r");
	FILE *out=fopen("dethi.txt","w+");
	nhap(in);
	printf("chuong trinh");
	print(de,out);
	fclose(in);
	fclose(out);
return 0;	
}
