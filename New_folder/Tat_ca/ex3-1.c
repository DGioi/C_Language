#include<stdio.h>
int main(){
	printf("Size of int :%d byte\n",sizeof(int)); 
		printf("Size of long :%d byte\n",sizeof(long));
			printf("Size of short :%d byte\n",sizeof(short));
				printf("Size of double :%d byte\n",sizeof(double));
					printf("Size of char :%d byte\n",sizeof(char));
	char a[]="anh",y[]="yeu",e[]="em";
	printf("%s %s %s",a,y,e);
	return 0; 
} 
