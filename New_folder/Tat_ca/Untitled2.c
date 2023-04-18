 
#include<conio.h>
#include<stdio.h>
int main(){
    float m, n, p,s;
    printf("\n\n\t- Nhap chieu rong canh m: ");
    scanf("%f",&m);
    printf("\t- Nhap chieu cao canh n: ");
    scanf("%f",&n);
    printf("\n");
    if((m>0)&&(n>0)){
        s=m*n;
        p=(m+n)*2;
        printf("\t=> Chu vi la: %.2f\n\n",p);
        printf("\t=> Dien tich la: %.2f\n\n",s);
    }else{
        printf("\tHinh khong hop le");
        printf("\t=============================\n\n");
    }
}
