#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int main(){
	int i;
	time_t t;
	srand((unsigned)time(&t));
	for(i=0;i<10;i++){
		printf("%d\n",rand()%10);
	}
	return 0;
}
