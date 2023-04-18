#include<stdio.h>
#include<math.h>
int main(){
	float a,b,c;
	float delta;
	float x1,x2;
	printf("PT: ax^2+bx+c=0 voi a,b,c:\n");
	scanf("%f%f%f",&a,&b,&c);
	delta=b*b-4*a*c;
	if(delta<0) printf("PTVN\n");
	if(delta==0) {
		printf("PT co nghiem kep\n");
		x1=x2=-b/(2*a);
		printf("x0=x1=x2=%f",x1);
	}
	if(delta>0){
		 printf("pt co hai nghiem\n");
		 x1=(-b+sqrt(delta))/(2*a);
		 x2=(-b-sqrt(delta))/(2*a);
		 printf("x1=%f\nx2=%f",x1,x2);
	}
	return 0;
} 
