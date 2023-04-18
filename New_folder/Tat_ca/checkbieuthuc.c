#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
(*curSize)--;
return Stack[*curSize];
}
// ham kiem tra bieu thuc hop le
// tra ve 1 la bieu thuc KHONG hop le
// tra ve 0 neu bieu thuc OK
int checkEq(char *eq)
{
	int i;
char* Stack;
int curSize=0;
Stack = initStack(100);

printf("Input: %s\n",eq);
int check=0;
for(i=0; i<strlen(eq); i++)
{
if(eq[i]=='('||eq[i]=='['||eq[i]=='{')
push(eq[i],Stack,&curSize);
else if(eq[i]==')'||eq[i]==']'||eq[i]=='}')
{
if(curSize==0) //stack rong
{
printf("Error at %d!\n",i);
check = 1;
}				
else
{
char ch = pop(Stack, &curSize);
if((eq[i]==')'&&ch!='(')||(eq[i]==']'&&ch!='[')||
          (eq[i]=='}'&&ch!='{'))
          {
          	printf("Error at %d!\n",i);
          	check = 1;
  }
          
}
}
}
return check;
}
int main()
{

char eq[] = "A={3+}5*(7-4*c)/(b+7)-(3+A[2]]}";

int ret=checkEq(eq);
if(ret==0)
printf("Bieu thuc OK!\n");
else
printf("Vui long kiem tra lai bieu thuc!\n");
return 0;
}

