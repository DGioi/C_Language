#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include <stdint.h>
#include <sys/time.h>

#define NOT_FOUND -1
// sinh ngau nhien so co gia tri toi co 1tr
int getNextRandNumber()
{
int a = rand();
int b = rand();
return a*1000 + b;
}
 
struct timeval timeSub(struct timeval s, struct timeval e)
{
struct timeval tval_result;
tval_result.tv_sec = 	e.tv_sec - s.tv_sec;
tval_result.tv_usec = e.tv_usec - s.tv_usec;
if(tval_result.tv_usec<0) {
tval_result.tv_usec = 1000000+tval_result.tv_usec;
tval_result.tv_sec--;
}
return tval_result;
}
// ham sinh ngau nhien cac phan tu cua mang
// cac phan tu cua mang khong trung nhau
int *generateRandomArray(int size) 
{
struct timeval tval_before, tval_after, tval_result;
gettimeofday(&tval_before, NULL);	

// khai bao mang dong
int *arr = (int*) malloc(size*sizeof(int));
int n=0, nextNum, check, i;
while(n<size)
{
nextNum = getNextRandNumber();
// kiem tra xem da bi trung? O(n^2)
check = 0;
for(i=0;i<n;i++)
if(arr[i]==nextNum) 
{
check =1;
break;
}
if(check==0) // so khong bi trung
{
arr[n]=nextNum;
n++;
}
}

gettimeofday(&tval_after, NULL);
tval_result = timeSub(tval_before, tval_after);

printf("thoi gian sinh mang : %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);


return arr;
}
// ham sap xep mang
void sortArray(int *arr, int size)
{
}
 
// in ra mang hien tai
void printArr(int *arr, int size)
{
	int i;
printf("Danh sach hien tai: \n");
for( i=0; i<size; i++) {
printf("%9d, ", arr[i]);
if((i+1)%10==0) printf("\n");
}
printf("\n");
}
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
 
    // Storing start time
    clock_t start_time = clock();
 
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}
 
// ham minh hoa qua trinh tim kiem tuan tu


void sequentialSearch0(int *arr, int size,int searchKey)
{
int i;
for(i=0; i<size; i++)
if(arr[i]==searchKey)
{
//printf("Found key %d at %d\n",searchKey, i);
return;
}
//printf("Could not find key %d\n", searchKey);
}

void quick_sort(int *array, int left, int right) {
	
  int pivot, i, j, temp;

  if (left < right) {
    pivot = left;
    i = left;
    j = right;

    while (i < j) {
      // Find a number from the left side that is larger than the pivot
      while (array[i] <= array[pivot] && i < right) {
        i++;
      }
      // Find a number from the right side that is smaller than the pivot
      while (array[j] > array[pivot]) {
        j--;
      }
      // Swap the numbers
      if (i < j) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }

    // Swap the pivot with the number at index j
    temp = array[pivot];
    array[pivot] = array[j];
    array[j] = temp;

    // Recursively sort the left side
    quick_sort(array, left, j-1);
    // Recursively sort the right side
    quick_sort(array, j+1, right);
  }
}

struct timeval checkTimeSpend2(int *arr, int n) {
  struct timeval tval_before, tval_after, tval_result;
  gettimeofday(&tval_before, NULL);

  // Some code you want to time, for example:
  quick_sort(arr, 0, n-1);

  gettimeofday(&tval_after, NULL);
  tval_result.tv_sec = tval_after.tv_sec - tval_before.tv_sec;
  tval_result.tv_usec = tval_after.tv_usec - tval_before.tv_usec;
	  if(tval_result.tv_usec<0) {
		tval_result.tv_usec = 1000000+tval_result.tv_usec;
		tval_result.tv_sec--;
		}
  return tval_result;
}


int binary_search(int* array, int size, int target) {
  int left = 0;
  int right = size - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (array[mid] == target) {
      return mid;
    } else if (array[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return NOT_FOUND;
}
void binarysearchss(int* searchKey,int m,int *array,int size ){
	int i;
	for(i=0;i<m;i++){
	int index = binary_search(array, size,searchKey[i]);
    if (index != NOT_FOUND) {
    //  printf("Found %d at index %d\n", searchKey[i], index);
    } else {
     // printf("%d not found in the array\n", searchKey[i]);
    }
	}
}
struct timeval checkTimeSpend3(int *arr,int* searchKey, int n,int m) {
  struct timeval tval_before, tval_after, tval_result;
  gettimeofday(&tval_before, NULL);

  // Some code you want to time, for example:
  binarysearchss(searchKey,m,arr,n);

  gettimeofday(&tval_after, NULL);
  tval_result.tv_sec = tval_after.tv_sec - tval_before.tv_sec;
  tval_result.tv_usec = tval_after.tv_usec - tval_before.tv_usec;
	  if(tval_result.tv_usec<0) {
		tval_result.tv_usec = 1000000+tval_result.tv_usec;
		tval_result.tv_sec--;
		}
  return tval_result;
}
void msequentialSearch(int *array,int n,int *searchKey,int m){
	int i;
	for(i=0;i<m;i++){
		sequentialSearch0(array,n,searchKey[i]);
	}
	return;
}
struct timeval checkTimeSpend0(int *arr,int* searchKey, int n,int m) {
  struct timeval tval_before, tval_after, tval_result;
  gettimeofday(&tval_before, NULL);

  // Some code you want to time, for example:
	msequentialSearch(arr,n,searchKey,m);
  gettimeofday(&tval_after, NULL);
  tval_result.tv_sec = tval_after.tv_sec - tval_before.tv_sec;
  tval_result.tv_usec = tval_after.tv_usec - tval_before.tv_usec;
	  if(tval_result.tv_usec<0) {
		tval_result.tv_usec = 1000000+tval_result.tv_usec;
		tval_result.tv_sec--;
		}
  return tval_result;
}

int main()
{
int *arr,*searchKey, size = 100000, repeatTimes = 100,m=10000;
arr =generateRandomArray(size);
searchKey =generateRandomArray(m);
//printArr(arr,size);

///

struct timeval elapsed0 = checkTimeSpend0(arr,searchKey,size,m); 
printf("Time elapsed sequential search: %ld.%06ld\n", (long int)elapsed0.tv_sec, (long int)elapsed0.tv_usec);
///
struct timeval elapsed2 = checkTimeSpend2(arr,size); 
//printArr(arr,size);
printf("Time elapsed quicksort: %ld.%06ld\n", (long int)elapsed2.tv_sec, (long int)elapsed2.tv_usec);
////
struct timeval elapsed3 = checkTimeSpend3(arr,searchKey,size,m); 
printf("Time elapsed binary search: %ld.%06ld\n", (long int)elapsed3.tv_sec, (long int)elapsed3.tv_usec);
////

return 0;
}

