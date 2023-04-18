#include<stdio.h>
int main(){
	char c1;
	int a1, a2;
	float f1;
	double f2;
	printf("dcbncp cho c1: %#X\n",&c1);
	printf("dcbncp cho a1: %#X\n",&a1); 
	printf("dcbncp cho a2: %#X\n",&a2); 
	printf("dcbncp cho c1: %#X\n",sizeof(c1)); 
	printf("dcbncp cho a1: %#X\n",sizeof(a1)); 
	printf("dcbncp cho a2: %#X\n",sizeof(a2)); 
	printf("dcbncp cho f2: %d\n",sizeof(f2)); 
	c1='C';
	printf("gia tri c1: %d\n",c1); 
	
	return 0; 
} 
