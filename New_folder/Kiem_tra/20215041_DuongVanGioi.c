#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define nn printf("\n");
#define xx system("cls");
#define gg getc(stdin);
#define file "C:\\Users\\ADMIN\\Documents\\C programming\\Kiem tra\\input_unlocked.txt"
#define file2 "C:\\Users\\ADMIN\\Documents\\C programming\\Kiem tra\\booking_ouput.txt"
int N;
int key5=0;
// danh sach lien ket {
typedef struct nodelk{
	char mayc[8];
	int songuoi;
	int sophong;
	char maks[4];
	char date[11];
	int kids;
	
	struct nodelk* pNext;
}Nodelk;
Nodelk* makeNodelk(char *mayc,int songuoi,int sophong,char *maks,char *date,int kids){
	Nodelk *newNode=(Nodelk*)malloc(sizeof(Nodelk));
	newNode->songuoi=songuoi;
	newNode->sophong=sophong;
	newNode->kids=kids;
	strcpy(newNode->date,date);
	strcpy(newNode->mayc,mayc);
	strcpy(newNode->maks,maks);
	newNode->pNext=NULL;
	return newNode;
	
}
typedef struct list{
	Nodelk *pHead;
	Nodelk *pTail;
} List;
void makeList(List *l){
	l->pHead=NULL;
	l->pTail=NULL;
}

void insertFirst(List *l,Nodelk *newNode){
	if(l->pHead==NULL){
		l->pHead=newNode;
		l->pTail=newNode;
	}
	else
	{
		newNode->pNext=l->pHead;
		l->pHead=newNode;
		
	}
}
void insertAfter(Nodelk*newNode,Nodelk*p){
			newNode->pNext=p->pNext;
			p->pNext=newNode;
		
}
void insertLast(List *l,Nodelk*newNode){
	if(l->pHead==NULL){
		l->pHead=newNode;
		l->pTail=newNode;
	}
	else{
	l->pTail->pNext=newNode;
	l->pTail=newNode;
	}
}
// danh sach lien ket }
//cay {
typedef struct Node{
	char mayc[8];
	int songuoi;
	int sophong;
	char maks[4];
	char date[11];
	int kids;
	struct Node* leftChild;
    struct Node* rightChild;
}Node;
Node* makeNode(char *mayc,int songuoi,int sophong,char *maks,char *date,int kids){
	Node *newNode=(Node*)malloc(sizeof(Node));
	newNode->songuoi=songuoi;
	newNode->sophong=sophong;
	newNode->kids=kids;
	strcpy(newNode->date,date);
	strcpy(newNode->mayc,mayc);
	strcpy(newNode->maks,maks);
	newNode->leftChild=NULL;
	newNode->rightChild=NULL;
	return newNode;
}
Node* insert(Node *r,char *mayc,int songuoi,int sophong,char *maks,char *date,int kids ){
	if(r==NULL) return makeNode(mayc,songuoi,sophong,maks,date,kids);
	int c=strcmp(r->mayc,mayc);
	if(c==0){
		printf("Yeu cau %s exists, do not insert\n",mayc); return r;
    	}else
	if(c<0){
		r->rightChild=insert(r->rightChild,mayc,songuoi,sophong,maks,date,kids); return r;
	}else{
		r->leftChild=insert(r->leftChild,mayc,songuoi,sophong,maks,date,kids); return r;
	}
}
Node* find(Node* r, char* mayc){
    if(r==NULL) return NULL;
    int c=strcmp(r->mayc,mayc);
    if(c==0) return r;
   if(c<0) return find(r->rightChild,mayc);
   else
    return find(r->leftChild,mayc);
}
///cay }
 
void PrintMenu(){
	printf("Ten chuong trinh\n");
	printf("0. Thoat\n");
	printf("1.Doc du lieu tu file log \n");
	printf("2.Kiem tra so yeu cau khong hop le\n");
	printf("3.Tra cuu theo ma yeu cau\n");
	printf("4.Thay doi yeu cau \n");
	printf("5.Huy yeu cau \n");
	printf("6.Luu danh sach yeu cau ra file \n");
	printf("7.(OP1)Thong ke khach san duoc yeu thich nhat \n");
	printf("8.(OP2) Ngay khong hop le\n");
	printf("9.(OP3) Ngay khong hop le\n");
	printf("Lua chon cua ban\n");


}

//load File{
//load file {
List loadFile(char *filename){
	FILE * f=fopen(filename,"r");
	List l;
	makeList(&l);
	char mayc[8];
	int songuoi;
	int sophong;
	char maks[4];
	char date[11];
	int kids;
	fscanf(f,"%d",&N);
	while(!feof(f)){
		fscanf(f,"%s %d %d %s %s %d",mayc,&songuoi,&sophong,maks,date,&kids);
		fgetc(f);
		insertLast(&l,makeNodelk(mayc,songuoi,sophong,maks,date,kids));
	}
	fclose(f);
	return l;
}

Node* loadFileR(char *filename){
	Node *root=NULL;
	FILE * f=fopen(filename,"r");
	char mayc[8];
	int songuoi;
	int sophong;
	char maks[4];
	char date[11];
	int kids;
	fscanf(f,"%d",&N);
	while(!feof(f)){
		fscanf(f,"%s %d %d %s %s %d",mayc,&songuoi,&sophong,maks,date,&kids);
		fgetc(f);
		root=insert(root,mayc,songuoi,sophong,maks,date,kids);
	}
	fclose(f);
	return root;
}
//load file}
//load file }

void printDs(List l){
	Nodelk *p;
	for(p=l.pHead;p!=NULL;p=p->pNext)
	printf("%s %d %d %s %s %d\n",p->mayc,p->songuoi,p->sophong,p->maks,p->date,p->kids);
}
void printNode(Node *p){
	printf("%s %d %d %s %s %d\n",p->mayc,p->songuoi,p->sophong,p->maks,p->date,p->kids);
}
void freeTree(Node* r){
    if(r == NULL) return;
    freeTree(r->leftChild);
    freeTree(r->rightChild);
    free(r);
}
void freeDs(Nodelk* p){
    if(p == NULL) return;
    freeDs(p->pNext);
    free(p);
}
void checkyc(List l){
	Nodelk* p;
	int sum=0;
	printf("Yeu cau khong hop le:\n");
	for(p=l.pHead;p!=NULL;p=p->pNext){
		if(p->kids>=p->songuoi) {
			printf("%s\n",p->mayc);
			sum++;
		}
	}
	printf("Tong : %d",sum);
}
Node* findMin(Node* r){
    if(r == NULL) return NULL;
    Node* lmin = findMin(r->leftChild);
    if(lmin != NULL) return lmin;
    return r;
} 
Node* removeNode(Node* r, char* mayc){
    if(r == NULL) return NULL;
    int c = strcmp(r->mayc,mayc);
    if(c > 0) r->leftChild = removeNode(r->leftChild,mayc);
    else if(c < 0) r->rightChild = removeNode(r->rightChild,mayc);
    else{
        if(r->leftChild != NULL && r->rightChild != NULL){
            Node* tmp = findMin(r->rightChild);
            strcpy(r->mayc,tmp->mayc);
			strcpy(r->maks,tmp->maks);
			strcpy(r->date,tmp->date);
			r->kids=tmp->kids;
			r->songuoi=tmp->songuoi;
			r->sophong=tmp->sophong;
            r->rightChild = removeNode(r->rightChild,tmp->mayc);
        }else{
            Node* tmp = r;
            if(r->leftChild == NULL) r = r->rightChild; else r = r->leftChild;
            printf("Delete");
            N--;
            key5=1;
            free(tmp);
        }
    }
    return r;
}
void inOrderF(Node* r,FILE *f){
    if(r == NULL) return;
    inOrderF(r->leftChild,f);
    fprintf(f,"%s %d %d %s %s %d\n",r->mayc,r->songuoi,r->sophong,r->maks,r->date,r->kids);
    inOrderF(r->rightChild,f);
}
void thaydoiyc(Node *r){
	int d;
	char mayc[8];
	int a,b,c;
	Node *p;
	printf("Nhap ma yeu cau:");
	scanf("%s",mayc);
	p=find(r,mayc);
	if(p==NULL) {
		printf("Ma yc sai");
		gg
		return;
	}
	gg
	printf("1.Thay doi so nguoi\n");
	printf("2.Thay doi so tre em\n ");
	printf("3.Thay doi ngay Thang nam\n");
	scanf("%d",&d);
	if(d==1){
		int songuoi;
		printf("so nguoi: ");
		scanf("%d",&songuoi);
		if(songuoi<=p->kids){
			printf("Invalid");
			gg
			return;
		}
		p->songuoi=songuoi;
		gg
		printf("update");
	}
	if(d==2){
		int kids;
		printf("so tre em: ");
		scanf("%d",kids);
		if(p->songuoi<=kids){
			printf("Invalid");
			gg
			return;
		}
		p->kids=kids;
		printf("update");
		gg
	}
	if(d==3){
		char date[8];
		printf("Ngay thang nam");
		scanf("%s",date);
		strcpy(p->date,date);
		printf("update");
		gg
	}
}
int main(){
	int key;
	List l;
	makeList(&l);
	Node *root=NULL;
	root=loadFileR(file);
	while(1){
		xx
		PrintMenu();
		key=getch();
		switch(key){
			case 48:{
				freeTree(root);
				freeDs(l.pHead);
				return 0;
				break;
			}
			case 49:{
				xx
				printf("1.Doc du lieu tu file log \n");
				l=loadFile(file);
				printDs(l);
				printf("so yeu cau : %d",N);
				gg xx break;
			}
			case 50:{
				xx
				printf("2.Kiem tra so yeu cau khong hop le\n");
				checkyc(l);
				gg xx  break;
			}
			case 51:{
				xx
				printf("3.Tra cuu theo ma yeu cau\n");
				Node *p;
				char mayc[100];
				gets(mayc);
				p=find(root,mayc);
				if(p==NULL) printf("Not found\n");
				else printNode(p);
				gg xx break;
			}
			case 52:{
				xx
				printf("4.Thay doi yeu cau \n");
				thaydoiyc(root);
				gg xx break;
			}
			case 53:{
				xx
				printf("5.Huy yeu cau \n");
				char mayc[100];
				gets(mayc);
				removeNode(root,mayc);
				if(key5==0) printf("Not found");
				key5=0;
				gg xx break;
			}
			case 54:{
				xx
				printf("6.Luu danh sach yeu cau ra file \n");
				FILE *f=fopen(file2,"w");
				fprintf(f,"%d\n",N);
				inOrderF(root,f);
				fclose(f);
				gg xx break;
			}
			case 55:{
				xx
				printf("7.(OP1)Thong ke khach san duoc yeu thich nhat \n");
				gg xx break;
			}
			case 56:{
				xx
				printf("8.(OP2) Ngay khong hop le\n");
				gg
				break;
			}
			case 57:{
				xx
				printf("9.(OP3) Ngay khong hop le\n");
				gg
				break;
			}
			
		}
	}
	return 0;
}
