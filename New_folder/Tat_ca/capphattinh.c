#include<stdlib.h>
#include<stdio.h>
#include<string.h>
const int TOTAL_WORDS = 370100;
const int WORD_LEN = 30;
int main()
{
char **Words;
int i,n,total_size=0;
char filename[]="C:\\Users\\ADMIN\\Documents\\C programming\\C co ban\\week2\\word.txt";
FILE *fPtr;
fPtr = fopen(filename, "r");
if(fPtr == NULL) {
      perror("Error in opening file");
      return(-1);
   	}
n = 0;

Words=(char**)malloc(sizeof(char*)*TOTAL_WORDS);

for(i=0;i<TOTAL_WORDS; i++)
{
Words[i] = (char*)malloc(sizeof(char)*WORD_LEN);		
}


              i=0;
while(fgets(Words[i], WORD_LEN, fPtr)!=NULL) {
puts(Words[i]);
i++;
total_size=total_size+WORD_LEN;
}
fclose(fPtr);

n=i;
printf("Total Read: %d\n",n);
printf("Total size: %d\n",total_size);
return 0;

}

