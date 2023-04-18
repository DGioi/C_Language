#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct dNode{
	char data[100];
	struct dNode*pNext;
	struct dNode*pPrev;
};
typedef struct dNode DNODE;

struct list{
	DNODE*pHead;
	DNODE*pTail;
};
typedef struct list LIST;
void makelist(LIST *l){
	l->pHead=NULL;
	l->pTail=NULL;
} 
DNODE* makeNode(char *data){
	DNODE*newNode;
	newNode=(DNODE*)malloc(sizeof(DNODE));
	if(newNode==NULL){
		printf("khong du bo nho cap phat");
		return NULL;
	}
	else{
		strcpy(newNode->data,data);
		newNode->pNext=NULL;
		newNode->pPrev=NULL;
		return newNode;
	}
}
void insertLast(LIST *l,DNODE*newNode){
	if(l->pHead==NULL){
		l->pHead=newNode;
		l->pTail=newNode;
	}
	else{
	l->pTail->pNext=newNode;
	newNode->pPrev=l->pTail;
	l->pTail=newNode;
	}
}

int main(){
	char data[100];
	DNODE*ctr;
	DNODE*newNode;
	LIST l;
	makelist(&l);
	while(1){
		char c=getch();
		if(c==13){
			if(l.pHead==l.pTail){
				printf("\ntab moi:");
				gets(data);
				newNode=makeNode(data);
				insertLast(&l,newNode);
				ctr=l.pTail;
			}else{
				printf("\ntab moi:");
				DNODE*i;
				for(i=ctr->pNext;i!=NULL;i=i->pNext){
					free(i);
				}
				//
				l.pTail=ctr;
				gets(data);
				newNode=makeNode(data);
				insertLast(&l,newNode);
				ctr=l.pTail;
			}
		}
		if(c==-32){
		c=getch();
		switch(c) 
 		{
   			case 77: {
   				if(ctr->pNext==NULL) break;
   				if(ctr==l.pTail){
   					printf("%s ",ctr->data);
				   }else{
				   	ctr=ctr->pNext;
				   	printf("%s ",ctr->data);
				   }
				break;
			   }
   			
   			case 75: {
   				if(ctr->pPrev==NULL) break;
   					if(ctr==l.pHead){
   					printf(" %s ",ctr->data);
				   }else{
				   	ctr=ctr->pPrev;
				   	printf(" %s ",ctr->data);
				   }
				break;
			   }
			 }
			 }
			 	if(c=='x') break;
	}
	for(ctr=l.pHead;ctr!=NULL;ctr=ctr->pNext){
		printf("%s",ctr->data);
	}
	return 0;
}
