#include<stdio.h>
#include<stdlib.h>

// Hàm tim so luong xe toi thieu
int findMinVehicles(int m, int wt[], int n)
{
    int i, w;
    int dp[n + 1][m + 1];
    // khoi tao ban dau
    for (i = 0; i<= n; i++)
        dp[i][0] = 0;
    for (w = 0; w <= m; w++)
        dp[0][w] = 0;

    // Tim gia tri toi thieu
    for (i = 1; i <= n; i++)
        for (w = 1; w <= m; w++)
        {
            if (wt[i - 1] <= w)
                dp[i][w] = dp[i - 1][w - wt[i - 1]] + 1;
            else
                dp[i][w] = dp[i - 1][w];
        }

    // tim so luong xe toi thieu
    int res = 0;
    w = m;
    for (i = n; i > 0 && w > 0; i--)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            res++;
            w = w - wt[i - 1];
        }
    }
    return res;
}
int * generateArray(int size)
{
 	int i; 
	srand(time(NULL));
	int *retArr = (int*)malloc(size*sizeof(int));
	for(i=0; i<size; i++)
	retArr[i]=rand()%100;
	return retArr;
}
void insertionsort(int *A,int N){
	int k; 
  for(k = 1; k < N; k++)
  {
   int last = A[k];
   int j = k;
   while(j > 0 && A[j-1] > last)
   {
     A[j] = A[j-1];
     j--;
   }
   A[j] = last;
  }
}
void swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}
void printArr(int A[],int size){
	int i;
	for(i=0;i<size;i++){
		printf("%5d, ",A[i]);
		if((i+1)%5==0) printf("\n");
	} 
}
int main()
{
    int m = 10;  // suc chua toi da cua xe
	int n=10;
    int *w; //chuoi khoi luong hang
    w=generateArray(n);
    insertionsort(w,n);
    printArr(w,n);
    printf("So luong xe tai toi thieu: %d\n", findMinVehicles(m,w, n));
    return 0;
}

