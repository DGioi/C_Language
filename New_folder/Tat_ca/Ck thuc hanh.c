#include<stdio.h>
#define MAX 200
typedef struct {
	char hoten[30];
	int cccd[30];
	char sdt[15];
	float nhietdo;
	int ha1,ha2;
} thongtin;
thongtin nhap(){
	thongtin tt;
	printf("\nNhap ho va ten:");	
	scanf("%[^\n]",tt.hoten);
	printf("\nNhap so CCCD:");
	scanf("%s",tt.cccd);
	printf("\nNhap Phone:");
	scanf("%s",tt.sdt);
	printf("\nNhap nhiet do:");
	scanf("%f",&tt.nhietdo);
	printf("\nNhap huyet ap ha1_ha2:");
	scanf("%d_%d",&tt.ha1,&tt.ha2);
	return tt;
}
void ds(thongtin s,int i){
	printf("\n%-5d%-20s%-15d%-11s",i+1,s.hoten,s.cccd,s.sdt);
	
}
void main(){
	int i=0,j;
	char n;
	thongtin ttin[MAX];
	printf("Bo Y Te\n");
	do {
		ttin[i]=nhap();
		printf("Ban muon nhap them nua khong?\nTiep tuc nhan phim bat ki \nDung lai nhap \"n\"\n..... ");
		fflush(stdin);
		scanf("%c",&n);
		}while(n!='n');
		j=i;
	printf("%-5s%-20s%-15s%-11s","STT","Ho Ten","CCCD","SDT");
	for(i=0;i<=j;i++) {ds(ttin[i],i);}
	
}
