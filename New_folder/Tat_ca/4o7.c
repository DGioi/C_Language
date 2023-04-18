#include<stdio.h> 
#define VAT 0.04
int main(){
	float x,y,z;
	char a[20],b[20];
	printf("Nhap ISBN va title: ");
	scanf("%s %s",a,b);
	printf("Nhap lan luot so luong va gia: ");
	scanf("%f%f",&x,&y);
	z=x*y;
	printf("BK Bookseller\n\n");
	printf("%-8s","Qty");
	printf("%-10s","ISBN");
	printf("%-15s","Title");
	printf("%-15s","Price");
	printf("%-15s","Total");
	printf("\n---------------------------------------------------------\n\n");
	printf("%-8.0f%-10s%-15s%-15.0f%-15.0f\n",x,a,b,y,z);
	printf("VAT: %f VND\n",VAT*z);
	printf("You pay:%f  VND",z*(1.0+VAT));
	printf("\n----------------------------------------------------------");
return 0;	
}



