#include<stdio.h> 
#include<math.h>
int main(){
	int i;
	int a=1;
	float sum=0;
	for (i=1;i<23;i++){
		a*=2;
		sum+=sin(i)/a;
	}
	printf("%f___ %f\n ",sin(i)/a,sum); 
	return 0;
}
