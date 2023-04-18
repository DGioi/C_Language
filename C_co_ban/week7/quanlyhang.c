#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define filename1 "C:\\Users\\ADMIN\\Documents\\C programming\\C co ban\\week7\\quanlyhang\\hanghoa.txt"
#define filename2 "C:\\Users\\ADMIN\\Documents\\C programming\\C co ban\\week7\\quanlyhang\\hanghoadangco.txt"
#define xx system("cls");
struct hang{
	char masp[10];
	char tensp[250];
	char hangsx[100];
	int soluong;
	struct hang *pNext;
};
typedef struct hang NODE;

struct list{
	NODE* pHead;
	NODE* pTail;
};
typedef struct list LIST;
void khoitaodauduoi(LIST *l){
	l->pHead=NULL;
	l->pTail=NULL;
}
NODE*khoitao(char ma[],char ten[],char hang[],char sl){
	NODE*p=(NODE*)malloc(sizeof(NODE));
	if(p==NULL){
		printf("khong du bo nho cap phat");
		return NULL;
	}
	strcpy(p->masp,ma);
	strcpy(p->tensp,ten);
	strcpy(p->hangsx,hang);
	p->soluong=sl;
	p->pNext=NULL;
	return p;
}

void themvaocuoi(LIST *l,NODE *p){
	NODE *q;
	
	if(l->pHead==NULL){
		l->pHead=p;
		l->pTail=p;
	}
	else{
	l->pTail->pNext=p;
	l->pTail=p;
	}
}
void print(LIST l){
	NODE *i;
	int j=1;
	printf("%-5s|%-30s|%-15s|%-5s\n","STT ","Ten san pham"," Hann san xuat ","Sl kho");
	for(i=l.pHead;i!=NULL;i=i->pNext){
		printf("%-5d|%-30s|%-15s|%-5d\n",j++,i->tensp,i->hangsx,i->soluong);
		
	}
}
void printmot(NODE *q){
	printf("Ma san pham:%s\n",q->masp);
	printf("Ten san pham %s\n",q->tensp);
	printf("Hang san xuat:%s\n",q->hangsx);
	printf("So luong :%d\n",q->soluong);
}
int checkkho(LIST *l,char ma[],int sl,int key){
	NODE*i;
	NODE*j;
		for(i=l->pHead;i->pNext!=NULL;i=i->pNext){
		if(strcmp(ma,i->pNext->masp)==0){
			j=i->pNext;
			if(key==3){
				printmot(j);
				return 1;
			} else{
					
					if(key==2) {
					printmot(j);	
					if((j->soluong)+sl<0){
					printf("Khong du de xuat\n");
					return 0;
					}
					}
					j->soluong+=sl;
					if(j->soluong==0){
					if(j==l->pHead){
					l->pHead=j->pNext;
					}
					if(j==l->pTail){
					l->pTail=i;
					i->pNext=NULL;
					}
					else{
					i->pNext=j->pNext;
					}	
					free(j);
					}
					return i->soluong;
			}
		
		}
	}
	
	 if(key!=1)printf("khong co\n");
	return 0;
}

void printfile(LIST l,FILE* hanghoa){
	NODE *i;
	for(i=l.pHead;i!=NULL;i=i->pNext){
		
		fprintf(hanghoa,"%s\n",i->hangsx);
		fprintf(hanghoa,"%s\n",i->tensp);
		fprintf(hanghoa,"%s\n",i->masp);
		fprintf(hanghoa,"%d\n",i->soluong);
		
	}
}
int main(){
	NODE*p;
	LIST l;
	khoitaodauduoi(&l);
	char masp[10];
	char tensp[250];
	char hangsx[100];
	int soluong;
	
	int key;
	FILE *dshangco;
	FILE *dshang;
	dshang=fopen(filename1,"r");
	if(dshang==NULL){
		printf("LOi Khong Mo DUoc FILE");
		return 0;
	}
	while(!feof(dshang)){
		fscanf(dshang,"%s",masp);
		fgetc(dshang);
		fscanf(dshang,"%[^\n]",tensp);
		fscanf(dshang,"%s",hangsx);
		fgetc(dshang);
		fscanf(dshang,"%d",&soluong);
		
		p=khoitao(masp,tensp,hangsx,soluong);
		themvaocuoi(&l,p);
		//printf("%s\n",l.pHead->masp);
	}
	fclose(dshang);
	while(1){
			printf("\nMENU\n");
			printf("1.Bo sung san pham\n");
			printf("2.Xuat kho\n");
			printf("3.Kiem tra san pham\n");
			printf("4.In ra\n");
			printf("5.Thoat\n");
			printf("Nhap lua chon:"); 
			scanf("%d",&key);
			fflush(stdin);
		switch(key){
		case 1:{
			xx
			printf("1.Bo sung san pham\n");
				printf("Ma san pham:");
				scanf("%s",masp);
				getc(stdin);
				printf("So luong:");
				scanf("%d",&soluong);
				if(!checkkho(&l,masp,soluong,1)){
				getc(stdin);
				printf("Ten san pham:");
				scanf("%[^\n]",tensp);
				printf("Hang san xuat:");
				scanf("%s",hangsx);
				p=khoitao(masp,tensp,hangsx,soluong);
				themvaocuoi(&l,p);
				print(l);
					}
				
			xx
			break;
		}
		case 2:{
			xx
			printf("2.Xuat kho\n");
			printf("Nhap vao ma hang:");
			scanf("%s",masp);
			printf("Nhap vao so luong :");
			scanf("%d",&soluong);
			checkkho(&l,masp,-soluong,2);
			getc(stdin);
			getc(stdin);
			xx
			
			break;
		}
		case 3:{
			xx
			printf("3.Kiem tra san pham\n");
			printf("Nhap vao ma hang:");
			scanf("%s",masp);
			checkkho(&l,masp,0,3);
			getc(stdin);
			getc(stdin);
			xx
			break;
		}
		case 4:{
			xx
			print(l);
			getc(stdin);
			xx
			break;
		}
		case 5:{	
			FILE*hanghoa;
			hanghoa=fopen(filename2,"w");
			printfile(l,hanghoa);
			fclose(hanghoa);
			free(p);
			return 0;
			break;
		}
	}
	}
	return 0;
}

