#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//M la ma tran cac loai to tien
//n la kich thuoc cua M
//money so tien can doi
void exchange(int *M,int n, int money){
	printf("Doi luong tien %d\n",money);
	int *slot=(int*)calloc(sizeof(int),n);
	int i=0;
	while(money>0){
		
		while(money>=M[i]){
			money=money-M[i];
			slot[i]++;	
			printf("%d \n",M[i]);		
		}
		
		i++;
		if(money>0&&i>=n){
			printf("Khong doi duoc");
			free(slot);
			return;
		}
	}
	for(i=0;i<n;i++)
	printf("%d: %d\n",M[i],slot[i]);
	free(slot);
}
int main(){
	int  M[]={5,3,2};
	int n=3;
	int money=11;
	exchange(M,n,money);
	return 0;
}
