#include<stdio.h>
int main(){
	char bh[200],tg[200];
	printf("nhap vao ten bai hat:");
	scanf("%[^\n]%*c",bh);
	//fflush(stdin);
	//getchar();
	printf("\nNhap vao ten tac gia:");
	scanf("%[^\n]",tg);
	printf("Bai hat %s cua %s",bh,tg);
	return 0;
}
