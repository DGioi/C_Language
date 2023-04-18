#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
typedef struct cauhoi {
	int nhom; // Nhóm/ch??ng mà câu h?i này thu?c v?
	char noidung[255]; // N?i dung câu h?i
	char dapan[5][255]; //Các ?áp án khác c?a câu h?i.
} cauhoi;

	int DS_Nhom[100];
	int Dem_Nhom = 0;
void KiemTraNhom(int id) { //Ham kiem tra nhom da co chua, neu chua co thi tang bo dem len 1 va luu vao danh sach
	int i;
	for (i = 0; i < Dem_Nhom;i++) {
		if (DS_Nhom[i] == id) return; //Nhom da co
	}
	//Den day thi nghia la co them nhom moi
	DS_Nhom[Dem_Nhom++] = id; 
}

int ChuaChon (int DS_CauDaChon[],int SoCauHienCo,int idToCheck) {
	//Ham kiem tra cau hoi da co trong danh sach chua
	int i;
	for (i = 0; i < SoCauHienCo;i++)
	   if (DS_CauDaChon[i] == idToCheck) return 0;
	return 1;
}
void main() {
	cauhoi DS_Cauhoi[100];
	int id = -1; //id luu so cau hoi hien co
	FILE *finput;
	int idChap;
	int idDapan = 0;
	
	char Dau_dong; // Dau cua 1 dong
	
	int i,j;
	
	finput = fopen("cauhoi.txt","r");
	if (finput == NULL) {
		perror(" Loi khong mo duoc file");
		return ;
	}
	while(!feof(finput)) {
		
		Dau_dong = fgetc(finput);//fgets(line,255,finput);
		if (Dau_dong =='*') { //Cau hoi moi
			id++;// Tang chi so cau hoi
			
			fscanf(finput,"*%d",&DS_Cauhoi[id].nhom);
			
			//printf("idnhom:%d\n",DS_Cauhoi[id].nhom);
			KiemTraNhom(DS_Cauhoi[id].nhom);
			fscanf(finput," %[^\n]s",DS_Cauhoi[id].noidung);
			
			idDapan = 0;
		}
		else if(Dau_dong== '#') {
			fscanf(finput," %[^\n]s",DS_Cauhoi[id].dapan[idDapan++]);
			//printf("Lua chon: %d %s\n",idDapan,DS_Cauhoi[id].dapan[idDapan-1]);
		}
		else if(Dau_dong == '\\') break;
		
	}
	printf("Tong so nhom cau hoi:%d\n",Dem_Nhom);
	printf("Tong so cau hoi:%d\n",id+1);
	cauhoi tmp;
	for (i = 0; i < id; i++)
		for(j = i+1;j <=id;j++)
		    if (DS_Cauhoi[i].nhom > DS_Cauhoi[j].nhom) {
		    	tmp = DS_Cauhoi[i];
		    	DS_Cauhoi[i] = DS_Cauhoi[j];
		    	DS_Cauhoi[j] = tmp;
			} 
	// In ra danh sach da sap xep		
	for (i = 0; i <= id; i++) {
		j = 0;
		printf("%d %s\n",DS_Cauhoi[i].nhom,DS_Cauhoi[i].noidung);
		while(strcmp(DS_Cauhoi[i].dapan[j],"")!=0) {
			puts(DS_Cauhoi[i].dapan[j]);
			j++;
		}
	}
	
	//Tao bo de
	srand(time(NULL)); // Khoi tao bo sinh so ngau nhien
	int DaChon[10];
	int random_id;
	char lua_chon[255];
	
		j = 0;
		while (j < 10) {
			random_id = rand()%(id+1);
			if (ChuaChon(DaChon,j+1,random_id)) {
				DaChon[j] = random_id;
				j++;
			}
		}

	printf("De Thi\n");
	FILE *foutput = fopen("dethi.txt","w");
	if (foutput == NULL) {
		perror("Can not open file dethi.txt to write\n");
		
	}
	else {
		for (i = 0; i < 10;i++)
		{
			printf("%d. %s\n",i+1,DS_Cauhoi[DaChon[i]].noidung); //In ra man hinh
			fprintf(foutput,"%d. %s\n",i+1,DS_Cauhoi[DaChon[i]].noidung); // In ra file
			for (j = 0; j < 5;j++) {
				strcpy(lua_chon,DS_Cauhoi[DaChon[i]].dapan[j]); //Chep sang bien lua_chon de viet cau lenh ngan gon
				if (strcmp(lua_chon,"") != 0) {
					printf("%c) %s\n",'a'+ j,lua_chon);
					fprintf(foutput,"%c) %s\n",'a'+ j,lua_chon);
				}
			}
		}
		fclose(foutput);
	}
	
	fclose(finput);
}
