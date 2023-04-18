#include<stdio.h>
#include<time.h>
int main(){
	int i, n;
   	time_t t;
   	scanf("%d",&n);
    srand((unsigned) time(&t));
    for(i=0;i<n;i++){
    	printf("%d\n",rand() % 10000);
	}
   return 0;
}
