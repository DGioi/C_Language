#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define xx system("cls");
#define sl 380000
typedef struct{
	char tt[30];
//	char nn[10];
//	char yn[100];
}word;
int i;
word *ww; 
void nhap(FILE *b){
	for(i=0;i<sl;i++){
		fscanf(b,"%[^\n]",ww[i].tt);
		getc(b);
	//	fscanf(b,"%[^\n]",ww[i].nn);
	//	getc(b);
	//	fscanf(b,"%[^\n]",ww[i].yn);
	//	getc(b);
		
	}
}
void search(char a[]){
	int k=0;
	for(i=0;i<sl;i++)
		if(strcmp(a,ww[i].tt)==0){
			k++;
			printf("dung \"%s\" ",ww[i].tt);
		}
	if(k==0) printf("SAI\n\n");
}
void check(char a[],word *b){
	int k=-1;
	for(i=0;i<sl;i++){
		if(strstr(b[i].tt,a)!=NULL){
			k++;
			if(k==0)
			printf("\n De xuat:");
			if(k%5==0) printf("\n");
			printf("%-20s",strstr(b[i].tt,a));
		}
	}
}

int main(){
	char wd[31];
	getc(stdin);
	ww=(word*)malloc(sl*sizeof(word));
	FILE *in=fopen("word.txt","r");
	nhap(in);
	while(1){
		printf("\nNhap tu: ");
		scanf("%[^\n]",wd);
		getc(stdin);
		search(wd);
	check(wd,ww);
		if(strcmp(wd,"out")==0) break;
		getch();
		xx
		}
free(ww);
ww=NULL;
	
} 
