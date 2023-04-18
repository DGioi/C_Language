#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
//M la ma tran cac loai to tien
//n la kich thuoc cua M
//money so tien can doi
int tien[10000];
int luu[10000][10000];
int dau[10000];
int g=-1,max=0,count[10000];
void luutien(int *a,int k,int j){
	int i;
	for(i=0;i<=k;i++){
		if(i>0&&tien[i]!=tien[i-1]) count[j]++;
		a[i]=tien[i];
	}
	if(count[j]>max) max=count[j];
}
void print(int k,int gg){
	int i;
	for(i=0;i<=k;i++){
		printf("%d ",luu[gg][i]);
	}
}
void exchange(int *M,int n, int money,int k){
	int i;
	for(i=0;i<n;i++){
		if(k==0||(k>0&&M[i]<=tien[k-1])){
		if(money-M[i]>=0){
			tien[k]=M[i];
			money=money-M[i];
			if(money==0){
				g++;
				if(g==0){
					printf("Cac Phuong An Co The:\n");
				}
				luutien(luu[g],k,g);
				dau[g]=k;
				printf("%4c",' ');
				print(k,g);
			
				printf("\n");
				
				
			}
			else if(k<34){
				exchange(M,n,money,k+1);
			} 
			money=money+M[i];
			tien[k]=0;
		}
		}
	}
	
}
int main(){
	int i;
	int  M[]={5,3,2};
	int n=3;
	memset(count,0,sizeof(count));
	//luu=(int **)malloc(sizeof(int*)*(1000));
	int money;
	printf("Phan Tich so tien:");
	scanf("%d",&money);
	exchange(M,n,money,0);
	if(g==-1){
		printf("Khong co phuong an!");
		return 0;
	}
	printf("Toi uu:\n");
	for(i=0;i<g;i++){
		if(count[i]==max){
			printf("%4c",' ');
			print(dau[i],i);
			printf("\n");
			
		}
	}
//	free(luu);
	return 0;
}
