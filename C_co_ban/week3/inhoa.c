#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define filename "C:\\Users\\ADMIN\\Documents\\C programming\\C co ban\\week3\\filetext.txt"
const int TOTAL_WORDS = 1000000;
const int WORD_LEN = 50;
int n;
char **rfile(FILE *in){
	int i=0,j=0,a;
	char**chu;
	char c;
	chu=(char**)malloc(sizeof(char*)*TOTAL_WORDS);
	char buff[50];
	while(!feof(in)) {
	c=getc(in);
		if((c>=65&&c<=90)||(c>=97&&c<=122)){
		if(j==0&&c>=97&&c<=122) continue;
		buff[j]=c;
		j++;
		}
		else if(j>0){
		chu[i]=(char*)malloc(sizeof(char)*(j+1));
		buff[j]='\0';
		strcpy(chu[i],buff);
		i++;
		j=0;
		}
	
	
}
 n=i;
fclose(in);
return chu;
}
void WORD(char **c){
	int i,j=1;
	printf("Slt: %d\n",n);
	for(i=0;i<n;i++)
	{ 	if(i==n-1) break;
		if(strcmp(c[i],c[i+1])!=0){
			printf("%-30s %d\n",c[i],j);
			j=0;
			}
		j++;
	}
	printf("%-30s %d",c[i],j);
}
void sapxep(char **a){
	char q[50];
	int i,j;
	for(i=0;i<n-1;i++)
	for(j=i+1;j<n;j++)
	if(strcmp(a[i],a[j])>0) {
		strcpy(q,a[i]);
		strcpy(a[i],a[j]);
		strcpy(a[j],q);
	}
}
void freeMem(char **pointer)
{
int i;
// giai phong bo nho
for(i=0;i<TOTAL_WORDS; i++)
free(pointer[i]);	
 
free(pointer);
}
int main(){
	FILE *in;
	in=fopen(filename,"r");
	if(in == NULL) {
      perror("Error in opening file");
      return 0;
   	}
	char **word;
	word=rfile(in);
	sapxep(word);
	WORD(word);
	freeMem(word);
	return 0;
}
