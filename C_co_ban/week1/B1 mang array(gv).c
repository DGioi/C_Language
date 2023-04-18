#include<stdio.h>
#include<math.h>
int main()
{
double gia_mo[30],gia_dong[30];
int i;
printf("Nhap vao gia mo va dong cua ma CK trong 30 ngay:\n");
for(i=0;i<30;i++)
{
scanf("%lf",&gia_mo[i]);
scanf("%lf",&gia_dong[i]);
}
// in ra de check
printf("Gia CK trong 30 ngay:\n");
for(i=0;i<30;i++)
printf("Mo: %.2lf | Dong: %.2lf\n",gia_mo[i],gia_dong[i]);

// tim ngay chenh lech nhieu nhat
int ngay_lech_max=0;
double chenh_lech_max = fabs(gia_mo[0]-gia_dong[0]);
for(i=1;i<30;i++)
if(fabs(gia_mo[i]-gia_dong[i])>chenh_lech_max)
{
chenh_lech_max = fabs(gia_mo[i]-gia_dong[i]);
ngay_lech_max = i;
}
printf("Ngay chenh lech nhieu nhat la %d:\n",ngay_lech_max);
printf("Gia mo: %.2lf  | Gia dong: %.2lf  = Chenh lech: %.2lf\n",
    gia_mo[ngay_lech_max],gia_dong[ngay_lech_max], 
       fabs(gia_mo[ngay_lech_max]-gia_dong[ngay_lech_max]));		

// tim chuoi ngay co gia mo tang dai nhat
int max_i=0;
int max_len = 1, len, j;
for(i = 0; i<30; i++)
{
len = 1;
for(j=i; j<30-1; j++) // thieu check day cuoi cung	
if(gia_mo[j]<gia_mo[j+1])			
len++;
else // het doan tang tu i
break;
if(len>max_len) // cho day cuoi cung
{
max_len = len;
max_i = i;
i = j; // cap nhat lai vi tri moi cua i
}
}	
printf("Chuoi ngay gia mo tang nhieu nhat: %d, tu ngay %d\n",max_len,max_i);
for(i=max_i; i<max_i+ max_len; i++)
    printf("%.2lf, ",gia_mo[i]);
printf("\n");
 
       

return 0;
}

