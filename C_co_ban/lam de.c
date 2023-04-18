#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define filename1 "C:\\Users\\ADMIN\\Documents\\C programming\\C co ban\\dict.txt"
#define xx system("cls");
#define nn printf("\n");
#define gg getc(stdin);
typedef struct Node{
	char eng[50];
	char vie[50];
	struct Node* leftChild;
    struct Node* rightChild;
}Node;
Node* makeNode(char*eng, char*vie){
	Node *newNode=(Node*)malloc(sizeof(Node));
	strcpy(newNode->eng,eng);
	strcpy(newNode->vie,vie);
	newNode->leftChild=NULL;
	newNode->rightChild=NULL;
	return newNode;
}
Node* insert(Node *r,char*eng, char*vie ){
	if(r==NULL) return makeNode(eng,vie);
	int c=strcmp(r->eng,eng);
	if(c==0){
		printf("word %s exists, do not insert\n",eng); return r;
    	}else
	if(c<0){
		r->rightChild=insert(r->rightChild,eng,vie); return r;
	}else{
		r->leftChild=insert(r->leftChild,eng,vie); return r;
	}
}
Node* loadFile(char *filename){
	Node *root=NULL;
	char eng[25];
	char vie[25];
	FILE *f=fopen(filename,"r");
	if(f == NULL) printf("Load data -> file not found\n");
    root = NULL;
	while(!feof(f)){
		fscanf(f,"%s",eng);
		fscanf(f,"%s",vie);
		printf("%s %s",eng,vie);nn
		root=insert(root,eng,vie);
	}
	fclose(f);
	return root;
}
Node* find(Node* r, char* eng){
    if(r==NULL) return NULL;
    int c=strcmp(r->eng,eng);
    if(c==0) return r;
   if(c<0) return find(r->rightChild,eng);
   else
    return find(r->leftChild,eng);
}
void printMenu(){
	printf("MENU\nQuan ly thong tin sach co trong thu vien\n");
	printf("1.Nap tu dien");nn
	printf("2.Thong tin tu dien");nn
	printf("3.Them/sua tu");nn
	printf("4.Dich Anh - Viet\n");
	printf("5. Thoat\n");
	return ;
} 
void freeTree(Node* r){
    if(r == NULL) return;
    freeTree(r->leftChild);
    freeTree(r->rightChild);
    free(r);
}
void inOrder(Node* r){
    if(r == NULL) return;
    inOrder(r->leftChild);
    printf("%s:%s",r->eng,r->vie);nn
    inOrder(r->rightChild);
}
int main(){
	Node *root=NULL;
	int key;
	while(1){
		xx
		printMenu();
		printf("KEY:");
		key=getch();
		switch(key){
			case 49:{
				xx
				printf("1.Nap tu dien");nn
				root=loadFile(filename1);
				gg
				xx
				break;
			}
			case 50:{
				xx
				printf("2.Thong tin tu dien");nn
				inOrder(root);
				gg
				xx
				//gg
				xx
				break;
			}
			case 51:{
				xx
				printf("3.Them/sua tu");nn
				freeTree(root);
				gg
				xx
				break;
			}
			case 52:{
				xx
				printf("4.Dich Anh - Viet\n");
				gg
				xx
				break;
			}
			case 53:{
				xx
				printf("5. Thoat\n");
				gg
				xx
				printf("cam on da su dung <3");
				return 0;
				break;
			}
	}
	
		
}
	return 0;
}
