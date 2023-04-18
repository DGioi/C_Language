#include<stdio.h>
#include<math.h>
int main(){
	int cnt=0;
	int a;
	while(1){
		printf("nhap vao day so");
		scanf("%d",&a);
		printf("%d",a);
		cnt++;
		if (a<=0) break;
	}
	return 0;
}
