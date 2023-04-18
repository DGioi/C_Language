#include<stdio.h>
float a[100],b[100];
int n,k=0,l=0;
typedef struct{
	float x;
	float y;
} nhom;
nhom N1[100];
nhom N2[100];
void sxnhom(float ,int a){
	    float tmp;
	    int i,j;
	    for(i=1;i<a;i++){
	    	for(j=i+1;j<=a;j++){
			if(s[j].x<s[i].x){
				tmp=s[i].x;
				s[i].x=s[j].x;
				s[j].x=tmp;
			}
		}
		}
		
	}
void sapxep(){
	
	int i,j;
	float tmp;
	for(i=1;i<=n;i++){
		if(a[i]<=b[i]){
			l++;
			N1[l].x=a[i];
			N1[l].y=b[i];
			
		}else{
			k++;
			N2[k].x=a[i];
			N2[k].y=b[i];
		
		}
	}
	sxnhom(N1,l);
	sxnhom(N2,k);
}
int main(){
	int i=1;
	FILE *file,*file2;
	file=fopen("dovat.txt","r+");
	file2=fopen("xep.txt","w+");
	n=0;
	while(!feof(file)){
		n++;
		fscanf(file,"%f %f",&a[i],&b[i]);
		printf("\n%f---%f",a[i],b[i]);
		i++;
	}
	 sapxep();
	 for(i=1;i<=l;i++){
	 	printf("\n%f~~",N1[i].x);
	 	fprintf(file2,"\n%f~~~%f",a[i]/b[i],b[i]);
	 }
	fclose(file);
	return 0;
}
