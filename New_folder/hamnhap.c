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
	b=(bill*)malloc(1000*sizeof(bill));
	int i=0;
	char c;
	while(1){
		if(scanf("%d",&b[i].dd)==0){
			 c=getc(stdin);
		//	if(c=='$')
				break;
		//	else continue;
		} 
			
		scanf("-%d-%d %s%s%s%d%d",&b[i].mm,&b[i].yy,b[i].seller,b[i].buyer,b[i].productID,&b[i].number,&b[i].cost);
	//	printf("%d-%d-%d %s %s %s %d %d\n",b[i].dd,b[i].mm,b[i].yy,b[i].seller,b[i].buyer,b[i].productID,b[i].number,b[i].cost);
		i++;
		getc(stdin);
	}
//	printf("%c",c);
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
void checkcost(int size,bill*b){
	int i;
	int count=0;
	for(i=0;i<size;i++){
		if(b[i].cost>=1&&b[i].cost<=200) count++;
	}
	printf("thoa man : %d\n",count);
}
int main(){
	bill *b;
	int size;
	b=nhapdulieu(&size);
	printBill(size,b);
	checkcost(size,b);
	free(b);
	return 0;

}
