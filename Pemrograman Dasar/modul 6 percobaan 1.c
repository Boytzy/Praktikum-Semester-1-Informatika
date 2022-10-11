#include <stdio.h>
#include <string.h>

int main()
{
    printf("Selamat Datang di Program Pembuatan Data I-Lab\n");
    char namamenu[5][50] = {{"Input  Data"}, {"View   Data"}, {"update Data"}, {"Delete Data"}, {"Search Data"}};
    int i, menu, a = 0, z, d;
    char c[16], nama['0'][99], nim['0'][99], kelas['0'][99], dosen['0'][99];
    char mainmenu = 'y';
    
    backMenu :

    for (i = 0; i < 4; i++)
    {
        printf("%i %s		\n", i + 1, namamenu[i]);
    };
    
    while (mainmenu == 'y')
    {
        printf("------------------------------------------\n");
        printf("Silahkan Masukan Menu Yang Anda Pilih : ");
        scanf("%d", &menu);
        system("cls");
        fflush(stdin);
        if (menu == 1)
        {
            buatKembali :
            printf("Masukan Nama Praktikan                : ");
            scanf(" %[^\n]s", &nama[a]);
            printf("Masukan NIM Praktikan                 : ");
            scanf("%s", &nim[a]);

            if (strlen(nim[a]) == 10)
            {
                if (a == 0)
                {
                    printf("Masukkan Kelas Pemrograman Dasar      : ");
                    scanf(" %[^\n]s", &kelas[a]);
                    printf("Masukkan Nama Dosen Pengampu          : ");
                    scanf(" %[^\n]s", &dosen[a]);
                    printf("---------------------------------------\n");
                    printf("Data Berhasil Ditambahkan\n");
                    printf("---------------------------------------\n");
                    a = a + 1;
                }
                else
                {
                    int z;
                    for (z = 0; z < a; z++)
                    {
                        if (strcmp(nim[a], nim[z]) == 0)
                        {
                            printf("\nNim Yang Anda Masukan Terduplikat, Dimohon Untuk Memasukan Nim Lain\n");
                            goto buatKembali;
                        }
                    }

                    printf("Masukkan Kelas Pemrograman Dasar      : ");
                    scanf(" %[^\n]s", &kelas[a]);
                    printf("Masukkan Nama Dosen Pengampu          : ");
                    scanf(" %[^\n]s", &dosen[a]);
                    printf("---------------------------------------\n");
                    printf("Data Berhasil Ditambahkan\n");
                    printf("---------------------------------------\n");
                    a = a + 1;
                }
            }
            
        }
        else if (menu == 2)
        {
            if (a < 1)
            {
                printf("Anda Belum Menginput Data\n");
            }
            else
            {
                int z;
                for (z = 0; z < a; z++)
                {
                    printf("%d.Nama Praktikan                 : %s\n",z+1, nama[z]);
                    printf("  NIM Praktikan                  : %s\n", nim[z]);
                    printf("  Kelas Pemrograman Dasar        : %s\n", kelas[z]);
                    printf("  Nama Dosen Pengampu            : %s\n", dosen[z]);
                    printf("----------------------------------\n");
                }
            }
        }
        else if (menu == 3)
        {
            system("cls");
            printf("Masukkan NIM yang Ingin Anda Update Datanya : ");
            scanf("%s", c);
            z = 0;
            d = 0;
            while (z <= a && d == 0)
            {
                if (strcmp(c, nim[z]) == 0)
                {
                    d++;
                }
                z++;
            }
            if (d > 1)
            {
                printf("Data yang Akan Anda Update Tidak Tersedia\n");
            }
            else
            {
                z--;
                printf("Nama Praktikan           : %s\n", nama[z]);
                printf("NIM  Praktikan           : %s\n", nim[z]);
                printf("Kelas Pemrograman Dasar  : %s\n", kelas[z]);
                printf("Nama Dosen Pengampu      : %s\n", dosen[z]);
                printf("--------------------------\n");
                printf("Input Data Baru");
                printf("\n--------------------------\n");
                printf("Masukkan Nama Praktikan          : ");
                scanf(" %[^\n]s", nama[z]);
                printf("Masukkan NIM Praktikan           : ");
                scanf("%s", nim[z]);
                printf("Masukkan Kelas Pemrograman Dasar : ");
                scanf("%s", kelas[z]);
                printf("Masukkan Nama Dosen Pengampu     : ");
                scanf(" %[^\n]s", dosen[z]);
            }
        }
        else if (menu == 4)
        {
            system("cls");
            printf("Masukkan NIM yang Ingin di Delete : ");
            scanf("%s", c);
            z = 0;
            d = 0;
            while (z <= a && d == 0)
            {
                if (strcmp(c, nim[z]) == 0)
                {
                    d++;
                }
                z++;
            }
            if (d < 1)
            {
                printf("Data NIM yang Akan Anda Delete Tidak Tersedia\n");
            }
            else
            {
                z--;
                printf("\-----------------------------------\n");
                printf("Data %s Berhasil di Delete\n", nama[z]);
                while (z <= a)
                {
                    strcpy(nama[z], nama[z + 1]);
                    strcpy(nim[z], nim[z + 1]);
                    strcpy(kelas[z], kelas[z + 1]);
                    strcpy(dosen[z], dosen[z + 1]);
                    z++;
                }
                z--;
                strcpy(nim[z], "");
                a--;
            }
        }
        else if(menu == 5){
            char search[15];
            int z;
            printf("Masukan Nim Data yang Ingin Dicari : ");
            scanf("%s", &search);

            for(z = 0; z < a; z++){
                if(strcmp(search, nim[z]) == 0){
                    printf("\nNim Mahasiswa : %s\n", nim[z]);
                    printf("Nama Mahasiswa : %s\n", nama[z]);
                    printf("Kelas Pemrograman Dasar : %s\n", kelas[z]);
                    printf("Nama Dosen Pengampu : %s\n\n", dosen[z]);
                    goto backMenu;
                }
            }
            printf("Data Yang Anda Cari Tidak Tersedia");
        }
        else
        {
            printf("mohon maaf menu tidak tersedia\n");
            fflush(stdin);
        }

        fflush(stdin);
        printf("\nkembali ke menu utama (y/n) : ");
        scanf("%c", &mainmenu);
        system("cls");
        for (i = 0; i < 4; i++)
        {
            printf("%i %s		\n", i + 1, namamenu[i]);
        };
    }
    return 0;
}