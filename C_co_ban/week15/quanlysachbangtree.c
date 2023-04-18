#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define filename1 "C:\\Users\\ADMIN\\Documents\\C programming\\C co ban\\week15\\kho1.txt"
#define filename2 "C:\\Users\\ADMIN\\Documents\\C programming\\C co ban\\week15\\kho2.txt"
#define filename3 "C:\\Users\\ADMIN\\Documents\\C programming\\C co ban\\week15\\thuvien.txt"
#define nn printf("\n");
#define xx system("cls");
#define gg getc(stdin);
typedef struct Node{
	char title[100];
	char kind[50];
	char author[50];
	int quantity;
	struct Node* leftChild;
    struct Node* rightChild;
}Node;
Node* makeNode(char *title,char*kind, char*author,int quantity){
	Node *newNode=(Node*)malloc(sizeof(Node));
	strcpy(newNode->title,title);
	strcpy(newNode->kind,kind);
	strcpy(newNode->author,author);
	newNode->quantity=quantity;
	newNode->leftChild=NULL;
	newNode->rightChild=NULL;
	return newNode;
}
Node* insert(Node *r,char *title,char*kind, char*author,int quantity ){
	if(r==NULL) return makeNode(title,kind,author,quantity);
	int c=strcmp(r->title,title);
	if(c==0){
		printf("Book %s exists, do not insert\n",title); return r;
    	}else
	if(c<0){
		r->rightChild=insert(r->rightChild,title,kind,author,quantity); return r;
	}else{
		r->leftChild=insert(r->leftChild,title,kind,author,quantity); return r;
	}
}
void insert2(Node**r,char *title,char*kind, char*author,int quantity){
	if(*r==NULL) *r=makeNode(title,kind,author,quantity);
	int c=strcmp((*r)->title,title);
	if(c==0){
	printf("Book %s exists, do not insert\n",title); 
	}else if(c<0){
		insert2(&((*r)->rightChild),title,kind,author,quantity);
	} else insert2(&((*r)->leftChild),title,kind,author,quantity);
}
void insert3(Node *r,char *title,char*kind, char*author,int quantity){
	int c=strcmp(r->title,title);
	if(c==0){
		printf("Book %s exists, do not insert\n",title);
	}else if(c<0){
		insert3(r->rightChild,title,kind,author,quantity);
	}else{
		insert3(r->leftChild,title,kind,author,quantity);
	}
}
Node* loadFile(char *filename){
	Node *root=NULL;
	FILE *f=fopen(filename,"r");
	if(f == NULL) printf("Load data -> file not found\n");
    root = NULL;
	while(!feof(f)){
		char c=fgetc(f);
		if(c=='*') break;
		else ungetc(c,f);
		char title[100];
		char kind[50];
		char author[50];
		int quantity;
		fgets(title,100,f);
		if(!isalpha(title[strlen(title)-1])) title[strlen(title)-1]='\0';
		fgets(kind,50,f);
		if(!isalpha(kind[strlen(kind)-1])) kind[strlen(kind)-1]='\0';
		fgets(author,50,f);
		if(!isalpha(author[strlen(author)-1])) author[strlen(author)-1]='\0';
		fscanf(f,"%d",&quantity);
		fgetc(f);
		root=insert(root,title,kind,author,quantity);
	}
	fclose(f);
	return root;
}

void printMenu(){
	printf("MENU\nQuan ly thong tin sach co trong thu vien\n");
	printf("0.IN RA DANH SACH");nn
	printf("1.Tra cuu thong tin qua ten sach");nn
	printf("2.Muon va tra sach thong qua ten sach");nn
	printf("3.Doc ghi thong tin sach tu file");nn
	printf("4.Liet ke danh sach dang het\n");
	printf("5.Liet ke danh sach trong linh vuc\n");
	printf("6.Bo sung sach moi\n");
	printf("7.Xoa thong tin sach cu\n");
	printf("8. Thoat\n");
	return ;
}
Node* find(Node* r, char* title){
    if(r==NULL) return NULL;
    int c=strcmp(r->title,title);
    if(c==0) return r;
   if(c<0) return find(r->rightChild,title);
   else
    return find(r->leftChild,title);
}
Node* findMin(Node* r){
    if(r == NULL) return NULL;
    Node* lmin = findMin(r->leftChild);
    if(lmin != NULL) return lmin;
    return r;
} 
void borrow(Node *r){
	printf("Title: ");
	char title[100];
	gets(title);
	Node *p=find(r,title);
	if(p==NULL){
		printf("NOT FOUND\n");
	}else if(p->quantity==0) printf("the book is out");
	else p->quantity--;
}
void giveback(Node* r){
	printf("Title:");
	char title[100];
	gets(title);
	Node *p=find(r,title);
	if(p==NULL){
		printf("NOT FOUND\n");
	}
	else p->quantity++;	
}
void printNode(Node*p){
	if(p==NULL){
		printf("NOT FOUND!!!\n");
		return;
	}
	printf("___________________________________________________________________________________\n");
	printf("|%-20s|%-10s|%-40s|%-8s|\n","Title","Kind","Author","Quantity");
	printf("___________________________________________________________________________________\n");
	printf("|%-20s|%-10s|%-40s|%-8d|\n",p->title,p->kind,p->author,p->quantity);
	printf("___________________________________________________________________________________\n");
	}
void printNode2(Node*p){
	printf("|%-20s|%-10s|%-40s|%-8d|\n",p->title,p->kind,p->author,p->quantity);
	printf("___________________________________________________________________________________\n");
}
//duyet cay theo thu tu giua
void inOrder(int i,Node* r){
	if(i==0){
		printf("___________________________________________________________________________________\n");
		printf("|%-20s|%-10s|%-40s|%-8s|\n","Title","Kind","Author","Quantity");
		printf("___________________________________________________________________________________\n");
		i=1;
	}
    if(r == NULL) return;
    inOrder(i,r->leftChild);
    printNode2(r);
    inOrder(i,r->rightChild);
}
void inOrderF(Node* r,FILE *f){
    if(r == NULL) return;
    inOrderF(r->leftChild,f);
    fprintf(f,"%s\n",r->title);
    fprintf(f,"%s\n",r->kind);
    fprintf(f,"%s\n",r->author);
    fprintf(f,"%d\n",r->quantity);
    inOrderF(r->rightChild,f);
}
void inOrderKind(int i,char *kind,Node* r){
	
	if(i==0){
		printf("___________________________________________________________________________________\n");
		printf("|%-20s|%-10s|%-40s|%-8s|\n","Title","Kind","Author","Quantity");
		printf("___________________________________________________________________________________\n");
		i=1;
	}
    if(r == NULL) return;
    inOrderKind(i,kind,r->leftChild);
    if (strcmp(r->kind,kind)==0) printNode2(r);
    inOrderKind(i,kind,r->rightChild);
}
int quantity(int q,int i,Node*r){
	if(r == NULL) {
		//printf("khong co");
		return 0;
	}
    quantity(q,i,r->leftChild);
    if(r->quantity==q){
    	i++;
    	if(i==1){
    			printf("___________________________________________________________________________________\n");
				printf("|%-20s|%-10s|%-40s|%-8s|\n","Title","Kind","Author","Quantity");
				printf("___________________________________________________________________________________\n");
		}
    	 printNode2(r);
	}
    quantity(q,i,r->rightChild);
}
void freeTree(Node* r){
    if(r == NULL) return;
    freeTree(r->leftChild);
    freeTree(r->rightChild);
    free(r);
}
Node* removeBook(Node* r, char* title){
    if(r == NULL) return NULL;
    int c = strcmp(r->title,title);
    if(c > 0) r->leftChild = removeBook(r->leftChild,title);
    else if(c < 0) r->rightChild = removeBook(r->rightChild,title);
    else{
        if(r->leftChild != NULL && r->rightChild != NULL){
            Node* tmp = findMin(r->rightChild);
            strcpy(r->title,tmp->title);
			strcpy(r->kind,tmp->kind);
			strcpy(r->author,tmp->author);
			r->quantity=tmp->quantity;
            r->rightChild = removeBook(r->rightChild,tmp->title);
        }else{
            Node* tmp = r;
            if(r->leftChild == NULL) r = r->rightChild; else r = r->leftChild;
            free(tmp);
        }
    }
    return r;
}
void printFile(char *filename,Node * r){
	FILE*f=fopen(filename,"w");
	inOrderF(r,f);
	fprintf(f,"***");
	fclose(f);
}
int main(){
	Node *root=NULL;
	int key;
	root=loadFile(filename1);
	while(1){
		printMenu();
		key=getch();
		switch(key){
			case 48:{
				xx
				printf("IN RA FILE THONG TIN SACH");nn
				if(root==NULL) printf("Danh sach dang trong!!!\nBan co muon tiep tuc khong???\nBam 'n' de dung lai:");
				if(getch()==110) {
				
					xx
					break;
				}
				inOrder(0,root);
				printFile(filename1,root);
				gg
				xx
				break;
			}
			
			case 49:{
				xx
				printf("Tra cuu thong tin qua ten sach");nn
				char title[100];
				gets(title);
				printNode(find(root,title));
				gg
				xx
				break;
			}
			case 50:{
				xx
				while(1){
				printf("Muon va tra sach thong qua ten sach");nn
				printf("1. Muon sach");nn
				printf("2. Tra sach");nn
				printf("0. Quay lai");nn
				int a;
				a=getch();
				if(a==49) borrow(root);
				if(a==50) giveback(root);
				if(a==48) break; 
				gg
				xx
				}
				//gg
				xx
				break;
			}
			case 51:{
				xx
				freeTree(root);
				printf("Doc ghi thong tin sach tu file");nn
				root=loadFile(filename1);
				inOrder(0,root);
				gg
				xx
				break;
			}
			case 52:{
				xx
				printf("Liet ke danh sach dang het\n");
				quantity(0,0,root);
				gg
				xx
				break;
			}
			case 53:{
				xx
				char kind[50];
				printf("Liet ke danh sach trong linh vuc\n");
				printf("KIND:");
				gets(kind);
				inOrderKind(0,kind,root);
				gg
				xx
				break;
			}
			case 54:{
				xx
				printf("Bo sung sach moi\n");
				char title[100];
				char kind[50];
				char author[50];
				int quantity;
				printf("Ten sach:");
				gets(title);
				printf("The loai: ");
				gets(kind);
				printf("Tac Gia:");
				gets(author);
				printf("So luong:");
				scanf("%d",&quantity);
				insert2(&root,title,kind,author,quantity);
				FILE*in=fopen(filename1,"r+");
				fseek(in,-3,SEEK_END);
				fprintf(in,"%s\n",title);
				fprintf(in,"%s\n",kind);
				fprintf(in,"%s\n",author);
				fprintf(in,"%d\n***",quantity);
				fclose(in);
				gg
				xx
				break;
			}
			case 55:{
				xx
				char title[50];
				printf("Xoa thong tin sach cu\n");
				printf("Ten sach:");
				gets(title);
				root=removeBook(root,title);
				gg
				xx
				break;
			}
			case 56:{
				xx
				printf("Cam on da su dung\n");
				freeTree(root);
				gg
				xx
				return 0;
				break;
			}
		}
	}
	return 0;
}

