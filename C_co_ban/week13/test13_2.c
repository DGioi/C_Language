#include<stdio.h>

int n;

void xoa(int arr[], int index){
	int i;
    for( i = index; i<n-1; i++){
        arr[i]=arr[i+1];
    }
    n--;
}

void dem(int arr[], int M){
    int count = 0;
    int i;
    while (n!=0){
        int s = 0;
        for(i = n -1; i >= 0; i--){
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
    int a[100];
    int M;
    int i;
    printf("Nhap so luong kien hang: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    printf("Nhap khoi luong toi da 1 xe co the cho: ");
    scanf("%d", &M);
    if(a[n-1] > M) printf("Khong cho duoc hang");
    else{
        dem(a, M);
    }
    return 0;
}
