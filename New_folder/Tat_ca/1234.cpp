#include<stdio.h>
#include<string.h>
typedef struct {
	int nhom;
	char noidung[255];
	char dapan[5][255];
} cautruc;
int main(){
	char c, s[50];
	int d;
	FILE *in=fopen("de.txt","r");
	fscanf(in,"%c",&c);
	if(c='*')
	{
		fscanf(in,"%d",&d);
		fgets(s,50,in);
	}
}
