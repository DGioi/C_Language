#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//#define textlen 750
int dem(FILE *t){
	char c;
	int i=0;
	while (c != EOF) {
      c = fgetc(t);
      if (c != EOF) 
	  	{
         	fputc( c ,stdout);
         	i++;
      	}
   	}
	   return i;	
}
int main(){
	int i=0,skt,j;
	FILE  *in;
	char ch;
	in = fopen( "bai 1.txt", "r" );
	skt=dem(in);	 			
	printf("\n");
	rewind(in);
	char *text;
	text=(char*) calloc((skt+1),sizeof(char));
	fgets(text,skt+1,in);
	printf("\n%s", text);
	printf("\n\nCac tu duoc viet hoa trong van ban: "); 
	for(i=0;i<skt;i++)
	{
		if(text[i]>=65&&text[i]<=90){
			j=i;
			while(text[j]!=32&&text[j]!='\0'&&text[j]!=','&&text[j]!='.'&&text[j]!=';'&&text[j]!='!'&&text[j]!='~'&&text[j]!='/'&&text[j]!='"'&&text[j]!=':') {				
				printf("%c", text[j]);
				j++;
			}
			printf(","); 
		}
	}
	free(text);
	fclose(in);
}

