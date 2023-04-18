#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define filename "C:\\Users\\ADMIN\\Documents\\C programming\\C co ban\\week5\\checkin.txt"
#define N 400  
#define SI 8*3600+30*60
#define SO 12*3600 
#define CI 13*3600+30*60
#define  CO 17*3600
typedef struct{
	int id;//msnv
	char inout[10];//int out
	int time;//time 
} checkin;
typedef struct{
	int id;
	int time[50];
	int solan;
	int sum;
} checkin2;
int n,m;
checkin *nhap(FILE *in){
	int i=0;
	int hour,min,sec;
	checkin *a;
	a=(checkin *)malloc(sizeof(checkin)*N);
	do{
		fscanf(in,"%d %s %d:%d:%d",&a[i].id,a[i].inout,&hour,&min,&sec);
		 	a[i].time=3600*hour+60*min+sec;
		 	i++;
		 	getc(in);
		if(getc(in)=='#') break;
		else fseek(in,ftell(in)-1,SEEK_SET);
	}while(1);
	n=i;
	return a;
}
void sx(checkin *a){
	checkin2 *b;
	checkin tmp;
	int i,j;
	for(i=0;i<n-1;i++)
	for(j=i+1;j<n;j++)
		if(a[i].id>a[j].id||(a[i].id==a[j].id&&a[i].time>a[j].time)){
			tmp=a[i];
			a[i]=a[j];
			a[j]=tmp;
		}
	}
checkin2 *xuly(checkin *a){
	int i=0,j=0,k=0;
	checkin2 *tinout;
	tinout=(checkin2 *)malloc(sizeof(checkin2)*N);
	tinout[j].id=a[i].id;
	tinout[j].time[k]=a[i].time;
	for(i=1;i<n;i++){
		if(a[i].id==a[i-1].id){
			k++;
			tinout[j].time[k]=a[i].time;
			if(i==n-1){
				tinout[j].solan=k+1;
			}
		}else{
			tinout[j].solan=k+1;
			if(tinout[j].solan%2!=0) printf("DU LIEU NHAN VIEN %d Loi,Nhan Vien Co The CHua Ve\n\n",tinout[j].id);
			k=0;
			j++;
			tinout[j].id=a[i].id;
			tinout[j].time[k]=a[i].time;
		}
	}
	m=j+1;
	printf("So nguoi di la hom nay la: %d\n\n",m);
	return tinout;
}
void sumtime(checkin2 *tt){
	int i,j;
	for(i=0;i<m;i++){
		tt[i].sum=0;
		if(tt[i].solan%2!=0){
			tt[i].sum=0;
			continue;
		}
		for(j=1;j<tt[i].solan;j+=2){
			tt[i].sum=tt[i].sum+tt[i].time[j]-tt[i].time[j-1];
		}
	}
}
int main(){
	int i,j; //bien lap
	int k=0;//danh dau
	int a;
	checkin *ch;
	checkin2 *tt;
	FILE *in;
	in=fopen(filename,"r");
	if(in == NULL) {
      perror("Error in opening file");
      return 0;
   	}
   	ch=nhap(in);
   	sx(ch);
	tt=xuly(ch);
	for(i=0;i<m;i++){
		for(j=0;j<tt[i].solan;j++)
		if(j==0) 		printf("%-6d%-4s%-2d:%-2d:%-2d\n\n",tt[i].id,"IN",tt[i].time[j]/3600,(tt[i].time[j]-(tt[i].time[j]/3600)*3600)/60,tt[i].time[j]%60);
			else
   				if(j%2==1)	printf("      %-4s%-2d:%-2d:%-2d\n\n","OUT",tt[i].time[j]/3600,(tt[i].time[j]-(tt[i].time[j]/3600)*3600)/60,tt[i].time[j]%60);
   				else
   						printf("      %-4s%-2d:%-2d:%-2d\n\n","IN",tt[i].time[j]/3600,(tt[i].time[j]-(tt[i].time[j]/3600)*3600)/60,tt[i].time[j]%60);
	   }
	sumtime(tt);
	//in tong thoi gian trong phong
	for(i=0;i<m;i++){
		printf("So lan ra vao: %d : ",tt[i].solan);
		if(tt[i].sum==0) printf("%-6d TIME: %-2s:%-2s:%-2s\n\n",tt[i].id,"##","##","##");
		else
		printf("%-6d TIME: %-2d:%-2d:%-2d\n\n",tt[i].id ,tt[i].sum/3600,(tt[i].sum-(tt[i].sum/3600)*3600)/60,tt[i].sum%60);
	}
	for(i=0;i<m;i++){
		if(tt[i].sum>tt[k].sum) k=i;
	}
	printf("-------------------------------------------------------------------\n");
	printf("Nguoi lam nhieu nhat: %d :Tong thoi gian: %-2d gio %-2d phut %-2d giay\n\n",tt[k].id,tt[k].sum/3600,(tt[k].sum-(tt[k].sum/3600)*3600)/60,tt[k].sum%60);
	k=0;
	printf("-------------------------------------------------------------------\n");
	for(i=0;i<m;i++){
		if(tt[i].solan%2==0){
			if(tt[i].time[tt[i].solan-1]<tt[k].time[tt[k].solan-1])
			k=i;
		}
	}
	a=tt[k].time[tt[k].solan-1];
	printf("Nguoi Ve som nhat: %d :Luc: %-2d gio %-2d phut %-2d giay\n\n",tt[k].id,a/3600,(a-(a/3600)*3600)/60,a%60);
	printf("-------------------------------------------------------------------\n");
	for(i=0;i<m;i++){
		if(tt[i].solan%2!=0) printf("%d :Khong checkout,hoac khong ve\n\n",tt[i].id);
		for(j=0;j<1;j++){
			a=tt[i].time[j];
			if((a>SI&&a<SO)||(a>CI&&a<CO)) 
			if(j%2==1) printf("%d :Ra som\n\n",tt[i].id);
			else printf("%d :Vao muon\n\n",tt[i].id);
	}}
	return 0;
}
