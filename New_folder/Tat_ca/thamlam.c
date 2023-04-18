#include<stdio.h>
#include<math.h>
int main(){
	int a,b;
	int c;
	scanf("%d %d",&a,&b);
	c=ceil((float)b/a);
	//a/b-1/c=a*c-b/bc
	printf("%d/%d=1/%d",a,b,c);
	while(a*c-b){
	a=a*c-b;
	b=b*c;
	c=ceil((float)b/a);
	printf("+1/%d",c);
	}
return 0;
}
