#include<stdio.h>
float a[100],b[100];
int n;
void sapxep(){
	int i,j;
	float tmp;
	for(i=1;i<=n-1;i++){
		for(j=i+1;j<=n;j++){
			if((a[i]/b[i])<(a[j]/b[j])){
				tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
				tmp=b[i];
				b[i]=b[j];
				b[j]=tmp;
			}
		}
	}

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
	 for(i=1;i<=n;i++){
	 	printf("\n%f~~~%f",a[i],b[i]);
	 	fprintf(file2,"\n%f~~~%f",a[i]/b[i],b[i]);
	 }
	fclose(file);
	return 0;
}
