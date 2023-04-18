#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include <stdint.h>
#include <sys/time.h>

int *a;
int n;
int M; //khoi luong hang toi da 1 xe co the cho

//sinh ngau nhien so co gia tri toi co 1tr
int getNextRandNumber(){
    int a = rand();
    int b = rand();
    return a%100;
}

// ham sinh ngau nhien phan tu cua mang va cac phan tu khong trung nhau
int *generateRandomArray(int size) 
{
    // khai bao mang dong
    int *arr = (int*) malloc(size*sizeof(int));
    int n=0, nextNum, check, i;
    while(n<size){
        nextNum = getNextRandNumber();
        // kiem tra xem da bi trung? O(n^2)
        check = 0;
        for(i=0;i<n;i++){
            if(arr[i]==nextNum) {
                check =1;
                break;}
            }
        if(check==0){ // so khong bi trung
            arr[n]=nextNum;
            n++;
        }
    }
    return arr;
}

//sap xep lai mang
void sortArray(int *arr,int size){  
	int i; 
	int j; 
    for (i=0;i<size-1;i++){
        for (j=i+1;j<size;j++){
            if (arr[i]>arr[j]){
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

void xoa(int arr[], int index){
	int i; 
    for(i = index; i<n-1; i++){
        arr[i]=arr[i+1];
    }
    n--;
}

void dem(int arr[], int M){
    int count = 0;
    int i; 
    while (n!=0){
        int s = 0;
        for( i = n -1; i >= 0; i--){
            s += arr[i];
            if(s<M){
                xoa(arr, i);
                continue;
            } 
            else{
                i--;
                continue;
            }
        }
        count++;
    }
    printf("So luong xe toi thieu can thiet la: %d", count);
}


int main(){
    printf("Nhap so luong kien hang: ");
    scanf("%d", &n);
    a = generateRandomArray(n);
    sortArray(a, n);
    int i; 
    for(i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\nNhap khoi luong hang toi da ma xe co the cho duoc: ");
    scanf("%d", &M);
    if(a[n-1] > M) printf("Khong cho duoc hang");
    else{
        dem(a, M);
    }
    return 0;
}
