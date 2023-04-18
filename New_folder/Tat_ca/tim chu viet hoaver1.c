#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int TOTAL_WORDS = 100000000;
const int WORD_LEN = 30;
int n;
char **rfile(FILE *in){
	int i=0,j,a;
	char**chu;
	chu=(char**)malloc(sizeof(char*)*TOTAL_WORDS);
	char buff[50];
	while(!feof(in)) {	
	fscanf(in,"%s",buff);
	getc(in);
	a=strlen(buff);
	for(j=a-1;j>=0;j--) if(buff[j]==32||buff[j]=='\0'||buff[j]==','||buff[j]=='.'||buff[j]==';'||buff[j]=='!'||buff[j]=='~'||buff[j]=='/'||buff[j]=='"'||buff[j]==':')
	 buff[j]='\0';
  chu[i]=(char*)malloc(sizeof(char)*(a+1));
  strcpy(chu[i],buff);
  i++;
}
 n=i+1;
fclose(in);
return chu;
}
void WORD(char **c){
	int i;
	for(i=0;i<n;i++)
	{ if(c[i][0]>=65&&c[i][0]<=90)
		printf("%s\n",c[i]);
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
	char filename[]="C:\\Users\\ADMIN\\Documents\\C programming\\C co ban\\week3\\filetext.txt";
	FILE *in;
	in=fopen(filename,"r");
	if(in == NULL) {
      perror("Error in opening file");
      return 0;
   	}
	char **word;
	word=rfile(in);
	WORD(word);
	freeMem(word);
	return 0;
}
