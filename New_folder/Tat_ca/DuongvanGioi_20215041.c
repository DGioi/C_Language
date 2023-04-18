#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
	char ten[5];
	float s;
	int dh;
} inf;
int n=0;
inf tro[101];
void nhap(){
	int i,j,a,b=1;
	while(1){
		scanf("%d",&a);
		if(0<n+a&&n+a<=100) break;
		else printf("\nNhap lai so luong thoa man:");
	}
	n=n+a;
	for(i=n-a;i<n;i++){
	while(1){
		b=1;
	printf("\nNhap ten:");
	scanf("%s",tro[i].ten);
	if(strlen(tro[i].ten)!=4) b=0;
	for(j=0;j<strlen(tro[i].ten);j++){
		if((int)tro[i].ten[j]<65||(int)tro[i].ten[j]>122) b=0;
		if((int)tro[i].ten[j]>90&&(int)tro[i].ten[j]<97) b=0;
	}
	if(b==0) printf("\nNhap lai! :\n");
	if(b==1) break;
	}while(1){
		printf("\nNhap dien tich :");
		scanf("%f",&tro[i].s);
		if(tro[i].s>=10&&tro[i].s<=40) break;
		else printf("\nNhap lai !:");
	}
	printf("\nDieu hoa: ");
	scanf("%d",&tro[i].dh);
	}
}
void print(){
	int i;
	printf("%-20s%-10s%-10s\n","Ten Phong","Dien Tich","Dieu Hoa");
	for(i=0;i<n;i++){
		printf("%-20s%-10f%-10d\n",tro[i].ten,tro[i].s,tro[i].dh);
	}
}
void search(){
	int i,d=0;
	float tim;
	printf("Nhap dien tich :");
	scanf("%f",&tim);
	for(i=0;i<n;i++){
	if((tro[i].s-5)<=tim&&tim<=(tro[i].s+5)){
		d++;
		if(d==1) printf("\n%-20s%-10s%-10s\n","Ten Phong","Dien Tich","Dieu Hoa");
		printf("%-20s%-10f%-10d\n",tro[i].ten,tro[i].s,tro[i].dh);
	}
	}
	if(d==0) printf("\nKhong tim thay!!\n");
}
void sx(){
	int i,j;
	inf tmp;
	for(i=0;i<n-1;i++)
	for(j=i;j<n;j++)
	if(tro[i].s<tro[j].s){
		tmp=tro[i];
		tro[i]=tro[j];
		tro[j]=tmp;
	}
}
void tkdh(){
	int i;
	int dh1=0,dh2=0,dh3=0,dh4=0;
	for(i=0;i<n;i++){
		if(tro[i].dh==0){
			if(tro[i].s<15) dh1++;
			if(tro[i].s>=15&&tro[i].s<22) dh2++;
			if(tro[i].s>=22&&tro[i].s<30) dh3++;
			if(tro[i].s>=30&&tro[i].s<=40) dh4++;
		}
	}
	printf("\n9000BTU: %d chiec \n",dh1);
	printf("\n12000TU: %d chiec \n",dh2);
	printf("\n18000BTU: %d chiec \n",dh3);
	printf("\n21000BTU: %d chiec \n",dh4);
}
	
int main(){
	int key;
	while(1){
		printf("------------MENU-----------\n");
		printf("1.Nhap thong tin phong tro\n");
		printf("2.In thong tin cac phong tro\n");
		printf("3.Tim kiem theo dien tich\n");
		printf("4.Sap xep\n");
		printf("5.Thong ke so luong dieu hoa can bo sung\n");
		printf("6.Thoat\n");
		printf("--------------------------\n");
		printf("Nhap vao lua chon : ");
		scanf("%d",&key);
		switch(key){
			case 1:{
				if(n==0) printf("\nNhap vao so luong phong tro (khong qua 100): ");
				if(n>0) printf("\nNhap them phong tro : ");
				nhap();
				break;
			}
			case 2:{
				print();
				break;
			}
			case 3:{
				search();
				break;
			}
			case 4:{
				sx();
				print();
				break;
			}
			case 5:{
				tkdh();
				break;
			}
			case 6:{
				printf("CHUONG TRINH KET THUC!!!\n");
				return 0;
				break;
			}
		}
	}
}
