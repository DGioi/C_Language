#include<stdio.h> 
#include<string.h>
typedef struct{
	long id;
	int chapter;
	char content[50];
} question;
question q[150],p[150],chuan[150];
int n,m;
void print1(question a[],int k){
	int i;
	printf("%-5s%-8s%-50s\n","ID","Chapter","Content");
	for(i=0;i<k;i++) printf("%-5ld%-8d\"%-s\"\n",a[i].id,a[i].chapter,a[i].content);
}
void print2(int i){
	printf("%-5s%-8s%-50s\n","ID","Chapter","Content");
	printf("%-5ld%-8d\"%-s\"\n",q[i].id,q[i].chapter,q[i].content);
}
void read(){
	int i;
	while(1){
	printf("\nNhap vap so cau hoi:");
	scanf("%d",&n);
		if(n>0&&n<=100){
		break;
		}
		else printf("Must be > 0 and <= 100\n");
	}
	printf("Nhap thong tin cau hoi\n");
	for(i=0;i<n;i++){
	scanf("%d %[^\n]",&q[i].chapter,q[i].content);
	q[i].id=(long)i+1;
	p[i]=q[i];
	}
}
void search(){
	int i;
	printf("Nhap vao ID cau hoi:");
	scanf("%d",&i);
	if(i<=0||i>n) {
		printf("\nID not found");
	}else print2(i-1);
	}
void add(){
	n=n+1;
	printf("\nNhap thong tin cau hoi moi\n");
	scanf("%d %[^\n]",&q[n-1].chapter,q[n-1].content);
	q[n-1].id=(long)n;
	p[n-1]=q[n-1];
}
void count(){
	int count=1;
	int i,j;
	question tmp;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(p[i].chapter>p[j].chapter){
			tmp=p[i];
			p[i]=p[j];
			p[j]=tmp;
			}
		}
	}
	printf("%-7s%-7s\n","Chapter","Count");
	for(i=0;i<n;i++){
		if(p[i].chapter==p[i+1].chapter){
			count++;
		}
		else{
			printf("%-7d%-7d\n",p[i].chapter,count);
			count=1;
		}
	}
	
}
void check(){
	int i,j;
		m=-1;
	for(i=0;i<n;i++){
		j=-1;
		if((int)q[i].content[0]<65||(int)q[i].content[0]>90) continue;
		while(1){
			j++;
			if((int)q[i].content[j]==36) break;
			if((int)q[i].content[j]==42) break;
			if((int)q[i].content[j]==92) break;
			if(q[i].content[j+1]=='\0'){
				m++;
				chuan[m]=q[i];
				break;
			}
		}
	}
}
int main(){
	int key;
	while(1){
	printf("************************\n");
	printf("1.READ\n");
	printf("2.SEARCH\n");
	printf("3.ADD\n");
	printf("4.count\n");
	printf("5.CHECK\n");
	printf("6.exit\n");
	printf("************************\n");
	printf("Nhap vao lua chon: ");
	scanf("%d",&key);
	switch(key){
		case 1 :{
			read();
			print1(q,n);
			break;
		}
		case 2:{
			search();
			break;
		}
		case 3:{
			add();
			print1(q,n);
			break;
		}
		case 4:{
			count();
			break;
		}
		case 5:{
			check();
			print1(chuan,m+1);
			break;
			}
		case 6:{
			printf("Chuong trinh ket thuc!!!");
			return 0;
			break;
		}
	}
	}
}

