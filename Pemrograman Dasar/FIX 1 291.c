#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <windows.h>

int k = 0, i = 0, l, pilihan = 0, duplicate;
char nim[30], n[30], depan[30], belakang[30], kelas[30], dosen[30], u[30], nim2[30], karcek[30],str;

FILE *c, *r, *replace;
void create();
void show();
void update();
void delete();

void create()
{
    int q;
    char duplicate[100];
    FILE *read, *create;
    read = fopen("test.txt", "r");
    create = fopen("test.txt", "a");
    printf("Masukkan NIM : ");
    scanf("%s", &nim );
    strupr(nim);
    if (nim[0] > 64 && nim[1] > 64){
        for (q = 2; q  < strlen(nim); q++){
            if ((int)nim[q] > 47  ){
                if ((int)nim[q] <= 58){

                }
               else {
                printf("Ada Karakter Dalam Inputan Anda ");
                return 0;
               }
            }
            
               else {
                printf("Ada Karakter Dalam Inputan Anda ");
                return 0;
            }
        }
    }
    
    else {
         printf("Dua Karakter Awal Harus Menggunakan A-Z ");
         return 0;
    }
    
    while (!feof(read)){
    fscanf(read, "%[^!]!%*[^!]!%*[^!]!%*[^!]!", duplicate);
    if (strcmp(duplicate, nim ) == 0){
        printf("NIM anda sudah pernah di input ");
    fclose(read);
        return 0;
    
    }
    }

printf("MASUKKAN NAMA DEPAN : ");
scanf(" %[^\n]s", &depan);
printf("MASUKKAN NAMA BELAKANG : ");
scanf(" %[^\n]s", &belakang);
printf("KELAS : ");
scanf(" %[^\n]s", &kelas);
strupr(kelas);
fprintf(create, "%s!%s!%s!%s!\n" , nim, nama_depan, nama_belakang, kelas);
fclose(create);
fclose(read);

 }
void show()
{
	r = fopen("modul6.txt", "r");
	printf("\n\t=== SHOW DATA ===\n\n");
	i = 1;
	while(fscanf(r, "%[^#]#%[^#]#%[^#]#%[^\n]\n", nim, depan, kelas, dosen) != EOF)
	{
		if(feof(r) && i == 1)
		{
			printf("\n-----------------------------------------");
			printf("\nAnda belum input data");
			printf("\n-----------------------------------------\n");

		}
		printf("%d. Nim Praktikan       : %s\n", i, nim);
		printf("   Nama Praktikan      : %s\n", depan);
		printf("   Kelas Praktikan     : %s\n", kelas);
		printf("   Dosen Pengampu      : %s\n", dosen);
		printf("--------------------------------------\n");
		i++;
	}
	fclose(r);
}

void update()
{
	printf("\n===== Update Data Praktikan =====\n");
	replace = fopen ("modul6_baru.txt", "w");
	r = fopen ("modul6.txt", "r");
	printf("Inputkan NIM yang akan diupdate datanya : ");
	fflush(stdin);
	scanf("%s", &u);
	i = 0;
	while(fscanf(r, "%[^#]#%[^#]#%[^#]#%[^\n]\n", nim, depan, kelas, dosen) != EOF)
	{
		if(strcmp(u, nim) == 0)
		{
			i++;
			printf("NIM Praktikan \t: %s\n", nim);
			printf("Nama Praktikan          : %s\n", depan);
			printf("Kelas Pemrograman Dasar : %s\n", kelas);
			printf("Nama Dosen Pengampu     : %s\n", dosen);
			printf("\n-----------------------------------\n");
			printf("masukkan nim baru      : ");
			fflush(stdin);
			scanf("%s", nim);
			printf("masukkan nama depan baru     : ");
			fflush(stdin);
			scanf(" %[^\n]s", depan);
			printf("masukkan nama belakang baru     : ");
			fflush(stdin);
			scanf(" %[^\n]s", belakang);
			strcat(depan, belakang);
			printf("nama praktikan : %s\n", depan);
			printf("masukkan kelas baru    : ");
			fflush(stdin);
			scanf("%[^\n]s", kelas);
			printf("masukkan dosen baru    : ");
			fflush(stdin);
			scanf(" %[^\n]s", dosen);

			fprintf(replace, "%s#", nim);
			fprintf(replace, "%s#", depan);
			fprintf(replace, "%s#", kelas, strupr(kelas));
			fprintf(replace, "%s\n", dosen);
		}
		else
		{
			fprintf(replace, "%s#", nim);
			fprintf(replace, "%s#", depan);
			fprintf(replace, "%s#", kelas, strupr(kelas));
			fprintf(replace, "%s\n", dosen);
		}
	}
	fclose(replace);
	fclose(r);
	remove("modul6.txt");
	rename( "modul6_baru.txt", "modul6.txt");
}

void delete()
{
	replace = fopen ("modul6_baru.txt", "w");
	r = fopen ("modul6.txt", "r");
	printf(" === hapus data ===\n");
	printf("masukkan NIM yang ingin di delete : ");
	scanf("%s", u);
	while(fscanf(r, "%[^#]#%[^#]#%[^#]#%[^\n]\n", nim, depan, kelas, dosen) != EOF)
	{
		if(strcmp(nim, u) != 0)
		{
			fprintf(replace, "%s#", nim);
			fprintf(replace, "%s#", depan);
			fprintf(replace, "%s#", kelas);
			fprintf(replace, "%s\n", dosen);
		}
	}
	printf("NIM Berhasil di hapus");
	fclose(replace);
	fclose(r);
	remove("modul6.txt");
	rename( "modul6_baru.txt", "modul6.txt");
}

void main()
{
	while(pilihan != 5)
	{

		printf("\n~Sistem Pendataan Akun I-Lab Infotech~\n");
		printf("\nMAIN MENU :");
		printf("\n[1]. Create Data");
		printf("\n[2]. Show Data");
		printf("\n[3]. Update Data");
		printf("\n[4]. Delete Data");
		printf("\n[5]. Exit");
		printf("\n\nInputkan Pilihan Anda : ");
		scanf("%d", &pilihan);

		switch(pilihan)
		{
		case 1 :
			create();
			break;
		case 2 :
			show();
			break;
		case 3 :
			update();
			break;
		case 4 :
			delete();
			break;
		case 5 :
			printf("\nEXIT");
			break;
		default :
			printf("\nWrong answer\n");
			break;
		}
	}
}
