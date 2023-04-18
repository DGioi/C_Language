#include<stdio.h> 
#include<string.h>
int sosanh(char *a,char *b){
	int pos1;
	for(pos1=strlen(a)-1;pos1>=0;pos1--){
 		if(a[pos1]==' ') break;
	 }
	 int pos2;
	for(pos2=strlen(b)-1;pos2>=0;pos2--){
 		if(b[pos2]==' ') break;
	 }
	return strcmp(a+pos1+1,b+pos2+1); 
}
	
int main(){
	int n,i,j;
	char name[45][31];
	char q[31];
	printf("Nhap vao so luong hs:");
	scanf("%d",&n);
	getc(stdin);
	for(i=0;i<n;i++){
		gets(name[i]);
	}
	for(i=0;i<n-1;i++)
	for(j=i+1;j<n;j++)
	if(sosanh(name[i],name[j])>0) {
		strcpy(q,name[i]);
		strcpy(name[i],name[j]);
		strcpy(name[j],q);
	}
	for(i=0;i<n;i++) printf("\n%s",name[i]);
	return 0;
}
