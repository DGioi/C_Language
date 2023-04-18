#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#define filename2 "C:\\Users\\ADMIN\\Documents\\C programming\\C co ban\\week5\\troochu.txt"
#define kk 10
#define qq 20
const int TOTAL_WORDS = 370100;
const int WORD_LEN = 30;
int c,r,min,g=0;
char s[50];
int key[500];
int mark[500];
char **Dict;
int dict_size;
char *a;
void standalizeWord(char *Word)
{
int i=0;
while(i<strlen(Word))
{
if(Word[i]=='\r' || Word[i]=='\n')
{
Word[i]='\0';
break;
}
else
i++;			
}
}
char **loadDict(char* filename, int* dict_size)
{
char **Words;
int i,total_size=0;;
char buff[50];
FILE *fPtr;
fPtr = fopen(filename, "r");
if(fPtr == NULL) {
      perror("Error in opening file");
      return(NULL);
   	}

// cap phat mang con tro
Words=(char**)malloc(sizeof(char*)*TOTAL_WORDS);
    i=0;
while(fgets(buff, WORD_LEN, fPtr)!=NULL) {
standalizeWord(buff);		
Words[i] = (char*)malloc(sizeof(char)*(strlen(buff)+1));
strcpy(Words[i],buff);
//puts(Words[i]);
//total_size=total_size+strlen(buff)+1;
i++;
}
fclose(fPtr);
//printf("Total Read: %d\n",i);
//printf("Total size: %d\n",total_size);
*dict_size = i;
return Words;
}
 
void freeMem(char **pointer)
{
int i;
// giai phong bo nho
for(i=0;i<TOTAL_WORDS; i++)
free(pointer[i]);	
 
free(pointer);
}
int checkWord(char *word, char **Dict, int dict_size)
{
	int i;
for(i=0; i<dict_size; i++)
if(strcmp(word,Dict[i])==0) return 1;
return 0;
}
char *scan(FILE* in){
	int j=0,i=0;
	char* aa;
   aa=(char*)malloc(sizeof(char)*10000);
	while(!feof(in)){
		aa[i]=getc(in);
		if(getc(in)=='\n'&&j==0){
			j=1;
			c=i+1;
			}
		i++;
	}
    r=i/(c);
    if(r<c) min=r;
    else min=c;
    return aa;
}
int check(int i,int k){
	if(k==0) return 1;
	if(mark[i]==1) return 0;
	if(mark[i-c]==1&&i>=c&&(key[i-c]==r||k==1)) {
		key[i]=r;
		return 1;
	}
	/*if(mark[i+c]==1&&i<r*c-c&&(key[i+c]==2||k==1)) {
		key[i]=2;
		return 1;
	}*/
	/*if(mark[i+1]==1&&i%c<c-1&&(key[i+1]==3||k==1)) {
		key[i]=3;
		return 1;
	}*/
	if(mark[i-1]==1&&(i%c)>0&&(key[i-1]==c||k==1)) {
		key[i]=c;
		return 1;}
	if(mark[i+c-1]==1&&(i+c)%c>0&&(key[i+c-1]==min+kk||k==1)){
		key[i]=min+kk;
		return 1;}
	if(mark[i-c-1]==1&&(i-c)%c>0&&(key[i-c-1]==min+qq||k==1)){
		key[i]=min+qq;
		return 1;}
	/*if(mark[i+c+1]==1&&(i+c)%c<c-1&&(key[i+c+1]==7||k==1)){
		key[i]=7;
		return 1;}
	if(mark[i-c+1]==1&&(i-c)%c<c-1&&(key[i-c+1]==8||k==1)){
		key[i]=8;
		return 1;}*/
	return 0;
	
}
int try(int k){
	int i;
	for(i=k;i<c*r;i++){
		if(check(i,k)){
		s[k]=a[i];
		mark[i]=1;
		g=checkWord(s,Dict,dict_size);
		if()
		puts(s);
		if(key[i]==c&&k<c-1){
			try(k+1);
		}
		if(key[i]!=c&&k<min-1){
			try(k+1);
		} 
		key[i]=0;
		mark[i]=0;
		s[k]='\0';
		if(k==1) continue;
		if(k>1) break;
		}
	}
	return 0;
}
int main()
{
memset(key,0,sizeof(key));
memset(mark,0,sizeof(mark));
char lookupW[30];
char filename[]="C:\\Users\\ADMIN\\Documents\\C programming\\C co ban\\week2\\word.txt";
Dict = loadDict(filename, &dict_size);
FILE *in;
in=fopen(filename2,"r");
a=scan(in);
try(0);
freeMem(Dict);
free(a);
return 0;

}
