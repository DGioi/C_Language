#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *pNext;
	struct node *pPrev;
}; 
typedef struct node NODE;
struct list{
	NODE *pHead;
	NODE *pTail;
	
};
typedef struct list LIST;
void makelist(LIST *l){
	l->pHead=NULL;
	l->pTail=NULL;
}
NODE *makeNode(int data){
	NODE*newNode;
	newNode=(NODE*)malloc(sizeof(NODE));
	if(newNode==NULL){
		printf("khong du bo nho cap phat!");
		return NULL;
	}
	newNode->data=data;
	newNode->pNext=NULL;
	newNode->pPrev=NULL;
	return newNode;
}
void insertFist(LIST *l,NODE *newNode){
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
int * generateArray(int size)
{
 	int i; 
	srand(time(NULL));
	int *retArr = (int*)malloc(size*sizeof(int));
	for(i=0; i<size; i++)
	retArr[i]=rand()%99+1;
	return retArr;
}
int *cloneArr(int * input, int size)
{
	int *copyArr=(int*)malloc(size*sizeof(int));
	memcpy(copyArr,input,size*sizeof(int));
	return copyArr;
}
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low - 1;
  int j;
  for (j = low; j <= high - 1; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void quicksort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quicksort(arr, low, pi - 1);
    quicksort(arr, pi + 1, high);
  }
}
void printArr(int A[],int size){
	int i;
	for(i=0;i<size;i++){
		if(A[i]!=-1) printf("%5d",A[i]);
		else  printf("%5c",'_');
		if((i+1)%5==0) printf("\n");
	} 
}
void printNode(LIST l){
	NODE *p;
	p=l.pHead;
	int i=0;
	printf("Dslk:\n");
	while(p!=NULL){
		if(p->data!=-1) printf("%5d",p->data);
		else  printf("%5c",'_');
		if((i+1)%5==0) printf("\n");
		p=p->pNext;
		i++;
	}
}
int main(){
	int i;
	int *Arr,sl,size,m;
	NODE *newNode;
	LIST l;
	makelist(&l);
	scanf("%d",&size);
	Arr= generateArray(size);
	printf("Hang hoa ban dau: \n");
	//printArr(Arr, size);
	int *copiedArr=cloneArr(Arr,size);
	quicksort(copiedArr,0,size-1);
	printf("Sort:\n"); 
	//printArr(copiedArr, size);
	
	for(i=0;i<=size-1;i++){
		newNode=makeNode(copiedArr[i]);
		insertFist(&l,newNode);
		}
	printNode(l);
	return 0;
}
