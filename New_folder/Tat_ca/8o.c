#include<stdio.h>
int main(){
	int i=0;
	float n,tg=0,tb,tgbp=0,ps;
	printf("Nhap Vao Day so:");
	//
	while(scanf("%f",&n)){
		if (n<=0.0) break;
		else 
	    i++;
		printf("n%d= %.0f \n",i,n);
	    tg+=n;
    	tgbp+=n*n;
		}
	//	
		tb=tg/i;            //tong chia cho so so hang
		ps=tgbp/i-tb*tb;    //phuong sai (xi-xtb)^2/n=(tong(xi^2)-2.tong(xi).xtb+sopt.xtb^2)/sopt
		printf("Gia tri trung binh: %.2f \n Phuong sai : %.2f",tb,ps);
	return 0;
}


