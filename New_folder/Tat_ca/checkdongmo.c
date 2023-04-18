#include<stdio.h>
#include<stdlib.h>
#define filename1 "C:\\Users\\ADMIN\\Documents\\C programming\\C co ban\\week9\\checkdongmo.txt"
// khai bao dslk don
struct dNode{
	char ch;
	struct dNode *pNext;
	struct dNode *pPrev;
};
typedef struct dNode DNODE;
struct list{
	DNODE *pHead;
	DNODE *pTail;
};
typedef struct list LIST;
void makelist(LIST *l){
	l->pHead=NULL;
	l->pTail=NULL;
}
DNODE* makeNode(char c){
	DNODE*newNode=(DNODE*)malloc(sizeof(DNODE));
	if(newNode==NULL){
		printf("khong du bo nho cap phat!");
		return NULL;
	}
	newNode->ch=c;
	newNode->pNext=NULL;
	newNode->pPrev=NULL;
	return newNode;
}
void push(LIST *l,DNODE*newNode){
	if(l->pHead==NULL){
		l->pHead=newNode;
		l->pTail=newNode;
		return;
	}
	else{
		l->pTail->pNext=newNode;
		newNode->pPrev=l->pTail;
		l->pTail=newNode;
	}
}
char pop(LIST*l){
	char c;
	if(l->pHead==l->pTail){
	c=l->pTail->ch;
	free(l->pHead);
	makelist(l);
	return c;
	}
	else{
	c=l->pTail->ch;
	l->pTail=l->pTail->pPrev;
	free(l->pTail->pNext);
	return c;
	}
	}
int check(char *namefile,LIST *l){
	 DNODE*newNode;
	 char ch;
	 int i=0,dau=0;
	 FILE *in;
	 in=fopen(namefile,"r");
	 if(in==NULL){
	 	printf("Loi mo file!");
	 	return 0;
	 }
	 while(!feof(in)) printf("%c",fgetc(in));
	 fseek(in,0,SEEK_SET);
	 while(!feof(in)){
	 	i++;
	 	ch=fgetc(in);
	 	if(ch=='<'){
	 		newNode=makeNode(ch);
	 		push(l,newNode);
		 }
		 if(ch=='>'){
		 	if(l->pTail==NULL){
		 		printf("\n\nLoi tai %d",i);
		 		dau++;
			 }
		 	else pop(l);
		 }
	 }
	 printf("\nco %d loi\n",dau);
	 if(dau) return 0;
	 else return 1;
}
int main(){
	LIST l;
	makelist(&l);
	if(check(filename1,&l)) printf("Khong tim thay loi !!!\n");
	else printf("\nLOI !!!\n");
	
}
