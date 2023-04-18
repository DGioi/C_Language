#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define xx system("cls");
typedef struct{
	char id[50];
	char ne[50];
	int yr;
	char hg[50];
	char vi[50];
} inf;
inf lp[100];
int n=0;
void nhap(FILE *b){
	int i;
	fscanf(b,"%d",&n);
	for(i=0;i<n;i++){
			getc(b);
				fscanf(b,"%[^\n]",lp[i].id);
				getc(b);
				fscanf(b,"%[^\n]",lp[i].ne);
				getc(b);
				fscanf(b,"%d",&lp[i].yr);
				getc(b);
				fscanf(b,"%[^\n]",lp[i].hg);
				getc(b);
				fscanf(b,"%[^\n]",lp[i].vi);
	}
}
void prin(FILE *b){
	int i;
	fprintf(b,"%d\n",n);
	for(i=0;i<n;i++){
				fprintf(b,"MAY________%d\n",i+1);
				fprintf(b,"id_________%s\n",lp[i].id);
				fprintf(b,"name_______%s\n",lp[i].ne);
				fprintf(b,"Nam________%d\n",lp[i].yr);
				fprintf(b,"hang_______%s\n",lp[i].hg);
				fprintf(b,"vi tri_____%s\n\n",lp[i].vi);
			}
}
int search(){
}
int main(){
	int i,a;
	char b[50];
	FILE *in=fopen("dulieu2.txt","r");
	FILE *out=fopen("dsthietbi.txt","w+");
//menu
	while(1){
			printf("\nChuog trinh quan ly thiet bi\n");
			printf("1.Nhap du lieu \n");
			printf("2.Them 1 thiet bi moi\n");
			printf("3.Sua doi vi tri dat \n");
			printf("4.Ghi thong tin thiet bi vao file (file:dsthietbi.txt)\n");
			printf("5.Tra cuu thiet bi bang ma \n");
			printf("6.Tra cuu thiet bi o vi tri \n");
			printf("7.Xong\n");
			printf("Nhap lua chon:"); 
			scanf("%d",&a);
	switch(a){
		case 1 :if(n==0) nhap(in);
				for(i=0;i<n;i++){
				printf("MAY %d\n",i+1);
				printf("id     %s\n",lp[i].id);
				printf("name   %s\n",lp[i].ne);
				printf("Nam    %d\n",lp[i].yr);
				printf("hang   %s\n",lp[i].hg);
				printf("vi tri %s\n",lp[i].vi);
				xx
				printf("Da nhap du lieu!!! \n");
				}break;
				
		case 2 :
			{	getc(stdin);
				scanf("%[^\n]",lp[n].id);
				getc(stdin);
				scanf("%[^\n]",lp[n].ne);
				getc(stdin);
				scanf("%d",&lp[n].yr);
				getc(stdin);
				scanf("%[^\n]",lp[n].hg);
				getc(stdin);
				scanf("%[^\n]",lp[n].vi);
				n++;
				xx
				printf("Da Them 1 thiet bi moi!!!\n");
			break;}
		case 3 :{
			printf("Nhap vi tri can thay doi ");
			getc(stdin);
			scanf("%[^\n]",b);
			getc(stdin);
			printf("\nVi tri can chuyen den :");
			for(i=0;i<n;i++){
				if(strcmp(b,lp[i].vi)==0)
				gets(lp[i].vi);
			}
			xx
			printf("Da sua doi vi tri dat \n");
			break;
			}
		case 4 :{
			prin(out);
			xx
			printf("Da Ghi thong tin thiet bi vao file (file:dsthietbi.txt)\n");
			break;
			
		}
		case 5 :
		printf("Nhap ma thiet bi:");
		getc(stdin);
			scanf("%[^\n]",b);
			getc(stdin);
			for(i=0;i<n;i++){
				if(strcmp(b,lp[i].id)==0){
					printf("\nThong tin thiet bi:\n");
					printf("MAY %d\n",i+1);
				printf("id     %s\n",lp[i].id);
				printf("name   %s\n",lp[i].ne);
				printf("Nam    %d\n",lp[i].yr);
				printf("hang   %s\n",lp[i].hg);
				printf("vi tri %s\n",lp[i].vi);
				}
			}
			getc(stdin);
			xx
			break;
		case 6 :printf("Nhap vi tri can tim thiet bi ");
			getc(stdin);
			scanf("%[^\n]",b);
			getc(stdin);
			for(i=0;i<n;i++){
				if(strcmp(b,lp[i].vi)==0){
					printf("\nThong tin thiet bi:\n");
					printf("MAY %d\n",i+1);
				printf("id     %s\n",lp[i].id);
				printf("name   %s\n",lp[i].ne);
				printf("Nam    %d\n",lp[i].yr);
				printf("hang   %s\n",lp[i].hg);
				printf("vi tri %s\n",lp[i].vi);
				}
				
			}
			getc(stdin);
			xx	break;
		case 7 : {
			printf("Ket Thuc chuong trinh !");
					fclose(in);
					fclose(out);
					return 0;
					break;}	
	}}
	return 0;
}
