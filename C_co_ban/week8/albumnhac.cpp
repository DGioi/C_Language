#include<stdio.h>
#include<stdlib.h>
#include<tring.h>
#define filename "C:\\Users\\ADMIN\\Documents\\C programming\\C co ban\\week8\\album\\nhac.txt"

struct dNode{
	char songname[255];
	char singer[255];
	int duration;
	struct dNode *pNext,*pPrev;
};
typedef struct dNode DNODE;

DNODE *makeNode(char *songname,char *singer,int duration){
	DNODE*newNode=(DNODE*)malloc(sizeof(DNODE));
	if(newNode==NULL){
		printf("khong du bo nho cap phat!");
		return NULL;
	}
	strcpy(newNode->songname,songname);
	strcpy(newNode->singer,singer);
	newNode->duration=duration;
	newNode->pNext=NULL;
	newNode->pPrev=NULL;
	return newNode;
}
struct list{
	DNODE*pHead;
	DNODE*pTail;
};
typedef struct list LIST;
void insertFirst(LIST *l,DNODE*newNode){
	if(l->pHead==NULL){
		l->pHead=newNode;
		l->pTail=newNode;
	}
	else
	{
		l->pHead->pPrev=newNode;
		newnode->next=l->pHead;
		l->pHead=newNode;
		
	}
}
void insertAfter(LIST l,DNODE*newNode,DNODE*p){
	DNODE*i;
	for(i=l.pHead;i!=NULL;i=i->pNext){
		if(i==p){
			newNode->pNext=i->pNext;
			i->pNext->pPrev=newNode;
			i->pNext=newNode;
			newNode->pPrev=i;
		}
	}
}
void inserLast(LIST *l,DNODE*newNode){
	if(l->pHead==NULL){
		l->pHead=p;
		l->pTail=p;
	}
	else{
	l->pTail->pNext=newNode;
	newNode->pPrev=l->pTail;
	l->pTail=newNode;
	}
}
