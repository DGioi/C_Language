#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define nn printf("\n");
#define xx system("cls");
#define gg getc(stdin);
#define file "C:\\Users\\ADMIN\\Documents\\C programming\\Kiem tra\\log_input.txt"
void Localtime(){
				time_t rawtime;
 				struct tm * timeinfo;
  				time ( &rawtime );
  				timeinfo = localtime ( &rawtime );
  				printf ( "Current local time and date: %s\n", asctime (timeinfo));
}
// danh sach lien ket {
typedef struct nodelk{
	int YYYY;
	int MM;
	int DD;
	int hh;
	int mm;
	int ss;
	char bienso[15];
	int inout;
	struct nodelk* pNext;
}Nodelk;
Nodelk* makeNodelk(int YYYY,int MM,int DD,int hh,int mm,int ss, char * bienso,int inout){
	Nodelk *newNode=(Nodelk*)malloc(sizeof(Nodelk));
	newNode->YYYY=YYYY;
	newNode->MM=MM;
	newNode->DD=DD;
	newNode->hh=hh;
	newNode->mm=mm;
	newNode->ss=ss;
	strcpy(newNode->bienso,bienso);
	newNode->inout=inout;
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
typedef struct node{
	int value;
	struct node* leftChild;
    struct node* rightChild;
}Node;
Node* makeNode(int value){
	Node *newNode=(Node*)malloc(sizeof(Node));
	newNode->value=value;
	newNode->leftChild=NULL;
	newNode->rightChild=NULL;
	return newNode;
}
Node* deleteNode(Node* node, int value) {
    if (node == NULL) {
        return node;
    }

    if (value < node->value) {
        node->leftChild = deleteNode(node->leftChild, value);
    } else if (value > node->value) {
        node->rightChild = deleteNode(node->rightChild, value);
    } else {
        if (node->leftChild == NULL) {
             Node* temp = node->rightChild;
            free(node);
            return temp;
        } else if (node->rightChild == NULL) {
            Node* temp = node->leftChild;
            free(node);
            return temp;
        }

         Node* temp = node->rightChild;
        while (temp->leftChild != NULL) {
            temp = temp->leftChild;
        }

        node->value = temp->value;
        node->rightChild = deleteNode(node->rightChild, temp->value);
    }

    return node;
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
///cay }
 
void PrintMenu(){
	Localtime();
	printf("Chuong trinh quan li bai xe\n");
        printf("Vui long chon mot trong nhung chuc nang sau\n");
        printf("[0] Thoat\n");
        printf("[1] Doc du lieu\n");
        printf("[2] Tra cuu so luong xe gui/lay theo ngay\n");
        printf("[3] Thong tin xe gui hien tai\n");
        printf("[4] Gui them xe moi\n");
        printf("[5] Tra xe\n");
        printf("[6] Cap nhat log du lieu\n");
        printf("[7] Luu danh sach xe dang co trong bai ra file\n");
        printf("Lua chon: ");
}

//load file {
List loadFile(char *filename){
	FILE * f=fopen(filename,"r");
	List l;
	makeList(&l);
	int YYYY;
	int MM;
	int DD;
	int hh;
	int mm;
	int ss;
	char bienso[15];
	int inout;
	while(!feof(f)){
		fscanf(f,"%d-%d-%d %d:%d:%d %s %d",&YYYY,&MM,&DD,&hh,&mm,&ss,bienso,&inout);
		fgetc(f);
		insertLast(&l,makeNodelk(YYYY,MM,DD,hh,mm,ss,bienso,inout));
	}
	return l;
}
//load file}
void printDS(List l){
	Nodelk *p;
	for(p=l.pHead;p!=NULL;p=p->pNext) 
	printf("%d-%d-%d %d:%d:%d %s %d\n",p->YYYY,p->MM,p->DD,p->hh,p->mm,p->ss,p->bienso,p->inout);
}
// sap xep {
void swap(int *a,int *b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[],int low,int high) {
    int pivot = arr[high];
    int i = low - 1;
    int j;
    for (j=low;j<=high-1;j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex=partition(arr,low,high);
        quicksort(arr,low,pivotIndex-1);
        quicksort(arr,pivotIndex+1,high);
    }
}
// sap xep }
void case2(List l){
	int YYYY,MM,DD;
	int in=0,out=0;
	scanf("%d-%d-%d",&YYYY,&MM,&DD);
	Nodelk *p=l.pHead;
	while(p!=NULL){
		if(YYYY==p->YYYY&&MM==p->MM&&p->DD==DD){
			if(p->inout==0) out++;
			if(p->inout==1) in++;
		}
		p=p->pNext;
	}
	printf("Vao: %d\nRa: %d\n",in,out);
	gg
	return;
}
int main(){
	int key;
	List l;
	while(1){
		xx
		PrintMenu();
		key=getch();
		switch(key){
			case 49:{
				xx
				printf("1. \n");
				l=loadFile(file);
				printDS(l);
				gg break;
			}
			case 50:{
				xx
				printf("2. \n");
				case2(l);
				gg break;
			}
			case 51:{
				xx
				printf("3. \n");
				gg break;
			}
			case 52:{
				xx
				printf("4. \n");
				gg break;
			}
			case 53:{
				xx
				printf("5. \n");
				gg break;
			}
			case 54:{
				xx
				printf("6. \n");
				gg break;
			}
			case 55:{
				xx
				printf("7. \n");
				gg break;
			}
			case 48:{
				xx
				printf("0.OUT\n");
				return 0;
				break;
			}
		}
	}
	return 0;
}
