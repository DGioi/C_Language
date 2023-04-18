#include<stdio.h>
#include<math.h>
int c[100];
int a,b;
void prin(int k){
	int i;
	printf("%d/%d=1/%d",a,b,c[0]);
	for(i=1;i<=k;i++){
		printf(" + 1/%d",c[i]);
	}
}
int start(int k,int a,int b){
	c[k]=ceil((double)b/a);
	
	if(a*c[k]-b==0){
		prin(k);
		return 1;
	}
	else {
		a=a*c[k]-b;
		b=b*c[k];
		start(k+1,a,b);
	}
}
int main(){
	scanf("%d %d",&a,&b);
	start(0,a,b);
return 0;
}
