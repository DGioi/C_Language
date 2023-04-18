#include<stdio.h>
#include<string.h>
int main(){
	int i;
	char hoten[31];
	printf("Ho ten:");
	gets(hoten);
 	int pos=-1;
 	for(pos=strlen(hoten);pos>=0;pos--){
 		if(hoten[pos]==' ') break;
	 }
	 char ten[31];
	 //cach 1:copy tung ky tu sang bien ten
	 /*for(i=pos+1;i<strlen(hoten);i++)
	 ten[i-(pos+1)]=hoten[i];
	 ten[i-(pos+1)]='\0';
	 */
	 //cach 2: dung strcpy
	 strcpy(ten,hoten+pos+1);
	 //IN
	 /* printf("\nxin chao:");
	 for(i=pos+1;i<strlen(hoten);i++)
	putchar(hoten[i]);*/
	printf("Xin chao %s\n",ten);
	printf("Xin chao %s\n",ten);
	 return 0;
	
}
