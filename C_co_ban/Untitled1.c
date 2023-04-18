#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define filename "C:\\Users\\ADMIN\\Documents\\C programming\\C co ban\\week8\\album\\hocsinh.txt"
const int N=100;
typedef struct thisinh{
	char name[100];
	int date;
	float math;
	float physic;
	float chem;
} THISINH;
int loadfile(char *namefile,THISINH *info){
	int i=0;
	FILE *in;
	in=fopen(namefile,"r");
	while(!feof(in)){
		fscanf(in,"%[^\n]",info[i].name);
		fgetc(in);
		fscanf(in,"%d",&info[i].date);
		fscanf(in,"%f",&info[i].math);
		fscanf(in,"%f",&info[i].physic);
		fscanf(in,"%f",&info[i].chem);
		fgetc(in);
		i++;
	}
	return i;
}
void print(THISINH *info,int n,int key){
	int i;
	for(i=0;i<n;i++){
		if(key==1) printf("%-15s %5d %0.3f %0.3f %0.3f TB: %0.3f\n",info[i].name,info[i].date,info[i].math,info[i].physic,info[i].chem,info[i].math/3+info[i].physic/3+info[i].chem/3);
		if(key==2) 
		if(info[i].math+info[i].physic+info[i].chem>20) 	printf("%-15s %5d %0.3f %0.3f %0.3f TB: %0.3f\n",info[i].name,info[i].date,info[i].math,info[i].physic,info[i].chem,info[i].math+info[i].physic+info[i].chem);
	}
}
int main(){
	int n;
	THISINH info[N];
	n=loadfile(filename,info);
	print(info,n,1);
	printf("\n\n\nThi sinh diem tong tren 20:\n");
	print(info,n,2);
}
