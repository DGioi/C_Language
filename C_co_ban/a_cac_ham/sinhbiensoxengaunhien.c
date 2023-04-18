#include<stdio.h>
#include<string.h>
#include<time.h>
#define xx printf("check");
int main(){
    time_t t;
  	srand((unsigned) time(&t));
	char biens[10];
		int r;
	r=49+rand()%9;
	biens[0]=r;
	r=48+rand()%10;
	biens[1]=r;
	r=rand()%26+65;
	biens[2]=r;
	r=48+rand()%10;
	biens[3]=r;
	biens[4]='-';
	r=48+rand()%10;
	biens[5]=r;
	r=48+rand()%10;
	biens[6]=r;
	r=48+rand()%10;
	biens[7]=r;
	r=48+rand()%10;
	biens[8]=r;
	r=48+rand()%10;
	biens[9]=r;
	printf("%s",biens);
	return 0;
}
