#include<stdio.h>
int main(){
	float x,y;
	scanf("%f%f",&x,&y);
	if (x-y>0 ){ 
	printf("x lon hon y");
	return 0;
	}
	if (x-y<0){
	printf("x nho hon y");
	return 0;}
	printf("x bang y");
	return 0;
}
