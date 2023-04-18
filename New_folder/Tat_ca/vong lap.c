#include<stdio.h>
int main(){
	FILE *f;
	f=fopen("vonglap.txt","w");
	int i;
	for(i=10;i>=0;i--){
		fprintf(f,"%d",i);
		for(i=0;i<=10;i++){
			fprintf(f,"%d",i);
		}
	}
	fclose(f);
		return 0;
}
