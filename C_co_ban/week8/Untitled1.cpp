#include<stido.h>
#include<stdlib.h>
char* initStack(int size){
	char *newStack=(char*)malloc(sizeof(char)*size);
	return newStack;
}
void push(char data,char *Stack,int *curSize){
	Stack[*curSize]=data;
	(*curSize)++;
}
char pop(char*Stack,int *curSize){
	(*curSize)--;
	return Stack[*curSize];
}
int main()
{
	char *Stack;
	char i;
	int curSize=0;
	Stack=iniStack(100);
	for(i='a';i<='z';i++)
	push();

}
