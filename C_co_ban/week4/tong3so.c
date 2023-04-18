#include <stdio.h>
#define N 100
int n,M,T,j=0;
int x[N];
int A[]={6,3,12,6,-4,17,1,21,4,-2,7};
void solution(){
	int i;
    for(i = 1; i <= n; i++) 
        printf("%d ",x[i]);
    printf("\n");
}
int check(int v, int k){
	int i;
	
    if(k == n) return T + v == M;
    return 1;
}
void Try(int k){
	int i;
    for(i=j;i<=10;i++ ){
        if(check(A[i],k)){
            x[k] = A[i];
            j=i; 
            T += A[i];
            if(k == n) solution();
            else Try(k+1);
            T -= A[i];
        }
    }
}
int main(){
    n = 3; M = 22; T = 0;
    Try(1);
}

