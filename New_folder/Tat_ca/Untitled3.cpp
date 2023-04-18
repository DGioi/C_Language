#include
#include
#include 
#define MAX 256
#define maxk 50 
int n,W,k;
int Tongtrongluong;
int Tonggiatri;
float Giatamthoi;
int xtemp;
typedef struct{
char Ten<50>;
int Trong_luong,Gia_tri,So_luong;
float Don_gia;
float Phuong_an;
float Gia_tri_vat; 
} Do_vat;
Do_vat Ds_vat; 
//************************************************** **************************** 
//Lay du lieu tu file INPUT.txt nam trong o dia E:
int Lay_dulieu(char *duongdan) {
FILE *f; 
f=fopen(duongdan,"r+");
if(f==NULL) { 
printf("\n\tLOI: khong tim duoc file INPUT.txt\n");
printf("\n\t************************************** **********\n"); 
return 1; }
else{ 
char s<100>;
fgets(s,100,f);
fscanf(f,"%d",&W); 
printf("\t\t Trong luong toi da cua ba lo la W=%d\n",W);
printf("\n\t\t Danh sach do vat khi nhap vao\n\n");
while(!feof(f)&&kfscanf(f,"%s%d%d%d",&(Ds_vat.Ten),&(Ds_vat.So_luong),&(Ds_vat.Trong_luong),&(Ds_vat.Gia_tri));
if(Ds_vat.Trong_luong){
Ds_vat.Don_gia=float(Ds_vat.Gia_tri)/float(Ds_vat.Trong_luong);
printf("\n- Do Vat %s co so luong m= %d, trong luong g= %d, gia tri v= %d, don gia= %.1f\n",Ds_vat.Ten,Ds_vat.So_luong,Ds_vat.Trong_luong,Ds_vat.Gia_tri,Ds_vat.Don_gia);k++; } }
if(k==maxk)
 printf("\n\tChi lay %d do vat",n);
 printf("\n\n\t\t Danh sach co n = %d loai do vat.",k);n=k;fclose(f);return 0; }
  }//************************************************** ****************************//Sap xep lai danh sach do vat theo thu tu giam dan cua don gia.
  void Sap_xep(){
  Do_vat temp;
  int i;
  for(i=0;iDs_vat.Don_gia=float(Ds_vat.Gia_tri)/float(Ds_vat.Trong_luong); for(i=0;ifor (int j=i+1;j{if(Ds_vat.Don_gia{ temp=Ds_vat; Ds_vat=Ds_vat; Ds_vat=temp;} } printf("\n\n\t\t********************************** *******\n\n");printf("\n\t Danh sach do vat sau khi sap xep theo thu tu giam dan cua don gia\n\n\n");for(i=0;i printf("- Do vat %s co so luong m= %d, trong luong g= %d, gia tri v= %d, don gia: %.1f\n\n",Ds_vat.Ten,Ds_vat.So_luong,Ds_vat.Trong_luong,Ds_vat.Gia_tri,Ds_vat.Don_gia); Ds_vat.Gia_tri=0;for (int l=0;l{xtemp=0; } } }//************************************************** ****************************//Tong trong luong void Tong_trong_luong(){ float Phuong_an, Trong_luong; for (int i=0;i Trong_luong=float(W -Phuong_an*Ds_vat.Trong_luong); } printf("\n - Trong luong con lai cua ba lo: W = %.f",Trong_luong);} //Ket qua in ra man hinh void Ket_qua(){ float Phuong_an; printf("\n\n\n\t\t******************************** **********\n"); printf("\n - Phuong an tot nhat:\n"); for(int i=0;i { Phuong_an=float (W/Ds_vat.Trong_luong); W=int(W-Ds_vat.Trong_luong*Phuong_an); Ds_vat.Gia_tri_vat= (Phuong_an*Ds_vat.Gia_tri); printf("\t\t\t\t* Chon %.f do vat loai %s \n",Phuong_an,Ds_vat.Ten); printf("\t\t\t\t - Gia tri vat %s: v = %.f\n\n",Ds_vat.Ten,Ds_vat.Gia_tri_vat); }}//************************************************** ****************************//Chuong trinh chinhint main() {printf("\n\t\t\t\t * * *\n");printf("\n\t\t\t KET QUA\n\t\t\t BAI TOAN BA LO 2.\n\n");printf("\n\n\t\t********************************** *******\n\n");char *pa ="INPUT.txt"; Lay_dulieu(pa);Sap_xep(); Ket_qua();Tong_trong_luong();getch();return 0; }

