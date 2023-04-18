#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define gett(a) { scanf("\n"); fgets(a,sizeof(a),stdin); a[strlen(a)-1]=NULL; }
#define ln(a) strlen(a)
#define ww printf("\n");

typedef struct info
{
    char hoten[51],cccd[15],sdt[15];
    float nhietdo;
    int ha1,ha2;
} in4;

in4 a[201];
int d;

void timbenhnhan()
{	int i; 
    char sdt[15];
    printf("nhap sdt: "); gett(sdt);
    for (i=1; i<=d; i++)
    {
        if (strcmp(a[i].sdt,sdt)==0)
        {
            printf("%-15s %-15s %-11s   %0.1f    %d   %d",a[i].hoten,a[i].cccd,a[i].sdt,a[i].nhietdo,a[i].ha1,a[i].ha2 ); ww
            return 0;
        }
    }
    printf("khong tim thay sdt trong danh sach");
}

int ktnd(int i)
{
    return (36.8<= a[i].nhietdo && a[i].nhietdo <= 38);
}
int ktha(int i)
{
    return ( 100<=a[i].ha1 && a[i].ha1<=130 && 79<=a[i].ha2 && a[i].ha2<=89 );
}


void danhsachdudk()
{	int i; 
    printf("danh sach du dieu kien tiem: "); ww;
    printf("STT    Hoten           CCCD            SDT"); ww
    for (i=1; i<=d; i++)
    {
        if (!ktnd(i) || !ktha(i)) continue;
        printf("%d      %-15s %-15s %-11s",i,a[i].hoten,a[i].cccd,a[i].sdt); ww
    }
}

void kiemtradk()
{
    int stt;
    printf("kiem tra benh nhan thu : ");
    scanf("%d",&stt);
    printf("ket qua kiem tra nhiet do: %d\n",ktnd(stt));
    printf("ket qua kiem tra huyet ap: %d\n",ktha(stt));
}

void in_ra()
{	int i; 
    printf("STT    Hoten           CCCD            SDT"); ww
    printf("------------------------------------------------"); ww
    for (i=1; i<=d; i++)
    {
        printf("%d      %-15s %-15s %-11s",i,a[i].hoten,a[i].cccd,a[i].sdt); ww
    }
}



void read()
{
    char YorN;
    if (d>200) { printf("khong the nhap them"); return ;};
    while (1)
    {
        printf("ban muon nhap tiep: [y/n] ?\n");
        scanf("\n%c",&YorN);
        if (YorN=='n') return ;
        ++d;
        printf("nhap ho va ten: "); gett(a[d].hoten); ww
        printf("nhap cccd: "); gett(a[d].cccd); ww
        printf("nhap sdt: "); gett(a[d].sdt); ww
        printf("nhap nhiet do:"); scanf("%f",&a[d].nhietdo); ww;
        printf("nhap lan luot huyet ap tam thu va tam truong: "); scanf("%d %d",&a[d].ha1,&a[d].ha2);
    }
}



void xuli(int num)
{
    if (num==1) read();
    if (num==2) in_ra();
    if (num==3) kiemtradk();
    if (num==4) danhsachdudk();
    if (num==5) timbenhnhan();
}

void init()
{
    d=0;
}

void menu()
{
    printf("1, nhap du lieu"); ww
    printf("2, in ra danh sach hien tai"); ww
    printf("3, kiem tra dieu kien benh nhan"); ww
    printf("4, in ra danh sach du dieu kien"); ww
    printf("5, tra cuu thong tin theo sdt"); ww;
    printf("6, thoat"); ww
}

int main()
{
    init();
    int num;
    while (1)
    {
        menu();
        scanf("%d",&num);
        if (num==6)
        {
            printf("program by Bakku");
            return 0;
        }
        else xuli(num);
    }
}
