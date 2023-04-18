#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h> 
int fmmax=0;
int wcurrent=0; 
int xe[1000];
int copyxe[1000][1000];
int min;
int sum[1000];
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

void printArr(int A[],int size){
	int i;
	for(i=0;i<size;i++){
		if(A[i]!=-1) printf("%5d",A[i]);
		else  printf("%5c",'_');
		if((i+1)%5==0) printf("\n");
	} 
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
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

void capnhatchuoi(int summ,int *copiedArr){
	int i;
	for(i=0;i<sum[summ];i++){
		printf("\n set:%d",copyxe[summ][i]+1);
		copiedArr[copyxe[summ][i]]=-1;
	}
	
}
int timmin(int *A,int size){
	int i;
	for(i=0;i<size;i++){
		if(A[i]!=-1) return A[i];
	}
}
int xecho(int m,int *A,int size){
	if(A[size-1]>m) return -1;
	else{
		int soluong,summ=0;
		int SIZE=size;
			while(SIZE>0){
			min=timmin(A,size);
			try(0,A,size,m,summ,SIZE);
			printf("\n\n Xe thu %d :%d (tan)\n",summ+1,fmmax);
			capnhatchuoi(summ,A);
		//	min=timmin(A,size);
			printf("\n");
			printArr(A, size);
			SIZE=SIZE-sum[summ];
			fmmax=0;
			wcurrent=0; 
			summ++;		
		}
	return summ;	
	}
	
}
int try(int k,int *A,int size,int m,int summ,int SIZE){
	int i;
	for(i=size-k-1;i>=0;i--)
	{
		if((wcurrent+A[i]<=m)&&A[i]!=-1) 
		{	
				xe[k]=i;
				wcurrent=wcurrent+A[i];
			 if(wcurrent==m||A[i]==min||(wcurrent+min>m))
			 {
			 	if(wcurrent>fmmax)
				 	{
					fmmax=wcurrent;
					sum[summ]=k+1; 
					memcpy(copyxe[summ],xe,sizeof(xe));
				}
			}else{
   					try(k+1,A,i+k+1,m,summ,SIZE);
   					
			   		}
			xe[k]='\0';
			wcurrent=wcurrent-A[i];
		}
	}
	 return 0;
} 
int main(){
	int *A, size,m=100,sl;
	scanf("%d",&size);
	A = generateArray(size);
	printf("Hang hoa ban dau: \n");
	printArr(A, size); 
	int *copiedArr=cloneArr(A,size);
	quicksort(copiedArr,0,size-1);
	printf("\nSort:\n"); 
	printArr(copiedArr, size);
	//xet 
	sl=xecho(m,copiedArr,size);
	if(sl!=-1){
		printf("\n So luong xe la: %d  ",sl);
	} 
	else printf("Khoi luong qua tai...");
	return 0;
} 
