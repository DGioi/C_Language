#include<stdio.h> 
#define n 5 
void printSolution(int a[]){
	int i;
	for(i=0;i<n;i++) printf("%d",a[i]);
	printf("\n");
}
int x[n];
int TRY(int k) { 
int v;
for(v = 0; v <= 1; v++){
if(x[k-1] + v < 2){
x[k] = v;
if(k == n) 
printSolution(x);
else TRY(k+1);
}
}
}
int main() {
x[0] = 0;
TRY(1);
}
