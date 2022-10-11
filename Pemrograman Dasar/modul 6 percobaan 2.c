#include<stdio.h>
#include<string.h>
char nim[20],nama_depan[70],kelas[15],nama_belakang[70];

int main()
{
    int pilih;

    backMenu:
    printf("\n==============================================\n");
    printf("\nSelamat Datang di Program Pembuatan Data I-Lab\n\n");
    printf("==============================================\n\n");
    printf("1.Create data\n");
    printf("2.Show data\n");
    printf("3.Update data\n");
    printf("4.Delete data\n");
    printf("5.Search data\n");
    printf("6.Exit Program\n");

    printf("\nSilahkan Masukkan Menu Yang Anda Pilih : ");
    scanf("%d", &pilih);

    system ("cls");

    switch(pilih){
        case 1 : 
        create_data();
        goto backMenu;
        break;

        case 2 : 
        show_data();
        goto backMenu;
        break;

        case 3 :
        update_data();
        goto backMenu;
        break;

        case 4 :
        delete_data();
        goto backMenu;
        break;
        
        case 5 :
        search_data();
        goto backMenu;
        break;

        case 6 :
        goto Exit;
        break;

        default : 
        printf("Menu Yang Anda Pilih Tidak Tersedia, Silahkan Pilih Kembali Menu 1-6 ");
        goto backMenu;
        break;
    }
    goto backMenu;
Exit:
printf("\nTerima Kasih");
}

int create_data()
{
    int b;
    char duplicate[100];
    FILE *read, *create;
    read = fopen("modul6.txt", "r");
    create = fopen("modul6.txt", "a");
    printf("NIM PRAKTIKAN           : ");
    scanf("%s", &nim );
    strupr(nim);
    if (nim[0] > 64 && nim[1] > 64){
        for (b = 2; b  < strlen(nim); b++){
            if ((int)nim[b] > 47  ){
                if ((int)nim[b] <= 58){

                }
               else {
                printf("Tidak Boleh Ada Spesial Karakter Dalam Menginput NIM ");
                return 0;
               }
            }
            
               else {
                printf("Tidak Boleh Ada Spesial Karakter Dalam Menginput NIM ");
                return 0;
            }
        }
    }
    
    else {
         printf("Dua Karakter Awal Harus Menggunakan Huruf ");
         return 0;
    }
    
    while (!feof(read)){
    fscanf(read, "%[^!]!%*[^!]!%*[^!]!%*[^!]!", duplicate);
    if (strcmp(duplicate, nim ) == 0){
        printf("NIM yang anda masukan anda sudah ada ");
    fclose(read);
        return 0;
    
    }
    }

printf("NAMA DEPAN PRAKTIKAN    : ");
scanf(" %[^\n]s", &nama_depan);
printf("NAMA BELAKANG PRAKTIKAN : ");
scanf(" %[^\n]s", &nama_belakang);

printf("KELAS PRAKTIKAN         : ");
scanf(" %[^\n]s", &kelas);
strupr(kelas);
fprintf(create, "%s!%s!%s!%s!\n" , nim, nama_depan, nama_belakang, kelas);
fclose(create);
fclose(read);

 }

 int show_data()
 {
     FILE *read; 
     read = fopen("modul6.txt", "r");

     while (!feof(read)){
         fscanf(read, "%[^!]!%[^!]!%[^!]!%[^!]!\n", nim, nama_depan, nama_belakang, kelas);
         printf("NIM           : %s\n", nim);
         printf("NAMA DEPAN    : %s\n", nama_depan);
         printf("Nama BELAKANG : %s\n", nama_belakang);
         printf("KELAS         : %s\n\n", kelas);
    
     }
     fclose(read);
 }

 int search_data()
 {
     char cari[100];
     FILE *read; 
     read = fopen("modul6.txt", "r");
     printf("Masukkan NIM Yang Ingin Anda Cari : ");
     scanf("%s", &cari);
     while (!feof(read)){
        fscanf(read, "%[^!]!%[^!]!%[^!]!%[^!]!\n", nim, nama_depan, nama_belakang, kelas);
         if (strcmp(nim, cari) == 0){
         printf("NIM           : %s\n", nim);
         printf("NAMA DEPAN    : %s\n", nama_depan);
         printf("Nama BELAKANG : %s\n", nama_belakang);
         printf("KELAS         : %s\n\n", kelas);
         fclose(read);
         return 0;
         }
         
     }
     printf("Data Yang Anda Cari Tidak Ada ");
     fclose(read);
    
 }

int update_data()
{
    FILE *read, *ubah;
    read = fopen("modul6.txt", "r");
    ubah = fopen("modul6_baru.txt", "w");
    char search[100];
    printf("Masukkan NIM Yang Ingin Anda Update : ");
    scanf("%s", search);
    while(!feof(read)){
        fscanf(read, "%[^!]!%[^!]!%[^!]!%[^!]!\n", nim, nama_depan, nama_belakang, kelas);
        if (strcmp(search, nim) == 0)
        {
            printf("UBAH NAMA DEPAN : ");
            scanf(" %[^\n]s", &nama_depan);
            printf("UBAH NAMA BELAKANG : ");
            scanf(" %[^\n]s", &nama_belakang);
            printf("UBAH KELAS : ");
            scanf(" %[^\n]s", &kelas);
            fprintf(ubah, "%s!%s!%s!%s!\n" , nim, nama_depan, nama_belakang, kelas);
            
        }
        else {
            fprintf(ubah, "%s!%s!%s!%s!\n" , nim, nama_depan, nama_belakang, kelas);
        }

    }
    fclose(ubah);
    fclose(read);
    remove("modul6.txt");
    rename("modul6_baru.txt", "test.txt" );
}

int delete_data()
{
    FILE *read, *delete;
    read = fopen("modul6.txt", "r");
    delete = fopen("modul6.txt", "w");
    char search[100];
    printf("Cari NIM Untuk Di Hapus : ");
    scanf("%s", search);
    while(!feof(read)){
        fscanf(read, "%[^!]!%[^!]!%[^!]!%[^!]!\n", nim, nama_depan, nama_belakang, kelas);
        if (strcmp(search, nim) == 0)
        {
            
        }
        else {
            fprintf(delete, "%s!%s!%s!%s!\n" , nim, nama_depan, nama_belakang, kelas);
        }

    }
    printf("NIM Berhasil Di Hapus");
    fclose(delete);
    fclose(read);
    remove("modul6.txt");
    rename("modul6_baru.txt", "modul6.txt" );
}