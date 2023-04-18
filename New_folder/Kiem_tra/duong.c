#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 1000
typedef struct Node{
    char bsx[13];
    char date[11], time[9];
    int inout;
    struct Node* leftChild;
    struct Node* rightChild;
}Node;
Node* root[M], *curr, *changelog;

int h(char* s){// hash function
    int rs = 0; int n = strlen(s);
    int i; 
    for(i = 0; i < n; i++) rs = (rs*255 + s[i])%M;
    return rs;
}

Node* makeNode(char* bsx, char* date, char * time, int inout){
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->bsx,bsx);
    strcpy(p->date,date);
    strcpy(p->time,time);
    p->inout=inout;
    p->leftChild = NULL;
    p->rightChild = NULL;
    return p;
}

Node* insert(Node* r, char* bsx, char* date, char * time, int inout){
    if(r == NULL) return makeNode(bsx, date, time, inout);
    int c = strcmp(r->bsx,bsx);
    if(c == 0){
        c = strcmp(r->time,time);
        if(c < 0){
            r->rightChild = insert(r->rightChild,bsx, date, time, inout); return r;
        }else{
            r->leftChild = insert(r->leftChild,bsx, date, time, inout); return r;
        }
    }else if(c < 0){
        r->rightChild = insert(r->rightChild,bsx, date, time, inout); return r;
    }else{
        r->leftChild = insert(r->leftChild,bsx, date, time, inout); return r;
    }
}

int count(Node* p){
    if(p == NULL) return 0;
    return 1 + count(p->leftChild) + count(p->rightChild);
}

Node* find(Node* r, char* bsx){
    if(r == NULL) return NULL;
    int c = strcmp(r->bsx,bsx);
    if(c == 0) return r;
    if(c < 0) return find(r->rightChild,bsx);
    return find(r->leftChild,bsx);
}

Node* findMin(Node* r){
    if(r == NULL) return NULL;
    Node* lmin = findMin(r->leftChild);
    if(lmin != NULL) return lmin;
    return r;
}

Node* removev(Node* r, char* bsx){
    if(r == NULL) return NULL;
    int c = strcmp(r->bsx,bsx);
    if(c > 0) r->leftChild = removev(r->leftChild,bsx);
    else if(c < 0) r->rightChild = removev(r->rightChild,bsx);
    else{
        if(r->leftChild != NULL && r->rightChild != NULL){
            Node* tmp = findMin(r->rightChild);
            strcpy(r->bsx,tmp->bsx);
            strcpy(r->date,tmp->date);
            strcpy(r->time,tmp->time);
            r->inout=tmp->inout;
            r->rightChild = removev(r->rightChild,tmp->bsx);
        }else{
            Node* tmp = r;
            if(r->leftChild == NULL) r = r->rightChild; else r = r->leftChild;
            free(tmp);
            }
        }
return r;
}

void freeTree(Node* r){
    if(r == NULL) return;
    freeTree(r->leftChild);
    freeTree(r->rightChild);
    free(r);
}

void load(){
    FILE* f = fopen("log_input.txt","r");
    if(f == NULL) printf("Load data -> file not found\n");
    int i; 
    for(i = 0; i < M; i++) root[i] = NULL;
    while(!feof(f)){
        char bsx[13];
        char date[11], time[9];
        int inout;
        fscanf(f,"%s%s%s%d",date, time, bsx, &inout);
        int idx = h(date);
        root[idx] = insert(root[idx], bsx, date, time, inout);
        if(find(curr,bsx)==NULL)
            curr = insert(curr, bsx, date, time, inout);
        else removev(curr,bsx);
    }
    fclose(f);
}

int inNumber(Node* r){
    if(r == NULL) return 0;
    if(r->inout==1)
    return 1 + inNumber(r->leftChild) + inNumber(r->rightChild);
    return inNumber(r->leftChild) + inNumber(r->rightChild);
}

int outNumber(Node* r){
    if(r == NULL) return 0;
    if(r->inout==0)
    return 1 + outNumber(r->leftChild) + outNumber(r->rightChild);
    return outNumber(r->leftChild) + outNumber(r->rightChild);
}

void InOut(){
    char date[11];
    scanf("%s",date);
    int idx = h(date);
    printf("Ngay %s co %d xe gui vao, %d xe lay ra.\n\n",date,inNumber(root[idx]),outNumber(root[idx]));
}

void in(char* bsx){
    Node* r = find(curr,bsx);
    time_t t=time(NULL);
    struct tm *tm=localtime(&t);
    char date[11], time[9], str[5];
    strftime(date,80,"%Y-%m-%d", tm);
    strftime(time,80,"%H:%M:%S", tm);

    if(r==NULL){

        curr = insert(curr, bsx, date, time, 1);
        changelog = insert(changelog, bsx, date, time, 1);
        int idx = h(date);
        root[idx] = insert(root[idx], bsx, date, time, 1);
    }else printf("Xe da o trong bai!\n");
}

void out(char* bsx){
    Node* r = find(curr,bsx);
    time_t t=time(NULL);
    struct tm *tm=localtime(&t);
    char date[11], time[9], str[5];
    strftime(date,80,"%Y-%m-%d", tm);
    strftime(time,80,"%H:%M:%S", tm);

    if(r!=NULL){
        printf("%s %s %s\n",r->date,r->time,r->bsx);
        removev(curr,bsx);
        changelog = insert(changelog, bsx, date, time, 0);
        int idx = h(date);
        root[idx] = insert(root[idx], bsx, date, time, 0);
    }else printf("Xe khong o trong bai!\n");
}

void inOrder(Node* r){
    if(r == NULL) return;
    inOrder(r->leftChild);
    printf("%-20s%s %s\n",r->bsx,r->date,r->time);
    inOrder(r->rightChild);
}

void inOrderF(Node* r, FILE* f){
    if(r == NULL) return;
    inOrderF(r->leftChild,f);
    fprintf(f,"%s %s %s %d\n",r->date,r->time,r->bsx,r->inout);
    inOrderF(r->rightChild,f);
}

void currInfo(){
    printf("Tong so xe hien co: %d\n",count(curr));
    printf("%-20s%s","Bien so","Thoi gian gui\n");
    inOrder(curr);
    printf("\n");
}

void processIn(){
    char bsx[256];
    scanf(" %s",bsx);
    in(bsx);
    printf("\n");
}

void processOut(){
    char bsx[256];
    scanf(" %s",bsx);
    out(bsx);
    printf("\n");
}

void printList(){
    //for(int i = 0; i < M; i++)
    inOrder(curr);
    printf("\n");
}

void processStoreChange(){
    FILE* f = fopen("chage_log.txt","w");
    inOrderF(changelog,f);
    fclose(f);
    printf("\n");
}

void processStoreChange(){
    FILE* f = fopen("log_present.txt","w");
    inOrderF(curr,f);
    fclose(f);
    printf("\n");
}

void main(){
    while(1){
        char cmd[256];
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
        scanf("%s",cmd);
        if(strcmp(cmd,"0")==0) break;
        else if(strcmp(cmd,"1")==0) load();
        else if(strcmp(cmd,"2")==0) InOut();
        else if(strcmp(cmd,"3")==0) currInfo();
        else if(strcmp(cmd,"4")==0) processIn();
        else if(strcmp(cmd,"5")==0) processOut();
        else if(strcmp(cmd,"6")==0) ; //tu dong cap nhat
        else if(strcmp(cmd,"7")==0) processStoreChange();
        else if(strcmp(cmd,"8")==0) printList();
    }
    for(int i = 0; i < M; i++)
        freeTree(root[i]);
}
