#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void xoaxd(char *a){
	a[strlen(a)-1]='\0';
}
void themtruong(char *a){
	int i;
	for(i=0;i<strlen(a);i++){
		if(a[i+1]>=65&&a[i+1]<=90){
			a[i]='@';
			return;
		}
	} 
}
void print(char b[][1000],FILE *out,int n){
	int i;
	for(i=0;i<n;i++){
		fprintf(out,"%s\n",b[i]);
	}
}
int main(){
	char a[1000][1000];
	int i=0;
	FILE*in=fopen("D:\\Documents\\Kien truc may tinh\\New folder\\extended.txt","r");
	while(!feof(in)){
		fgets(a[i],1000,in);
		xoaxd(a[i]);
		themtruong(a[i]);
		i++;
	}
	FILE *out=fopen("D:\\Documents\\Kien truc may tinh\\New folder\\extended_out.txt","w");
	print(a,out,i);
	fclose(in);
	fclose(out);
	return 0;
} 
