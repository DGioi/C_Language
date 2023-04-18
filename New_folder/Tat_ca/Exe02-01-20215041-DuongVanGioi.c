#include<stdio.h>

int main(){
	float  x,y,z,t; 
	printf("nhap vao chieu dai:"); 
	scanf("%f",&x); 
	printf("\nhap vao chieu rong:");
	scanf("%f",&y);
if ((y>0) && (x>0)){
 z=2*(x+y);
 t=x*y;
  printf("\nChu vi %f",z); 
  printf("\ndien tich %f",t);}
  else
  printf("Hinh khong ton tai");
  return 0; }
