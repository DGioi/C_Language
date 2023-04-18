#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define filename1 "C:\\Users\\ADMIN\\Documents\\C programming\\C co ban\\week7\\quanlytime\\time.txt"
#define filename2 "C:\\Users\\ADMIN\\Documents\\C programming\\C co ban\\week7\\quanlytime\\.txt"
#define xx system("cls");
struct node{
	float timein[500];
	char id[50];
	int solan;
	struct node *pNext;
};
typedef struct node NODE;
struct list{
	NODE*pHead;
	NODE*pTail;
};
typedef struct list LIST;
void khoitao(LIST *l){
	l->pHead=NULL;
	l->pTail=NULL;
}
NODE *khoitaop(float timein,char id[]){
	NODE*p=(NODE*)malloc(sizeof(NODE));
		if(p==NULL){
		printf("khong du bo nho cap phat");
		return NULL;
	}
	strcpy(p->id,id);
	
	p->pNext=NULL;
	p->solan=1;
	p->timein[0]=timein;
	return p;
}
void themvaodau(LIST *l,NODE *p){
	if(l->pHead=NULL){
		l->pHead=p;
		l->pTail=p;
	}
	else{
		p->pNext=l->pHead;
		l->pHead=p;
	}
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

int timkiem(LIST *l,char id[],float timein){
	NODE*i;
	
	for(i=l->pHead;i!=NULL;i=i->pNext){
		if(strcmp(i->id,id)==0){
			i->solan++;
			i->timein[i->solan-1]=timein;
			return 1;
		}
		
	}
	return 0;
}
int main(){
	float timein;
	int hour,min,sec;
	char id[50];
	NODE*p;
	LIST l;
	FILE *in;
	in=fopen(filename1,"r");
	while(!feof(in)){
		fscanf(in,"%d:%d:%d",&hour,&min,&sec);
		printf("%02d:%02d:%02d ",hour,min,sec);
		timein=hour+min/60.0+sec/3600.0;
	//	printf("moku:[  %5f  ]",timein);
		fscanf(in,"%s",id);
		printf("%s\n",id);
		fgetc(in);
		p=khoitaop(timein,id);
		if(!timkiem(&l,id,timein))themvaocuoi(&l,p);
		
	}
}
