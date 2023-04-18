/*
test th?i gian th?c hien cua cac thu?t toan co ban
 
**/
 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h> // cho memcpy
// sinh mang ngau nhien
int * generateArray(int size)
{
	int i; 
srand(time(NULL));
int *retArr = (int*)malloc(size*sizeof(int));
for(i=0; i<size; i++)
retArr[i]=rand();
return retArr;
}
// tao ra copy cua mang ban dau
int *cloneArr(int * input, int size)
{
int *copyArr = (int*)malloc(size*sizeof(int));
memcpy(copyArr, input, size*sizeof(int));
return copyArr;
}
// doi cho 2 phan tu
void swap(int *a, int *b)
{
int c = *a;
*a = *b;
*b = c;
}
// ham in mang
void printArr(const int *input, int size)
{
	int i; 
printf("Cac phan tu trong mang kich thuoc %d la: \n",size);
for(i=0; i<size; i++)
{
printf("%5d, ", input[i]);
if((i+1)%10==0) printf("\n");
}

printf("\n");
}
// sap xep noi bot
void bubblesort(int *input, int size)
{
	int i,j; 
for( i=size; i>1; i--)
   for(j=1; j<i; j++)
   	  if(input[j-1]>input[j]) swap(&input[j-1], &input[j]);
}
// sap xep lua chon
void selectionsort(int *input, int size)
{
	int i,j;
for(i=size; i>1; i--) // cuoi day la i-1
{
int vtMax = 0;
for(j=1; j<i; j++)
if(input[j]>input[vtMax]) vtMax=j;

swap(&input[vtMax], &input[i-1]);
}
}
// sap xep chen tren mang
void insertionSort(int *A, int N) {
  // index tu 1 -> N
  int k; 
  for(k = 2; k <= N; k++)
  {
   int last = A[k];
   int j = k;
   while(j > 1 && A[j-1] > last)
   {
     A[j] = A[j-1];
     j--;
   }
   A[j] = last;
  }
}
 
int main()
{
int *A, size;
size = 100;
A = generateArray(size);
printf("Mang ban dau: \n");
printArr(A, size);

// minh hoa bubble sort
int *copiedArr = cloneArr(A, size);
bubblesort(copiedArr, size);
printf("Mang sau khi bubblesort: \n");
printArr(copiedArr, size);
 
// minh hoa selection sort
free(copiedArr);
copiedArr = cloneArr(A, size);	
selectionsort(copiedArr, size);	
printf("Mang sau khi selectionsort: \n");
printArr(copiedArr, size);


// minh hoa insertion sort
free(copiedArr);
copiedArr = cloneArr(A, size);	
insertionSort(copiedArr, size);	
printf("Mang sau khi insertionsort: \n");
printArr(copiedArr, size);
return 0;
}

