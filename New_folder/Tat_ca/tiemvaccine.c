#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct{
	char name[50];
	char cccd[50];
	char sdt[15];
	float t;
	int ha1,ha2;
	bool dk;
} inf;
int n=0;
int nhap(inf *a){
	int i=n-1;
	char k;
	do{
	fflush(stdin);
	i++;
	printf("\nNhap vao thong tin\n 	Name 		CCCD 	SDT 	T	 HA1 HA2\n");
	scanf("%[^{0,1,2,3,4,5,6,7,8,9,\n}] %s %s %f %d %d",a[i].name,a[i].cccd,a[i].sdt,&a[i].t,&a[i].ha1,&a[i].ha2);
	printf("\nNhap bat ky de nhap tiep, 'n' de dung lai\n");
	fflush(stdin);
	scanf("%c",&k);
	}
	while(k!='n');
return i+1;
}
void print(inf a[]){
	int i;
	printf("%-5s%-20s%-15s%-20s\n","STT","Name","CCCD","SDT");
	for(i=0;i<n;i++){
		printf("%-5d%-20s%-15s%-20s\n",i+1,a[i].name,a[i].cccd,a[i].sdt);
	}
}
int checkt(float a){
	if(a>=36.8&&a<=38) return 1;
	return 0;
}
int checkha(int ha1,int ha2){
	if(ha1>=100&&ha1<=130) if(ha2>=79&&ha2<=89) return 1;
	return 0;
}
void print1(inf *a){
	int i;
	char s[10];
	printf("%-5s%-20s%-15s%-20s%-20s\n","STT","Name","CCCD","SDT","Ket Qua");
	for(i=0;i<n;i++){
	if(checkha(a[i].ha1,a[i].ha2)&&checkt(a[i].t)) a[i].dk=1;
	else a[i].dk=0;
	if(a[i].dk) strcpy(s,"Duoc Tiem");
	else strcpy(s,"Khong tiem");
	printf("%-5d%-20s%-15s%-20s%-20s\n",i+1,a[i].name,a[i].cccd,a[i].sdt,s);
	}
}
void printdudk(inf a[]){
	int i;
	printf("%-5s%-20s%-15s%-20s\n","STT","Name","CCCD","SDT");
	for(i=0;i<n;i++)
		if(a[i].dk) 
		printf("%-5d%-20s%-15s%-20s\n",i+1,a[i].name,a[i].cccd,a[i].sdt);
}
void search(inf a[]){
	int i;
	char b[15];
	printf("Nhap vao sdt:");
	scanf("%s",b);
	for(i=0;i<n;i++){
		if(strcmp(a[i].sdt,b)==0){
		printf("\n%-5s%-20s%-15s%-20s\n","STT","Name","CCCD","SDT");
		printf("%-5d%-20s%-15s%-20s\n",i+1,a[i].name,a[i].cccd,a[i].sdt);
		break;
		}
		printf("\nKhong tim thay!\n");
	}
}
int main(){
	inf in4[200];
	int key;
	while(1){
		printf("%30s\n","MENU");
		printf("1.Nhap thong tin nguoi den tim\n");
		printf("2.In ra danh sach nhung nguoi dang ky\n");
		printf("3.Kiem tra dieu kien duoc tiem\n");
		printf("4.In danh sach du dieu kien\n");
		printf("5.Tra cu thong tin nguoi dang ky theo sdt\n");
		printf("6.Thoat\n");
		printf("Nhap vao lua chon: ");
		scanf("%d",&key);
		fflush(stdin);
		switch(key){
			case 1:{
				n=nhap(in4);
				break;
			}
			case 2:{
				print(in4);
				break;
			}
			case 3:{
				print1(in4);
				break;
			}
			case 4:{
				printdudk(in4);
				break;
			}
			case 5:{
				search(in4);
				break;
			}
			case 6:{
				return 0;
				break;
			}
			
		}
	}
}
