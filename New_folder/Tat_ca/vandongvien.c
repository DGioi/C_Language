#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
typedef struct{
	int id;
	char nation[50];
	char name[50];
	float r[3],pr;
} inf;
inf f[20];
int n;
void nhap(){
	int i;
	printf("Nhap vao so vdv:");
	while(1){
		scanf("%d",&n);
		if(n<0||n>20){
			printf("vui long nhap lai!!\n ");
			continue;
		}else break;
	}
	for(i=0;i<n;i++){
		scanf("%d %s %[^\n]",&f[i].id,f[i].nation,f[i].name);
	}	
}
void prin1(){
	int i;
	printf("%-5s%-15s%-30s%-7s%-7s%-7s%-7s\n","STT","Nation","Name","R1","R2","R3","PR");
	for(i=0;i<n;i++){
		printf("%-5d%-15s%-30s%-7.2f%-7.2f%-7.2f%-7.2f\n",f[i].id,f[i].nation,f[i].name,f[i].r[0],f[i].r[1],f[i].r[2],f[i].pr);
	}
}
void lan1(){
	int i;
	printf("\n%30s\n","LAN 1");
	printf("%-5s%-20s%-10s\n","ID","Name","R1");
	for(i=0;i<n;i++){
	printf("%-5d%-20s",f[i].id,f[i].name);
	scanf("%f",&f[i].r[0]);
	}
}
void lan2(){
	int i;
	printf("\n%30s\n","LAN 2");
	printf("%-5s%-20s%-10s\n","ID","Name","R2");
	for(i=0;i<n;i++){
	printf("%-5d%-20s",f[i].id,f[i].name);
	scanf("%f",&f[i].r[1]);
	}
}
void lan3(){
	int i;
	printf("\n%30s\n","LAN 3");
	printf("%-5s%-20s%-10s\n","ID","Name","R3");
	for(i=0;i<n;i++){
	printf("%-5d%-20s",f[i].id,f[i].name);
	scanf("%f",&f[i].r[2]);
	f[i].pr=f[i].r[0]>f[i].r[1]?(f[i].r[0]>f[i].r[2]?f[i].r[0]:f[i].r[2]):(f[i].r[1]>f[i].r[2]?f[i].r[1]:f[i].r[2]);
	}
}
void timqg(){
	int i;
	char s[50];
	printf("Nhap ten quoc gia can tim: ");
	scanf("%s",s);
	printf("\n%-5s%-15s%-30s%-7s%-7s%-7s%-7s\n","STT","Nation","Name","R1","R2","R3","PR");
	for(i=0;i<n;i++)
	if(strcmp(s,f[i].nation)==0)
	printf("%-5d%-15s%-30s%-7.2f%-7.2f%-7.2f%-7.2f\n",f[i].id,f[i].nation,f[i].name,f[i].r[0],f[i].r[1],f[i].r[2],f[i].pr);
}
void timten(){
	int i;
	char s[50];
	printf("Nhap ten VDV can tim: ");
	fflush(stdin);
	scanf("%[^\n]",s);
	printf("\n%-5s%-15s%-30s%-7s%-7s%-7s%-7s\n","STT","Nation","Name","R1","R2","R3","PR");
	for(i=0;i<n;i++)
	if(strcmp(s,f[i].name)==0)
	printf("%-5d%-15s%-30s%-7.2f%-7.2f%-7.2f%-7.2f\n",f[i].id,f[i].nation,f[i].name,f[i].r[0],f[i].r[1],f[i].r[2],f[i].pr);
}
void xephang(){
	int i,j;
	inf tmp;
		for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++){
			if(f[i].pr<f[j].pr){
				tmp=f[i];
				f[i]=f[j];
				f[j]=tmp;
			}
		}
}
int main(){
	int key,key2;
	while(1){
		printf("%-15s\n","MENU");
		printf("1.Nhap thong tin truoc khi thi dau\n");
		printf("2.In thong tin\n");
		printf("3.Thi dau\n");
		printf("4.Tim kiem\n");
		printf("5.In ket qua\n");
		printf("6.Ket thuc\n");
		printf("Nhap vao lua chon : ");
		scanf("%d",&key);
		switch(key){
			case 1:{
				nhap();
				break;
			}
			case 2:{
				prin1();
				break;
			}
			case 3:{
				lan1();
				prin1();
				
				lan2();
				prin1();
				
				lan3();
				prin1();
				break;
			}
			case 4:{
				printf("\n1. Tim theo quoc gia\n");
				printf("2. Tim theo ten\n");
				printf("chon ");
				scanf("%d",&key2);
				if(key2==1){
					timqg();
				}else
				if(key2==2){
					timten();
				}
				else printf("\nVui long chon lai");
				break;
			}
			case 5:{
				xephang();
				prin1();
				break;
			}
			case 6:{
				printf("\nChuong trinh ket thuc!!");
				return 0;
				break;
			}
		}
	}
}
