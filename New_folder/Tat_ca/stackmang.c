#include<stdio.h>
#include<stdlib.h>
 
char* initStack(int size)
{
char *newStack =(char*)malloc(size*sizeof(char));
return newStack;
}
 
void push(char data, char* Stack, int *curSize)
{
Stack[*curSize]=data;
(*curSize)++;
}
 
char pop(char* Stack, int *curSize)
{
Stack[*curSize]='\0';
(*curSize)--;
return Stack[*curSize];
}
 
int main()
{
char* Stack;
char i;
int curSize=0;
Stack = initStack(100);
for(i='a';i<='z';i++)
push(i,Stack,&curSize);
while(curSize>0)
printf("%c ", pop(Stack,&curSize));

return 0;
}

