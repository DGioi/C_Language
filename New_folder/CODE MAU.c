#include<stdio.h>
#include<stdlib.h>
#define nn printf("\n");
#define xx system("cls");
#define gg getc(stdin);

//cay {
typedef struct Node{
	int value;
	struct Node* leftChild;
    struct Node* rightChild;
}Node;
Node* makeNode(int value){
	Node *newNode=(Node*)malloc(sizeof(Node));
	newNode->value=value;
	newNode->leftChild=NULL;
	newNode->rightChild=NULL;
	return newNode;
}

///cay }
 
void PrintMenu(){
	printf("Ten chuong trinh\n");
	printf("1. \n");
	printf("2. \n");
	printf("3. \n");
	printf("4. \n");
	printf("5. \n");
	printf("6. \n");
	printf("7. \n");
	printf("8.OUT \n");
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
int main(){
	int key;
	while(1){
		PrintMenu();
		key=getch();
		switch(key){
			case 49:{
				xx
				printf("1. \n");
				gg xx break;
			}
			case 50:{
				xx
				printf("2. \n");
				gg xx  break;
			}
			case 51:{
				xx
				printf("3. \n");
				gg xx break;
			}
			case 52:{
				xx
				printf("4. \n");
				gg xx break;
			}
			case 53:{
				xx
				printf("5. \n");
				gg xx break;
			}
			case 54:{
				xx
				printf("6. \n");
				gg xx break;
			}
			case 55:{
				xx
				printf("7. \n");
				gg xx break;
			}
			case 56:{
				xx
				printf("8.OUT\n");
				return 0;
				break;
			}
		}
	}
	return 0;
}
