#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int i,j,k,found,slt,st,hint;
char search[20];
FILE *in;
typedef struct
{
	char w[20];       //tu 
	char ty[20];      //loai tu
	char mn[200];     //nghia cua tu
} word;
word *wd;
int main()
{
	
	in=fopen("dic.txt", "r");
	printf("So luong tu:");
	scanf("%d", &slt);
	wd=(word*) malloc(slt*sizeof(word));
	for(i=0;i<slt;i++)
	{
		fscanf(in,"%s",wd[i].w);
		getc(in);
		fscanf(in,"%s", wd[i].ty);
		getc(in);
	    fgets(wd[i].mn,200,in);
	}
	do {
		printf("\nSearch:"); scanf("%s", search);
		found =0;
	for(i=0;i<slt;i++)
	{
		if(strcmp(search,wd[i].w)==0){
	    printf("%s", wd[i].mn);
	    found=1;
	}
	if(strcmp(search,"done")==0) return 0;
	}
	if (found==0) {
	printf("WORD HAD NOT BEEN FOUND!!");
	printf("\nMay be you are looking for:");
    i=0;
	st=0;
    while(search[i]!='\0') 
    {
        st++;
		i++;	
	}
	for (i = 0; i < slt; i++)
	{
		k=0;
		for(j=0;j<st;j++)
		{
			if (search[j]==wd[i].w[j]) k++;
            if (search[j]!=wd[i].w[j]) k--;			
		}
		if(k==st) printf("\n%s", wd[i].w);
    }
    }
	getch();
	system("cls");
} while(1);
free(wd);
wd=NULL;
return 0;
}
