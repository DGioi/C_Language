#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define filename1 "C:\\Users\\ADMIN\\Documents\\C programming\\C co ban\\ck.txt"
#define nn printf("\n");
#define xx system("cls");
#define gg getc(stdin);
#define DD 3
int N;
typedef struct Node{
	char ma[100];
	float mo[10];
	float dong[10];
	struct Node* leftChild;
    struct Node* rightChild;
}Node;
Node* makeNode(char *ma,float mo,float dong,int i){
	Node *newNode=(Node*)malloc(sizeof(Node));
	strcpy(newNode->ma,ma);
	newNode->mo[i]=mo;
	newNode->dong[i]=dong;
	newNode->leftChild=NULL;
	newNode->rightChild=NULL;
	return newNode;
}
Node* insert(Node *r,char *ma,float mo,float dong,int i ){
	if(r==NULL) return makeNode(ma,mo,dong,i);
	int c=strcmp(r->ma,ma);
	if(c==0){
		r->mo[i]=mo;
		r->dong[i]=dong;
		return r;
    	}else
	if(c<0){
		r->rightChild=insert(r->rightChild,ma,mo,dong,i); return r;
	}else{
		r->leftChild=insert(r->leftChild,ma,mo,dong,i); return r;
	}
}
Node* loadFile(char *filename){
	Node *root=NULL;
	FILE *f=fopen(filename,"r");
	if(f == NULL) printf("Load data -> file not found\n");
    root = NULL;
    fscanf(f,"%d",&N);
    fgetc(f);
    int i;
    char ma[10];
    float mo;
    float dong;
    	for(i=0;i<N*DD;i++){
    		fscanf(f,"%s",ma);
    		fscanf(f,"%f",&mo);
    		fscanf(f,"%f",&dong);
			fgetc(f);
			printf("%s %0.2f %0.2f\n",ma,mo,dong);
			root=insert(root,ma,mo,dong,i/N);
		}	
	fclose(f);
	return root;
}

void printMenu(){
	printf("MENU\nQuan ly thong tin sach co trong thu vien\n");
	printf("0.Doc File");nn
	printf("1.Tim theo ma chung khoan");nn
	printf("2.Tim kiem theo ma chung khoan co xu huong tang");nn
	printf("3.Tim ma co so ngay tang lon nhat");nn
	printf("4.Thoat\n");
	return ;
}
Node* find(Node* r, char* ma){
    if(r==NULL) return NULL;
    int c=strcmp(r->ma,ma);
    if(c==0) return r;
   if(c<0) return find(r->rightChild,ma);
   else
    return find(r->leftChild,ma);
}
Node* findMin(Node* r){
    if(r == NULL) return NULL;
    Node* lmin = findMin(r->leftChild);
    if(lmin != NULL) return lmin;
    return r;
} 

void inOrderF(Node* r,FILE *f){
    if(r == NULL) return;
    inOrderF(r->leftChild,f);
    
    inOrderF(r->rightChild,f);
}
void freeTree(Node* r){
    if(r == NULL) return;
    freeTree(r->leftChild);
    freeTree(r->rightChild);
    free(r);
}
void printNode(Node*p){
	int i;
	float tb=0;
	for(i=0;i<DD;i++){
			printf("DAY %d : %s %0.2f %0.2f\n",i+1,p->ma,p->mo[i],p->dong[i]);
			tb+=(-p->mo[i]+p->dong[i])/DD;
	}
	printf("TB dong-mo : %0.3f",tb);nn

}
void printNode1(Node*p){
	if(p==NULL) {printf("khong tim thay");
	return;}
	int i;
	float max=p->dong[0];
	float min=p->dong[0];
	for(i=0;i<DD;i++){
			printf("DAY %d : %s %0.2f %0.2f\n",i+1,p->ma,p->mo[i],p->dong[i]);
			if(min>p->dong[i]) min=p->dong[i];
			if(max<p->dong[i]) max=p->dong[i];
	}
	printf("Gia dong cua thap nhat: %0.3f",min);nn
	printf("Gia dong cua cao nhat: %0.3f",max);nn

}
void printNode2(Node*p){
	int i;
	if(p->dong[0]-p->mo[0]>0&& p->dong[1]-p->mo[1]>0)
	printf("-%s",p->ma);nn

}
void inOrder(Node* r){
    if(r == NULL) return;
    inOrder(r->leftChild);
    nn
	printNode(r);nn
    inOrder(r->rightChild);
}
void inOrder2(Node* r){
    if(r == NULL) return;
    inOrder2(r->leftChild);
	printNode2(r);nn
    inOrder2(r->rightChild);
}
int sumday(Node *p){
	int i;
	int sum=0;
	for(i=0;i<DD;i++){
		if(p->dong[i]-p->mo[i]>0) sum++;
	}
	return sum;
}

void inOrder3(Node* r,int *sum){
    if(r == NULL) return;
    inOrder3(r->leftChild,sum);
	if(*sum<sumday(r)) 
	*sum=sumday(r);
    inOrder3(r->rightChild,sum);
}
void inOrder4(Node* r,int sum){
    if(r == NULL) return;
    inOrder4(r->leftChild,sum);
	if(sumday(r)==sum )printNode(r);nn
    inOrder4(r->rightChild,sum);
}
/*
void arrcpy(int a[],int b[]){
	
}
Node* removeNode(Node* r, char* ma){
    if(r == NULL) return NULL;
    int c = strcmp(r->ma,ma);
    if(c > 0) r->leftChild = removeNode(r->leftChild,ma);
    else if(c < 0) r->rightChild = removeNode(r->rightChild,ma);
    else{
        if(r->leftChild != NULL && r->rightChild != NULL){
            Node* tmp = findMin(r->rightChild);
            strcpy(r->ma,tmp->ma);
            arrcpy(r->mo,tmp->mo,N);
            arrcpy(r->dong,tmp->dong,N);
            r->rightChild = removeNode(r->rightChild,tmp->ma);
        }else{
            Node* tmp = r;
            if(r->leftChild == NULL) r = r->rightChild; else r = r->leftChild;
            free(tmp);
        }
    }
    return r;
} */
int main(){
	int n;
	Node *root=NULL;
	int key;
	
	while(1){
		printMenu();
		key=getch();
		switch(key){
			case 48:{
				xx
				printf("Doc File");nn
				root=loadFile(filename1);
				inOrder(root);
				gg
				xx
				break;
			}
			
			case 49:{
				xx
				printf("Tim theo ma chung khoan");nn
				char ma[10];
				gets(ma);
				printNode1(find(root,ma));
				gg
				xx
				break;
			}
			case 50:{
				xx
				printf("Tim kiem theo ma chung khoan co xu huong tang");nn
				inOrder2(root);
				gg
				xx
				//gg
				xx
				break;
			}
			case 51:{
				xx
				printf("Tim ma co so ngay tang lon nhat");nn
				int sumday=0;
				inOrder3(root,&sumday);
				inOrder4(root,sumday);
				gg
				xx
				break;
			}
			case 52:{
				xx
				printf("Cam on da su dung\n");
				gg
				xx
				return 0;
				break;
			}
		}
	}
	return 0;
}

