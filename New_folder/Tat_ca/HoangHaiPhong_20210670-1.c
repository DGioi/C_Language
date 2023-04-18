#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n;
struct athlete{
	char name[50];
	char nation[50];
	int regis[3];
	short pass[3];
	int total;
	char medal;
};

typedef struct athlete athlete;
void form1(){
	printf("%-32s","Name");
	printf("%-32s","Nation");
	printf("%-10s","R1");
	printf("%-10s","R2");
	printf("%-10s","R3");
	printf("%-10s","P1");
	printf("%-10s","P2");
	printf("%-10s","P3");
	printf("\n");
	
}
void form2(){
	printf("%-28s","Name");
	printf("%-28s","Nation");
	printf("%-8s","R1");
	printf("%-8s","R2");
	printf("%-8s","R3");
	printf("%-8s","P1");
	printf("%-8s","P2");
	printf("%-8s","P3");
	printf("%-8s","Total");
	printf("\n");
	
}
void form3(){
	printf("%-26s","Name");
	printf("%-26s","Nation");
	printf("%-7s","R1");
	printf("%-7s","R2");
	printf("%-7s","R3");
	printf("%-7s","P1");
	printf("%-7s","P2");
	printf("%-7s","P3");
	printf("%-7s","Total");
	printf("%-7s","Medal");
	printf("\n");
	
}
void xuat1(athlete a){
	printf("%-32s",a.name);
	printf("%-32s",a.nation);
	printf("%-10d",a.regis[0]);
	printf("%-10d",a.regis[1]);
	printf("%-10d",a.regis[2]);
	printf("%-10d",a.pass[0]);
	printf("%-10d",a.pass[1]);
	printf("%-10d",a.pass[2]);
	printf("\n");
}
void xuat2(athlete a){
	printf("%-28s",a.name);
	printf("%-28s",a.nation);
	printf("%-8d",a.regis[0]);
	printf("%-8d",a.regis[1]);
	printf("%-8d",a.regis[2]);
	printf("%-8d",a.pass[0]);
	printf("%-8d",a.pass[1]);
	printf("%-8d",a.pass[2]);
	printf("%-8d",a.total);
	printf("\n");
}
void xuat3(athlete a){
	printf("%-26s",a.name);
	printf("%-26s",a.nation);
	printf("%-7d",a.regis[0]);
	printf("%-7d",a.regis[1]);
	printf("%-7d",a.regis[2]);
	printf("%-7d",a.pass[0]);
	printf("%-7d",a.pass[1]);
	printf("%-7d",a.pass[2]);
	printf("%-7d",a.total);
	printf("%-7c",a.medal);
	printf("\n");
}
void nhap(athlete *a){
	printf("Nhap so van dong vien : ");
	scanf("%d",&n);
	while(n<3||n>100){
		printf("So van dong vien khong thoa man, moi ban nhap lai !\n");
		printf("Nhap so van dong vien : ");
		scanf("%d",&n);
	}
	int i;
	for(i=0;i<n;i++){
		fflush(stdin);
		scanf("%s",a[i].name);
		scanf("%s",a[i].nation);
		scanf("%d%d%d",&a[i].regis[0],&a[i].regis[1],&a[i].regis[2]);
		scanf("%d%d%d",&a[i].pass[0],&a[i].pass[1],&a[i].pass[2]);
	}
	form1();
	for(i=0;i<n;i++)
	{
		xuat1(a[i]);
	}
}
void tinhtongdiem(athlete *a){
	int i;
	for(i=0;i<n;i++){
		if(a[i].pass[0]==1) a[i].total+=a[i].regis[0];
		if(a[i].pass[1]==1) a[i].total+=a[i].regis[1];
		if(a[i].pass[2]==1) a[i].total+=a[i].regis[2];
	}
	form2();
	for(i=0;i<n;i++){
	    xuat2(a[i]);
	}
}
void sapxeptheotongdiem(athlete *a){
	int i,j;
	athlete temp;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a[i].total<a[j].total){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	a[0].medal='G';
	a[1].medal='S';
	a[2].medal='B';
	form3();
	for(i=0;i<3;i++){
		xuat3(a[i]);
	}
}
void indanhsachquocgia(athlete *a){
	int i,j;
	athlete temp;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(strcmp(a[i].nation,a[j].nation)>0){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	int dem;
	dem=1;
	printf("%-32s","Nation");
	printf("%-32s","Number");
	printf("\n");
	for(i=0;i<n;i++){
		if(strcmp(a[i].nation,a[i+1].nation)==0){
			dem++;
		}
		if(strcmp(a[i].nation,a[i+1].nation)!=0){
			printf("%-32s",a[i].nation);
			printf("%-32d",dem);
			printf("\n");
			dem=1;
		}
	}
}



   
int main(){
	athlete a[102];
	int key;
	int b=1;
	while(b){
		printf("---------------MENU----------------\n");
		printf("1.Nhap\n");
		printf("2.Tinh tong diem\n");
		printf("3.Sap xep theo tong diem\n");
		printf("4.In danh sach quoc gia\n");
		printf("5.Ket thuc chuong trinh\n");
		printf("-------------------------------------\n");
		printf("Chuc nang ban chon : ");
		scanf("%d",&key);
		switch(key){
			case 1: nhap(a);break;
			case 2: tinhtongdiem(a);break;
			case 3: sapxeptheotongdiem(a);break;
			case 4: indanhsachquocgia(a);break;
			case 5: printf("Chuong trinh ket thuc!\n");b=0;break;
		}
		
	}
}
