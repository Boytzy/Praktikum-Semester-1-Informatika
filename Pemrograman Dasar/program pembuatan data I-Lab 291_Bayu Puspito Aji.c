#include <stdio.h>
#include <string.h>

int main(){
printf("Selamat Datang di Program Pembuatan Data I-Lab\n");
char namamenu[4][50] = {{"Input  Data"},{"View   Data"},{"update Data"},{"Delete Data"}};
int i,menu,a=0,b,d;
char c[16],nama['0'][99],nim['0'][99],kelas['0'][99],dosen['0'][99];
char mainmenu = 'y';


for(i = 0; i < 4;i++ ){
printf("%i %s		\n",i+1,namamenu[i]);
};
while(mainmenu=='y'){
	printf("------------------------------------------\n");
    printf("Silahkan Masukan Menu Yang Anda Pilih : ");
    scanf("%d",&menu);
    system("cls");
    fflush(stdin);
    if (menu==1){
    	a=a+1;
    	printf("Masukan Nama Praktikan                : ");
    	scanf(" %[^\n]s",nama[a]);
    	printf("Masukan NIM Praktikan                 : ");
    	scanf("%s",nim[a]);
    	printf("Masukkan Kelas Pemrograman Dasar      : ");
    	scanf("%s",kelas[a]);
    	printf("Masukkan Nama Dosen Pengampu          : ");
    	scanf(" %[^\n]s",dosen[a]);
		printf("---------------------------------------\n"); 
		printf("Data Berhasil Ditambahkan\n");
		printf("---------------------------------------\n");   
    }
    else if(menu==2){
    	if(a<1){
        printf("Anda Belum Menginput Data\n");
    	}else{
        b=1;
        while(b<=a){
            printf("%d.Nama          : %s\n",b,nama[b]);
            printf("  NIM           : %s\n",nim[b]);
            printf("  Kelas         : %s\n",kelas[b]);
            printf("  Nama Dosen    : %s\n",dosen[b]);
            printf("-----------------\n");
            b++;
        }
    }
    }
    else if(menu==3){
		system("cls");
    	printf("Masukkan NIM yang Ingin Anda Update Datanya : ");
    	scanf("%s",c);
    	b=1;
    	d=0;
    	while(b<=a && d==0){
        	if(strcmp(c,nim[b])==0){
        	    d++;
        	}
        	b++;
    	}
    	if(d<1){
    	    printf("Data yang Akan Anda Update Tidak Tersedia\n");
    	}else{
    	    b--;
    	    printf("Nama                     : %s\n",nama[b]);
    	    printf("NIM                      : %s\n",nim[b]);
    	    printf("Kelas                    : %s\n",kelas[b]);
    	    printf("Nama Dosen               : %s\n",dosen[b]);
    	    printf("--------------------------\n");
    	    printf("Input Data Baru");
    	    printf("\n--------------------------\n");
    	    printf("Masukkan Nama Baru       : ");
    	    scanf(" %[^\n]s",nama[b]);
    	    printf("Masukkan NIM Baru        : ");
			scanf("%s",nim[b]);
			printf("Masukkan Kelas Baru      : ");
			scanf("%s",kelas[b]);
			printf("Masukkan Nama Dosen Baru : ");
    	   	scanf(" %[^\n]s",dosen[b]);   
    }
	}
	else if(menu==4){
		system("cls");
    	printf("Masukkan NIM yang Ingin di Delete : ");
    	scanf("%s",c);
    	b=1;
    	d=0;
    	while(b<=a && d==0){
    		    if(strcmp(c,nim[b])==0){
    		        d++;
    	    }
    	    b++;
    	}
    	if(d<1){
    	    printf("Data NIM yang Akan Anda Delete Tidak Tersedia\n");
    	}else{
    	    b--;
    	    printf("Data %s Berhasil di Delete\n",nama[b]);
        	while(b<=a){
        	    strcpy(nama[b],nama[b+1]);
        	    strcpy(nim[b],nim[b+1]);
        	    strcpy(kelas[b],kelas[b+1]);
        	    strcpy(dosen[b],dosen[b+1]);
        	    b++;
        	}
        	b--;
        	strcpy(nim[b],"");
        	a--;
    	}	
	}	
    else
	{
        printf("mohon maaf menu tidak tersedia\n");
        fflush(stdin);
    }
    
    fflush(stdin);
    printf("kembali ke menu utama (y/n) : ");
    scanf("%c", &mainmenu);
    system("cls");   
	for(i = 0; i < 4;i++ ){
	printf("%i %s		\n",i+1,namamenu[i]);
	};
    
}
return 0;
}