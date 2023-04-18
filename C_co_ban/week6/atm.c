#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define xx system("cls");
#define yy getc(stdin);
#define filename1 "C:\\Users\\ADMIN\\Documents\\C programming\\C co ban\\week6\\atm\\theatm1.txt"
#define filename2 "C:\\Users\\ADMIN\\Documents\\C programming\\C co ban\\week6\\atm\\theatm2.txt"
const int N=1000;
void exchange(int *M,int n, int money){
	printf("Doi luong tien %d\n",money);
	int *slot=(int*)calloc(sizeof(int),n);
	int i=0;
	while(money>0){
		
		while(money>=M[i]){
			money=money-M[i];
			slot[i]++;	
			printf("%d \n",M[i]);		
		}
		
		i++;
		if(money>0&&i>=n){
			printf("Khong doi duoc");
			free(slot);
			return;
		}
	}
	for(i=0;i<n;i++)
	printf("%d: %d\n",M[i],slot[i]);
	free(slot);
}
int main2(int money){
	int a[20];
	int M[]={500,200,100,50};
	int slt[]={800,500,500,400};
	int n=4;
	exchange(M,n,money);
	return 0;
}




typedef struct{
	char ctk[50];
	int stk;
	int sodu;
} datanganhang;
typedef struct{
	int stk;
	int pin;
} dulieuthe;
datanganhang* loaddulieu(FILE*nganhang,int *sl){
	int i=0;
	datanganhang *data;
	data=(datanganhang*)malloc(sizeof(datanganhang)*N);
	while(!feof(nganhang)){
		fscanf(nganhang,"ctk:%[^\n]",data[i].ctk);
		fgetc(nganhang);
		fscanf(nganhang,"stk:%d",&data[i].stk);
		fgetc(nganhang);
		fscanf(nganhang,"sdu:%d",&data[i].sodu);
		fgetc(nganhang);
		i++;
	}
	*sl=i;
	for(i=0;i<*sl;i++){
		printf("%s\n",data[i].ctk);
		printf("%d\n",data[i].stk);
		printf("%d\n",data[i].sodu);
	}
	return data;
}
int quetthe(FILE*thecung,dulieuthe *the){
	int i=0;
	int tmp;
	fscanf(thecung,"stk:%d",&(the->stk));
	getc(thecung);
	if(getc(thecung)=='!') {
		printf("THE BAN DA BI KHOA. LH:0374348370 de biet them chi tiet");
		return 0;
	}
	fseek(thecung,-1,SEEK_CUR);
	fscanf(thecung,"pin:%d",&(the->pin));
	while(i<=2){
		printf("Nhap ma pin:");
		scanf("%d",&tmp);
		if(the->pin==tmp) {
			return 1;
		}
		printf("Ban da nhap sai ma pin %d lan \n",i+1);
		i++;
		printf("Nhan \" \" de dung lai\n");
		getc(stdin);
		if(getc(stdin)==' ') return 0;
		printf("Thu lai!");
		xx
	}
	if(i==3){
		fseek(thecung,0,SEEK_SET);
		printf("The cua ban da bi khoa");
		fprintf(thecung,"stk:%d\n",the->stk);
		fprintf(thecung,"!pin:%d",the->pin);
		fclose(thecung);
	}
	return 0;
}

int napdulieu(datanganhang *data,int sl,int stkthe){
	int i=0;
	for(i=0;i<sl;i++){
		if(data[i].stk==stkthe){
			return i;
		}
	}
}
void chuyentien(datanganhang* data,int sl,int sotien,int stknhan){
	int i;
	for(i=0;i<sl;i++){
		if(stknhan==data[i].stk){
			data[i].sodu+=sotien;
			return;
		}
	}
	printf("khong hop le\n");
	return;
}

void capnhatfile(datanganhang *nh,int sl){
	int i;
	FILE *nganhang;
	nganhang=fopen(filename2,"w");
					for(i=0;i<sl-1;i++){
					fprintf(nganhang,"ctk:%s\n",nh[i].ctk);
					fprintf(nganhang,"stk:%d\n",nh[i].stk);
					fprintf(nganhang,"sdu:%d\n",nh[i].sodu);
					}
					fprintf(nganhang,"ctk:%s\n",nh[i].ctk);
					fprintf(nganhang,"stk:%d\n",nh[i].stk);
					fprintf(nganhang,"sdu:%d",nh[i].sodu);
			fclose(nganhang);
		return;
}
int main(){
	int i;
	int sl;
	int stknhan,sotien;
	int vtsd;
	int menhgia[]={500,200,100,50};
	int slt[]={800,500,500,400};
	dulieuthe the;
	datanganhang *nh;
	int key;
	FILE*thecung;
	FILE*nganhang;
	thecung=fopen(filename1,"r+");
	nganhang=fopen(filename2,"r+");
	printf("Dang Nhap\n");
			if(!quetthe(thecung,&the)) return 0;
			xx
	nh=loaddulieu(nganhang,&sl);
	fclose(nganhang);
	yy
	yy
	xx
	while(1){		
			printf("MENU\n");
			printf("1.Kiem tra so du\n");
			printf("2.Chuyen Tien\n");
			printf("3.Rut Tien\n");
			printf("4.Nap tien \n");
			printf("5.Dang xuat\n");
			printf("Nhap lua chon:"); 
			scanf("%d",&key);
			fflush(stdin);
			
		vtsd=napdulieu(nh,sl,the.stk);
		switch(key){
		case 1:{
			printf("So du hien tai :%d",nh[vtsd].sodu);
			yy
			yy
			xx
			break;
		}
		case 2:{
			
			printf("STK nguoi nhan:");
			scanf("%d",&stknhan);
			yy
			printf("So tien:");
			scanf("%d",&sotien);
				while(sotien>5000){
				printf("Khong qua 5tr, vui long nhap lai:");
				scanf("%d",&sotien);
			}
			nh[vtsd].sodu-=sotien;
			chuyentien(nh,sl,sotien,stknhan);
			capnhatfile(nh,sl);
			break;
		}
		case 3:{
			printf("Nhap so tien can rut:");
			scanf("%d",&sotien);
			while(sotien>5000){
				printf("Khong qua 5tr, vui long nhap lai:");
				scanf("%d",&sotien);
			}
			main2(sotien);
			nh[vtsd].sodu-=sotien;
			yy
			yy
			xx
			break;
		}
		case 4:{
			printf("Nhap so tien can nap:");
			scanf("%d",&sotien);
			nh[vtsd].sodu+=sotien;
			yy
			yy
			xx
			break;
		}
		case 5:{
			capnhatfile(nh,sl);
			free(nh);
			return 0;
			break;
		}
	}
	}
	return 0;
}
/////

