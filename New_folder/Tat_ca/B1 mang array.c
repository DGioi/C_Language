#include<stdio.h>
#include<math.h>
const int D=30;
typedef struct{
	double gm;
	double gd; 
} ck; 
ck a[30];
void nhap(FILE *b){
	int i;
	for(i=0;i<D;i++){
		fscanf(b,"%lf",&a[i].gm);
		printf("Mo %d:%lf   ",i+1,a[i].gm);
		fscanf(b,"%lf",&a[i].gd);
		printf("Dong %d:%lf\n",i+1,a[i].gd);
	} 
	
}
void main(){
	double b=0,m,gtb=0;
	int i,j=-1,k,t=1,max=0,d;
	FILE *in=fopen("dulieu.txt","r");
	//FILE *out=fopen("out.txt","w+");
	nhap(in);
	for(i=0;i<D;i++){
		if(fabs(a[i].gd-a[i].gm)>b) {
			b=fabs(a[i].gd-a[i].gm);
			j=i;	
		}
	} 
	
	printf("ngay %d :%lf",j+1,b);
	//tim chuoi ngay	 
	for(k=1;k<30;k++){
		if(a[k-1].gm>=a[k].gm){
			if(t>max){
				max=t;
				d=k-1;
			}
			t=0;
		}
		t++;
		if((k==D-1)&&(t>max)){
				max=t;
				d=k;
		}
}
printf(" d %d** max %d",d,max);
	for(i=d-max+1;i<=d;i++){
		printf("\nngay %d",i+1);
	}
//tim ngay sut giam nhieu
	m=0;
	j=0;
for(i=0;i<D-1;i++){
	if((a[i].gd-a[i+1].gd)>m) {
		m=a[i].gd-a[i+1].gd;
		j=i+1;
	}
	}
printf("\nNgay sut giam manh %d , %lf",j+1,m);
//gia dong -gia mo >0.01*gia mo
for(i=0;i<D;i++){
	if((a[i].gd-a[i].gm)>(0.01*a[i].gm))
	printf("\nNgay %d____%lf",i+1,a[i].gd-a[i].gm);
}
//gia dong cua duoi gia mo cua trung binh 30 ngay
printf("\ngia dong cua duoi gia mo cua trung binh 30 ngay");
for(i=0;i<D;i++){
	gtb=gtb+a[i].gm/30;
}
for(i=0;i<D;i++){
	if(a[i].gd<gtb) printf("\n Ngay %d %lf<%lf:",i+1,a[i].gd,gtb);
}

}
