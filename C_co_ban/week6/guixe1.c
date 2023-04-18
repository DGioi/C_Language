#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
//do dai 1 ctruc 42
#define xx system("cls");
#define filename1 "C:\\Users\\ADMIN\\Documents\\C programming\\C co ban\\week6\\guixe\\baixe.txt"
#define filename2 "C:\\Users\\ADMIN\\Documents\\C programming\\C co ban\\week6\\guixe\\lichsu.txt"
#define filename3 "C:\\Users\\ADMIN\\Documents\\C programming\\C co ban\\week6\\guixe\\doanhthu.txt"
const int N=100;
typedef struct{
	int id;
	struct tm thoigian;
	char bienso[50];
} cautrucxe;

void docghi(FILE*baixe,int* n,cautrucxe *xe){
	int i=0;
	int nn,tt,ng,gg,pp,ss;
	while(!feof(baixe)){
		fscanf(baixe,"#id:%d",&xe[i].id);
		getc(baixe);
		fscanf(baixe,"in:%d %d %d %d:%d:%d",&nn,&tt,&ng,&gg,&pp,&ss);
		xe[i].thoigian.tm_mday=nn;
		xe[i].thoigian.tm_mon=tt-1;
		xe[i].thoigian.tm_year=ng-1900;
		xe[i].thoigian.tm_hour=gg;
		xe[i].thoigian.tm_min=pp;
		xe[i].thoigian.tm_sec=ss;
		getc(baixe);
		fscanf(baixe,"bs:%s",xe[i].bienso);
		getc(baixe);
		i++;
	} 
	*n=i;
	return;
}
void guixe(FILE*baixe,cautrucxe*xe,int *n){
	int i,soluong;
	int nn,tt,ng,gg,pp,ss;
	if(*n>=N){
		printf("BAI XE DA DAY!\n");
		return;
	}
	i=*n;
	*n=i+1;
		printf("Xe thu %d:\nid:",i+1);
		scanf("%d",&xe[i].id);
		getc(stdin);
		printf("Bien so:");
		scanf("%s",xe[i].bienso);
		time_t rawtime;
  		time ( &rawtime );
  		xe[i].thoigian=*localtime (&rawtime );
  		fseek(baixe,0,SEEK_END);
  		fprintf(baixe,"\n");
  		fprintf(baixe,"#id:%04d\n",xe[i].id);
		fprintf(baixe,"in:%d %d %d %d:%d:%d\n",xe[i].thoigian.tm_mday, xe[i].thoigian.tm_mon + 1, xe[i].thoigian.tm_year + 1900, xe[i].thoigian.tm_hour, xe[i].thoigian.tm_min, xe[i].thoigian.tm_sec);
		fprintf(baixe,"bs:%s",xe[i].bienso);
	return;
}
int traxe(FILE*baixe,FILE*lichsu,FILE*doanhthu,cautrucxe*xe,int *slx){
	int id,dau=0;
	int n=*slx;
	int i,dem=0,tongao;
	int tienguixe,tong;
	int gio1,ngay1,thang1,nam1;
	int gio2,ngay2,thang2,nam2;
	char rac[50];
	cautrucxe tmp;
	printf("Nhap vao id xe:");
	scanf("%d",&id);
	for(i=0;i<n;i++){
		if(xe[i].id==id){
			dau=1;
			tmp=xe[i];
			xe[i]=xe[n-1];
			xe[n-1]=tmp;
			break;
		}
	}
	if(dau==1){   
		time_t rawtime;
 				struct tm * timeinfo;
  				time ( &rawtime );
  				timeinfo = localtime ( &rawtime );
  		{
  			gio1=xe[n-1].thoigian.tm_hour;
  			ngay1=xe[n-1].thoigian.tm_mday;
  			thang1= timeinfo->tm_mon + 1;
  			nam1=xe[n-1].thoigian.tm_year + 1900;
  			gio2=timeinfo->tm_hour;
  			ngay2=timeinfo->tm_mday;
  			thang2=timeinfo->tm_mon + 1;
  			nam2=timeinfo->tm_year + 1900;
  			//tinh phi gui xe
  			//phiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii
  			if(nam1==nam2){
  				if(thang1==thang2){
  					if(ngay1==ngay2){
  						if(gio2<=18){
  							printf("Phi gui xe: 3000 vnd\n");
  							tienguixe=3000;
						  }
						else {
							printf("Phi gui xe: 5000 vnd\n");
							tienguixe=5000;
						}
					  }
					  else{
					  	tienguixe=(ngay2-ngay1)*10000;
					  	printf("Phi gui xe: %d vnd\n",tienguixe);
					  }
				  }
					
			  }
			  //phiiiiiiiiiiiiiiiiiiiiiiiiiiiiii
			  //cap nhat doanh thu
			//#####################
			fseek(doanhthu,-40,SEEK_END);
			while(!feof(doanhthu)){
			if(getc(doanhthu)=='D'){
			fscanf(doanhthu,"oanh thu:%d",&tong);
			}
			else fgets(rac,50,doanhthu);
			}
				if(tong==0) dem=1;
			   tongao=tong;
			  while(tongao>0){
			  	tongao=tongao/10;
			  	dem++;
			  }
			  tong=tong+tienguixe;
			  fseek(doanhthu,-dem-10,SEEK_END);
				fprintf(doanhthu,"+%-8d luc: %d %d %d %d:%d:%d\n",tienguixe,timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
				fprintf(doanhthu,"Doanh thu:%d",tong); 
				//##############################
		  }
  		if(getc(lichsu)!='\0'){
			fseek(lichsu,0,SEEK_END);
			printf("\n");
		  }
  		fseek(lichsu,0,SEEK_END);
  		fprintf(lichsu,"#id:%04d\n",xe[n-1].id);
		fprintf(lichsu,"in:%d %d %d %d:%d:%d\n",xe[n-1].thoigian.tm_mday, xe[n-1].thoigian.tm_mon + 1, xe[n-1].thoigian.tm_year + 1900, xe[n-1].thoigian.tm_hour, xe[n-1].thoigian.tm_min, xe[n-1].thoigian.tm_sec);
		fprintf(lichsu,"out:%d %d %d %d:%d:%d\n",timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
		fprintf(lichsu,"bs:%s\n",xe[n-1].bienso);
	*slx=n-1;
	return 1;
	}else printf("Khong co xe!");
	return 0;
	
}
void ghilai(int*slx,FILE*baixe,cautrucxe *xe){
	int n=*slx;
	int i;
		for(i=0;i<n-1;i++){
		fprintf(baixe,"#id:%d\n",xe[i].id);
		fprintf(baixe,"in:%d %d %d %d:%d:%d\n",xe[i].thoigian.tm_mday, xe[i].thoigian.tm_mon + 1, xe[i].thoigian.tm_year + 1900, xe[i].thoigian.tm_hour, xe[i].thoigian.tm_min, xe[i].thoigian.tm_sec);
		fprintf(baixe,"bs:%s\n",xe[i].bienso);
	}
		fprintf(baixe,"#id:%d\n",xe[i].id);
		fprintf(baixe,"in:%d %d %d %d:%d:%d\n",xe[i].thoigian.tm_mday, xe[i].thoigian.tm_mon + 1, xe[i].thoigian.tm_year + 1900, xe[i].thoigian.tm_hour, xe[i].thoigian.tm_min, xe[i].thoigian.tm_sec);
		fprintf(baixe,"bs:%s",xe[i].bienso);
	return ;
}
void tracuubs(cautrucxe*xe,int slx){
	int i;
	char bienso[50];
	printf("Nhap vao bien so:");
	gets(bienso);
	for(i=0;i<slx;i++){
		if(strcmp(bienso,xe[i].bienso)==0){
			printf("in:%d %d %d %d:%d:%d\n",xe[i].thoigian.tm_mday, xe[i].thoigian.tm_mon + 1, xe[i].thoigian.tm_year + 1900, xe[i].thoigian.tm_hour, xe[i].thoigian.tm_min, xe[i].thoigian.tm_sec);
		return;
		}
		
	}
	printf("\nKhong co");
	return ;
}
void tracuuid(FILE*lichsu){
	int id,xe,dem=0;
	char nhap[50];
	printf("Nhap vao id:");
	scanf("%d",&id);
	getc(stdin);
	printf("============================\n");
	while(!feof(lichsu)){
		
		
		if(getc(lichsu)=='#'){
			fscanf(lichsu,"id:%d",&xe);
			if(xe==id) {
				dem=1;
				getc(lichsu);
				fgets(nhap,50,lichsu);
				puts(nhap);
				fgets(nhap,50,lichsu);
				puts(nhap);
				fgets(nhap,50,lichsu);
				puts(nhap);
				printf("============================\n");
			}
		} else
		fgets(nhap,50,lichsu);
	}
	if(dem==0) printf("Khong co du lieu");
	return;
}
void print(cautrucxe* xe,int slx){
	int i;
	printf("so luong xe:%d\n",slx);
	printf("=====================================\n");
	for(i=0;i<slx;i++){
 					printf("%d\n",xe[i].id);
 					printf("[%d %d %d %d:%d:%d]\n",xe[i].thoigian.tm_mday, xe[i].thoigian.tm_mon + 1, xe[i].thoigian.tm_year + 1900, xe[i].thoigian.tm_hour, xe[i].thoigian.tm_min, xe[i].thoigian.tm_sec);
 					printf("Bien so:%s\n",xe[i].bienso);
 					printf("=====================================\n");
				 }
				return;	
}
int main(){
	int i;
	int slx;
	int money;
	FILE *baixe;
	FILE *lichsu;
	FILE *doanhthu;
	cautrucxe xe[N];
	baixe=fopen(filename1,"r+");
	lichsu=fopen(filename2,"r+");
	doanhthu=fopen(filename3,"r+");
	docghi(baixe,&slx,xe);
	int key;
	while(1){
				time_t rawtime;
 				struct tm * timeinfo;
  				time ( &rawtime );
  				timeinfo = localtime ( &rawtime );
  				printf ( "Current local time and date: %s", asctime (timeinfo) );
			printf("\nMENU\n");
			printf("0.Xem bai gui xe\n");
			printf("1.Gui xe\n");
			printf("2.Tra xe\n");
			printf("3.Tra cuu theo ma the\n");
			printf("4.Tra cuu theo bien so\n");
			printf("5.Thoat\n");
			printf("Nhap lua chon:"); 
			scanf("%d",&key);
			fflush(stdin);
		switch(key){
		case 0:{
			xx
			printf("0.Xem bai gui xe\n");
			print(xe,slx);
			getc(stdin);
			xx
			break;
		}
		case 1:{
			xx
			while(1){
			printf("1.Gui xe\n");
			printf("Nhap thong tin xe\n");
			guixe(baixe,xe,&slx);
			getc(stdin);
			printf("ENTER->xe tiep theo\n");
			printf("Space+ENTER->Ve menu");
			if(getc(stdin)==' ') {xx break;}
			xx
			}
			fclose(baixe);
			baixe=fopen(filename1,"r+");
			break;
		}
		case 2:{
			xx
			while(1){
			
			printf("2.Tra xe\n");
			if(traxe(baixe,lichsu,doanhthu,xe,&slx)){
			fclose(doanhthu);
			fclose(baixe);
			fclose(lichsu);
			lichsu=fopen(filename2,"r+");
			doanhthu=fopen(filename3,"r+");
			baixe=fopen(filename1,"w");
			ghilai(&slx,baixe,xe);
			fclose(baixe);
			baixe=fopen(filename1,"r+");
			}
			printf("ENTER->xe tiep theo\n");
			printf("Space+ENTER->Ve menu");
			getc(stdin);
			if(getc(stdin)==' ') {xx break;}
			xx
			}
			break;
		}
		case 3:{
			xx
			printf("3.Tra cuu theo ma the\n");
			tracuuid(lichsu);
			getc(stdin);
			xx
			break;
		}
		case 4:{
			xx
			printf("4.Tra cuu theo bien so\n");
			tracuubs(xe,slx);
			getc(stdin);
			xx
			break;
		}
		case 5:{
			xx	
			fclose(baixe);
			fclose(lichsu);
			fclose(doanhthu);
			printf("CHUONG TRINH KET THUC!");
			getc(stdin);
			xx
		
			return 0;
			break;
		}
	}
	}
	return 0;
}

