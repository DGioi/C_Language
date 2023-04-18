#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define xx system("cls");
#define nn printf("\n");
#define filename "C:\\Users\\ADMIN\\Documents\\C programming\\C co ban\\week14\\list.txt"
typedef struct{
		char name[50];
		int gender;
		int id;
		int s1,m1,h1;
		int s2,m2,h2;
		int t1;
		int t2;
		int dt;
} list;
int thoigian(int s,int m,int h){
	int t;
	if(h==-1) return -1;
	t=h*3600+m*60+s;
	return t;
}
list *nhapdulieu(int *size){
	list *b;
	FILE *data=fopen(filename,"r");
	b=(list*)malloc(1000*sizeof(list));
	int i=0;
	int c;
	while(1){
		fscanf(data,"%[^:]:%d",b[i].name,&b[i].gender);
		if(b[i].name[0]=='#') break;
		fscanf(data,"%d",&b[i].id);
		fscanf(data,"%d",&b[i].h1);
			fgetc(data);
		fscanf(data,"%d",&b[i].m1);
			fgetc(data);
		fscanf(data,"%d",&b[i].s1);
		fgetc(data);
		if(fgetc(data)==10){
		//	printf("%c_",c);
			b[i].s2=b[i].m2=b[i].h2=-1;
		b[i].t1=thoigian(b[i].s1,b[i].m1,b[i].h1);
		b[i].t2=thoigian(b[i].s2,b[i].m2,b[i].h2);
		b[i].dt=-1;
			i++;
			continue;
		}
		fscanf(data,"%d",&b[i].h2);
			fgetc(data);
		fscanf(data,"%d",&b[i].m2);
			fgetc(data);
		fscanf(data,"%d",&b[i].s2);
			fgetc(data);
		b[i].t1=thoigian(b[i].s1,b[i].m1,b[i].h1);
		b[i].t2=thoigian(b[i].s2,b[i].m2,b[i].h2);
		b[i].dt=b[i].t2-b[i].t1;
		b[i].t1=thoigian(b[i].s1,b[i].m1,b[i].h1);
		b[i].t2=thoigian(b[i].s2,b[i].m2,b[i].h2);
		b[i].dt=b[i].t2-b[i].t1;
		i++;
	}
	*size=i;
	fclose(data); 
	return b;
}
void top1(int size,list *b){
	int i;
	printf("TOP 1: \n");
	printf("%s:%d",b[0].name,b[0].gender);nn
		printf("%05d ",b[0].id);
		printf("%02d:%02d:%02d  ",b[0].s1,b[0].m1,b[0].h1);
		printf("%02d:%02d:%02d",b[0].s2,b[0].m2,b[0].h2);nn
		printf("total time: %d (s)",b[0].dt);nn
	for(i=0;i<size;i++){
		if(b[i].dt==b[0].dt&&i!=0) {
			printf("%s:%d",b[0].name,b[0].gender);nn
		printf("%05d ",b[0].id);
		printf("%02d:%02d:%02d  ",b[0].h1,b[0].m1,b[0].s1);
		printf("%02d:%02d:%02d",b[0].h2,b[0].m2,b[0].s2);nn
		printf("total time: %d (s)",b[0].dt);nn nn
		}
	}
}

void swap(list *a, list *b) {
  list temp = *a;
  *a = *b;
  *b = temp;
}

int partition(list *arr, int low, int high) {
  int pivot = arr[high].dt;
  int i = low - 1;
  int j;
  for (j = low; j <= high - 1; j++) {
    if (arr[j].dt<= pivot&&arr[j].dt!=-1) {
      i++;
      swap(&arr[i],& arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void quicksort(list *arr, int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quicksort(arr, low, pi - 1);
    quicksort(arr, pi + 1, high);
  }
}
int thongke(int size,list*b){
	int d=size;
	int i;
	for(i=0;i<size;i++){
		if (b[i].dt==-1) d--;
	}
	printf("So nguoi tham gia: %d ",size);nn
	printf("So nguoi hoan thanh :%d ",d);
	return d;
}
void printbxh(int size,list *b,int sln,int nam[],int nu[]){
	xx;
	int sum1,sum2;
	sum1=sum2=0;
	int x,y;
	x=y=0;
	int d;
	int i;
	printf("%-40s%30s%-40s","BXH Nam"," ","BXH Nu");
	printf("\n%-40s%30s%-40s","----------------------------------"," ","-------------------------------");nn
	printf("%-5s%-25s%-10s","Stt","Ten","Time");
	printf("%30s"," ");
	printf("%-5s%-25s%-10s","Stt","Ten","Time");nn
	for(i=0;i<size;i++){
		if(i<sln){
			if(b[nam[i]].dt!=-1){
				x++;
				sum1=sum1+b[nam[i]].dt;
			}
			if(b[nam[i]].dt==-1) 
			printf("\n%-5d%-25s%-10s",i+1,b[nam[i]].name,"Not completed");
			else
						printf("\n%-5d%-25s%-10d",i+1,b[nam[i]].name,b[nam[i]].dt);
			
		}
		if(i<size-sln){
			printf("%30s"," ");
			if(b[nu[i]].dt!=-1){
				y++;
				sum2=sum2+b[nu[i]].dt;
			}
			if(b[nu[i]].dt==-1) 
			printf("%-5d%-25s%-10s",i+1,b[nu[i]].name,"Not completed");
			else
			printf("%-5d%-25s%-10d",i+1,b[nu[i]].name,b[nu[i]].dt);
			
		}
		if(i==9||i==99||i==sln-1){
				nn
				printf("%-17s%s%-5d%-0.2f"," ","average ",x,(float)sum1/x);
				d=1;
			}
		if(i==9||i==99||i==size-sln-1){
				printf("%30s"," ");
				if(d==1)
				printf("%-20s%s%-5d%0.2f"," ","average ",y,(float)sum2/y);	
							else {
				printf("\n%-5s%-25s%-10s"," ","_","_");
				printf("%30s"," ");
				printf("%-17s%s%-5d%0.2f"," ","average ",y,(float)sum2/y);
				} 

			}
		d=0;
	}
}
int phanloai(int size,list* b,int nam[],int nu[]){
	int sln=0;
	int i=0;
	for(i=0;i<size;i++){
		if(b[i].gender==1){
			nam[sln]=i;
			sln++;
		}
		else{
			nu[i-sln]=i;
		}
	}
	return sln;
}
int main(){
	list *b;
	int size;
	int tb10;
	int nam[1000];
	int sln; //so luong nam
	int nu[1000];
	b=nhapdulieu(&size);
	quicksort(b,0,size-1);
	sln=phanloai(size,b,nam,nu);
   	top1(size,b);
   	thongke(size,b);
   	getc(stdin);
   	printbxh(size,b,sln,nam,nu);
	free(b);
	return 0;
}
