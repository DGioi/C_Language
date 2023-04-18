#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h> 
int n,sl;
int phanbo[100];
typedef struct {	
	int nhom;
	char noidung[255];
	char dapan[5][255];
} cautruc;
int nhap(cautruc *a,FILE *b){
	int i=-1,j;
	char c;
	while(!feof(b)){
		c=getc(b);
		if(c=='*'){
			i++;
			fscanf(b,"*%d",&a[i].nhom);
			fgets(a[i].noidung,255,b);
			j=0;
		}
		if(c=='#'){
			fgets(a[i].dapan[j],255,b);
			j++;
		}
		if(c=='\\') break; 	
	}
	return i+1; 
}
void sxnhom(cautruc *a){
	int i,j;
	for(i=0;i<n-1;i++)
	for(j=i+1;j<n;j++){
	if(a[i].nhom>a[j].nhom){
cautruc tmp=a[i];
		a[i]=a[j];
		a[j]=tmp;
	}	
	}	
}
int demnhom(cautruc *a){
	int i,j,dem=1;
	phanbo[1]=1;
	for(i=0;i<n-1;i++){
		if(a[i].nhom==a[i+1].nhom){
		phanbo[dem]++;
		}else{
			dem++;
			phanbo[dem]=1;
		}
	}
	printf("\nSo nhom bai tap :%d",dem);
	printf("\nSo cau hoi la: %d",n); 
	for(i=1;i<=dem;i++) printf("\nNhom %d:  %d\n",i,phanbo[i]);
	return dem;
}
void taode(cautruc *a,cautruc *b){
	int i=0,j=1,l,k=0,m=phanbo[1],e=-1;
	time_t t;
	srand((unsigned)time(&t));
	while(i<10){ 
		l=rand()%m;
		
		if(l>=m-phanbo[j]&&l!=e){
		e=l; 
		b[i]=a[l];
		i++;
		k++; 
		if(k==2){k=0;j++; m+=phanbo[j]; continue; 
		} 
		}
		}
}
void print(cautruc *b,FILE *c){
	int i,j;
	for(i=0;i<10;i++){
		printf("Cau%d:[chuong %3d] %-50s\n",i+1,b[i].nhom,b[i].noidung);
		fprintf(c,"Cau%d:[chuong %3d] %-50s\n",i+1,b[i].nhom,b[i].noidung);
		j=0;
		while(b[i].dapan[j][0]!='\0'){
			fprintf(c,"%c) %s\n",97+j,b[i].dapan[j]);
			printf("%c) %s\n",97+j,b[i].dapan[j]);
			j++;
		}
	}
}
int main(){
	int i,j,a;
	cautruc dethi[100],dechinh[10];
	FILE *in=fopen("cauhoi.txt","r");
	FILE *out=fopen("dethi.txt","w+");
	
	while(1){
			printf("Chuog trinh tao de thi\n");
			printf("1.Nhap nguon tai lieu\n");
			printf("2.Sap xep lai cau hoi\n");
			printf("3.Phan tich tai lieu\n");
			printf("4.Tao de thi\n");
			printf("5.In ra de duoc tao (file:dethi.txt)\n");
			printf("6.Thoat\n");
			printf("Nhap lua chon:"); 
			scanf("%d",&a);
	switch(a){
		case 1 : n=nhap(dethi,in); break;
		case 2 : sxnhom(dethi);	break;
		case 3 :	demnhom(dethi);	break;
		case 4 : taode(dethi,dechinh);	break;
		case 5 :	print(dechinh,out);	break;
		case 6 : 	printf("Ket Thuc chuong trinh !");
					fclose(in);
					fclose(out);  return 0; break;
	}}
	return 0;          
}
