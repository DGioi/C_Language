#include<stdio.h>
void sapxep(float a[],float b[],int n){
	int tmp,i,j;
	for(i=0;i<n-1;i++)
	for(j=i;j<n;j++){
		if (a[j]/b[j]>a[i]/b[i]){
		tmp=a[i];
		a[i]=a[j];
		a[j]=tmp;
		tmp=b[i];
		b[i]=b[j];
		b[j]=tmp;}
	}

}
int main(){
	int n,i;
	float a[100],b[100];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%f %f",&a[i],&b[i]);
		printf("\na[%d]/b[%d]=%f/%f",i,i,a[i],b[i]);
	}
	sapxep(a,b,n);
	for(i=0;i<n;i++){
		printf("\na[%d]/b[%d]=%f/%f",i,i,a[i],b[i]);
	}
}
