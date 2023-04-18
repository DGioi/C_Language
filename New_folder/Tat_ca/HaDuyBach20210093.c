#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define gett(a) { scanf("\n"); fgets(a,sizeof(a),stdin); a[strlen(a)-1]=NULL; }
#define ln(a) strlen(a)
#define ww printf("\n");

typedef struct athlete {
    char name[51],nation[51];
    int R[4];
    short P[4];
    int total;
    char medal;
} at;

at a[110];
int n;

void print()
  
{ int i; 
    printf("Name      Nation       R1  R2  R3  P1  p2  P3"); ww;
    for (i=1; i<=n; i++)
    {
        printf("%-10s %-10s  %-3d %-3d %-3d %-3d %-3d %-3d",a[i].name,a[i].nation,a[i].R[1],a[i].R[2],a[i].R[3],a[i].P[1],a[i].P[2],a[i].P[3]);
        ww;
    }
}

void read()
{   int i; 
    char tam[200];
    printf("nhap so vdv tham gia: "); scanf("%d",&n); ww;
    for (i=1; i<=n; i++)
    {
        scanf("%s %s %d %d %d %d %d %d",a[i].name,a[i].nation,&a[i].R[1],&a[i].R[2],&a[i].R[3],&a[i].P[1],&a[i].P[2],&a[i].P[3]);
        a[i].total=a[i].R[1]*a[i].P[1]+a[i].R[2]*a[i].P[2]+a[i].R[3]*a[i].P[3];
    }

    print();
}

void tongdiem()
{   int i; 
    printf("Name      Nation       R1  R2  R3  P1  p2  P3   Total"); ww;
    for (i=1; i<=n; i++)
    {
        printf("%-10s %-10s  %-3d %-3d %-3d %-3d %-3d %-3d %-4d",a[i].name,a[i].nation,a[i].R[1],a[i].R[2],a[i].R[3],a[i].P[1],a[i].P[2],a[i].P[3],a[i].total);
        ww;
    }
}

void sapxeptongdiem()
{
    at tam;
    int i,j; 
    for (i=1; i<=n; i++)
    {
        for ( j=i+1; j<=n; j++)
        {
            if (a[i].total<a[j].total)
            {
                tam=a[i]; a[i]=a[j]; a[j]=tam;
            }
        }
        switch (i)
        {
            case 1:a[i].medal='G'; break;
            case 2:a[i].medal='S'; break;
            case 3:a[i].medal='B'; break;
            default : a[i].medal='N';
        }
    }
    printf("Name       Nation      R1  R2  R3  P1  p2  P3  Total   Medal"); ww;
    for (i=1; i<=n; i++)
    {
        printf("%-10s %-10s  %-3d %-3d %-3d %-3d %-3d %-3d %-4d    %c",a[i].name,a[i].nation,a[i].R[1],a[i].R[2],a[i].R[3],a[i].P[1],a[i].P[2],a[i].P[3],a[i].total,a[i].medal);
        ww;
    }
}

typedef struct dsach {
    char nation[50];
    int num;
} dsa;

dsa na[110];

void danhsach()
{
    int d=0; short kt=1;
    int i,j; 
    for (i=1; i<=n; i++)
    {
        kt=1;
        for ( j=1; j<=d; j++)
        {
            if (strcmp(na[j].nation,a[i].nation)==0)
            {
                na[j].num++;
                kt=0;
                break;
            }
        }
        if (kt)
        {
            strcat(na[++d].nation,a[i].nation);
            na[d].num=1;
        }
    }
    dsa tam;
    for (i=1; i<=d; i++)
    {
        for (j=i+1; j<=d; j++)
        {
            if (strcmp(na[i],na[j])>0)
            {
                tam=na[i]; na[i]=na[j]; na[j]=tam;
            }
        }
    }
    printf("Nation            Number"); ww
    for (i=1; i<=d; i++)
    {
        printf("%-15s      %-5d",na[i].nation,na[i].num); ww;
    }
}
void xuli(int num)
{
    if (num==1) read();
    if (num==2) tongdiem();
    if (num==3) sapxeptongdiem();
    if (num==4) danhsach();
}

void menu()
{
    printf("1,nhap"); ww
    printf("2,tinh tong diem"); ww
    printf("3,sap xep theo tong diem"); ww
    printf("4,in danh sach quoc gia"); ww
    printf("5,thoat"); ww;
    printf("nhap lenh:_");
}

int main()
{
    int num;
    while (1)
    {
        menu();
        scanf("%d",&num);
        if (num==5)
        {
            printf("program by Bakku");
            return 0;
        }
        else xuli(num);
    }
}
