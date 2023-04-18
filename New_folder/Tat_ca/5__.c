#include<stdio.h>
int main(){
	char a,b;
	scanf("%c",&a);
	scanf("%c",&b);
    	if (a-b>0 ){ 
	printf("%c dung truoc %c",a,b);
	return 0;
	}
	if (a-b<0){
	printf("%c dung sau %c");
	return 0;}
	printf("%c la %c");
	return 0;
}
