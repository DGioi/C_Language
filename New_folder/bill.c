#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define xx system("cls");
#define nn printf("\n");
typedef struct{
	int dd,mm,yy;
	char seller[50];
	char buyer[50];
	char productID[50];
	int number,cost;
} bill;
bill *nhapdulieu(int *size){
	bill *b;
	b=(bill*)malloc(sizeof(bill));
	int i=0;
	char c='c';
	while(1){
		if(scanf("%d",&b[i].dd)==0){
			char c=getc(stdin);
			if(c=='$')
			break;
		} 
		scanf("-%d-%d %s%s%s%d%d",&b[i].mm,&b[i].yy,b[i].seller,b[i].buyer,b[i].productID,&b[i].number,&b[i].cost);
		i++;
		c=getc(stdin);
	}
	*size=i;
	return b;
}
void printBill(int size,bill *b){
	int i;
	nn
	for(i=0;i<size;i++){
			printf("%d-%d-%d %s %s %s %d %d\n",b[i].dd,b[i].mm,b[i].yy,b[i].seller,b[i].buyer,b[i].productID,b[i].number,b[i].cost);
	}
	}
int main(){
	bill *b;
	int size;
	b=nhapdulieu(&size);
	printBill(size,b);
	return 0;

}
