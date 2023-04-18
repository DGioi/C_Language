#include<stdio.h>
int main(){
	int i;
	int k,n[100],m[100],a[100][2000],b[100][2000];
	scanf("%d",&k);
	for(i=0;i<k;i++){
		scanf("%d %d",&n[i],&m[i]);
		for(int j=0;j<n[i];j++){
				scanf("%d",&a[i][j]);
			}
			for(int j=0;j<m[i];j++){
				scanf("%d",&b[i][j]);
			}
	}
	for(i=0;i<k;i++){
	
		if(m[i]!=n[i]) {
			printf("0\n");
			continue;
		}
		if(m[i]==n[i]){
			for(int j=0;j<n[i];j++){
				if(a[i][j]!=b[i][j]){
					printf("0\n");
					 break;	 
				}
			if(j==n[i]-1) printf("1\n");
			}	
		}
		}
		return 0;
	
}
