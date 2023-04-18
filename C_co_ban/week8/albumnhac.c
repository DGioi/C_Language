#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define xx system("cls");
#define filename "C:\\Users\\ADMIN\\Documents\\C programming\\C co ban\\week8\\album\\nhac.txt"
#define MAX_LEN 35
#define filename1 "C:\\Users\\ADMIN\\Documents\\C programming\\C co ban\\week8\\album\\luunhac.txt"
int sobai;
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
void makelist(LIST *l){
	l->pHead=NULL;
	l->pTail=NULL;
}
void insertFirst(LIST *l,DNODE*newNode){
	if(l->pHead==NULL){
		l->pHead=newNode;
		l->pTail=newNode;
	}
	else
	{
		l->pHead->pPrev=newNode;
		newNode->pNext=l->pHead;
		l->pHead=newNode;
		
	}
}
void insertAfter(DNODE*newNode,DNODE*p){
			newNode->pNext=p->pNext;
			p->pNext->pPrev=newNode;
			p->pNext=newNode;
			newNode->pPrev=p;
		
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

void printPlaylist(LIST l){
	int idx=0;
	char sname[MAX_LEN];
	char singer[15];
	DNODE *i;
	printf("Danh sach bai hat hien tai:\n");
	for(i=l.pHead;i!=NULL;i=i->pNext){
		strncpy(sname,i->songname,MAX_LEN-1); 
		if(strlen(i->songname)>=MAX_LEN) { 
		sname[strlen(sname)-3]='.';
		 sname[strlen(sname)-2]='.';
		  sname[strlen(sname)-1]='.';}
		  
		  strncpy(singer,i->singer,10); 
		if(strlen(i->singer)>=10) { 
		singer[strlen(singer)-3]='.';
		 singer[strlen(singer)-2]='.';
		 singer[strlen(singer)-1]='.';}
		printf("%2d. ",1+idx++);
		printf("%-50s",sname);
		printf("-%15s",singer);
		printf("%02d:%02d\n",i->duration/60,i->duration%60);
	}
}
LIST loadPlaylist(char *namefile){
	int i=0;
	char songname[255];
	char singer[255];
	int duration;
	LIST l;
	makelist(&l);
	DNODE*newNode;
	FILE* file;
	file=fopen(namefile,"r");
	fscanf(file,"%d",&sobai);
	while(i<sobai){
		i++;
		fgetc(file);
		fscanf(file,"%[^\n]",songname);
		fgetc(file);
		fscanf(file,"%[^\n]",singer);
		fscanf(file,"%d",&duration);
		newNode=makeNode(songname,singer,duration);
		insertLast(&l,newNode);
	}
	fclose(file);
	return l;
}
void printp(DNODE*p){
	if(p==NULL) return;
	char sname[MAX_LEN];
	char singer[15];
	
	strncpy(sname,p->songname,MAX_LEN-1); 
		if(strlen(p->songname)>=MAX_LEN) { 
		sname[strlen(sname)-3]='.';
		 sname[strlen(sname)-2]='.';
		  sname[strlen(sname)-1]='.';}
		  
		  strncpy(singer,p->singer,10); 
		if(strlen(p->singer)>=10) { 
		singer[strlen(singer)-3]='.';
		 singer[strlen(singer)-2]='.';
		 singer[strlen(singer)-1]='.';}
		printf("%-50s",sname);
		printf("-%15s",singer);
		printf("%02d:%02d\n",p->duration/60,p->duration%60);
}
void savePlayListToFile(char* namefile, LIST l){
	FILE *file;
	file=fopen(namefile,"w");
		int idx=0;
	char sname[MAX_LEN];
	char singer[15];
	DNODE *i;
	fprintf(file,"Danh sach bai hat hien tai:\n");
	for(i=l.pHead;i!=NULL;i=i->pNext){
		strncpy(sname,i->songname,MAX_LEN-1); 
		if(strlen(i->songname)>=MAX_LEN) { 
		sname[strlen(sname)-3]='.';
		 sname[strlen(sname)-2]='.';
		  sname[strlen(sname)-1]='.';}
		  
		  strncpy(singer,i->singer,10); 
		if(strlen(i->singer)>=10) { 
		singer[strlen(singer)-3]='.';
		 singer[strlen(singer)-2]='.';
		 singer[strlen(singer)-1]='.';}
		fprintf(file,"%2d. ",1+idx++);
		fprintf(file,"%-50s",sname);
		fprintf(file,"-%15s",singer);
		fprintf(file,"%02d:%02d\n",i->duration/60,i->duration%60);
	}
	fclose(file);
	return;
}
// tim kiem bai hat trong playlist va tra ve 
// con tro toi bai hat neu no co trong playlist
// nguoc lai tra ve NULL
// chi can tim kiem 1 phan cua ten
DNODE *searchSongName(LIST l, char *sName)
{
	char s[MAX_LEN];
	DNODE*i;
	for(i=l.pHead;i!=NULL;i=i->pNext){
		strncpy(s,i->songname,strlen(sName));
		if(strcmp(s,sName)==0){
			return i;
		}
	}
	printf("khong co\n");
	return NULL;
}
 
// tim kiem va in ra tat cac cac bai hat cua ca si
void listAllSongBySinger(LIST l, char *singerName)
{	
	char s[MAX_LEN];
	DNODE*i;
	for(i=l.pHead;i!=NULL;i=i->pNext){
		strncpy(s,i->singer,strlen(singerName));
		if(strcmp(s,singerName)==0){
			printp(i);
			return;
		}
	}
printf("Khong co");
return;
}
 
// dua bai hat dang tro boi con tro P len dau danh sach
// neu danh sach co 1 bai hat thi ko lam gi ca
void adjustToTopPlaylist(LIST *l, DNODE *p)
{	if(l->pHead->pNext==NULL){
			return;
			}
	else{
		p->pPrev->pNext=p->pNext;
		p->pNext->pPrev=p->pPrev;
		//
		p->pNext=l->pHead;
		l->pHead->pPrev=p;
		l->pHead=p;
		l->pHead->pPrev=NULL;
	}
  
}
 
// dua bai hat dang tro boi con tro P ve cuoi danh sach
// neu danh sach co 1 bai hat thi ko lam gi ca
void adjustToEndPlaylist(LIST*l, DNODE *p)
{
			if(l->pTail->pPrev==NULL){
			return;
			}
	else{
		//lay p ra va noi lai
		p->pPrev->pNext=p->pNext;
		p->pNext->pPrev=p->pPrev;
		//noi p vao cuoi
		l->pTail->pNext=p;
		p->pPrev=l->pTail;
		l->pTail=p;
		l->pTail->pNext=NULL;
		
	}
}
 
 
// Xoa bai hat dang tro boi con tro p trong danh sach
// co the la dau, giua/cuoi danh sach
void removeSong(LIST *l, DNODE *p)
{	if(p==l->pHead){
		l->pHead=l->pHead->pNext;
		free(p);
	}
	if(p==l->pTail){
		l->pTail=l->pTail->pPrev;
		free(p);
	}
	else{	
		p->pPrev->pNext=p->pNext;
		p->pNext->pPrev=p->pPrev;
		}
}
 
// tra ve bai hat tiep theo ngay sau bai hat tro boi p
// neu p la cuoi danh sach thi tra ve NULL
DNODE *getNextSong(LIST l, DNODE *p)
{	if(p==NULL){
	p=l.pHead;
	return p;
}
	if(p==l.pTail){
		return l.pHead;
	}
	else{
		return p->pNext;
	}

}
 
// tra ve bai hat tiep theo ngay truoc bai hat tro boi p
// neu p la dau danh sach thi tra ve NULL
DNODE *getPrevSong(LIST l, DNODE *p)
{	if(p==l.pHead){
		return l.pTail;
	}
	else{
	return p->pPrev;
		}

}

int main(){
	char sName[MAX_LEN];
	char key;
	int keyyy;
	DNODE*newNode;
	DNODE *ctr=NULL;
	LIST l;
	makelist(&l);
	l=loadPlaylist(filename);
	savePlayListToFile(filename1,l);
	printPlaylist(l);
	
	while(1){
		printf("MENu\n");
		printf("0. Tim bai hat\n");
		
		printf("1 Chen Xuong duoi\n");
		printf("2 Chen len tren \n");
		printf("3 Di chuyen\n");
		printf("4. thoat\n");
		scanf("%d",&keyyy);
		getc(stdin);
		switch(keyyy){
			case 0:{
				ctr=NULL;
				while(ctr==NULL){
				getc(stdin);
				printf("search:");
				scanf("%[^\n]",sName);
				ctr=searchSongName(l,sName);
						}
	
							printp(ctr);
				break;
			}
			case 1:{
				ctr=NULL;
				while(ctr==NULL){
				getc(stdin);
				printf("search:");
				scanf("%[^\n]",sName);
				ctr=searchSongName(l,sName);
						}
				printf("chen xuong duoi\n");
				adjustToEndPlaylist(&l,ctr);
				printPlaylist(l);
				break;
			}
			case 2:{
				ctr=NULL;
				while(ctr==NULL){
				getc(stdin);
				printf("search:");
				scanf("%[^\n]",sName);
				ctr=searchSongName(l,sName);
						}
				printp(ctr);
				printf("chen len tren\n");
				adjustToTopPlaylist(&l,ctr);
				printPlaylist(l);
				break;
			}
			case 3:{
				while(1){
		char c=getch();
		if(c==-32){
		c=getch();
		switch(c) 
 		{
   			case 77: {
   				ctr=getNextSong(l,ctr);
   				if(ctr==NULL) break;
   				printp(ctr);
				break;
			   }
   			
   			case 75: {
   				ctr=getPrevSong(l,ctr);
   				if(ctr==NULL) break;
   				printp(ctr);
				break;
			   }
			 }
			 }
			 	if(c=='x') break;
	}
				break;
			}
		}
	}
	
	
	
	return 0;
}
